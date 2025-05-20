//FormAI DATASET v1.0 Category: String manipulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function to reverse a string
void reverse_string(char* str) {
    int len = strlen(str);
    int i = 0;
    int j = len-1;
    while (i<j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

//function to capitalize the first letter of each word in a string
void capitalize(char* str) {
    int len = strlen(str);
    str[0] = toupper(str[0]);
    for (int i=1; i<len; i++) {
        if (str[i] == ' ') {
            str[i+1] = toupper(str[i+1]);
        }
    }
}

//function to convert a string to camel case
void to_camel_case(char* str) {
    capitalize(str);
    int len = strlen(str);
    for (int i=0; i<len; i++) {
        if (str[i] == ' ') {
            strcpy(&str[i], &str[i+1]);
            len--;
            str[i] = toupper(str[i]);
        }
    }    
}

int main() {
    char* str = "this is a sample string.";
    printf("Original string: %s\n", str);

    reverse_string(str);
    printf("Reversed string: %s\n", str);

    capitalize(str);
    printf("Capitalized string: %s\n", str);

    to_camel_case(str);
    printf("Camel case string: %s\n", str);

    return 0;
}