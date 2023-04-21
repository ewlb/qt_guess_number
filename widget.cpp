#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer1=new QTimer(this);
    connect(timer1,SIGNAL(timeout()),this,SLOT(func1()));
    timer1->start(10);
    QRandomGenerator rd;
    the_ans=rd.bounded(QTime::currentTime().msec())%100+1;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::func1()
{

    QString curTime=QTime::currentTime().toString("hh:mm:ss.zzz");
    ui->label->setText("時間: "+curTime);
}


void Widget::on_pushButton_clicked()
{
//    qDebug()<<the_ans;
    int input = ui->lineEdit->text().toInt();
    QString str=QString::number(input);
    if(input>the_ans && input<ui->right->text().toInt()){
        ui->right->setText(str);
        ui->lineEdit->clear();
    }
    else if(input<the_ans && input>ui->left->text().toInt()){
        ui->left->setText(str);
        ui->lineEdit->clear();
    }
    else if(input==the_ans) {
        this->close();
        QMessageBox::information(this,"yaya", "good job~");
    }
    else{
        QMessageBox::information(this,"error", "invalid input");
    }
}

