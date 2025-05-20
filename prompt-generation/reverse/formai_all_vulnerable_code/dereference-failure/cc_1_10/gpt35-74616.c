//FormAI DATASET v1.0 Category: File Synchronizer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <file1> <file2>\n", argv[0]);
        return 1;
    }

    FILE *file1 = fopen(argv[1], "rb");
    if (file1 == NULL) {
        perror("Error opening file1");
        return 2;
    }

    FILE *file2 = fopen(argv[2], "rb");
    if (file2 == NULL) {
        perror("Error opening file2");
        fclose(file1);
        return 2;
    }

    char buffer1[MAX_BUFFER_SIZE];
    char buffer2[MAX_BUFFER_SIZE];

    size_t bytesRead1, bytesRead2, bytesWritten1, bytesWritten2;
    int lineCount = 1;

    do {
        bytesRead1 = fread(buffer1, 1, MAX_BUFFER_SIZE, file1);
        bytesRead2 = fread(buffer2, 1, MAX_BUFFER_SIZE, file2);

        if (bytesRead1 != bytesRead2) {
            printf("Files are different, line %d\n", lineCount);
            fclose(file1);
            fclose(file2);
            return 3;
        }

        bytesWritten1 = fwrite(buffer1, 1, bytesRead1, file2);
        bytesWritten2 = fwrite(buffer2, 1, bytesRead2, file1);

        if (bytesWritten1 != bytesRead1 || bytesWritten2 != bytesRead2) {
            printf("Error writing files, line %d: %s\n", lineCount, strerror(errno));
            fclose(file1);
            fclose(file2);
            return 4;
        }

        lineCount++;
    } while (bytesRead1 != 0);

    fclose(file1);
    fclose(file2);

    printf("Files synchronized successfully!\n");
    return 0;
}