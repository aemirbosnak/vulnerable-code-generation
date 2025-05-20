//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *text;
    int length;
} Text;

void initialize(Text *text) {
    text->text = NULL;
    text->length = 0;
}

void destroy(Text *text) {
    free(text->text);
    text->text = NULL;
    text->length = 0;
}

void append(Text *text, char *str) {
    int len = strlen(str);
    char *new_text = realloc(text->text, text->length + len + 1);
    if (new_text == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    text->text = new_text;
    strcat(text->text, str);
    text->length += len;
}

void print_text(Text *text) {
    printf("%s\n", text->text);
}

int main() {
    Text input_text;
    initialize(&input_text);
    char ch;
    while ((ch = getchar())!= EOF) {
        if (isalpha(ch)) {
            char word[100];
            int i = 0;
            while (isalpha(ch)) {
                word[i++] = tolower(ch);
                ch = getchar();
            }
            word[i] = '\0';
            append(&input_text, word);
        }
    }
    destroy(&input_text);
    return 0;
}