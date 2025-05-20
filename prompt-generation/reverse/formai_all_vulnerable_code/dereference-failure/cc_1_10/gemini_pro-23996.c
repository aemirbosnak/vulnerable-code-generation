//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *value;
    struct node *next;
} node;

typedef struct list {
    node *head;
    node *tail;
} list;

void push_front(list *list, char *value) {
    node *new_node = malloc(sizeof(node));
    new_node->value = strdup(value);
    new_node->next = list->head;
    list->head = new_node;
    if (list->tail == NULL) {
        list->tail = new_node;
    }
}

void push_back(list *list, char *value) {
    node *new_node = malloc(sizeof(node));
    new_node->value = strdup(value);
    new_node->next = NULL;
    if (list->tail == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

char *pop_front(list *list) {
    if (list->head == NULL) {
        return NULL;
    }
    char *value = strdup(list->head->value);
    node *next_node = list->head->next;
    free(list->head);
    list->head = next_node;
    if (list->head == NULL) {
        list->tail = NULL;
    }
    return value;
}

char *pop_back(list *list) {
    if (list->tail == NULL) {
        return NULL;
    }
    char *value = strdup(list->tail->value);
    node *new_tail = list->tail->next;
    free(list->tail);
    list->tail = new_tail;
    if (list->tail == NULL) {
        list->head = NULL;
    }
    return value;
}

int main() {
    list *input_list = malloc(sizeof(list));
    input_list->head = NULL;
    input_list->tail = NULL;

    char *input = malloc(1024);
    printf("Enter a hexadecimal number: ");
    scanf("%s", input);

    int i = 0;
    while (input[i] != '\0') {
        char *substring = malloc(2);
        substring[0] = input[i];
        substring[1] = '\0';
        push_back(input_list, substring);
        i++;
    }

    list *output_list = malloc(sizeof(list));
    output_list->head = NULL;
    output_list->tail = NULL;

    while (input_list->head != NULL) {
        char *substring = pop_front(input_list);
        int value = 0;
        if (substring[0] >= '0' && substring[0] <= '9') {
            value = substring[0] - '0';
        } else if (substring[0] >= 'A' && substring[0] <= 'F') {
            value = substring[0] - 'A' + 10;
        } else if (substring[0] >= 'a' && substring[0] <= 'f') {
            value = substring[0] - 'a' + 10;
        }
        char *binary_substring = malloc(5);
        sprintf(binary_substring, "%04b", value);
        push_front(output_list, binary_substring);
    }

    while (output_list->head != NULL) {
        char *substring = pop_front(output_list);
        printf("%s", substring);
    }

    printf("\n");

    return 0;
}