//MISTRAL-7B DATASET v1.0 Category: File system simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int size;
    int isFile;
    int isDirectory;
    struct Node *next;
} Node;

typedef Node *List;

List root = NULL;

void createFile(char *name, int size) {
    List newNode = (List) malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->size = size;
    newNode->isFile = 1;
    newNode->isDirectory = 0;
    newNode->next = root;
    root = newNode;
}

void createDirectory(char *name) {
    List newNode = (List) malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->size = 0;
    newNode->isFile = 0;
    newNode->isDirectory = 1;
    newNode->next = root;
    root = newNode;
}

void writeToFile(char *name, char *data) {
    List current = root;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0 && current->isFile == 1) {
            FILE *file = fopen(name, "w");
            fprintf(file, "%s", data);
            fclose(file);
            printf("File %s has been updated.\n", name);
            break;
        }
        current = current->next;
    }
}

void printDirectory() {
    List current = root;
    printf("Current directory:\n");
    while (current != NULL) {
        printf("%s%c", current->name, current->isDirectory == 1 ? '/' : ' ');
        current = current->next;
    }
    printf("\n");
}

int main() {
    createDirectory("Capulet House");
    createDirectory("Montague House");

    createFile("Capulet House/Juliet.txt", 100);
    createFile("Capulet House/Romeo.txt", 150);

    createFile("Montague House/Mercutio.txt", 50);
    createFile("Montague House/Benvolio.txt", 75);

    printDirectory();

    writeToFile("Capulet House/Juliet.txt", "My fair lord, what light through yonder window breaks?");

    printDirectory();

    return 0;
}