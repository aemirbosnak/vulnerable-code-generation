//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct file_system {
    Node* root;
} FileSystem;

FileSystem* create_file_system() {
    FileSystem* fs = malloc(sizeof(FileSystem));
    fs->root = NULL;
    return fs;
}

void insert(FileSystem* fs, int data) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = fs->root;
    fs->root = new_node;
}

void delete_file_system(FileSystem* fs) {
    Node* current = fs->root;
    Node* prev = NULL;

    while (current!= NULL) {
        Node* temp = current->next;
        free(current);
        current = temp;
    }
    free(fs);
}

void print_file_system(FileSystem* fs) {
    Node* current = fs->root;

    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    FileSystem* fs = create_file_system();

    insert(fs, 1);
    insert(fs, 2);
    insert(fs, 3);
    insert(fs, 4);
    insert(fs, 5);

    print_file_system(fs);

    delete_file_system(fs);

    return 0;
}