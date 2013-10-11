/*
 * =====================================================================================
 *
 *       Filename:  addserver.c
 *
 *    Description:  server of web service
 *
 *        Version:  1.0
 *        Created:  10/11/2013 02:43:25 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Siko Chen (SC), sikocb@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include "add.h"
#include "add.nsmap"
int main(int argc, char **argv)
{
　　int m, s; /* master and slave sockets */
　　struct soap add_soap;
　　soap_init(&add_soap);
　　soap_set_namespaces(&add_soap, add_namespaces);
　　if (argc < 2)
　　{
　　　　printf("usage: %s　 ", argv[0]);
　　　　exit(1);
　　}
　　else
　　{
　　　　m = soap_bind(&add_soap, NULL, atoi(argv[1]), 100);
　　　　if (m < 0)
　　　　{
　　　　　　soap_print_fault(&add_soap, stderr);
　　　　　　exit(-1);
　　　　}
　　　　fprintf(stderr, "Socket connection successful: master socket = %d ", m);
　　　　for ( ; ; )
　　　　{
　　　　　　s = soap_accept(&add_soap);
　　　　　　if (s < 0)
　　　　　　{
　　　　　　　　soap_print_fault(&add_soap, stderr);
　　　　　　　　exit(-1);
　　　　　　}
　　　　　　fprintf(stderr, "Socket connection successful: slave socket = %d ", s);
　　　　　　add_serve(&add_soap);//该句说明该server的服务
　　　　　　soap_end(&add_soap);
　　　　}
　　}
　　return 0;
}

//server端的实现函数与add.h中声明的函数相同，但是多了一个当前的soap连接的参数
int ns__add(struct soap *add_soap, int num1, int num2, int *sum)
{
　　*sum = num1 + num2;
　　return 0;
}



