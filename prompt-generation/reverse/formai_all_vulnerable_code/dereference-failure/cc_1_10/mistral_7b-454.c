//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Word {
    char *word;
    size_t length;
    struct Word *next;
} Word;

Word *create_new_word(const char *word) {
    Word *new_word = (Word *) malloc(sizeof(Word));

    new_word->word = strdup(word);
    new_word->length = strlen(word);
    new_word->next = NULL;

    return new_word;
}

void add_word(Word **head, Word *new_word) {
    if (*head == NULL) {
        *head = new_word;
    } else {
        Word *current = *head;

        while (current->next != NULL) {
            if (strcmp(current->word, new_word->word) == 0) {
                free(new_word->word);
                free(new_word);
                return;
            }
            current = current->next;
        }

        current->next = new_word;
    }
}

bool is_valid_word(const char *word, size_t length) {
    if (length > 0 && length < 50) {
        for (size_t i = 0; i < length; ++i) {
            if (!isalpha(word[i]) && word[i] != '\'' && word[i] != '\'' && word[i] != '-') {
                return false;
            }
        }

        return true;
    }

    return false;
}

void count_words(const char *text, Word **head) {
    char *token = strtok(strdup(text), " \t\n.,;:!?()[]{}");

    while (token != NULL) {
        if (is_valid_word(token, strlen(token))) {
            Word *new_word = create_new_word(token);
            add_word(head, new_word);
        }

        token = strtok(NULL, " \t\n.,;:!?()[]{}");
    }

    free(strdup(text));
}

void print_word_count(Word *head) {
    Word *current = head;

    while (current != NULL) {
        printf("%s: %zu\n", current->word, current->length);
        current = current->next;
    }
}

int main() {
    Word *words_list = NULL;
    char text[1024];

    printf("Enter the text to count words:\n");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    count_words(text, &words_list);
    print_word_count(words_list);

    Word *current = words_list;
    while (current != NULL) {
        Word *temp = current;
        current = current->next;
        free(temp->word);
        free(temp);
    }

    return 0;
}