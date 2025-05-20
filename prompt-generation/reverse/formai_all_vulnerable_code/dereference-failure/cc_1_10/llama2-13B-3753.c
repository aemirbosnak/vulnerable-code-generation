//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRLEN 50

void randomize_string(char *str) {
    size_t len = strlen(str);
    for (size_t i = 0; i < len; i++) {
        str[i] = 'a' + (rand() % 26);
    }
}

int main() {
    char str[MAX_STRLEN];
    randomize_string(str);
    printf("Original string: %s\n", str);

    // Shuffle the string
    for (size_t i = 0; i < MAX_STRLEN; i++) {
        size_t j = rand() % MAX_STRLEN;
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    printf("Shuffled string: %s\n", str);

    // Reverse the string
    for (size_t i = 0; i < MAX_STRLEN / 2; i++) {
        char temp = str[i];
        str[i] = str[MAX_STRLEN - i - 1];
        str[MAX_STRLEN - i - 1] = temp;
    }

    printf("Reversed string: %s\n", str);

    // Remove duplicates
    for (size_t i = 0; i < MAX_STRLEN; i++) {
        for (size_t j = i + 1; j < MAX_STRLEN; j++) {
            if (str[i] == str[j]) {
                str[j] = '\0';
            }
        }
    }

    printf("String without duplicates: %s\n", str);

    return 0;
}