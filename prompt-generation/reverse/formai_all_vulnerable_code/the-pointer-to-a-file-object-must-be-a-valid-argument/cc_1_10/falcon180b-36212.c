//Falcon-180B DATASET v1.0 Category: File handling ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80
#define MAX_FILE_NAME_LENGTH 20

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    FILE* file;
} File;

int create_file(char* file_name) {
    File* file = malloc(sizeof(File));
    strcpy(file->name, file_name);
    file->file = fopen(file_name, "w");
    if (file->file == NULL) {
        printf("Error: Failed to create file %s\n", file_name);
        free(file);
        return 1;
    }
    printf("File %s created successfully\n", file_name);
    return 0;
}

int append_to_file(File* file, char* text) {
    int length = strlen(text);
    if (length > MAX_LINE_LENGTH) {
        printf("Error: Text is too long\n");
        return 1;
    }
    fprintf(file->file, "%s", text);
    printf("Text appended to file %s\n", file->name);
    return 0;
}

int read_from_file(File* file) {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file->file)!= NULL) {
        printf("%s", line);
    }
    return 0;
}

int main() {
    File* file1 = NULL;
    File* file2 = NULL;
    char text1[MAX_LINE_LENGTH];
    char text2[MAX_LINE_LENGTH];

    printf("Enter file name for file 1: ");
    scanf("%s", text1);
    if (create_file(text1)) {
        return 1;
    }
    file1 = malloc(sizeof(File));
    strcpy(file1->name, text1);
    file1->file = fopen(text1, "a");

    printf("Enter file name for file 2: ");
    scanf("%s", text2);
    if (create_file(text2)) {
        return 1;
    }
    file2 = malloc(sizeof(File));
    strcpy(file2->name, text2);
    file2->file = fopen(text2, "a");

    printf("Enter text to append to file 1: ");
    scanf("%s", text1);
    append_to_file(file1, text1);

    printf("Enter text to append to file 2: ");
    scanf("%s", text2);
    append_to_file(file2, text2);

    printf("Contents of file 1:\n");
    read_from_file(file1);

    printf("Contents of file 2:\n");
    read_from_file(file2);

    fclose(file1->file);
    fclose(file2->file);
    free(file1);
    free(file2);

    return 0;
}