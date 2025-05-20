//FormAI DATASET v1.0 Category: Error handling ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(void) {
    char filename[] = "nonexist.txt";
    FILE *file = NULL;
    int filesize = 0;

    // Try to open a non-existent file
    if ((file = fopen(filename, "r")) == NULL) {
        // Handle fopen() errors
        switch (errno) {
            case EACCES:
                fprintf(stderr, "Error: %s is not accessible\n", filename);
                break;
            case ENOENT:
                fprintf(stderr, "Error: %s does not exist\n", filename);
                break;
            default:
                fprintf(stderr, "Error: %s\n", strerror(errno));
                break;
        }
        exit(EXIT_FAILURE);
    }

    // Get filesize
    fseek(file, 0, SEEK_END);
    if ((filesize = ftell(file)) == -1) {
        // Handle ftell() errors
        fprintf(stderr, "Error: %s\n", strerror(errno));
        fclose(file);
        exit(EXIT_FAILURE);
    }
    fseek(file, 0, SEEK_SET);

    // Allocate memory for file contents
    char *file_contents = malloc(filesize);
    if (file_contents == NULL) {
        // Handle malloc() errors
        fprintf(stderr, "Error: %s\n", strerror(errno));
        fclose(file);
        exit(EXIT_FAILURE);
    }

    // Read file contents
    if (fread(file_contents, 1, filesize, file) != filesize) {
        // Handle fread() errors
        fprintf(stderr, "Error: %s\n", strerror(errno));
        free(file_contents);
        fclose(file);
        exit(EXIT_FAILURE);
    }

    // Print file contents
    printf("File contents:\n%s", file_contents);

    // Clean up
    free(file_contents);
    fclose(file);

    return 0;
}