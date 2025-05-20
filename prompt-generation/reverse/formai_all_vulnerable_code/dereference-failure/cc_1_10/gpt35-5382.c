//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* function to convert decimal to hexadecimal */
char* decimalToHexadecimal(long int decimal)
{
    char* hex = (char*)malloc(100*sizeof(char));
    long int remainder, quotient;
    int i=1, j;
    
    quotient = decimal;
    
    while(quotient != 0){
        remainder = quotient % 16;
        if(remainder < 10)
            hex[i++] = 48 + remainder;
        else
            hex[i++] = 55 + remainder;
        quotient = quotient / 16;
    }
    
    /*return 0 if input is zero*/
    if(i==1)
        hex[i++]='0';
    
    hex[0]='0';
    hex[i]='x';
    hex[i+1]='\0';
    
    /*reverse the result*/
    for(j=1; j<=i-1; j++){
        char temp = hex[j];
        hex[j] = hex[i-j];
        hex[i-j] = temp;
    }
    
    return hex;
}

int main()
{
    long int num;
    char *hex;
    
    printf("Enter a decimal number: ");
    scanf("%ld", &num);
    
    hex = decimalToHexadecimal(num);
    
    printf("Hexadecimal number is: %s", hex);
    
    free(hex);
    
    return 0;
}