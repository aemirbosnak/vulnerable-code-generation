//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 1000
#define MAX_FILENAME_LENGTH 50
#define MAX_BUFFER_SIZE 2048

int scanFile(char *filename);

int main(int argc, char *argv[]) {
    char fileList[MAX_FILES][MAX_FILENAME_LENGTH];
    int numOfFiles = 0;

    if (argc < 2) {
        printf("Usage: ./antivirus [file1] [file2] ... [fileN]\n");
        return 0;
    }

    for (int i = 1; i < argc; i++) {
        strcpy(fileList[numOfFiles], argv[i]);
        numOfFiles++;
    }

    for (int i = 0; i < numOfFiles; i++) {
        if (scanFile(fileList[i])) {
            printf("%s is infected!\n", fileList[i]);
        } else {
            printf("%s is clean.\n", fileList[i]);
        }
    }

    return 0;
}

int scanFile(char *filename) {
    FILE *fp;
    unsigned char buffer[MAX_BUFFER_SIZE];
    int bytesRead;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Could not open %s.\n", filename);
        return -1;
    }

    while ((bytesRead = fread(buffer, 1, MAX_BUFFER_SIZE, fp)) > 0) {
        for (int i = 0; i < bytesRead - 3; i++) {
            if (buffer[i] == 'v' && buffer[i+1] == 'i' && buffer[i+2] == 'r' && buffer[i+3] == 'u') {
                fclose(fp);
                return 1;
            }
        }
    }

    fclose(fp);
    return 0;
}