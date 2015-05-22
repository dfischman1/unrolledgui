#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Unrolled Linked List");

    mainWidget = new QWidget();
    mainLayout = new QVBoxLayout();

    H0Layout = new QHBoxLayout();

    //first horizontal box for creating list of certain type and node size
    nodeSize = new QLineEdit();
    nodeSize->setPlaceholderText("input node size");
    createButton = new QPushButton();
    createButton->setText("Create");
    dropDownBox2 = new QComboBox();
    dropDownBox2->addItem(tr("int"));
    dropDownBox2->addItem(tr("string"));
    dropDownBox2->addItem(tr("double"));

    H0Layout->addWidget(nodeSize);
    H0Layout->addWidget(dropDownBox2);
    H0Layout->addWidget(createButton);

    connect(createButton,SIGNAL(clicked(bool)),this,SLOT(createList()));

    //second horizontal area to insert or remove an item
    H1Layout = new QHBoxLayout();

    dropDownBox1 = new QComboBox();
    dropDownBox1->addItem(tr("Insert"));
    dropDownBox1->addItem(tr("Remove"));

    valueLine = new QLineEdit();
    valueLine->setPlaceholderText("input value here");
    enterButton = new QPushButton();
    enterButton->setText("Enter");

    H1Layout->addWidget(dropDownBox1);
    H1Layout->addWidget(valueLine);
    H1Layout->addWidget(enterButton);

    connect(enterButton,SIGNAL(clicked(bool)),this,SLOT(insertButton()));

    //third horizontal area to search for an item
    H2Layout = new QHBoxLayout();

    searchLine = new QLineEdit();
    searchLine->setPlaceholderText("search value here");
    findButton = new QPushButton();
    findButton->setText("Search");

    H2Layout->addWidget(searchLine);
    H2Layout->addWidget(findButton);

    connect(findButton,SIGNAL(clicked(bool)),this,SLOT(searchButton()));

    //forth horizonal area for sorting linked list
    H3Layout = new QHBoxLayout();

    sortButton = new QPushButton();
    sortButton->setText("Sort");

    H3Layout->addWidget(sortButton);

    connect(sortButton,SIGNAL(clicked(bool)),this,SLOT(sortAction()));

    //fifth horizontal area to print
    H4Layout = new QVBoxLayout();

    printBox = new QTextEdit();

    H4Layout->addWidget(printBox);

    //sixth hoizontal area to delete list
    H5Layout = new QHBoxLayout();

    deleteButton = new QPushButton();
    deleteButton->setText("Delete");

    H5Layout->addWidget(deleteButton);

    connect(deleteButton,SIGNAL(clicked(bool)),this,SLOT(deleteAction()));

    //labels for each box
    H0Label = new QLabel();
    H0Label->setText("Create a new unrolled linked list");
    H1Label = new QLabel();
    H1Label->setText("Add or remove values");
    H2Label = new QLabel();
    H2Label->setText("Search for values");
    H3Label = new QLabel();
    H3Label->setText("Sort the list");
    H4Label = new QLabel();
    H4Label->setText("Your list");
    H5Label = new QLabel();
    H5Label->setText("Delete your list");
    H6Label = new QLabel();
    H6Label->setText("Created by: Ryan Simpson & Daelin Fischman");
    H6Label->setAlignment(Qt::AlignRight);
    H6Label->setTextFormat(Qt::PlainText);

    //dividers for each box
    H11Label = new QLabel();
    H11Label->setFrameStyle(QFrame::HLine | QFrame::Sunken);
    H11Label->setLineWidth(2);
    H21Label = new QLabel();
    H21Label->setFrameStyle(QFrame::HLine | QFrame::Sunken);
    H21Label->setLineWidth(2);
    H31Label = new QLabel();
    H31Label->setFrameStyle(QFrame::HLine | QFrame::Sunken);
    H31Label->setLineWidth(2);
    H41Label = new QLabel();
    H41Label->setFrameStyle(QFrame::HLine | QFrame::Sunken);
    H41Label->setLineWidth(2);
    H51Label = new QLabel();
    H51Label->setFrameStyle(QFrame::HLine | QFrame::Sunken);
    H51Label->setLineWidth(2);
    H61Label = new QLabel();
    H61Label->setFrameStyle(QFrame::HLine | QFrame::Sunken);
    H61Label->setLineWidth(2);

    //add horizontal layouts, labels, and dividers to main window
    mainLayout->addWidget(H0Label);
    mainLayout->addLayout(H0Layout);
    mainLayout->addWidget(H11Label);
    mainLayout->addWidget(H1Label);
    mainLayout->addLayout(H1Layout);
    mainLayout->addWidget(H21Label);
    mainLayout->addWidget(H2Label);
    mainLayout->addLayout(H2Layout);
    mainLayout->addWidget(H31Label);
    mainLayout->addWidget(H3Label);
    mainLayout->addLayout(H3Layout);
    mainLayout->addWidget(H41Label);
    mainLayout->addWidget(H4Label);
    mainLayout->addLayout(H4Layout);
    mainLayout->addWidget(H51Label);
    mainLayout->addWidget(H5Label);
    mainLayout->addLayout(H5Layout);
    mainLayout->addWidget(H61Label);
    mainLayout->addWidget(H6Label);

    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);

    //style
    deleteButton->setObjectName("deleteB");
}

//create a new list
void MainWindow::createList()
{
    QMessageBox msgBox;
    msgBox.setText("Your list has been created");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.exec();
    list = new ulinklist<int>(nodeSize->text().toDouble());
    updatePrint();
}

/*std::string MainWindow::listType()
{
    return dropDownBox2->currentData().toString();
}*/

//insert or remove objects from list
void MainWindow::insertButton()
{
    QMessageBox msgBox;
    msgBox.setText(valueLine->text() + " was not found in your list.");
    msgBox.setIcon(QMessageBox::Critical);
    if(dropDownBox1->currentIndex() == 0)
        list->insert(valueLine->text().toInt());
    else
    {
        bool truth = list->remove(valueLine->text().toInt());
        if(!truth)
            msgBox.exec();
    }
    updatePrint();
}

//search for an object
void MainWindow::searchButton()
{
    QMessageBox msgBox;
    bool found = list->search(searchLine->text().toInt());
    if(found)
    {
        msgBox.setText(searchLine->text() + " was found in your list.");
        msgBox.setIcon(QMessageBox::Information);
    }
    else
    {
        msgBox.setText(searchLine->text() + " was not found in your list.");
        msgBox.setIcon(QMessageBox::Critical);
    }
    msgBox.exec();
}

//sort the list
void MainWindow::sortAction()
{
    list->sort();
    updatePrint();
}

//update the print field
void MainWindow::updatePrint()
{
    QString string = QString::fromStdString(list->print());
    printBox->setText(string);
}

//delete the current list
void MainWindow::deleteAction()
{
    QMessageBox msgBox;
    msgBox.setText("Your list has been deleted.");
    msgBox.setInformativeText("Feel free to make a new list.");
    msgBox.setIcon(QMessageBox::Critical);
    ulinklist<int> *tmp = list;
    delete tmp;
    list = tmp;
    updatePrint();
    msgBox.exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}
