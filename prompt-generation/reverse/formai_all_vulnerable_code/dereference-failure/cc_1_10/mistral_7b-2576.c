//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define FILE_NAME "whispers.txt"

int main() {
    int file_fd;
    char buffer[1024];
    char *file_content;
    struct stat file_stat;

    // Open the file in read-only mode
    if ((file_fd = open(FILE_NAME, O_RDONLY)) == -1) {
        perror("Error opening file");
        exit(1);
    }

    // Get file size
    if (fstat(file_fd, &file_stat) == -1) {
        perror("Error getting file size");
        exit(1);
    }

    // Allocate memory for the entire file content
    file_content = (char*) malloc(file_stat.st_size);
    if (file_content == NULL) {
        perror("Error allocating memory");
        exit(1);
    }

    // Read the entire file into memory
    if (read(file_fd, file_content, file_stat.st_size) != file_stat.st_size) {
        perror("Error reading file");
        exit(1);
    }

    // Close the file descriptor
    close(file_fd);

    // Print the contents of the file in an artistic way
    printf("\n---------\n");
    printf("| Whispers |\n");
    printf("---------\n");

    int line_number = 1;
    for (int i = 0; i < file_stat.st_size; i += strlen(file_content) + 1) {
        int len = strlen(&file_content[i]);
        if (len > 72) {
            printf("\n%d. %s...\n", line_number++, &file_content[i]);
            i += len - 71;
        } else {
            printf("%d. %s\n", line_number++, &file_content[i]);
        }
    }

    // Free allocated memory
    free(file_content);

    return 0;
}