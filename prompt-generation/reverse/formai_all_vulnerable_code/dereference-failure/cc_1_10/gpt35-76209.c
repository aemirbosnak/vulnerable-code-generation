//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: scientific
/* 
* C User Input Sanitizer Example 
* This program validates and sanitizes user input and can be used to prevent security breaches and errors.
*
* Author: John Doe
* Date: 2021-08-31
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function prototype declaration */
char* sanitizeInput(char* input, int size);

/* Main function */
int main()
{
    char input[256];
    printf("Enter a string of characters: ");
    fgets(input,255,stdin); //This is used to get input from user
    
    printf("Sanitized input: %s\n", sanitizeInput(input, strlen(input)));
    return 0;
}

/* Sanitizing function to restrict unwanted characters */
char* sanitizeInput(char* input, int size){

    char* result = malloc(size+1); //since size could be upto 256 and we are setting the limit of 255 characters

    int j = 0; //counter variable 
    int i = 0;

    while(input[i]!='\0' && j < size){  //checking through each character of string to find unwanted characters
        
        /* ASCII value checking */
        if(input[i]>=65 && input[i]<=90){ //checking for UPPERCASE alphabets
            result[j] = input[i];
            j++;
        }
        else if(input[i]>=97 && input[i]<=122){ //checking for LOWERCASE alphabets
            result[j] = input[i];
            j++;
        }
        else if(input[i]>=48 && input[i]<=57){ //checking for NUMBERS
            result[j] = input[i];
            j++;
        }
        else if(input[i]==' '){ //checking for SPACE
          result[j] = input[i];
          j++;  
        }
        i++;
    }

    result[j]='\0'; //Terminating string once found all unwanted characters 
    return result;
}