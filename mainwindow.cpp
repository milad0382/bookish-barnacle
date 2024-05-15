#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCryptographicHash>
#include <QtCore>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     //connect(ui->cb_sha,SIGNAL(currentTextChanged()),this,SLOT(clear_var()));
     connect(ui->cb_sha,SIGNAL(currentIndexChanged(int)), this, SLOT(clear_var()));
}
MainWindow::~MainWindow()
{
    delete ui;



}
void MainWindow::on_le_sha_textChanged(const QString &hash)
{
    QString sha256;
    QByteArray hash_data;
    hash_data.append(hash);

    //convert
    if(ui->cb_sha->currentText() == "SHA256 Base64")
    sha256 = QString(QCryptographicHash::hash(QByteArray::fromBase64(hash_data),QCryptographicHash::Sha256).toHex());
    else if(ui->cb_sha->currentText() == "SHA256 Hex")
    sha256 = QString(QCryptographicHash::hash(QByteArray::fromHex(hash_data),QCryptographicHash::Sha256).toHex());
    else if(ui->cb_sha->currentText() == "SHA256 ASCII")
    sha256 = QString(QCryptographicHash::hash(hash.toLocal8Bit(),QCryptographicHash::Sha256).toHex());

    //write to log
    ui->log_sha->setText(QString("Response : %0").arg(sha256));
}
void MainWindow::on_bt_sha_gen_clicked()
{
    QString sha256;
    QByteArray hash_data;
    hash_data.append(ui->le_sha->text());

    //convert
    if(ui->cb_sha->currentText() == "SHA256 Base64")
    sha256 = QString(QCryptographicHash::hash(QByteArray::fromBase64(hash_data),QCryptographicHash::Sha256).toHex());
    else if(ui->cb_sha->currentText() == "SHA256 Hex")
    sha256 = QString(QCryptographicHash::hash(QByteArray::fromHex(hash_data),QCryptographicHash::Sha256).toHex());
    else if(ui->cb_sha->currentText() == "SHA256 ASCII")
    sha256 = QString(QCryptographicHash::hash(ui->le_sha->text().toLocal8Bit(),QCryptographicHash::Sha256).toHex());

    //write to log
    ui->log_sha->setText(QString("Response : %0").arg(sha256));
}
void MainWindow::clear_var(){
qInfo()<<"hello";
    ui->le_sha->clear();
}
