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
    int fahr;
    
    //say hello,siko!
    printf("Hi Siko\n");

    //check the format
    for(fahr = 0 ;fahr <= 300;fahr = fahr +20){
        printf("%3d %6.1f\n",fahr,(5.0/9.0)*(fahr-32));
    }

    //check the input
    int c;
    while( (c = getchar()) != EOF )
        putchar(c);

}


