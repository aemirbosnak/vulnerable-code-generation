//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_SIZE 50

typedef struct Word {
    char str[WORD_SIZE];
    int length;
    struct Word *next;
} Word;

int main() {
    FILE *file;
    Word *word_list = NULL;
    int num_words = 0, i;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fscanf(file, "%s%*c", word_list) != EOF) {
        int len = strlen(word_list->str);
        word_list->length = len;

        for (Word *p = word_list; p != NULL; p = p->next) {
            if (p->next != NULL && strcmp(p->str, p->next->str) == 0) {
                free(p->next);
                p->next = p->next->next;
                num_words--;
                break;
            }
        }

        num_words++;
    }

    fclose(file);

    printf("Total number of unique words: %d\n", num_words);
    printf("Average word length: %.2f\n", (float)total_length(word_list) / num_words);

    for (Word *p = word_list; p != NULL; p = p->next) {
        printf("%s ", p->str);
        free(p);
    }

    free(word_list);

    return 0;
}

Word *create_word(char *str) {
    Word *new_word = (Word *)malloc(sizeof(Word));
    strcpy(new_word->str, str);
    new_word->next = NULL;
    return new_word;
}

void free_list(Word *head) {
    Word *current = head;
    Word *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int total_length(Word *head) {
    int sum = 0;
    Word *current = head;

    while (current != NULL) {
        sum += current->length;
        current = current->next;
    }

    return sum;
}