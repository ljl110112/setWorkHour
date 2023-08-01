#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    xlsx = new QXlsx::Document();
    xlsx->saveAs("2022-modified.xlsx");

    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(getPersons()));
    connect(ui->calendarWidget,SIGNAL(clicked(QDate)),this,SLOT(getData(QDate)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::getPersons()
{
    lPerson.clear();
    QFile file("persons.txt");
    if(!file.open(QIODevice::ReadWrite|QIODevice::Text)){
        QMessageBox::information(this,
                                 "Information",
                                 "文件打开失败！请确认文件位置是否存在！");
    }
    while (!file.atEnd()) {
             QByteArray line = file.readLine();
             lPerson.append(QString::fromLatin1(line));
             qDebug()<<line.toStdString().c_str();
         }
}

bool MainWindow::getProjects()
{

}

bool MainWindow::getData(QDate date)
{
    qDebug()<<date;
    qDebug()<<date.dayOfWeek();
}

