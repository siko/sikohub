/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/28/2014 12:18:09 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Siko Chen (SC), sikocb@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <QApplication>
#include "burning.h"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  Burning window;

  window.resize(370, 200);
  window.move(300, 300);
  window.setWindowTitle("The Burning widget");
  window.show();

  return app.exec();
}

