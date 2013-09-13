/*
 * =====================================================================================
 *
 *       Filename:  strchr.c
 *
 *    Description:  all string's function.
 *
 *        Version:  1.0
 *        Created:  09/13/2013 09:52:54 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Siko Chen (SC), sikocb@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <string.h>

int main(){
    char string[15];
    char *ptr, c = 'r';
    strcpy(string, "This is a string");
    ptr = strrchr(string, c);

    if (ptr)
        printf("The character %c is at position: %d\n", c, ptr-string);
    else
        printf("The character was not found\n");
    return 0;

}

