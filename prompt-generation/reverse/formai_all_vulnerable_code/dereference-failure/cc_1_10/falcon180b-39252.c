//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64

typedef struct {
    char *text;
    int length;
} Text;

typedef struct {
    int index;
    int length;
} Word;

typedef struct {
    Word *words;
    int count;
} WordList;

void read_text(FILE *file, Text *text) {
    char ch;
    int length = 0;
    text->text = malloc(MAX_LINE_LENGTH);
    if (text->text == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    while ((ch = fgetc(file))!= EOF) {
        if (isspace(ch)) {
            length = 0;
        } else if (length < MAX_LINE_LENGTH - 1) {
            text->text[length++] = ch;
        } else {
            printf("Error: Line too long.\n");
            exit(1);
        }
    }
    text->length = length;
    text->text[length] = '\0';
}

void tokenize(char *text, WordList *word_list) {
    char *ptr = text;
    Word *word = word_list->words;
    int count = 0;
    while (*ptr!= '\0') {
        if (isspace(*ptr)) {
            *ptr = '\0';
            if (count < word_list->count) {
                word->index = count;
                word->length = strlen(ptr);
                word++;
                count++;
            }
            ptr++;
        } else {
            ptr++;
        }
    }
    word->index = count;
    word->length = strlen(ptr);
    word++;
    word_list->count = count + 1;
}

void print_word_list(WordList *word_list) {
    Word *word = word_list->words;
    for (int i = 0; i < word_list->count; i++, word++) {
        printf("%d: %.*s\n", i + 1, word->length, word->index >= 0? word->index : "");
    }
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }
    Text text;
    read_text(file, &text);
    WordList word_list;
    word_list.words = malloc(text.length * sizeof(Word));
    if (word_list.words == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }
    word_list.count = 0;
    tokenize(text.text, &word_list);
    print_word_list(&word_list);
    free(text.text);
    free(word_list.words);
    fclose(file);
    return 0;
}