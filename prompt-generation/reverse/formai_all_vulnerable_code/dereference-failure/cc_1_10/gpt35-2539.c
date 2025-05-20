//FormAI DATASET v1.0 Category: File Synchronizer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_PATH_LENGTH 500
#define MAX_FILE_SIZE 10000000

void sync_files(char *src_path, char *dest_path) {
    DIR *src_dir = opendir(src_path);
    DIR *dest_dir = opendir(dest_path);

    if(!src_dir) {
        printf("Cannot open source directory.\n");
        return;
    }

    if(!dest_dir) {
        printf("Creating destination directory.\n");
        mkdir(dest_path, S_IRWXU | S_IRWXG | S_IRWXO);
        dest_dir = opendir(dest_path);
    }

    struct dirent *ent;
    while((ent = readdir(src_dir)) != NULL) {
        char src_file[MAX_PATH_LENGTH];
        char dest_file[MAX_PATH_LENGTH];

        if(strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
            continue;
        }

        snprintf(src_file, MAX_PATH_LENGTH, "%s/%s", src_path, ent->d_name);
        snprintf(dest_file, MAX_PATH_LENGTH, "%s/%s", dest_path, ent->d_name);

        struct stat src_stat, dest_stat;
        if(stat(src_file, &src_stat) == -1) {
            printf("Cannot access source file \"%s\".\n", src_file);
            continue;
        }

        int src_size = src_stat.st_size;

        int should_copy = 0;
        if(access(dest_file, F_OK) == -1) {
            should_copy = 1;
        } else if(stat(dest_file, &dest_stat) == -1) {
            printf("Cannot access destination file \"%s\".\n", dest_file);
            continue;
        } else {
            int dest_size = dest_stat.st_size;
            if(src_size != dest_size) {
                should_copy = 1;
            } else {
                FILE *src = fopen(src_file, "rb");
                FILE *dest = fopen(dest_file, "rb");

                char *src_contents = malloc(MAX_FILE_SIZE);
                char *dest_contents = malloc(MAX_FILE_SIZE);
                if(!src_contents || !dest_contents) {
                    printf("Memory allocation failed for file \"%s\".\n", src_file);
                    continue;
                }

                fread(src_contents, sizeof(char), src_size, src);
                fread(dest_contents, sizeof(char), dest_size, dest);

                should_copy = memcmp(src_contents, dest_contents, src_size);

                free(src_contents);
                free(dest_contents);
                fclose(src);
                fclose(dest);
            }
        }

        if(should_copy) {
            printf("Copying \"%s\" to \"%s\".\n", src_file, dest_file);
            FILE *src = fopen(src_file, "rb");
            FILE *dest = fopen(dest_file, "wb");

            char buffer[MAX_FILE_SIZE];
            int bytes_read = 0;
            while((bytes_read = fread(buffer, sizeof(char), MAX_FILE_SIZE, src))) {
                fwrite(buffer, sizeof(char), bytes_read, dest);
            }

            fclose(src);
            fclose(dest);
        }
    }

    closedir(src_dir);
    closedir(dest_dir);

    printf("Done.\n");
}

int main(int argc, char **argv) {
    if(argc != 3) {
        printf("Usage: ./sync [source directory] [destination directory]\n");
        return 0;
    }

    char src_path[MAX_PATH_LENGTH];
    realpath(argv[1], src_path);

    char dest_path[MAX_PATH_LENGTH];
    realpath(argv[2], dest_path);

    sync_files(src_path, dest_path);

    return 0;
}