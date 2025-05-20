//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_FILESIZE 1048576 // 1MB

// Function to check if a given file contains a virus
int is_infected(char *filename) {
    FILE *input = fopen(filename, "rb");
    if (input == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    // Read the contents of the file into a buffer
    char buffer[MAX_FILESIZE];
    size_t buffer_size = fread(buffer, 1, MAX_FILESIZE, input);
    fclose(input);

    // Check for virus signature
    char *virus_signature = "73657475705f70726f6d70742e657865";
    char *buffer_hex = malloc(buffer_size * 2 + 1);
    for (size_t i = 0; i < buffer_size; i++) {
        sprintf(buffer_hex + i * 2, "%02x", (unsigned char)buffer[i]);
    }

    int is_virus = strstr(buffer_hex, virus_signature) != NULL;

    free(buffer_hex);

    return is_virus;
}

int main() {
    char filename[MAX_FILENAME_LENGTH];

    while (1) {
        printf("Enter filename to scan (or 'exit' to quit): ");
        fgets(filename, MAX_FILENAME_LENGTH, stdin);

        // Remove newline character from input
        filename[strcspn(filename, "\n")] = 0;

        if (strcmp(filename, "exit") == 0) {
            break;
        }

        if (is_infected(filename)) {
            printf("Virus detected in file %s\n", filename);
        } else {
            printf("File %s is clean\n", filename);
        }
    }

    return 0;
}