//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ROW 80
#define MAX_COL 40

typedef struct {
    char *text;
    char *art;
} TextArt;

void generate_art(char *text, char *art) {
    int i, j, k;
    char ch;

    for (i = 0; i < strlen(text); i++) {
        ch = tolower(text[i]);
        if (ch >= 'a' && ch <= 'z') {
            art[i] = ch;
        } else if (ch >= 'A' && ch <= 'Z') {
            art[i] = ch + 32;
        } else if (ch >= '0' && ch <= '9') {
            art[i] = ch;
        } else {
            art[i] = '.';
        }
    }
}

void print_art(char *art) {
    int i;

    for (i = 0; i < strlen(art); i++) {
        printf("%c", art[i]);
    }
}

int main() {
    char text[MAX_ROW * MAX_COL];
    TextArt art;
    int i, j, k;
    char ch;

    printf("Enter your text (maximum %d characters):\n", MAX_ROW * MAX_COL);
    fgets(text, MAX_ROW * MAX_COL, stdin);

    art.text = text;
    art.art = malloc(MAX_ROW * MAX_COL);

    generate_art(art.text, art.art);

    printf("\nYour ASCII art:\n");
    for (i = 0; i < strlen(art.art); i++) {
        if (i % MAX_COL == 0) {
            printf("\n");
        }
        printf("%c", art.art[i]);
    }

    free(art.art);

    return 0;
}