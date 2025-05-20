//Falcon-180B DATASET v1.0 Category: File handling ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char filename[MAX_FILE_NAME_LENGTH];
    FILE *file;
    int line_count;
} File;

void open_file(File *file) {
    char filename[MAX_FILE_NAME_LENGTH];
    printf("Enter file name: ");
    scanf("%s", filename);
    strcpy(file->filename, filename);
    file->file = fopen(filename, "r");
    if (file->file == NULL) {
        printf("Error: Could not open file\n");
        exit(1);
    }
    file->line_count = 0;
}

void close_file(File *file) {
    fclose(file->file);
}

void read_file(File *file) {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file->file)!= NULL) {
        printf("%s", line);
        file->line_count++;
    }
}

void main() {
    File file;
    int choice;
    do {
        printf("\nFile Handling Menu\n");
        printf("1. Open a file\n");
        printf("2. Close a file\n");
        printf("3. Read a file\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                open_file(&file);
                break;
            case 2:
                close_file(&file);
                break;
            case 3:
                read_file(&file);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 4);
}