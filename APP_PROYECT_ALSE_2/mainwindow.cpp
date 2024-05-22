#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer =  new QTimer(this);
    connect(timer, SIGNAL( timeout() ), this, SLOT(tiempo()));
    segundos = 0;
    minutos = 0;
    timer -> start(1000);

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
    QString dbPath = "/home/sebastian/proyect_ALSE/PROYECTO-FINAL/APP_grafica_ALSE/sensores.db";  // Ajusta esto a la ruta absoluta correcta

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
