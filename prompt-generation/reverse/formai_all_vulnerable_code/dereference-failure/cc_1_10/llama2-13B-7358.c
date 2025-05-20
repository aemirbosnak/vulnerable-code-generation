//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: brave
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STR_LEN 1024
#define MAX_ARRAY_SIZE 64

// Brave-style string manipulation functions

// Function to reverse a string
void reverse_str(char *str) {
    int i, j;
    char temp;

    for (i = 0; i < strlen(str); i++) {
        j = strlen(str) - i - 1;
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to capitalize the first letter of a string
char *capitalize_first(char *str) {
    if (*str == '\0') {
        return str;
    }

    *str = toupper(*str);
    return str + 1;
}

// Function to remove duplicates from a string
char *remove_dupes(char *str) {
    char *ptr = str;
    char *prev = NULL;

    while (*ptr != '\0') {
        if (prev == NULL || strcmp(prev, ptr) != 0) {
            if (prev != NULL) {
                *prev = '\0';
            }
            prev = ptr;
            ptr += strcspn(ptr, "\n\t ");
        }
    }

    return prev;
}

// Function to print a string in a brave style
void print_brave(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\t') {
            print_brave(str + i);
        } else {
            printf("%c", str[i]);
        }
    }
}

int main() {
    char str[MAX_STR_LEN];
    gets(str);

    // Reverse the string
    reverse_str(str);

    // Capitalize the first letter
    char *cap_str = capitalize_first(str);

    // Remove duplicates
    char *removed_str = remove_dupes(cap_str);

    // Print the string in a brave style
    print_brave(removed_str);

    return 0;
}