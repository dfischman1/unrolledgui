#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QComboBox>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QWidget>
#include <QLabel>
#include <sstream>
#include <QMessageBox>
#include "ulinklist.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void createList();
    void listType(){}
    void insertButton();
    void searchButton();
    void sortAction();
    void updatePrint();
    void deleteAction();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:

    Ui::MainWindow *ui;
    QWidget *mainWidget;
    QVBoxLayout *mainLayout;

    //first horizontal box for creating list of certain type and node size
    QHBoxLayout *H0Layout;
    QPushButton *createButton;
    QLineEdit *nodeSize;
    QComboBox *dropDownBox2;

    //second horizontal area to insert or remove an item
    QHBoxLayout *H1Layout;
    QComboBox *dropDownBox1;
    QLineEdit *valueLine;
    QPushButton *enterButton;

    //third horizontal area to search for an item
    QHBoxLayout *H2Layout;
    QLineEdit *searchLine;
    QPushButton *findButton;

    //forth horizonal area for sorting linked list
    QHBoxLayout *H3Layout;
    QPushButton *sortButton;

    //fifth horizontal area to print
    QVBoxLayout *H4Layout;
    QTextEdit *printBox;

    //sixth hoizontal area to delete list
    QHBoxLayout *H5Layout;
    QPushButton *deleteButton;

    //labels for each box
    QLabel *H0Label;
    QLabel *H1Label;
    QLabel *H2Label;
    QLabel *H3Label;
    QLabel *H4Label;
    QLabel *H5Label;
    QLabel *H6Label;

    //dividers for each box
    QLabel *H11Label;
    QLabel *H21Label;
    QLabel *H31Label;
    QLabel *H41Label;
    QLabel *H51Label;
    QLabel *H61Label;

    //change type
    ulinklist<int> *list = new ulinklist<int>;
};

#endif // MAINWINDOW_H
