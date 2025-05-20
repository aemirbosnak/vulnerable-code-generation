//FormAI DATASET v1.0 Category: File Backup System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void backup(char *source, char *destination) {
    DIR *source_dir, *dest_dir;
    struct dirent *entry;
    char source_path[PATH_MAX], dest_path[PATH_MAX];
    
    source_dir = opendir(source);
    dest_dir = opendir(destination);
    
    if (!source_dir || !dest_dir) {
        perror("Error opening directory");
        return;
    }
    
    while ((entry = readdir(source_dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        snprintf(source_path, PATH_MAX, "%s/%s", source, entry->d_name);
        snprintf(dest_path, PATH_MAX, "%s/%s", destination, entry->d_name);
        
        if (entry->d_type == DT_DIR) {
            // create directory in destination
            mkdir(dest_path, 0777);
            // recursively backup directory
            backup(source_path, dest_path); 
        } else {
            // open source file
            FILE *source_file = fopen(source_path, "rb");
            if (!source_file) {
                perror("Error opening source file");
                continue;
            }
            // create destination file
            FILE *dest_file = fopen(dest_path, "wb");
            if (!dest_file) {
                perror("Error creating destination file");
                continue;
            }
            // copy contents of source file to destination file
            char buffer[1024];
            size_t bytes_read;
            while ((bytes_read = fread(buffer, 1, sizeof(buffer), source_file))) {
                fwrite(buffer, 1, bytes_read, dest_file);  
            }
            fclose(source_file);
            fclose(dest_file);
        }
    }
    
    closedir(source_dir);
    closedir(dest_dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_dir> <destination_dir>\n", argv[0]);
        return 1;
    }
    
    backup(argv[1], argv[2]);
    
    printf("Backup successful!\n");
    return 0;
}