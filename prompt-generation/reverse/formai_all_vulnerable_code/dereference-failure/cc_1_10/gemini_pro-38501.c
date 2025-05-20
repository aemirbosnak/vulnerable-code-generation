//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *data;
    struct node *next;
} node_t;

typedef struct string {
    node_t *head;
    node_t *tail;
    size_t length;
} string_t;

string_t *string_new() {
    string_t *string = malloc(sizeof(string_t));
    string->head = NULL;
    string->tail = NULL;
    string->length = 0;
    return string;
}

void string_free(string_t *string) {
    node_t *current = string->head;
    while (current != NULL) {
        node_t *next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    free(string);
}

char *string_to_char_array(string_t *string) {
    char *array = malloc(string->length + 1);
    node_t *current = string->head;
    size_t index = 0;
    while (current != NULL) {
        strcpy(array + index, current->data);
        index += strlen(current->data);
        current = current->next;
    }
    array[string->length] = '\0';
    return array;
}

string_t *string_from_char_array(char *array) {
    string_t *string = string_new();
    char *current = array;
    while (*current != '\0') {
        size_t length = strlen(current);
        node_t *node = malloc(sizeof(node_t));
        node->data = malloc(length + 1);
        strcpy(node->data, current);
        node->next = NULL;
        if (string->head == NULL) {
            string->head = node;
            string->tail = node;
        } else {
            string->tail->next = node;
            string->tail = node;
        }
        string->length += length;
        current += length;
    }
    return string;
}

void string_insert(string_t *string, size_t index, char *data) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = malloc(strlen(data) + 1);
    strcpy(new_node->data, data);
    new_node->next = NULL;

    if (index == 0) {
        new_node->next = string->head;
        string->head = new_node;
        if (string->tail == NULL) {
            string->tail = new_node;
        }
    } else {
        node_t *current = string->head;
        for (size_t i = 0; i < index - 1 && current->next != NULL; i++) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
        if (new_node->next == NULL) {
            string->tail = new_node;
        }
    }

    string->length += strlen(data);
}

void string_delete(string_t *string, size_t index) {
    if (index == 0) {
        node_t *next = string->head->next;
        free(string->head->data);
        free(string->head);
        string->head = next;
        if (string->head == NULL) {
            string->tail = NULL;
        }
    } else {
        node_t *current = string->head;
        for (size_t i = 0; i < index - 1 && current->next != NULL; i++) {
            current = current->next;
        }
        node_t *next = current->next->next;
        free(current->next->data);
        free(current->next);
        current->next = next;
        if (current->next == NULL) {
            string->tail = current;
        }
    }

    string->length -= strlen(string->head->data);
}

int main() {
    string_t *string = string_new();

    string_insert(string, 0, "Hello");
    string_insert(string, 5, " ");
    string_insert(string, 6, "World");
    string_insert(string, 12, "!");

    char *array = string_to_char_array(string);
    printf("%s\n", array);
    free(array);

    string_delete(string, 12);
    string_delete(string, 6);

    array = string_to_char_array(string);
    printf("%s\n", array);
    free(array);

    string_free(string);

    return 0;
}