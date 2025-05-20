//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 80
#define MAX_TEXT_LENGTH 2000

typedef struct {
    char *text;
    int length;
} Text;

void init_text(Text *t) {
    t->text = (char *)malloc(MAX_TEXT_LENGTH * sizeof(char));
    t->length = 0;
}

void append_char(Text *t, char c) {
    if (t->length >= MAX_TEXT_LENGTH - 1) {
        printf("Error: Text too long.\n");
        exit(1);
    }
    t->text[t->length++] = c;
}

void append_string(Text *t, char *s) {
    int i;
    for (i = 0; i < strlen(s); i++) {
        append_char(t, s[i]);
    }
}

void print_text(Text *t) {
    printf("%s", t->text);
}

void free_text(Text *t) {
    free(t->text);
}

void generate_ascii_art(Text *t, int width) {
    int i, j;
    for (i = 0; i < t->length; i++) {
        char c = t->text[i];
        if (isalpha(c)) {
            c = tolower(c);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                printf("*");
            } else {
                printf("-");
            }
        } else {
            printf(" ");
        }
        if ((i + 1) % width == 0) {
            printf("\n");
        }
    }
}

int main() {
    Text text;
    init_text(&text);

    printf("Enter some text:\n");
    fgets(text.text, MAX_TEXT_LENGTH, stdin);

    int width = 0;
    while (width < MAX_LINE_LENGTH) {
        int i;
        for (i = 0; i < strlen(text.text); i++) {
            if (text.text[i] == '\n') {
                width = i;
                break;
            }
        }
        if (i == strlen(text.text)) {
            width = MAX_LINE_LENGTH;
        }
    }

    printf("ASCII art:\n");
    generate_ascii_art(&text, width);

    free_text(&text);

    return 0;
}