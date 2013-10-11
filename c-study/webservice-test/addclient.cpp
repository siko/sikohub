/*
 * =====================================================================================
 *
 *       Filename:  addclient.c
 *
 *    Description:  client
 *
 *        Version:  1.0
 *        Created:  10/11/2013 02:54:03 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Siko Chen (SC), sikocb@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "stdsoap2.h"
#include "soapH.h"
#include "add.nsmap"

int add(const char* server, int num1, int num2, int *sum);

int main(int argc, char **argv)
{
     int result = -1;
     char* server="http://localhost:4567/";
     int num1 = 0;
     int num2 = 0;
     int sum = 0;
     if( argc < 3 )
     {
         printf("usage: %s num1 num2 \n", argv[0]);
         exit(0);
     }
     num1 = atoi(argv[1]);
     num2 = atoi(argv[2]);
     result = add(server, num1, num2, &sum);
     if (result != 0)
     {
         printf("soap err,errcode = %d\n", result);
     }
     else
     {
         printf("%d+%d=%d\n", num1, num2, sum );
     }
     return 0;
}

int add(const char* server, int num1, int num2, int *sum)
{
     struct soap add_soap;
     int result = 0;
     soap_init(&add_soap);

     soap_call_ns__add( &add_soap, server, "", num1, num2, sum );
     if(add_soap.error)
     {
         printf("soap error:%d,%s,%s\n", add_soap.error, *soap_faultcode(&add_soap), *soap_faultstring(&add_soap) );
         result = add_soap.error;
     }
     soap_end(&add_soap);
     soap_done(&add_soap);
     return result;
}
