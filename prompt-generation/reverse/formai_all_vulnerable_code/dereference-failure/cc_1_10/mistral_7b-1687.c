//MISTRAL-7B DATASET v1.0 Category: File Synchronizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

void compareFiles(FILE *file1, FILE *file2, char *fileName1, char *fileName2) {
    char buffer1[BUF_SIZE], buffer2[BUF_SIZE];
    int status;

    while ((status = fgetc(file1)) != EOF && fgetc(file2) != EOF) {
        if (status != getc(file2)) {
            printf("%s:%d: %s\n%s:%d: %s\n", fileName1, (int) ftell(file1), buffer1, fileName2, (int) ftell(file2), buffer2);
            fgets(buffer1, BUF_SIZE, file1);
            fgets(buffer2, BUF_SIZE, file2);
            buffer1[strlen(buffer1) - 1] = '\0';
            buffer2[strlen(buffer2) - 1] = '\0';
            printf("----\n");
        }
        fgetc(file1);
        getc(file2);
    }

    if (feof(file1) && feof(file2)) {
        printf("Files are identical.\n");
    } else {
        fseek(file1, 0, SEEK_SET);
        fseek(file2, 0, SEEK_SET);
        compareFiles(file1, file2, fileName1, fileName2);
    }
}

int main(int argc, char **argv) {
    if (argc != 5) {
        printf("Usage: %s <file1> <file2> <output> <ignore_case>\n", argv[0]);
        return 1;
    }

    FILE *file1 = fopen(argv[1], "r");
    FILE *file2 = fopen(argv[2], "r");
    FILE *output = fopen(argv[3], "w");
    int ignoreCase = atoi(argv[4]);

    if (file1 == NULL || file2 == NULL || output == NULL) {
        printf("Error opening file(s).\n");
        return 1;
    }

    compareFiles(file1, file2, argv[1], argv[2]);
    fclose(file1);
    fclose(file2);
    fclose(output);

    return 0;
}