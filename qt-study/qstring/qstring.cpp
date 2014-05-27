/*
 * =====================================================================================
 *
 *       Filename:  qstring.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/27/2014 11:24:43 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Siko Chen (SC), sikocb@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <QTextStream>

#define STR_EQUAL 0


int main(void)
{
   QTextStream out(stdout);

   QString aa = "love";
   
   aa.append(" chess");
   aa.prepend("I ");
   
   out << aa << endl;
   out << "The a string has " << aa.count() 
       << " characters" << endl;
       
   out << aa.toUpper() << endl;    
   out << aa.toLower() << endl;
   
   QString str1 = "The night train";
   out << str1 << endl;
   
   QString str2("A yellow rose");
   out << str2 << endl;
   
   std::string s1 = "A blue sky";
   QString str3 = s1.c_str(); 
   out << str3 << endl;
   
   std::string s2 = "A thick fog";
   QString str4 = QString::fromAscii(s2.data(), s2.size());
   out << str4 << endl;
   
   char s3[] = "A deep forest";
   QString str5(s3);
   out << str5 << endl;

   QString bb = "Eagle";

   out << bb[0] << endl;
   out << bb[4] << endl;
   
   out << bb.at(0) << endl;
   
   if (bb.at(5).isNull()) {
     out << "Outside the range of the string" << endl;  
   }
   
   QString ss1 = "Eagle";
   QString ss2 = "Eagle\n";
   QString ss3 = "Eagle ";
   QString ss4 = "орел";

   out << ss1.length() << endl;
   out << ss2.length() << endl;
   out << ss3.length() << endl;
   out << ss4.length() << endl;

   QString sa1 = "There are %1 white roses";
   int n = 12;
   
   out << sa1.arg(n) << endl;
   
   QString sa2 = "The tree is %1m high";
   double h = 5.65;
   
   out << sa2.arg(h) << endl;
   
   QString sa3 = "We have %1 lemons and %2 oranges";
   int ln = 12;
   int on = 4;
   
   out << sa3.arg(ln).arg(on) << endl;

   QString sub_str = "The night train";
   
   out << sub_str.right(5) << endl;
   out << sub_str.left(9) << endl;
   out << sub_str.mid(4, 5) << endl;
   
   QString sub_str2("The big apple");
   QStringRef sub(&sub_str2, 0, 7);
   
   out << sub.toString() << endl;
   
  QString loop_str = "There are many stars.";
  
  foreach (QChar qc, loop_str) {
    out << qc << " ";  
  }
  
  out << endl;
  
  for (QChar *it=loop_str.begin(); it!=loop_str.end(); ++it) {
    out << *it << " " ;
  }
  
  out << endl;
  
  for (int i = 0; i < loop_str.size(); ++i) {
    out << loop_str.at(i) << " ";    
  }
  
  out << endl;

   QString a = "Rain";
   QString b = "rain";
   QString c = "rain\n";
   
   if (QString::compare(a, b) == STR_EQUAL) {
     out << "a, b are equal" << endl;
   } else {
     out << "a, b are not equal" << endl;
   }
   
   out << "In case insensitive comparison:" << endl;
   
   if (QString::compare(a, b, Qt::CaseInsensitive) == STR_EQUAL) {
     out << "a, b are equal" << endl;
   } else {
     out << "a, b are not equal" << endl;
   }     
   
   if (QString::compare(b, c) == STR_EQUAL) {
     out << "b, c are equal" << endl;
   } else {
     out << "b, c are not equal" << endl;
   }   

   c.chop(1);
   
   out << "After removing the new line character" << endl;
   
   if (QString::compare(b, c) == STR_EQUAL) {
     out << "b, c are equal" << endl;
   } else {
     out << "b, c are not equal" << endl;
   }            

  QString ssa1 = "12";
  QString ssa2 = "15";
  QString ssa3, ssa4;
  
  out << ssa1.toInt() + ssa2.toInt() << endl;
   
  int n1 = 30;
  int n2 = 40;
  
  out << ssa3.setNum(n1) + ssa4.setNum(n2) << endl;

  int digits  = 0;
  int letters = 0;
  int spaces  = 0;
  int puncts  = 0;
  
  QString str = "7 white, 3 red roses.";
  
  foreach(QChar s, str)
  {
    if (s.isDigit()) {
      digits++;
    } else if (s.isLetter()) {
      letters++;
    } else if (s.isSpace()) {
      spaces++;
    } else if (s.isPunct()) {
      puncts++;
    }    
  }  
  
  out << QString("There are %1 characters").arg(str.count()) << endl;
  out << QString("There are %1 letters").arg(letters) << endl;
  out << QString("There are %1 digits").arg(digits) << endl;
  out << QString("There are %1 spaces").arg(spaces) << endl;
  out << QString("There are %1 punctuation characters").arg(puncts) << endl;

  QString str_t = "Lovely";   
   str_t.append(" season");
   
   out << str_t << endl;
   
   str_t.remove(10, 3);
   out << str_t << endl;

   str_t.replace(7, 3, "girl");
   out << str_t << endl;
   
   str_t.clear();
   
   if (str_t.isEmpty()) {
     out << "The string is empty" << endl;
   }

   return 0;
}


