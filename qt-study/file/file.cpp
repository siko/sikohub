/*
 * =====================================================================================
 *
 *       Filename:  file.cpp
 *
 *    Description:  qt file example
 *
 *        Version:  1.0
 *        Created:  05/27/2014 11:02:35 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Siko Chen (SC), sikocb@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <QTextStream>
#include <QFile>

int main()
{

   QFile data("myfile");

   if (data.open(QFile::WriteOnly)) {
     QTextStream out(&data);
     out << "You make me want to be a better man." << endl;
   }
}
