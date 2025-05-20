//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: retro
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>

#define MAX_LEN 1024

// Function to reverse a string
void reverse_str(char *str) {
    int i, j;
    char temp;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to print a string in reverse
void print_reverse(char *str) {
    int i, j;

    for (i = strlen(str) - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
}

// Function to swap two strings
void swap_strings(char *str1, char *str2) {
    char temp[MAX_LEN];

    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}

int main() {
    char str1[] = "Hello World!";
    char str2[] = "Cool Beans!";

    // Reverse the first string
    reverse_str(str1);

    // Print the first string in reverse
    print_reverse(str1);

    // Swap the first and second strings
    swap_strings(str1, str2);

    // Print the second string
    printf("%s\n", str2);

    return 0;
}