/*
 * =====================================================================================
 *
 *       Filename:  hello.c
 *
 *    Description:  study c, hello worrld
 *
 *        Version:  1.0
 *        Created:  09/11/2013 01:50:06 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Siko Chen (SC), sikocb@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>

main(){
    /* int fahr; */
    
    /* say hello,siko! */
    /* printf("Hi Siko\n"); */

    /* check the format */
    /* for(fahr = 0 ;fahr <= 300;fahr = fahr +20){ */
        /* printf("%3d %6.1f\n",fahr,(5.0/9.0)*(fahr-32)); */
    /* } */

    /* check the input */
    /* int c; */
    /* while( (c = getchar()) != EOF ) */
        /* putchar(c); */

    /* check the input ,using the for */
    /* double nc; */
    /* for (nc = 0;getchar() != EOF ;++nc) */
        /* ; */
    /* printf("%.0f\n", nc); */
    /* int k = 0; */
    /* int s = 0; */
    /* while(k <= 3){ */
        /* printf("before\t%d\t%d",k,s); */
        /* printf("\n"); */
        /* [> s = s+k; <] */
        /* k++; */
        /* s = s+k; */
        /* printf("after\t%d\t%d",k,s); */
        /* printf("\n"); */

    /* } */

    int x, y ,z ;
    x=0 ; y = 2; z = 3;
    switch(x)
    {
        case 0 : switch(y == 2)
                 {
                     case 1 : ( printf ("*") );break;
                     case 2 : ( printf ("x") );break;

                 }
        case 1 : switch(z)
                 {
                     case 1 : ( printf ("$" ));break;
                     case 2 : ( printf ("*" ));break;
                     default: printf("#");

                 }
    }
}


