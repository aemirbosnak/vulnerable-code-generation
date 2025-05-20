//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>
#include<unistd.h>

#define BUF_SIZE 1024 // buffer size for storing file/directory names

// Function to synchronize two directories
void sync_dirs(char* src_dir, char* dest_dir) {
    DIR* dir_src = opendir(src_dir);
    DIR* dir_dest = opendir(dest_dir);
    struct dirent* ent_src;
    struct dirent* ent_dest;

    // Check if source and destination directories exist
    if (dir_src == NULL || dir_dest == NULL) {
        printf("Invalid directory path.\n");
        exit(1);
    }

    // Create destination directory if it doesn't exist
    if (mkdir(dest_dir, 0777)!= 0) {
        printf("Error creating directory.\n");
        exit(1);
    }

    // Loop through source directory and sync files/directories with destination directory
    while ((ent_src = readdir(dir_src))!= NULL) {
        char src_file[BUF_SIZE];
        char dest_file[BUF_SIZE];
        strcpy(src_file, src_dir);
        strcat(src_file, "/");
        strcat(src_file, ent_src->d_name);

        strcpy(dest_file, dest_dir);
        strcat(dest_file, "/");
        strcat(dest_file, ent_src->d_name);

        // Check if it's a file or directory
        if (ent_src->d_type == DT_DIR) {
            sync_dirs(src_file, dest_file);
        } else {
            // Copy file from source to destination directory
            FILE* src_file_ptr = fopen(src_file, "r");
            FILE* dest_file_ptr = fopen(dest_file, "w");

            if (src_file_ptr == NULL || dest_file_ptr == NULL) {
                printf("Error opening file.\n");
                exit(1);
            }

            char buf[BUF_SIZE];
            while (fgets(buf, BUF_SIZE, src_file_ptr)!= NULL) {
                fputs(buf, dest_file_ptr);
            }

            fclose(src_file_ptr);
            fclose(dest_file_ptr);
        }
    }

    closedir(dir_src);
    closedir(dir_dest);
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage:./program <source_directory> <destination_directory>\n");
        exit(1);
    }

    sync_dirs(argv[1], argv[2]);

    return 0;
}