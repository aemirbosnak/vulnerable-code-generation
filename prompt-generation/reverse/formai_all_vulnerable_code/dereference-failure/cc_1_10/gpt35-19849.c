//FormAI DATASET v1.0 Category: File Synchronizer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void synchronize_files(char* source_path, char* target_path);

int main(int argc, char* argv[]) {
    if(argc < 3) {
        printf("Usage: %s <source_directory> <target_directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    synchronize_files(argv[1], argv[2]);

    printf("Synchronization Complete.\n");

    return 0;
}

void synchronize_files(char* source_path, char* target_path) {
    DIR* source_dir = opendir(source_path);

    if(source_dir == NULL) {
        printf("%s is not a directory.\n", source_path);
        exit(EXIT_FAILURE);
    }

    DIR* target_dir = opendir(target_path);

    if(target_dir == NULL) {
        printf("%s is not a directory.\n", target_path);
        exit(EXIT_FAILURE);
    }

    struct dirent* source_dir_ent;
    struct dirent* target_dir_ent;

    while((source_dir_ent = readdir(source_dir)) != NULL) {
        if(source_dir_ent->d_name[0] == '.') continue;
        char source_file_path[255];
        char target_file_path[255];

        strncpy(source_file_path, source_path, sizeof(source_file_path));
        strncpy(target_file_path, target_path, sizeof(target_file_path));

        strncat(source_file_path, "/", sizeof(source_file_path));
        strncat(target_file_path, "/", sizeof(target_file_path));

        strncat(source_file_path, source_dir_ent->d_name, sizeof(source_file_path));
        strncat(target_file_path, source_dir_ent->d_name, sizeof(target_file_path));

        struct stat source_file_stat;
        struct stat target_file_stat;

        if(stat(source_file_path, &source_file_stat) == -1) {
            printf("Error accessing %s\n", source_file_path);
            continue;
        }

        int target_exists = (stat(target_file_path, &target_file_stat) == 0);

        if(S_ISDIR(source_file_stat.st_mode)) {
            if(!target_exists) {
                if(mkdir(target_file_path, source_file_stat.st_mode) == -1) {
                    printf("Error creating directory %s\n", target_file_path);
                    continue;
                }
            }
            synchronize_files(source_file_path, target_file_path);
        } else {
            if(!target_exists) {
                printf("%s does not exist. Copying...\n", target_file_path);

                FILE* source_file = fopen(source_file_path, "rb");
                FILE* target_file = fopen(target_file_path, "wb");

                if(target_file == NULL) {
                    printf("Error creating %s\n", target_file_path);
                    continue;
                }

                char buffer[1024];
                size_t size;
                while((size = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
                    fwrite(buffer, 1, size, target_file);
                }

                fclose(source_file);
                fclose(target_file);
            } else {
                if(source_file_stat.st_mtime > target_file_stat.st_mtime) {
                    printf("%s is out of date. Updating...\n", target_file_path);

                    FILE* source_file = fopen(source_file_path, "rb");
                    FILE* target_file = fopen(target_file_path, "wb");

                    if(target_file == NULL) {
                        printf("Error creating %s\n", target_file_path);
                        continue;
                    }

                    char buffer[1024];
                    size_t size;
                    while((size = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
                        fwrite(buffer, 1, size, target_file);
                    }

                    fclose(source_file);
                    fclose(target_file);
                }
            }
        }
    }

    closedir(source_dir);
    closedir(target_dir);
}