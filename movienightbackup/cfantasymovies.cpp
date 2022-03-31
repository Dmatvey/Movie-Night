//File: cfantasymovies.cpp

#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>
#include "cfantasymovies.h"
#include "./ui_cfantasymovies.h"
#include "CRandom.h"
#include "CReadFile.h"

CFantasyMovies::CFantasyMovies(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CFantasyMovies)
{
    ui->setupUi(this);    //UI initiated
    QString mFilename = "D:/Documents/SE560/MovieNight/Movie_night/movieTitles.txt";  //File directory
    ReadFile=new CReadFile();   //ReadFile object created here
    random = new CRandom(ReadFile);     //random object created with ReadFile passed to it
    ReadFile->readTitles(mFilename);   //Function call initiates file read

    connect ( ui->Ok_Button, SIGNAL( clicked() ), this, SLOT(pushButtonClicked() ) ); //"OK" button
    connect ( ui->X_btn, SIGNAL( clicked() ), this, SLOT(exitButtonClicked() ) );     //"X" button

}

CFantasyMovies::~CFantasyMovies()    //Destructor
{
    delete ui;
}

void CFantasyMovies::pushButtonClicked(void){    //Listener for "OK" button

    QString number = ui->InputNumber->toPlainText();   //Number entered by user
    int InputInt = number.toInt();
    int random_result = random->randomNumber(InputInt);   //inputNumber passed to function to select random number
    QString outputText = QString::fromStdString(random->selectTitle(random_result));  //Movie title selection
    ui->label_Output->setText(outputText);    //Movietitle passed to output text for result on UI
}
void CFantasyMovies::exitButtonClicked(){       //Listener for "X" button
    QApplication::quit();
}
