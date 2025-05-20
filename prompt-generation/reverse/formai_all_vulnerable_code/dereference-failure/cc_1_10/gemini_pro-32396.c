//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct word_node {
    char *word;
    int count;
    struct word_node *next;
} word_node_t;

typedef struct word_list {
    word_node_t *head;
    word_node_t *tail;
} word_list_t;

word_list_t *create_word_list() {
    word_list_t *list = malloc(sizeof(word_list_t));
    if (list == NULL) {
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void destroy_word_list(word_list_t *list) {
    if (list == NULL) {
        return;
    }
    word_node_t *node = list->head;
    while (node != NULL) {
        word_node_t *next = node->next;
        free(node->word);
        free(node);
        node = next;
    }
    free(list);
}

word_node_t *create_word_node(char *word) {
    word_node_t *node = malloc(sizeof(word_node_t));
    if (node == NULL) {
        return NULL;
    }
    node->word = strdup(word);
    if (node->word == NULL) {
        free(node);
        return NULL;
    }
    node->count = 1;
    node->next = NULL;
    return node;
}

void destroy_word_node(word_node_t *node) {
    if (node == NULL) {
        return;
    }
    free(node->word);
    free(node);
}

int add_word_to_list(word_list_t *list, char *word) {
    if (list == NULL || word == NULL) {
        return -1;
    }
    word_node_t *node = list->head;
    while (node != NULL) {
        if (strcmp(node->word, word) == 0) {
            node->count++;
            return 0;
        }
        node = node->next;
    }
    node = create_word_node(word);
    if (node == NULL) {
        return -1;
    }
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
    return 0;
}

int print_word_list(word_list_t *list) {
    if (list == NULL) {
        return -1;
    }
    word_node_t *node = list->head;
    while (node != NULL) {
        printf("%s: %d\n", node->word, node->count);
        node = node->next;
    }
    return 0;
}

int main() {
    word_list_t *list = create_word_list();
    if (list == NULL) {
        return EXIT_FAILURE;
    }
    char *text = "The quick brown fox jumps over the lazy dog";
    char *token = strtok(text, " ");
    while (token != NULL) {
        int result = add_word_to_list(list, token);
        if (result != 0) {
            destroy_word_list(list);
            return EXIT_FAILURE;
        }
        token = strtok(NULL, " ");
    }
    int result = print_word_list(list);
    if (result != 0) {
        destroy_word_list(list);
        return EXIT_FAILURE;
    }
    destroy_word_list(list);
    return EXIT_SUCCESS;
}