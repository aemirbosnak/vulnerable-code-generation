//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIR_NAME_LEN 255
#define MAX_FILE_NAME_LEN 255

typedef struct Node {
    char dir_name[MAX_DIR_NAME_LEN];
    struct Node* next_dir;
    struct Node* next_file;
    char file_name[MAX_FILE_NAME_LEN];
    int file_size;
} Node;

Node* create_node(char* dir_name, char* file_name, int file_size) {
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->dir_name, dir_name);
    node->next_dir = NULL;
    node->next_file = NULL;
    strcpy(node->file_name, file_name);
    node->file_size = file_size;
    return node;
}

void print_dir(Node* node) {
    printf("%s\n", node->dir_name);
    for (Node* child = node->next_dir; child; child = child->next_dir) {
        printf("  %s\n", child->dir_name);
    }
    for (Node* child = node->next_file; child; child = child->next_file) {
        printf("  %s (%d bytes)\n", child->file_name, child->file_size);
    }
}

int main() {
    Node* root = create_node("home", NULL, 0);
    create_node("documents", NULL, 0)
        ->next_dir = root;
    create_node("pictures", NULL, 0)
        ->next_dir = root;
    create_node("music", NULL, 0)
        ->next_dir = root;

    create_node("documents/hello.txt", "hello.txt", 10)
        ->next_file = root->next_dir->next_dir;
    create_node("pictures/photo.jpg", "photo.jpg", 20)
        ->next_file = root->next_dir->next_dir->next_dir;

    print_dir(root);

    return 0;
}