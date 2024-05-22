#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer =  new QTimer(this);
        connect(timer, SIGNAL( timeout() ), this, SLOT(tiempo()));

        abrir_db();
        fecha_hora = {};

        const char* fecha_y_hora_anterior = consultar_hora();
        if (fecha_y_hora_anterior != nullptr) {
            int totalSegundos = restar_fechas(reinterpret_cast<const unsigned char*>(fecha_y_hora_anterior));

            minutos = totalSegundos / 60;
            segundos = totalSegundos % 60;

            ui->segundos->display(segundos);
            ui->minutos->display(minutos);
        } else {
            // Si no se pudo obtener la hora anterior, iniciar desde cero
            segundos = 0;
            minutos = 0;
        }

        timer->start(1000);

    lineEdits[0] = ui->MIN_temp;
    lineEdits[1] = ui->MIN_hum;
    lineEdits[2] = ui->MIN_hum_suel;
    lineEdits[3] = ui->MIN_vel;
    lineEdits[4] = ui->MIN_dir;
    lineEdits[5] = ui->MIN_pre;
    lineEdits[6] = ui->MIN_in;

    lineEdits[7] = ui->MX_temp;
    lineEdits[8] = ui->MX_hum;
    lineEdits[9] = ui->MX_hum_suel;
    lineEdits[10] = ui->MX_vel;
    lineEdits[11] = ui->MX_dir;
    lineEdits[12] = ui->MX_pre;
    lineEdits[13] = ui->MX_in;

    lineEdits[14] = ui->PR_temp;
    lineEdits[15] = ui->PR_hum;
    lineEdits[16] = ui->PR_hum_suel;
    lineEdits[17] = ui->PR_vel;
    lineEdits[18] = ui->PR_dir;
    lineEdits[19] = ui->PR_pre;
    lineEdits[20] = ui->PR_in;

    // Conectar la señal minutoIncrementado a la ranura consultarMinimo
    for (int i = 0; i < 7; ++i) {
            connect(this, &MainWindow::minutoIncrementado, this, [=]() { consultarValor("minimo", lineEdits[i]); });
            connect(this, &MainWindow::minutoIncrementado, this, [=]() { consultarValor("maximo", lineEdits[i + 7]); });
            connect(this, &MainWindow::minutoIncrementado, this, [=]() { consultarValor("promedio", lineEdits[i + 14]); });
        }


    id = 1;
    id_sensor = 1;

    abrir_db();    

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::tiempo()
{
    //qDebug() << "update..";
    segundos = segundos + 1;
    if (segundos == 60) {
        minutos = minutos + 1;
        segundos = 0;
        id_sensor = 1;
        emit minutoIncrementado();
    }
    else{
        ui -> segundos -> display(segundos);
        ui -> minutos -> display(minutos);
    }
}



void MainWindow::abrir_db()
{
    QString dbPath = "/home/sebastian/proyect_ALSE/PROYECTO-FINAL/app_consola/build/sensores.db";

       // Verifica si el archivo de la base de datos existe
       if (!QFile::exists(dbPath)) {
           qDebug() << "Error: La base de datos no existe en la ruta especificada:" << dbPath;
           return;
       }

       // Crear una instancia de QSqlDatabase y establecer el controlador a SQLite
       QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

       // Establecer el nombre de la base de datos
       db.setDatabaseName(dbPath);

       // Abrir la base de datos
       if (!db.open()) {
           qDebug() << "Error: No se pudo abrir la base de datos!";
           qDebug() << db.lastError().text();
           return;
       }
       else{
           qDebug() << "La base de datos está abierta.";
       }
}

const char* MainWindow::consultar_hora() {
    QString consulta = QString("SELECT fecha_y_hora_de_ejecucion FROM datos WHERE id_ejecucion = :id");
    QSqlQuery consultar;
    consultar.prepare(consulta);

    consultar.bindValue(":id", 1); // Asumiendo que estamos buscando el registro con id = 1.

    if (!consultar.exec()) {
        qDebug() << "No se ha consultado correctamente.";
        qDebug() << "ERROR! " << consultar.lastError();
        return nullptr; // Retornar nullptr en caso de error
    }

    if (consultar.next()) {
        QString fechaStr = consultar.value(0).toString();
        qDebug() << "Fecha y hora obtenida de la base de datos: " << fechaStr;

        // Convertir QString a std::string y almacenarlo en la variable miembro
        fecha_str = fechaStr.toStdString();

        // Retornar un puntero a los datos del std::string
        return fecha_str.c_str();
    }

    return nullptr; // Retornar nullptr si no se encontró el registro
}

int MainWindow::restar_fechas(const unsigned char* fecha_y_hora_anterior) {
    time_t marca_tiempo = time(nullptr);
    string fecha_y_hora = ctime(&marca_tiempo);

    char hora1[9];
    strncpy(hora1, reinterpret_cast<const char*>(fecha_y_hora_anterior) + 11, 8);
    hora1[8] = '\0';

    char hora2[9];
    strncpy(hora2, fecha_y_hora.c_str() + 11, 8);
    hora2[8] = '\0';

    int h1, m1, s1;
    sscanf(hora1, "%d:%d:%d", &h1, &m1, &s1);

    int h2, m2, s2;
    sscanf(hora2, "%d:%d:%d", &h2, &m2, &s2);

    int difHoras = h2 - h1;
    int difMinutos = m2 - m1;
    int difSegundos = s2 - s1;

    // Convertir todo a segundos
    int totalSegundos = (difHoras * 3600) + (difMinutos * 60) + difSegundos;

    // Asegurarse de que los segundos no sean negativos
    if (totalSegundos < 0) {
        totalSegundos += 24 * 3600; // Añadir un día en segundos si la diferencia es negativa
    }

    return totalSegundos;
}


void MainWindow::consultarValor(const QString &campo, QLineEdit *lineEdit)
{
    QString consulta = QString("SELECT %1 FROM Mediciones WHERE id = :id AND id_sensor = :id_sensor").arg(campo);
    QSqlQuery consultar;
    consultar.prepare(consulta);

    // Enlazar las variables con los placeholders
    consultar.bindValue(":id", id);
    consultar.bindValue(":id_sensor", id_sensor);

    QString valor;

    if (consultar.exec()) {
        qDebug() << "Se ha consultado correctamente.";

        if (consultar.next()) {  // Mover al primer (y en este caso único) resultado
            valor = consultar.value(0).toString();  // Obtener el valor del primer campo
        }
    } else {
        qDebug() << "No se ha consultado correctamente.";
        qDebug() << "ERROR! " << consultar.lastError();
    }

    // Actualizar la interfaz de usuario con el valor obtenido
    lineEdit->setText(valor);

    static int contador = 0; // Variable estática para mantener el valor entre las llamadas a la función
    contador++;
    if (contador == 3) { // Si hemos actualizado todos los QLineEdit correspondientes al "mínimo"
        id += 1;
        id_sensor += 1;
        contador = 0;
    }
}

