//File cfantasymovies.h

//This file uses slots and signals for operating the ui. Two slots are used; pushButtonClicked()
//is used for the "OK" button once user has entered a number, exitButtonClicked() is used when
//the user clicks the "X" button to exit program

#ifndef CFANTASYMOVIES_H
#define CFANTASYMOVIES_H

#include "CRandom.h"
#include "CReadFile.h"

#include <QMainWindow>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class CFantasyMovies; }
QT_END_NAMESPACE

class CFantasyMovies : public QMainWindow
{
    Q_OBJECT
private slots:
    void pushButtonClicked();   //This function is called with "OK" is pressed
    void exitButtonClicked();   //This function is called when the red "X" is pressed

public:
    CFantasyMovies(QWidget *parent = nullptr);   //Constructor
    ~CFantasyMovies();                           //Destructor


private:
    CRandom * random;
    CReadFile * ReadFile;
    Ui::CFantasyMovies *ui;
    QLabel  outputLabel;
};
#endif // CFANTASYMOVIES_H
