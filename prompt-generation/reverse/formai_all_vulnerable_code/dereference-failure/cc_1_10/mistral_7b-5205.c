//MISTRAL-7B DATASET v1.0 Category: File system simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

typedef struct Node {
    char name[50];
    int size;
    struct Node *next;
    struct Node *prev;
} Node;

Node *head = NULL;
Node *tail = NULL;

void create_file(char *name, int size) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->size = size;
    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
}

int main() {
    create_file("The_Elephant_of_Surrealism.txt", 100);
    create_file("The_Cake_of_Dreams.txt", 50);
    create_file("The_Mirror_of_Reflections.txt", 75);

    Node *current = head;
    while (current != NULL) {
        printf("%s %d\n", current->name, current->size);
        current = current->next;
    }

    // Surrealistic file system commands
    if (rename("The_Elephant_of_Surrealism.txt", "The_Lemming_of_Surrealism.txt") == -1) {
        perror("Error renaming file");
    }

    if (mkdir("The_Garden_of_Absurdity", 0777) == -1) {
        perror("Error creating directory");
    }

    if (chmod("The_Garden_of_Absurdity", 0777) == -1) {
        perror("Error changing permissions");
    }

    if (chdir("The_Garden_of_Absurdity") == -1) {
        perror("Error changing directory");
    }

    if (unlink("The_Lemming_of_Surrealism.txt") == -1) {
        perror("Error deleting file");
    }

    if (rmdir("The_Garden_of_Absurdity") == -1) {
        perror("Error removing directory");
    }

    return 0;
}