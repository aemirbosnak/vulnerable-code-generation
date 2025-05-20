//FormAI DATASET v1.0 Category: Data recovery tool ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME_LEN 256
#define BUFFER_SIZE 2048

int main() {
    char filename[FILENAME_LEN];
    printf("Enter the name of the file you want to recover: ");
    fgets(filename, FILENAME_LEN, stdin);
    filename[strcspn(filename, "\n")] = 0; // remove newline character from filename

    FILE *fp = fopen(filename, "rb");

    if (fp == NULL) {
        printf("Error: Unable to open the file\n");
        return 1;
    }

    fseek(fp, 0L, SEEK_END);
    long int file_size = ftell(fp);
    rewind(fp);

    char *buffer = malloc(BUFFER_SIZE);
    if (buffer == NULL) {
        printf("Error: Unable to allocate buffer\n");
        return 1;
    }

    printf("The recovered data:\n\n");
    long int bytes_read = 0;
    while (bytes_read < file_size) {
        int bytes_to_read = BUFFER_SIZE;
        if (bytes_read + bytes_to_read > file_size) {
            bytes_to_read = file_size - bytes_read;
        }

        int bytes_read_now = fread(buffer, 1, bytes_to_read, fp);

        if (bytes_read_now != bytes_to_read) {
            printf("Error: Unable to read the file\n");
            return 1;
        }

        for (int i = 0; i < bytes_to_read; i++) {
            if (buffer[i] >= 32 && buffer[i] <= 126) {
                printf("%c", buffer[i]); // print printable characters
            } else {
                printf("."); // replace non-printable characters with a dot
            }
        }

        bytes_read += bytes_to_read;
    }

    printf("\n");

    fclose(fp);
    free(buffer);

    return 0;
}