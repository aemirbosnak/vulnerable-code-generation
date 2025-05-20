//FormAI DATASET v1.0 Category: File Backup System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME 100

typedef struct file_data {
    char filename[MAX_FILENAME];
    int size;
    char* contents;
} file_data;

void backup_file(const char* filename) {
    FILE* f = fopen(filename, "r");
    if (!f) {
        printf("Error: File not found.\n");
        return;
    }
    
    // Get file size
    fseek(f, 0, SEEK_END);
    int size = ftell(f);
    fseek(f, 0, SEEK_SET);
    
    // Allocate memory for contents
    char* contents = malloc(size);
    if (!contents) {
        printf("Error: Memory allocation failed.\n");
        return;
    }
    
    // Read file contents
    fread(contents, 1, size, f);
    
    // Close file handle
    fclose(f);
    
    // Create new file_data struct
    file_data file;
    strncpy(file.filename, filename, MAX_FILENAME);
    file.size = size;
    file.contents = contents;
    
    // Open backup file for writing
    char backup_filename[MAX_FILENAME + 5]; // +5 for ".bak\0"
    strncpy(backup_filename, filename, MAX_FILENAME);
    strncat(backup_filename, ".bak", 4);
    FILE* backup_f = fopen(backup_filename, "w");
    if (!backup_f) {
        printf("Error: Could not create backup file.\n");
        free(contents);
        return;
    }
    
    // Write file_data struct to backup file
    fwrite(&file, sizeof(file_data), 1, backup_f);
    
    // Close backup file handle
    fclose(backup_f);
    
    printf("Backup complete: %s -> %s\n", filename, backup_filename);
    free(contents);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    
    backup_file(argv[1]);
    
    return 0;
}