//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void print_welcome_message() {
    printf("=======================================\n");
    printf("       C File Backup System           \n");
    printf("         by Ada Lovelace Style        \n");
    printf("=======================================\n");
}

void display_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void copy_file(const char *src_file, const char *dest_file) {
    FILE *src = fopen(src_file, "rb");
    if (src == NULL) {
        display_error("Failed to open source file");
    }
    
    FILE *dest = fopen(dest_file, "wb");
    if (dest == NULL) {
        fclose(src);
        display_error("Failed to open destination file");
    }
    
    char buffer[BUFFER_SIZE];
    size_t bytes;
    
    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }
    
    fclose(src);
    fclose(dest);
    printf("File %s backed up to %s\n", src_file, dest_file);
}

void backup_directory(const char *src_dir, const char *dest_dir) {
    DIR *dir = opendir(src_dir);
    if (dir == NULL) {
        display_error("Failed to open source directory");
    }
    
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue; // Skip hidden files and directories
        }
        
        char src_path[1024];
        char dest_path[1024];
        
        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);
        
        if (entry->d_type == DT_DIR) {
            mkdir(dest_path, 0755); // Create directory in destination
            backup_directory(src_path, dest_path); // Recur into subdirectory
        } else if (entry->d_type == DT_REG) {
            copy_file(src_path, dest_path); // Copy the file
        }
    }
    
    closedir(dir);
}

int main(int argc, char *argv[]) {
    print_welcome_message();
    
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    const char *src_directory = argv[1];
    const char *dest_directory = argv[2];
    
    mkdir(dest_directory, 0755); // Create destination directory if it doesn't exist
    
    backup_directory(src_directory, dest_directory);
    
    printf("Backup completed successfully!\n");
    return 0;
}