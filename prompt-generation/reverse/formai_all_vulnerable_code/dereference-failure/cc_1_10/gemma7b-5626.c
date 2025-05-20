//Gemma-7B DATASET v1.0 Category: Metadata Extractor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_BUFFER_SIZE 4096

int main() {
    char buffer[MAX_BUFFER_SIZE];
    FILE *fp;
    int i = 0;
    char *ptr;
    struct stat stat_buf;
    char filename[] = "/path/to/file.txt";

    // Get file statistics
    stat(filename, &stat_buf);

    // Open file in binary mode
    fp = fopen(filename, "rb");

    // Allocate memory for buffer
    ptr = malloc(stat_buf.st_size);

    // Read file contents into buffer
    fread(ptr, stat_buf.st_size, 1, fp);

    // Close file
    fclose(fp);

    // Search for metadata entries
    for (i = 0; i < stat_buf.st_size; i++) {
        // Check if character is a colon
        if (ptr[i] == ':') {
            // Extract metadata key and value
            char key[MAX_BUFFER_SIZE];
            char value[MAX_BUFFER_SIZE];

            // Copy key and value from buffer
            key[0] = '\0';
            value[0] = '\0';
            i++;
            while (ptr[i] != ':' && ptr[i] != '\0') {
                key[i] = ptr[i];
                i++;
            }

            // Copy key and value to separate variables
            while (ptr[i] != '\0') {
                value[i] = ptr[i];
                i++;
            }

            // Print key-value pair
            printf("%s: %s\n", key, value);
        }
    }

    // Free memory
    free(ptr);

    return 0;
}