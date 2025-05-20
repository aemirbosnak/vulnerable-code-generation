//Gemma-7B DATASET v1.0 Category: File Synchronizer ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void insert_at_tail(Node* head, char data) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        head->next = new_node;
    }
}

void synchronize_files(char* file_a, char* file_b) {
    FILE* file_a_ptr = fopen(file_a, "r");
    FILE* file_b_ptr = fopen(file_b, "r");

    Node* head_a = NULL;
    Node* head_b = NULL;

    char buffer[BUFFER_SIZE];

    while (!feof(file_a_ptr) || !feof(file_b_ptr)) {
        char data_a = fgetc(file_a_ptr);
        char data_b = fgetc(file_b_ptr);

        insert_at_tail(head_a, data_a);
        insert_at_tail(head_b, data_b);

        if (data_a != data_b) {
            printf("Error: Files do not match at character %c.\n", data_a);
            exit(1);
        }
    }

    fclose(file_a_ptr);
    fclose(file_b_ptr);

    printf("Files synchronized successfully.\n");
}

int main() {
    synchronize_files("file_a.txt", "file_b.txt");

    return 0;
}