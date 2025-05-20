//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define FILE_MODE "r"

typedef struct {
    char *filename;
    char *content;
    size_t size;
} File;

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage:./program file1 file2\n");
        exit(1);
    }

    File file1, file2;

    // Read the contents of file1
    file1.filename = argv[1];
    file1.content = malloc(MAX_LINE_SIZE);
    file1.size = 0;

    FILE *fp1 = fopen(file1.filename, FILE_MODE);
    if (fp1 == NULL) {
        printf("Error opening file %s\n", file1.filename);
        exit(1);
    }

    char ch;
    while ((ch = fgetc(fp1))!= EOF) {
        if (file1.size >= MAX_LINE_SIZE) {
            printf("Error: File %s is too large\n", file1.filename);
            exit(1);
        }
        file1.content[file1.size++] = ch;
    }

    fclose(fp1);

    // Read the contents of file2
    file2.filename = argv[2];
    file2.content = malloc(MAX_LINE_SIZE);
    file2.size = 0;

    FILE *fp2 = fopen(file2.filename, FILE_MODE);
    if (fp2 == NULL) {
        printf("Error opening file %s\n", file2.filename);
        exit(1);
    }

    while ((ch = fgetc(fp2))!= EOF) {
        if (file2.size >= MAX_LINE_SIZE) {
            printf("Error: File %s is too large\n", file2.filename);
            exit(1);
        }
        file2.content[file2.size++] = ch;
    }

    fclose(fp2);

    // Compare the contents of the two files
    if (file1.size!= file2.size) {
        printf("Files are not the same size\n");
        exit(1);
    }

    int result = memcmp(file1.content, file2.content, file1.size);

    if (result == 0) {
        printf("Files are the same\n");
    } else {
        printf("Files are different\n");
    }

    free(file1.content);
    free(file2.content);

    return 0;
}