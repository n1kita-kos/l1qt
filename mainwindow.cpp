#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settingsdialog.h"
#include <QtMath>
#include <QFileDialog>
#include <QProcess>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , listModel(new QStringListModel(this))
    , settingsDialog(new SettingsDialog(this))
{
    ui->setupUi(this);

    // Пример установки модели для QListView
    QStringList list;
    list << "Asin" << "Acos" << "Atg"<<"Actg";
    listModel->setStringList(list);
    ui->listView->setModel(listModel);

    // Подключаем сигналы и слоты
    connect(ui->actionExit, &QAction::triggered, this, &MainWindow::on_actionExit_triggered);
    connect(ui->button, &QPushButton::clicked, this, &MainWindow::on_buttonClicked);
    connect(ui->calculateButton, &QPushButton::clicked, this, &MainWindow::calculateTrigFunctions);
    connect(ui->settingsButton, &QPushButton::clicked, this, &MainWindow::showSettingsDialog);
    connect(ui->radioButton, &QRadioButton::toggled, this, &MainWindow::on_radioButton_toggled);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_buttonClicked()
{
    ui->labelAcos->setText("");
    ui->labelAsin->setText("");
    ui->labelAtan->setText("");
    ui->labelAcot->setText("");
    ui->lineEdit->setText("");

}

void MainWindow::calculateTrigFunctions()
{
    qreal value = ui->lineEdit->text().toDouble();
    qreal acosValue = qAcos(value);
    qreal asinValue = qAsin(value);
    qreal atanValue = qAtan(value);
    qreal acotValue = qAtan(1 / value);

    ui->labelAcos->setText(QString::number(acosValue));
    ui->labelAsin->setText(QString::number(asinValue));
    ui->labelAtan->setText(QString::number(atanValue));
    ui->labelAcot->setText(QString::number(acotValue));
}

void MainWindow::showSettingsDialog()
{
    settingsDialog->setModal(false);
    settingsDialog->show();
}

void MainWindow::readFile(const QString &fileName)
{
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QStringList list;
        while (!in.atEnd()) {
            QString line = in.readLine();
            list << line;
        }
        listModel->setStringList(list);
        file.close();
    }
}

void MainWindow::writeFile(const QString &fileName, const QString &text)
{
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << text;
        file.close();
    }
}




void MainWindow::on_radioButton_toggled(bool checked)
{
    if(!checked) {
        ui->calculateButton->show();
    }
    else {
        ui->calculateButton->hide();
    }
}







