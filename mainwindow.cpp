#include "mainwindow.h"

/*
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // default
    ui->setupUi(this);

    // create scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,ui->gVScene->width(), ui->gVScene->height());
    ui->gVScene->setScene(scene);
    scene->clear();

    // create tree
    vector<double> vec;
    for (int i = 0; i < 6; i++)
        vec.push_back(rand() % 1000 / 10.0);
    myTree = new QtVTree<double>(vec);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pbSearch_clicked()
{
    myTree->ToSearchTree();
    myTree->Draw(scene);
}

void MainWindow::on_pbBalanced_clicked()
{
    myTree->ToBalancedTree();
    myTree->Draw(scene);
}
*/
