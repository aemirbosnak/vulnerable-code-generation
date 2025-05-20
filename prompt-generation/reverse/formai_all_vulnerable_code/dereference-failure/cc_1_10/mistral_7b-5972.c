//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LEN 256
#define NUM_ELEMENTS 10

typedef struct {
    char str[MAX_LEN];
    int count;
} Element;

void process_text(char text[]) {
    Element elements[NUM_ELEMENTS];
    int i = 0, j = 0;
    char current_str[MAX_LEN];

    memset(elements, 0, sizeof(elements));

    for (i = 0; text[i] != '\0'; i++) {
        if (isalnum(text[i])) {
            current_str[j++] = tolower(text[i]);
        } else if (j > 0) {
            elements[i / NUM_ELEMENTS].str[elements[i / NUM_ELEMENTS].count++] = current_str[0];
            current_str[0] = '\0';
            j = 0;
        }
    }

    if (j > 0) {
        elements[i / NUM_ELEMENTS].str[elements[i / NUM_ELEMENTS].count++] = current_str[0];
        elements[i / NUM_ELEMENTS].count++;
    }

    printf("Unique words:\n");

    for (i = 0; i < NUM_ELEMENTS; i++) {
        if (elements[i].count > 0) {
            printf("%s: %d\n", elements[i].str, elements[i].count);
        }
    }
}

int main(int argc, char *argv[]) {
    srand(time(NULL));

    if (argc < 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    char text[MAX_LEN] = {0};
    strncat(text, argv[1], MAX_LEN - 1);

    process_text(text);

    return 0;
}