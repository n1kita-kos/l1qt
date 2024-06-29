#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QListView>
#include <QStringListModel>
#include <QFile>
#include <QTextStream>
#include <QDialog>
#include <QString>
#include <QStringList>
#include"settingsdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionExit_triggered();
    void on_buttonClicked();
    void calculateTrigFunctions();
    void showSettingsDialog();

    void on_button_clicked();

    void on_radioButton_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    QStringListModel *listModel;
    SettingsDialog *settingsDialog;

    // Пример методов для работы с файлами
    void readFile(const QString &fileName);
    void writeFile(const QString &fileName, const QString &text);
};

#endif // MAINWINDOW_H
