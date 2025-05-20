//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Function to copy a file
void copy_file(FILE *source, FILE *destination) {
    char buffer[1024];
    int bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytes_read, destination);
    }
}

// Function to backup a file
void backup_file(char *filename) {
    FILE *source, *destination;
    char backup_filename[strlen(filename) + 5];

    // Open source file
    source = fopen(filename, "rb");
    if (source == NULL) {
        printf("Error opening %s\n", filename);
        exit(1);
    }

    // Create backup filename
    strcpy(backup_filename, filename);
    strcat(backup_filename, ".bak");

    // Open destination file
    destination = fopen(backup_filename, "wb");
    if (destination == NULL) {
        printf("Error creating %s\n", backup_filename);
        exit(1);
    }

    // Backup file
    copy_file(source, destination);

    // Close files
    fclose(source);
    fclose(destination);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }

    // Backup file
    backup_file(argv[1]);

    return 0;
}