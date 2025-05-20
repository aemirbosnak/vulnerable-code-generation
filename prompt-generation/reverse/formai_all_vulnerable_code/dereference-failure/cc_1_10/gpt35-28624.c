//FormAI DATASET v1.0 Category: File Synchronizer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

void copy_file(char *src, char *dst) {
    FILE *fsrc = fopen(src, "r");
    FILE *fdst = fopen(dst, "w");

    if(fsrc == NULL || fdst == NULL) {
        printf("Error opening file!\n");
        return;
    }

    int read_char;
    while((read_char = fgetc(fsrc)) != EOF) {
        fputc(read_char, fdst);
    }

    fclose(fsrc);
    fclose(fdst);
}

void sync_files(char *src_path, char *dst_path) {
    DIR *src_dir = opendir(src_path);
    if(src_dir == NULL) {
        perror("src directory does not exist");
        exit(EXIT_FAILURE);
    }

    DIR *dst_dir = opendir(dst_path);
    if(dst_dir == NULL) {
        mkdir(dst_path, 0777);
        printf("dst directory created \n");
        dst_dir = opendir(dst_path);
    }

    struct dirent *ent;
    while((ent = readdir(src_dir)) != NULL) {
        if(strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
            continue;
        }

        char src_file_path[1000];
        sprintf(src_file_path, "%s/%s", src_path, ent->d_name);

        char dst_file_path[1000];
        sprintf(dst_file_path, "%s/%s", dst_path, ent->d_name);

        struct stat st;
        if(stat(src_file_path, &st) != 0) {
            printf("src file stat failed");
            continue;
        }

        if(S_ISDIR(st.st_mode)) {
            sync_files(src_file_path, dst_file_path);
        } else {
            struct stat dst_st;
            int exists = stat(dst_file_path, &dst_st) == 0;
            if(!exists || st.st_mtime > dst_st.st_mtime) {
                copy_file(src_file_path, dst_file_path);
                if(exists) {
                    printf("%s updated \n", dst_file_path);
                } else {
                    printf("%s created \n", dst_file_path);
                }
            }
        }
    }

    closedir(src_dir);
    closedir(dst_dir);
}

int main(int argc, char **argv) {
    if(argc < 3) {
        printf("Please provide both source and destination directories");
        exit(EXIT_FAILURE);
    }

    sync_files(argv[1], argv[2]);

    return EXIT_SUCCESS;
}