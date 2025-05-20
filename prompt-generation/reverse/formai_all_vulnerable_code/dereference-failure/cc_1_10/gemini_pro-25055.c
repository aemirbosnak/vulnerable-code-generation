//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A node in a linked list
struct node {
    char *word;
    int count;
    struct node *next;
};

// A linked list of nodes
struct list {
    struct node *head;
    struct node *tail;
};

// Create a new node
struct node *new_node(char *word) {
    struct node *node = malloc(sizeof(struct node));
    if (node == NULL) {
        return NULL;
    }
    node->word = strdup(word);
    node->count = 1;
    node->next = NULL;
    return node;
}

// Insert a node into a list
void insert_node(struct list *list, struct node *node) {
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
}

// Find a node in a list
struct node *find_node(struct list *list, char *word) {
    struct node *node = list->head;
    while (node != NULL) {
        if (strcmp(node->word, word) == 0) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

// Count the number of occurrences of a word in a list
int count_word(struct list *list, char *word) {
    struct node *node = find_node(list, word);
    if (node == NULL) {
        return 0;
    } else {
        return node->count;
    }
}

// Print the contents of a list
void print_list(struct list *list) {
    struct node *node = list->head;
    while (node != NULL) {
        printf("%s: %d\n", node->word, node->count);
        node = node->next;
    }
}

// Free the memory allocated to a list
void free_list(struct list *list) {
    struct node *node = list->head;
    while (node != NULL) {
        struct node *next = node->next;
        free(node->word);
        free(node);
        node = next;
    }
}

// Count the number of occurrences of each word in a file
struct list *count_words(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    struct list *list = malloc(sizeof(struct list));
    if (list == NULL) {
        fclose(file);
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;

    char word[1024];
    while (fscanf(file, "%s", word) != EOF) {
        struct node *node = find_node(list, word);
        if (node == NULL) {
            node = new_node(word);
            if (node == NULL) {
                fclose(file);
                free_list(list);
                return NULL;
            }
            insert_node(list, node);
        } else {
            node->count++;
        }
    }

    fclose(file);
    return list;
}

// Print the words in a list in order of decreasing frequency
void print_words(struct list *list) {
    struct node *node = list->head;
    while (node != NULL) {
        printf("%s: %d\n", node->word, node->count);
        node = node->next;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct list *list = count_words(argv[1]);
    if (list == NULL) {
        printf("Error: could not count words in file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    print_words(list);
    free_list(list);
    return EXIT_SUCCESS;
}