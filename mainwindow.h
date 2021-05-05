#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma once
#include <QMainWindow>
#include "QtVTree.h"
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QGraphicsScene* scene;
    QtVTree<double>* myTree;

public:
    MainWindow(QWidget *parent = nullptr)
    {
        // default
        ui->setupUi(this);

        // other
        srand(time(0));

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

    ~MainWindow()
    {
        //delete ui;
    }

private slots:
    void on_pbSearch_clicked()
    {
        if (myTree != nullptr)
        {
            scene->clear();
            myTree->ToSearchTree();
            myTree->Draw(scene);
        }
    }

    void on_pbBalanced_clicked()
    {        
        if (myTree != nullptr)
        {
            scene->clear();
            myTree->ToBalancedTree();
            myTree->Draw(scene);
        }
    }

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
