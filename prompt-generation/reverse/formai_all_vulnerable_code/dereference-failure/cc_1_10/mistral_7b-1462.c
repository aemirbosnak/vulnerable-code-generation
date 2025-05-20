//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_SIZE 50

typedef struct Word {
    char str[WORD_SIZE];
    struct Word *next;
} Word;

Word *head = NULL;

int is_unique(char *str, Word *list) {
    Word *current = list;
    while (current != NULL) {
        if (strcmp(current->str, str) == 0)
            return 0;
        current = current->next;
    }
    return 1;
}

void add_word(char *str) {
    Word *new_word = (Word *)malloc(sizeof(Word));
    strcpy(new_word->str, str);
    new_word->next = head;
    head = new_word;
}

int main(int argc, char *argv[]) {
    FILE *file;
    char filename[100], line[1024], word[WORD_SIZE];
    int line_num = 1;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    strcpy(filename, argv[1]);
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        char *token = strtok(line, " \t\n\r.,;:!?");
        while (token != NULL) {
            for (int i = 0; token[i] != '\0'; i++) {
                token[i] = tolower(token[i]);
            }
            if (is_unique(token, head)) {
                add_word(token);
            }
            token = strtok(NULL, " \t\n\r.,;:!?");
        }
        line_num++;
    }

    fclose(file);

    Word *current = head;
    printf("\nUnique words in %s:\n", filename);
    while (current != NULL) {
        printf("%s\n", current->str);
        current = current->next;
    }

    while (head != NULL) {
        Word *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}