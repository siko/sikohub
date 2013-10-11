/*
 * =====================================================================================
 *
 *       Filename:  add.h
 *
 *    Description:  web service using c
 *
 *
 *        Version:  1.0
 *        Created:  10/11/2013 02:39:35 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Siko Chen (SC), sikocb@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

//gsoap ns service name: add
//gsoap ns service namespace: http://mail.263.net/add.wsdl
//gsoap ns service location: http://mail.263.net
//gsoap ns service executable: add.cgi
//gsoap ns service encoding: encoded
//gsoap ns schema namespace: urn:add
int ns__add( int num1, int num2, int* sum );


