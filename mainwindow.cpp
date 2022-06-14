#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "readfile.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    free(information.massivdata);
    delete ui;
}




void MainWindow::on_btn_openfile_clicked()
{
    QString path_file;
    if (ui->LinePathFile->text() == ""){
       path_file = QFileDialog::getOpenFileName(this, tr("Open File"), "C://", "All files(*.*);;Table File(*.csv");
       ui->LinePathFile->setText(path_file);
    }
}


void MainWindow::on_btn_loaddata_clicked()//слот под кнопку загрузки
{
    if ((ui->NameRegion->text() == "") or (ui->LinePathFile->text() == "")){
        if (ui->NameRegion->text() == ""){
            QMessageBox::information(this,"окно","пустой регион");
        }
        if (ui->LinePathFile->text() == ""){
            QMessageBox::information(this,"окно","пустой регион");
        }
    }else{
        if(information.size != 0)free(information.massivdata);
        information.linePathFile = ui->LinePathFile->text();
        information.lineNameRegion= ui->NameRegion->text();
        information.work_file = variants::readfile;
        SinglePointOfEmpty(&information);
        if (information.kolerrorfile == -1){
            QMessageBox::information(this,"окно","не удалось открыть файл");
            return;
        }else if(information.kolerrorfile == -2){
            QMessageBox::information(this,"окно","не найден регион");
            return;
        }

        Work_table();
    }

}



void MainWindow::on_pushButton_calculations_clicked()
{
    if (ui->NameRegion->text() == ""){
        QMessageBox::information(this,"окно","пустой регион");
    }else{
        if (ui->number_colomn->text() == "3" or ui->number_colomn->text() == "4" or ui->number_colomn->text() == "5" or ui->number_colomn->text() == "6" or ui->number_colomn->text() == "7"){
        information.stolb = ui->number_colomn->text();
        information.work_file = variants::maxandmin;
        information.maxminavg = (double*)calloc(3, sizeof(double));
        if(information.size == 0){
            QMessageBox::critical(this,"окно","ошибка ввода");
        }
        SinglePointOfEmpty(&information);
        if (information.kolerrorminmaxavd == -1){
            QMessageBox::information(this,"окно","ошибка ввода");
            return;
        }
        if (information.maxminavg[0] == 0 and information.maxminavg[1] == 0 and information.maxminavg[2] == 0){
            QMessageBox::information(this,"окно","пустые значения");
        }else{
            ui->min->setText(QString::number(information.maxminavg[0]));
            ui->max->setText(QString::number(information.maxminavg[1]));
            ui->med->setText(QString::number(information.maxminavg[2]));
            DrawRez();
            free(information.drawList);
        }

        free(information.maxminavg);
        }else{
            QMessageBox::information(this,"окно","неправильный ввод колонки");
        }
    }
}

