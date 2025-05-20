//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void sync_files(char* source_dir, char* dest_dir) {
    DIR *src_dir = opendir(source_dir);
    struct dirent *ent;
    char path[1024];
    char dest_path[1024];
    if (src_dir == NULL) {
        printf("Error: %s is not a valid directory\n", source_dir);
        exit(1);
    }

    while ((ent = readdir(src_dir))!= NULL) {
        strcpy(path, source_dir);
        strcat(path, "/");
        strcat(path, ent->d_name);

        struct stat st_src, st_dest;
        stat(path, &st_src);

        strcpy(dest_path, dest_dir);
        strcat(dest_path, "/");
        strcat(dest_path, ent->d_name);

        stat(dest_path, &st_dest);

        if (S_ISDIR(st_src.st_mode)) {
            if (!S_ISDIR(st_dest.st_mode)) {
                mkdir(dest_path, 0777);
            }
            sync_files(path, dest_path);
        } else if (S_ISREG(st_src.st_mode)) {
            if (!S_ISREG(st_dest.st_mode)) {
                FILE* file = fopen(dest_path, "w");
                fclose(file);
            }
            FILE* src_file = fopen(path, "r");
            FILE* dest_file = fopen(dest_path, "a");

            char buffer[BUFFER_SIZE];
            while (fgets(buffer, BUFFER_SIZE, src_file)!= NULL) {
                fputs(buffer, dest_file);
            }

            fclose(src_file);
            fclose(dest_file);
        }
    }

    closedir(src_dir);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        exit(1);
    }

    char* source_dir = argv[1];
    char* dest_dir = argv[2];

    sync_files(source_dir, dest_dir);

    printf("File synchronization complete!\n");
    return 0;
}