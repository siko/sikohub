/*
 * =====================================================================================
 *
 *       Filename:  quit.cpp
 *
 *    Description:  qt example of quit
 *
 *        Version:  1.0
 *        Created:  11/02/2013 03:02:49 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Siko Chen (SC), sikocb@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <QApplication>
#include <QPushButton>

int main(int argc,char *argv[])
{

    QApplication app(argc,argv);
    QPushButton *button = new QPushButton("Quit!!");
    QObject::connect(button,SIGNAL(clicked()),
            &app,SLOT(quit()));
    button->show();
    return app.exec();

}

