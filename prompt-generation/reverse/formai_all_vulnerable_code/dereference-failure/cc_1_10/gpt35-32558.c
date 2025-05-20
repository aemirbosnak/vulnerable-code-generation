//FormAI DATASET v1.0 Category: File Backup System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

void backup_file(char *backup_dir_path, char *file_path);
int get_file_size(char *file_path);

int main(int argc, char **argv){
    if(argc != 3){
        printf("Usage: ./backup <directory to backup> <backup directory path>\n");
        return 1;
    }

    char *path = argv[1];
    char *backup_path = argv[2];
    backup_file(backup_path, path);
    printf("Backup Successful!\n");

    return 0;
}

void backup_file(char *backup_dir_path, char *file_path){
    // Extract the filename from the file path
    char *file_name = strrchr(file_path, '/') + 1;

    // Create the destination path for the backup
    char dest_path[MAX_BUFFER_SIZE];
    strcpy(dest_path, backup_dir_path);
    strcat(dest_path, "/");
    strcat(dest_path, file_name);

    // Check if the backup file already exists
    if(access(dest_path, F_OK) != -1){
        int file_size = get_file_size(file_path);
        int backup_size = get_file_size(dest_path);

        // If the size of the backup and original file match, return
        if(file_size == backup_size){
            printf("File already backed up. Nothing to do.\n");
            return;
        }
    }

    FILE *src_file = fopen(file_path, "rb");
    FILE *dest_file = fopen(dest_path, "wb");

    if(src_file == NULL || dest_file == NULL){
        printf("Could not open file. Please check permissions.\n");
        return;
    }

    char buffer[MAX_BUFFER_SIZE];
    size_t bytes_read;

    while((bytes_read = fread(buffer, sizeof(char), MAX_BUFFER_SIZE, src_file)) > 0){
        fwrite(buffer, sizeof(char), bytes_read, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);
}

int get_file_size(char *file_path){
    FILE *file = fopen(file_path, "rb");

    if(file == NULL){
        return -1;
    }

    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    fclose(file);

    return file_size;
}