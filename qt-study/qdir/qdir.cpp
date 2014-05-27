/*
 * =====================================================================================
 *
 *       Filename:  qdir.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/27/2014 11:17:49 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Siko Chen (SC), sikocb@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <QTextStream>
#include <QDir>


int main()
{
  QTextStream out(stdout);
  QDir dir;

  QString home = QDir::homePath();
  out << home << endl;

  QStringList filters;
  filters << "*.cpp" << "*.c~";
  dir.setNameFilters(filters);

  QFileInfoList list = dir.entryInfoList();

  for (int i = 0; i < list.size(); ++i) {
    QFileInfo fileInfo = list.at(i);
    out << QString("%1").arg(fileInfo.fileName());
    out << endl;
  } 
}
