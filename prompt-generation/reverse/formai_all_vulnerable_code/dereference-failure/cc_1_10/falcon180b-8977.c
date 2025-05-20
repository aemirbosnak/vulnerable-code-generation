//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80

void print_art(char *text) {
    int len = strlen(text);
    int i, j;

    for (i = 0; i < len; i++) {
        if (text[i] == '\n') {
            printf("\n");
            continue;
        }

        if (isalpha(text[i])) {
            printf("%c", text[i]);
        } else {
            printf(" ");
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    char *text = argv[1];
    int len = strlen(text);
    int width = 0;

    for (int i = 0; i < len; i++) {
        if (isalpha(text[i])) {
            width++;
        } else if (text[i] == '\n') {
            printf("\n");
            width = 0;
        }
    }

    if (width > 0) {
        printf("\n");
    }

    return 0;
}