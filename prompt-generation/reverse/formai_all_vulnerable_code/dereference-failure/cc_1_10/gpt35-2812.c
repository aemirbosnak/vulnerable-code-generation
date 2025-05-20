//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//function to check if character is alphanumeric
int isAlnum(char c){
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
        return 1;
    }
    else{
        return 0;
    }
}

//function to sanitize URL
char* sanitizeURL(char* url){
    int i, j = 0;
    char* sanitizedURL = (char*)malloc(strlen(url)*sizeof(char)+1);
    for (i = 0; url[i] != '\0'; i++){
        //if character is alphanumeric, copy it to sanitizedURL
        if (isAlnum(url[i])){
            sanitizedURL[j] = url[i];
            j++;
        }
        //if character is a space, replace it with a dash in sanitizedURL
        else if (url[i] == ' '){
            sanitizedURL[j] = '-';
            j++;
        }
        //if character is not alphanumeric, skip it
        else{
            continue;
        }
    }
    //add null character to end of string
    sanitizedURL[j] = '\0';
    return sanitizedURL;
}

int main(){
    //test input URL
    char url[] = "https://www.example.com/path/?param1=value1&param2=value+2";
    //sanitize input URL
    char* sanitizedURL = sanitizeURL(url);
    //print sanitized URL
    printf("Input URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitizedURL);
    //free memory allocated for sanitized URL
    free(sanitizedURL);
    return 0;
}