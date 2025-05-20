//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STR_LEN 1024

void reverse_string(char *str) {
    int i, j, len = strlen(str);
    char temp[len];

    for (i = 0; i < len; i++) {
        temp[i] = str[len - i - 1];
    }
    strcpy(str, temp);
}

void rotate_string(char *str, int num_rotations) {
    int i, j, len = strlen(str);
    char temp[len];

    for (i = 0; i < num_rotations; i++) {
        for (j = 0; j < len; j++) {
            temp[j] = str[j + i];
        }
        strcpy(str, temp);
    }
}

void shuffle_string(char *str) {
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
    char str[MAX_STR_LEN];
    printf("Enter a string: ");
    fgets(str, MAX_STR_LEN, stdin);

    printf("Original string: %s\n", str);

    reverse_string(str);
    printf("Reversed string: %s\n", str);

    rotate_string(str, 3);
    printf("Rotated string: %s\n", str);

    shuffle_string(str);
    printf("Shuffled string: %s\n", str);

    return 0;
}