//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_CONTENT_LENGTH 1000
#define MAX_NUM_FILES 100

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    char file_content[MAX_FILE_CONTENT_LENGTH];
    int file_size;
    struct node* next;
} file_t;

typedef struct node {
    file_t* file;
    struct node* next;
} node_t;

int num_files = 0;
node_t* root = NULL;

void create_file(char* file_name, char* file_content) {
    file_t* new_file = (file_t*)malloc(sizeof(file_t));
    strcpy(new_file->file_name, file_name);
    strcpy(new_file->file_content, file_content);
    new_file->file_size = strlen(file_content);
    new_file->next = NULL;

    if (root == NULL) {
        root = (node_t*)malloc(sizeof(node_t));
        root->file = new_file;
        root->next = NULL;
    } else {
        node_t* curr_node = root;
        while (curr_node->next!= NULL) {
            curr_node = curr_node->next;
        }
        curr_node->next = (node_t*)malloc(sizeof(node_t));
        curr_node->next->file = new_file;
        curr_node->next->next = NULL;
    }

    num_files++;
}

void delete_file(char* file_name) {
    node_t* curr_node = root;
    while (curr_node!= NULL) {
        if (strcmp(curr_node->file->file_name, file_name) == 0) {
            file_t* temp_file = curr_node->file;
            curr_node->file = curr_node->file->next;
            free(temp_file);
            num_files--;
            break;
        }
        curr_node = curr_node->next;
    }
}

void display_files() {
    node_t* curr_node = root;
    while (curr_node!= NULL) {
        printf("File name: %s\nFile content: %s\nFile size: %d bytes\n", curr_node->file->file_name, curr_node->file->file_content, curr_node->file->file_size);
        curr_node = curr_node->next;
    }
}

int main() {
    create_file("test1.txt", "Hello, world!");
    create_file("test2.txt", "This is a test file.");
    display_files();

    delete_file("test1.txt");
    display_files();

    return 0;
}