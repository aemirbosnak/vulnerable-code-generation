//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *filename;
    int filesize;
    char *data;
    struct node *next;
} file_node;

typedef struct directory {
    char *name;
    file_node *head;
    struct directory *next;
} dir_node;

dir_node *root;
file_node *current;

void create_dir(dir_node *current) {
    char name[64];
    printf("Enter directory name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    current->name = name;
    current->head = NULL;
    current->next = NULL;
}

void create_file(dir_node *current, char *filename) {
    file_node *new_file;
    new_file->filename = filename;
    new_file->filesize = 0;
    new_file->data = NULL;
    new_file->next = NULL;
    if (current->head == NULL) {
        current->head = new_file;
    } else {
        file_node *temp = current->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_file;
    }
}

void print_dir(dir_node *current) {
    printf("%s:\n", current->name);
    file_node *temp = current->head;
    while (temp!= NULL) {
        printf(" %s (%d bytes)\n", temp->filename, temp->filesize);
        temp = temp->next;
    }
}

int main() {
    root = (dir_node *)malloc(sizeof(dir_node));
    root->name = "root";
    root->head = NULL;
    root->next = NULL;
    current = root;

    create_dir(current);
    create_file(current, "file1.txt");
    create_file(current, "file2.txt");
    print_dir(current);
    return 0;
}