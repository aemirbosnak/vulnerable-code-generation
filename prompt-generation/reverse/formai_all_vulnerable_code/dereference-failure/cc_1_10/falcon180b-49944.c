//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct node {
    char* data;
    int size;
    struct node* next;
};

struct node* head = NULL;

void add_node(char* data, int size) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->size = size;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        return;
    }

    struct node* last_node = head;
    while (last_node->next!= NULL) {
        last_node = last_node->next;
    }

    last_node->next = new_node;
}

void print_list() {
    struct node* current_node = head;
    while (current_node!= NULL) {
        printf("Data: %s, Size: %d\n", current_node->data, current_node->size);
        current_node = current_node->next;
    }
}

void free_list() {
    struct node* current_node = head;
    while (current_node!= NULL) {
        free(current_node->data);
        free(current_node);
        current_node = current_node->next;
    }
}

int main() {
    char binary_string[MAX_SIZE];
    int binary_string_size;

    printf("Enter a binary string: ");
    scanf("%s", binary_string);
    binary_string_size = strlen(binary_string);

    add_node(binary_string, binary_string_size);

    print_list();

    free_list();

    return 0;
}