//FormAI DATASET v1.0 Category: File Synchronizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_BUFFER_SIZE 1024

void synchronize_files(char *file1, char *file2);

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Invalid arguments. Usage: ./file_synchronizer file1 file2\n");
        return 1;
    }

    char *file1 = argv[1];
    char *file2 = argv[2];

    synchronize_files(file1, file2);

    return 0;
}

void synchronize_files(char *file1, char *file2) {
    FILE *fp1, *fp2;
    char buffer1[MAX_BUFFER_SIZE], buffer2[MAX_BUFFER_SIZE];
    fp1 = fopen(file1, "r");
    fp2 = fopen(file2, "r+");

    if (!fp1) {
        printf("Unable to open file '%s'\n", file1);
        return;
    }
    if (!fp2) {
        printf("Unable to open file '%s'\n", file2);
        return;
    }

    while (fgets(buffer1, MAX_BUFFER_SIZE, fp1)) {
        int line_length = strlen(buffer1);
        if (fgets(buffer2, MAX_BUFFER_SIZE, fp2)) {
            if (strcmp(buffer1, buffer2) != 0) {
                fseek(fp2, -line_length, SEEK_CUR);
                fwrite(buffer1, line_length, 1, fp2);
                printf("Line '%s' synchronized from file '%s' to '%s'\n", buffer1, file1, file2);
            }
        } else {
            fwrite(buffer1, line_length, 1, fp2);
            printf("Line '%s' appended from file '%s' to '%s'\n", buffer1, file1, file2);
        }
    }

    while (fgets(buffer2, MAX_BUFFER_SIZE, fp2)) {
        printf("Line '%s' deleted from file '%s'\n", buffer2, file2);
    }

    fclose(fp1);
    fclose(fp2);
}