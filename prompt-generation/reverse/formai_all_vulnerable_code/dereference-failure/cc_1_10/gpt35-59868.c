//FormAI DATASET v1.0 Category: File Backup System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to backup a file
void backup_file(char *filename) {
    // Create a new filename with '.bak' extension
    char *bak_filename = malloc(strlen(filename) + 5);
    strcpy(bak_filename, filename);
    strcat(bak_filename, ".bak");

    // Open the source file for reading
    FILE *src_file = fopen(filename, "r");
    if (!src_file) {
        printf("Failed to open file %s for reading.\n", filename);
        return;
    }

    // Open the backup file for writing
    FILE *bak_file = fopen(bak_filename, "w");
    if (!bak_file) {
        printf("Failed to open backup file %s for writing.\n", bak_filename);
        fclose(src_file);
        return;
    }

    // Copy the contents of the source file to the backup file
    char buffer[1024];
    size_t num_read;
    do {
        num_read = fread(buffer, 1, sizeof(buffer), src_file);
        fwrite(buffer, 1, num_read, bak_file);
    } while (num_read > 0);

    // Close both files
    fclose(src_file);
    fclose(bak_file);

    printf("File %s backed up to %s successfully.\n", filename, bak_filename);

    // Free dynamically allocated memory
    free(bak_filename);
}

int main() {
    // Backup a file named 'input.txt'
    backup_file("input.txt");

    return 0;
}