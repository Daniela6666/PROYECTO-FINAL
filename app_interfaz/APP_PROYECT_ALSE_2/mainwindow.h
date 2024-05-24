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

/**
 * @brief Class represents the main window of the application
*/

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:

    /**
     * @brief Method to update the time in the interface.
    */
    void tiempo();

    /**
     * @brief Method to open the database.
    */
    void abrir_db();

    /**
     * @brief Method to check the current time.
     * @return The current time in const char* format.
    */
    const char* consultar_hora();

    /**
     * @brief Method to calculate the time difference between the current date and time and a previous date and time.
     * @param previous_date_and_time The previous date and time in const unsigned char* format.
     * @return The time difference in seconds.
    */
    int restar_fechas( const unsigned char* fecha_y_hora_anterior );

    /**
     * @brief Method to query and display the value of a field in a QLineEdit.
     * @param field The name of the field to query.
     * @param lineEdit The QLineEdit where to display the value.
    */
    void consultarValor(const QString &campo, QLineEdit *lineEdit);

    /**
     * @brief Method to display initial data in the interface.
    */
    void mostrarDatosIniciales();


signals:
    /**
     * @brief Signal emitted when the minute is incremented.
    */
    void minutoIncrementado();

private:
    Ui::MainWindow *ui;
    QTimer *timer; /**< Timer to update time. */
    std::tm fecha_hora; /**< Actual time and date */
    std::string fecha_str; /**< Actual time and date in string format */
    QSqlDatabase db; /**< Database. */
    short int segundos; /**< Seconds on timer. */
    short int minutos; /**< Minutes on timer. */
    double minutos_transcurridos; /**< minutes elapsed since the start of the console application execution. */
    int id; /**< id in Mediciones table. */
    int id_sensor; /**< id sensor in Mediciones table. */
    std::array<QLineEdit*, 21> lineEdits; /**< Array of QLineEdit. */
};
#endif // MAINWINDOW_H
