//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10

typedef struct File {
    char name[256];
    struct File* next;
    FILE* file;
} File;

File* insertFile(File* head, char* name, FILE* file) {
    File* newNode = malloc(sizeof(File));
    strcpy(newNode->name, name);
    newNode->file = file;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void listFiles(File* head) {
    FILE* file;
    File* current = head;

    while (current) {
        printf("%s\n", current->name);
        file = current->file;
        rewind(file);
        printf("  Content:\n");
        while (fscanf(file, "%s", current->name) != EOF) {
            printf("    %s\n", current->name);
        }
        printf("\n");
        current = current->next;
    }
}

int main() {
    File* head = NULL;

    // Insert some files
    insertFile(head, "mytext.txt", fopen("mytext.txt", "r"));
    insertFile(head, "photo.jpg", fopen("photo.jpg", "r"));
    insertFile(head, "music.mp3", fopen("music.mp3", "r"));

    // List all files
    listFiles(head);

    return 0;
}