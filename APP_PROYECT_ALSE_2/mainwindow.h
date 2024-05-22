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
    void consultarValor(const QString &campo, QLineEdit *lineEdit);

signals:
    void minutoIncrementado();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QSqlDatabase db;
    short int segundos;
    short int minutos;
    int id;
    int id_sensor;
    std::array<QLineEdit*, 21> lineEdits;
};
#endif // MAINWINDOW_H
