/*
 * =====================================================================================
 *
 *       Filename:  hello.cpp
 *
 *    Description:  qt study
 *
 *        Version:  1.0
 *        Created:  11/02/2013 02:53:40 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Siko Chen (SC), sikocb@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <QApplication>
#include <QLabel>

int main(int argc,char *argv[])
{

    QApplication app(argc,argv);
    QLabel *label = new QLabel("Hello Qt!");
    label->show();
    return app.exec();

}
