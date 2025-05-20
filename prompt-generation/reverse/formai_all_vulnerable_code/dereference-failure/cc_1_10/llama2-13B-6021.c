//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: retro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEN 100

// Function to reverse a string
void reverse_string(char *str) {
    int i, j;
    char temp;

    for (i = 0; i < strlen(str); i++) {
        temp = str[i];
        str[i] = str[strlen(str) - i - 1];
        str[strlen(str) - i - 1] = temp;
    }
}

// Function to generate a random string
char *generate_random_string(int len) {
    char *str = malloc(len * sizeof(char));
    int i;

    for (i = 0; i < len; i++) {
        str[i] = 'a' + (rand() % 26);
    }

    return str;
}

int main() {
    char *str1 = generate_random_string(MAX_LEN);
    char *str2 = generate_random_string(MAX_LEN);

    // Swap the strings
    reverse_string(str1);
    reverse_string(str2);

    // Print the swapped strings
    printf("Original strings:\n");
    printf("%s\n", str1);
    printf("%s\n", str2);

    // Swap the strings again
    reverse_string(str1);
    reverse_string(str2);

    // Print the final swapped strings
    printf("Final strings:\n");
    printf("%s\n", str1);
    printf("%s\n", str2);

    free(str1);
    free(str2);

    return 0;
}