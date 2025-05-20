//Gemma-7B DATASET v1.0 Category: File system simulation ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FILES 10

typedef struct File {
    char name[256];
    struct File* next;
    FILE* fp;
} File;

File* file_insert(File* head, char* name) {
    File* new_file = (File*)malloc(sizeof(File));
    strcpy(new_file->name, name);
    new_file->next = NULL;
    new_file->fp = NULL;

    if (head == NULL) {
        head = new_file;
    } else {
        head->next = new_file;
    }

    return head;
}

void file_list(File* head) {
    FILE* fp;
    File* current = head;
    while (current) {
        printf("%s ", current->name);
        fp = current->fp;
        if (fp) {
            printf(" (opened)\n");
        } else {
            printf("\n");
        }
        current = current->next;
    }
}

int main() {
    File* files = NULL;

    // Insert some files
    file_insert(files, "test.txt");
    file_insert(files, "my.doc");
    file_insert(files, "image.jpg");

    // List the files
    file_list(files);

    return 0;
}