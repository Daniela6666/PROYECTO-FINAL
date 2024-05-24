#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>
#include <QFile>
#include <QLineEdit>
#include <array>
#include <ctime>
#include <QString>
#include <sstream>
#include <string>
#include <cstring>
#include <QDir>
#include <QCoreApplication>
#include <QStandardPaths>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void tiempo();
    void abrir_db();

    const char* consultar_hora();
    int restar_fechas( const unsigned char* fecha_y_hora_anterior );


    void consultarValor(const QString &campo, QLineEdit *lineEdit);
    void mostrarDatosIniciales();


signals:
    void minutoIncrementado();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    std::tm fecha_hora;
    std::string fecha_str;
    QSqlDatabase db;
    short int segundos;
    short int minutos;
    double minutos_transcurridos;

    int id;
    int id_sensor;
    std::array<QLineEdit*, 21> lineEdits;
};
#endif // MAINWINDOW_H
