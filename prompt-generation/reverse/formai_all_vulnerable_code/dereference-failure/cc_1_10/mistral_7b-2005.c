//MISTRAL-7B DATASET v1.0 Category: File system simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[50];
    int is_file;
    struct Node *next;
} Node;

Node *root = NULL;
Node *current = NULL;

void create_node(const char *name, int is_file) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->is_file = is_file;
    new_node->next = NULL;

    if (root == NULL) {
        root = new_node;
        current = new_node;
    } else {
        Node *temp = root;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
        current = new_node;
    }
}

void remove_node(const char *name) {
    if (root == NULL) {
        return;
    }

    Node *temp = root;
    Node *prev = NULL;

    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            if (prev == NULL) {
                root = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void change_directory(const char *name) {
    Node *temp = root;

    while (temp != NULL && strcmp(temp->name, name) != 0) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Error: Directory not found\n");
        return;
    }

    current = temp;
}

void list_contents() {
    Node *temp = current;

    if (current == NULL) {
        printf("Error: Current directory is null\n");
        return;
    }

    printf("%s:\n", current->name);

    while (temp != NULL) {
        printf("%s%s\n", temp->is_file ? "  |- " : "  |-- ", temp->name);
        temp = temp->next;
    }
}

void search(const char *name) {
    Node *temp = root;

    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("Found: %s\n", temp->name);
            return;
        }
        temp = temp->next;
    }

    printf("Error: File or directory not found\n");
}

int main() {
    create_node("/", 0);

    create_node("home", 0);
    current = (Node *) malloc(sizeof(Node));
    strcpy(current->name, "home");
    current->is_file = 0;
    current->next = (Node *) malloc(sizeof(Node));
    strcpy(current->next->name, "desktop");
    current->next->is_file = 0;
    current->next->next = root;
    current = root;

    create_node("home/desktop/file.txt", 1);
    create_node("home/desktop/folder", 0);

    list_contents();
    change_directory("home/desktop");
    list_contents();
    search("file.txt");
    search("nonexistent");

    remove_node("home/desktop/folder");
    list_contents();

    return 0;
}