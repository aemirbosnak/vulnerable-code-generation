//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *word;
    int count;
    struct node *next;
} node;

typedef struct word_count_tool {
    node *head;
} word_count_tool;

word_count_tool *create_word_count_tool() {
    word_count_tool *tool = malloc(sizeof(word_count_tool));
    tool->head = NULL;
    return tool;
}

void add_word(word_count_tool *tool, char *word) {
    node *new_node = malloc(sizeof(node));
    new_node->word = strdup(word);
    new_node->count = 1;
    new_node->next = tool->head;
    tool->head = new_node;
}

int get_count(word_count_tool *tool, char *word) {
    node *current = tool->head;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            return current->count;
        }
        current = current->next;
    }
    return 0;
}

void increment_count(word_count_tool *tool, char *word) {
    node *current = tool->head;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            current->count++;
            return;
        }
        current = current->next;
    }
    add_word(tool, word);
}

void print_words(word_count_tool *tool) {
    node *current = tool->head;
    while (current != NULL) {
        printf("%s: %d\n", current->word, current->count);
        current = current->next;
    }
}

void destroy_word_count_tool(word_count_tool *tool) {
    node *current = tool->head;
    while (current != NULL) {
        node *next = current->next;
        free(current->word);
        free(current);
        current = next;
    }
    free(tool);
}

int main() {
    word_count_tool *tool = create_word_count_tool();
    char *words[] = {"hello", "world", "this", "is", "a", "test"};
    for (int i = 0; i < 6; i++) {
        increment_count(tool, words[i]);
    }
    print_words(tool);
    destroy_word_count_tool(tool);
    return 0;
}