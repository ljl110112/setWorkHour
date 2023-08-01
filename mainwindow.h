#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtXlsx>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QXlsx::Document* xlsx;
    QList<QString> lPerson;
    QList<QString> lProject;

private slots:
    bool getPersons();
    bool getProjects();
    bool getData(QDate date);
};
#endif // MAINWINDOW_H
