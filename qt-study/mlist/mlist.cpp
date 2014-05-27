/*
 * =====================================================================================
 *
 *       Filename:  mlist.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/27/2014 11:13:48 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Siko Chen (SC), sikocb@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <QTextStream>
#include <QList>

int main()
{
  QTextStream out(stdout);

  QList<QString> list;

  list << "Balzac" << "Tolstoy" << "Guldbrassen"
       << "London" << "Galsworthy" << "Sienkiewicz";

  qSort(list);

  for (int i = 0; i < list.size(); ++i) {
    out << list.at(i) << endl;
  }

}

