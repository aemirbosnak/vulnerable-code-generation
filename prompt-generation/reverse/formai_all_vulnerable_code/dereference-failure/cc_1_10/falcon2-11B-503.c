//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100

int main() {
    char file1[MAX_FILENAME_LENGTH], file2[MAX_FILENAME_LENGTH];

    printf("Enter file 1 name: ");
    fgets(file1, MAX_FILENAME_LENGTH, stdin);

    printf("Enter file 2 name: ");
    fgets(file2, MAX_FILENAME_LENGTH, stdin);

    int file1Size = strlen(file1);
    int file2Size = strlen(file2);

    if (file1Size > MAX_FILENAME_LENGTH) {
        file1[MAX_FILENAME_LENGTH - 1] = '\0';
    }

    if (file2Size > MAX_FILENAME_LENGTH) {
        file2[MAX_FILENAME_LENGTH - 1] = '\0';
    }

    FILE *file1Ptr = fopen(file1, "r");
    FILE *file2Ptr = fopen(file2, "r");

    if (!file1Ptr ||!file2Ptr) {
        printf("Error opening files.\n");
        return 1;
    }

    char buffer1[1024], buffer2[1024];
    int bytesRead1, bytesRead2;

    while ((bytesRead1 = fread(buffer1, sizeof(char), sizeof(buffer1), file1Ptr))!= 0) {
        bytesRead2 = fread(buffer2, sizeof(char), sizeof(buffer2), file2Ptr);
        if (bytesRead2 == 0) {
            printf("File 2 is empty.\n");
            break;
        }

        if (memcmp(buffer1, buffer2, bytesRead1) == 0) {
            printf("Files 1 and 2 are identical.\n");
            break;
        }
    }

    fclose(file1Ptr);
    fclose(file2Ptr);

    return 0;
}