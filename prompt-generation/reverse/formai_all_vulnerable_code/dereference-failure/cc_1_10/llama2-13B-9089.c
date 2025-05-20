//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>

#define MAX_PATH 1024
#define MAX_MESSAGE 1024

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <filename> <message>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    char *message = argv[2];

    // Check if the filename exists and is a regular file
    if (!access(filename, F_OK | X_OK) == 0) {
        perror(filename);
        fprintf(stderr, "%s\n", message);
        return 1;
    }

    // Open the file in read mode
    FILE *file = fopen(filename, "r");

    // Check if the file opened successfully
    if (file == NULL) {
        perror(filename);
        fprintf(stderr, "%s\n", message);
        return 1;
    }

    // Read the contents of the file
    char buffer[1024];
    size_t bytes_read = fread(buffer, 1, sizeof(buffer), file);

    // Check if the file has any contents
    if (bytes_read == 0) {
        fprintf(stderr, "%s\n", message);
        return 1;
    }

    // Print the contents of the file
    printf("%s\n", buffer);

    // Close the file
    fclose(file);

    return 0;
}