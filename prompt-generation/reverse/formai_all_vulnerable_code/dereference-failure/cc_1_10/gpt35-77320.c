//FormAI DATASET v1.0 Category: File Backup System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH_LEN 256
#define MAX_FILE_LEN 1024

// Function to get the backup file path
char* get_backup_path(char* path) {
    char* backup_path = (char*)malloc(MAX_PATH_LEN * sizeof(char));
    if (backup_path == NULL) {
        printf("Error: Failed to allocate memory for backup path.\n");
        exit(1);
    }
    
    // Get the file name from the path
    char* file_name = strrchr(path, '/');
    if (file_name == NULL) {
        file_name = path;
    } else {
        file_name++;
    }
    
    // Create the backup file name
    sprintf(backup_path, "%s.bak", file_name);
    
    return backup_path;
}

int main() {
    char path[MAX_PATH_LEN];
    printf("Enter the path of the file to backup: ");
    fgets(path, MAX_PATH_LEN, stdin);
    path[strcspn(path, "\n")] = '\0';
    
    FILE* input_file = fopen(path, "r");
    if (input_file == NULL) {
        printf("Error: Failed to open file at \"%s\".\n", path);
        exit(1);
    }
    
    // Get the backup file path
    char* backup_path = get_backup_path(path);
    
    FILE* output_file = fopen(backup_path, "w");
    if (output_file == NULL) {
        printf("Error: Failed to create backup file at \"%s\".\n", backup_path);
        exit(1);
    }
    
    char buffer[MAX_FILE_LEN];
    size_t bytes_read;
    do {
        bytes_read = fread(buffer, sizeof(char), MAX_FILE_LEN, input_file);
        fwrite(buffer, sizeof(char), bytes_read, output_file);
    } while (bytes_read == MAX_FILE_LEN);
    
    fclose(input_file);
    fclose(output_file);
    
    printf("File backed up successfully to \"%s\".\n", backup_path);
    free(backup_path);
    
    return 0;
}