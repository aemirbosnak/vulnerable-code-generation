//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void sanitizeInput(char s[], int len){

    //Remove leading whitespaces
    int i = 0;
    while(s[i] == ' '){
        i++;
    }

    //Remove trailing whitespaces
    int j = len - 1;
    while(s[j] == ' '){
        j--;
    }

    //Move the effective string's starting position to i
    memmove(s, &s[i], j - i + 1);

    //Remove any duplicate whitespaces in between
    len = j - i + 1;
    for(i = 0; i < len; i++){
        if(s[i] == ' ' && s[i+1] == ' '){
            memmove(&s[i], &s[i+1], len - i);
            len--;
            i--;
        }
    }

    //Capitalize the first letter
    s[0] = toupper(s[0]);

    //Print the sanitized input
    printf("Sanitized Input: %s\n", s);
}

int main(){

    //Get the user input
    char input[100];
    printf("Enter User Input: ");
    fgets(input, 100, stdin);

    //Calculate length of input
    int len = strlen(input);

    //Sanitize the input
    sanitizeInput(input, len);

    return 0;
}