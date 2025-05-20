//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STR_LEN 100
#define MAX_REPEAT 5

// Function to reverse a string
void reverse_str(char *str) {
    int i, j, len = strlen(str);
    char temp[len];

    for (i = 0; i < len; i++) {
        temp[i] = str[len - i - 1];
    }

    strcpy(str, temp);
}

// Function to repeat a string
void repeat_str(char *str, int times) {
    int i, len = strlen(str);
    char repeated_str[len * times];

    for (i = 0; i < times; i++) {
        strcpy(repeated_str + i * len, str);
    }

    strcpy(str, repeated_str);
}

// Function to shuffle a string
void shuffle_str(char *str) {
    int i, j, len = strlen(str);
    char temp[len];

    for (i = 0; i < len; i++) {
        j = rand() % len;
        temp[i] = str[j];
        str[j] = str[i];
    }

    strcpy(str, temp);
}

int main() {
    char str[] = "Hello, world!";
    int repeat = 3;
    int shuffle = 5;

    // Reverse the string
    reverse_str(str);
    printf("Reversed string: %s\n", str);

    // Repeat the string
    repeat_str(str, repeat);
    printf("Repeated string: %s\n", str);

    // Shuffle the string
    shuffle_str(str);
    printf("Shuffled string: %s\n", str);

    return 0;
}