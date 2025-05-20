//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char *word;
    int count;
    struct node *next;
};

struct node *head = NULL;

void add_word(char *word) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->word = strdup(word);
    new_node->count = 1;
    new_node->next = head;
    head = new_node;
}

void print_word_counts() {
    struct node *current = head;
    while (current != NULL) {
        printf("%s: %d\n", current->word, current->count);
        current = current->next;
    }
}

int main() {
    char *filename = "input.txt";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        char *word = strtok(buffer, " ");
        while (word != NULL) {
            add_word(word);
            word = strtok(NULL, " ");
        }
    }

    fclose(file);

    print_word_counts();

    return 0;
}