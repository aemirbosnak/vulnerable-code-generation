//GEMINI-pro DATASET v1.0 Category: Spell checking ; Style: active
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct node {
    char *word;
    struct node *next;
} node_t;

node_t *head = NULL;
node_t *tail = NULL;

void insert_word(char *word) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->word = strdup(word);
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
}

bool check_word(char *word) {
    node_t *current = head;

    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return true;
        }

        current = current->next;
    }

    return false;
}

void load_dictionary(char *filename) {
    FILE *fp = fopen(filename, "r");
    char line[256];

    while (fgets(line, sizeof(line), fp)) {
        char *word = strtok(line, "\n");
        insert_word(word);
    }

    fclose(fp);
}

void check_text(char *filename) {
    FILE *fp = fopen(filename, "r");
    char line[256];
    int line_number = 1;

    while (fgets(line, sizeof(line), fp)) {
        char *word = strtok(line, " ");

        while (word != NULL) {
            word = strtok(NULL, " ");

            if (word != NULL) {
                int word_length = strlen(word);
                char lower_word[word_length + 1];

                for (int i = 0; i < word_length; i++) {
                    lower_word[i] = tolower(word[i]);
                }

                lower_word[word_length] = '\0';

                if (!check_word(lower_word)) {
                    printf("Misspelled word: %s on line %d\n", word, line_number);
                }
            }
        }

        line_number++;
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dictionary> <text>\n", argv[0]);
        return 1;
    }

    load_dictionary(argv[1]);
    check_text(argv[2]);

    return 0;
}