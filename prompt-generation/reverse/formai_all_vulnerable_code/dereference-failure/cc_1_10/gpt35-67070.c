//FormAI DATASET v1.0 Category: File Synchronizer ; Style: single-threaded
#include <stdio.h>
#include <string.h>

#define MAX_FILE_SIZE 1024
#define FILENAME_LENGTH 20

void synchronizeFiles(char* file1, char* file2);

int main(int argc, char const *argv[]) {
    synchronizeFiles("file1.txt", "file2.txt");
    return 0;
}

void synchronizeFiles(char* file1, char* file2) {
    FILE *fptr1, *fptr2;
    char data[MAX_FILE_SIZE], filename[FILENAME_LENGTH];
    int i, j;

    fptr1 = fopen(file1, "r");
    fptr2 = fopen(file2, "r");

    if (fptr1 == NULL || fptr2 == NULL) {
        printf("Error opening file.");
        return;
    }

    while (fgets(data, MAX_FILE_SIZE, fptr1) != NULL) {
        for (i = 0; i < strlen(data); i++) {
            if (data[i] >= 'a' && data[i] <= 'z') {
                data[i] = data[i] - 32;
            }
        }

        if (fgets(filename, FILENAME_LENGTH, fptr2) == NULL) {
            // write to end of file 2
            fptr2 = fopen(file2, "a+");
            fputs(data, fptr2);
            fclose(fptr2);
            return;
        }

        for (j = 0; j < strlen(filename); j++) {
            if (filename[j] == '\n') {
                filename[j] = '\0';
            }
        }

        fptr2 = fopen(filename, "w+");
        fputs(data, fptr2);
        fclose(fptr2);
    }

    fclose(fptr1);
    fclose(fptr2);
}