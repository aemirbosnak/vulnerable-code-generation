//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: interoperable
/*
This program demonstrates the use of performance-critical component in C programming language.
The program receives an input string from the user and performs some string manipulation operations. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 10000

// function prototypes
size_t string_length(const char* str);
char* reverse_string(char* str);
char* concatenate_strings(const char* str1, const char* str2);

int main(){

    char input_str[MAX_STR_LEN];

    printf("Enter a string to perform some operations: ");
    fgets(input_str, MAX_STR_LEN, stdin);

    // remove newline character from the input string
    input_str[strcspn(input_str, "\n")] = 0;

    // calculate the length of the input string
    size_t str_len = string_length(input_str);

    // reverse the input string
    char* reversed_str = reverse_string(input_str);
    printf("Reversed string: %s\n", reversed_str);

    // concatenate the input string with its reversed string
    char* concatenated_str = concatenate_strings(input_str, reversed_str);
    printf("Concatenated string: %s\n", concatenated_str);

    // free dynamically allocated memory
    free(reversed_str);
    free(concatenated_str);

    return 0;
}

// function to calculate the length of a string
size_t string_length(const char* str){
    return strlen(str);
}

// function to reverse a string
char* reverse_string(char* str){
    size_t str_len = string_length(str);
    char* reversed_str = (char*)malloc((str_len+1) * sizeof(char));
    for(int i=0; i<str_len; i++){
        reversed_str[i] = str[str_len-i-1];
    }
    reversed_str[str_len] = '\0';
    return reversed_str;
}

// function to concatenate two strings
char* concatenate_strings(const char* str1, const char* str2){
    size_t str1_len = string_length(str1);
    size_t str2_len = string_length(str2);
    char* concatenated_str = (char*)malloc((str1_len+str2_len+1) * sizeof(char));
    for(int i=0; i<str1_len; i++){
        concatenated_str[i] = str1[i];
    }
    for(int i=0; i<str2_len; i++){
        concatenated_str[str1_len+i] = str2[i];
    }
    concatenated_str[str1_len+str2_len] = '\0';
    return concatenated_str;
}