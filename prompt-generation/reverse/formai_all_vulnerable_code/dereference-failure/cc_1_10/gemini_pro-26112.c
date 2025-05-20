//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char* data;
    struct node* next;
};

struct node* create_list(char* str) {
    struct node* head = NULL;
    struct node* tail = NULL;
    char* token = strtok(str, " ");
    while (token != NULL) {
        struct node* new_node = malloc(sizeof(struct node));
        new_node->data = malloc(strlen(token) + 1);
        strcpy(new_node->data, token);
        new_node->next = NULL;
        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
        token = strtok(NULL, " ");
    }
    return head;
}

int get_list_length(struct node* head) {
    int length = 0;
    struct node* current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

char* concatenate_strings(struct node* head) {
    int length = get_list_length(head);
    char* concatenated_string = malloc(length * 20);  // assuming each word is at most 20 characters long
    strcpy(concatenated_string, "");
    struct node* current = head;
    while (current != NULL) {
        strcat(concatenated_string, current->data);
        current = current->next;
    }
    return concatenated_string;
}

int main() {
    char* input_string = "The quick brown fox jumps over the lazy dog";
    struct node* list = create_list(input_string);
    char* concatenated_string = concatenate_strings(list);
    printf("Concatenated string: %s\n", concatenated_string);
    return 0;
}