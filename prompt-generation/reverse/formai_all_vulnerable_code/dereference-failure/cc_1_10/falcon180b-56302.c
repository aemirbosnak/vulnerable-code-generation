//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100

/* Function to reverse a string */
void reverse(char* str) {
    int len = strlen(str);
    char* new_str = (char*) malloc(sizeof(char) * len);
    int i = 0;
    for(int j = len - 1; j >= 0; j--) {
        new_str[i++] = str[j];
    }
    strcpy(str, new_str);
    free(new_str);
}

/* Function to convert a string to uppercase */
void to_upper(char* str) {
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        str[i] = toupper(str[i]);
    }
}

/* Function to convert a string to lowercase */
void to_lower(char* str) {
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        str[i] = tolower(str[i]);
    }
}

/* Function to check if a string is a palindrome */
int is_palindrome(char* str) {
    int len = strlen(str);
    for(int i = 0; i < len / 2; i++) {
        if(str[i]!= str[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[MAX_STR_LEN];

    /* Prompt user for input */
    printf("Enter a string: ");
    fgets(str, MAX_STR_LEN, stdin);

    /* Remove newline character */
    str[strcspn(str, "\n")] = '\0';

    /* Reverse the string */
    reverse(str);

    /* Convert to uppercase */
    to_upper(str);

    /* Convert to lowercase */
    to_lower(str);

    /* Check if the string is a palindrome */
    if(is_palindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}