//FormAI DATASET v1.0 Category: File Synchronizer ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

#define BUFF_SIZE 1024

void synchronize(char *src, char *dest);

int main(int argc, char** argv){

    if(argc != 3){
        printf("Usage: %s <source_dir> <destination_dir>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *src = argv[1];
    char *dest = argv[2];

    printf("Synchronizing %s with %s...\n", src, dest);

    synchronize(src, dest);

    printf("Synchronization complete!\n");

    return EXIT_SUCCESS;
}

void synchronize(char *src, char *dest){

    DIR *dir = opendir(src);

    struct dirent *dp;
    char src_path[BUFF_SIZE] = {'\0'};
    char dest_path[BUFF_SIZE] = {'\0'};

    while((dp = readdir(dir)) != NULL){

        if(strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0){

            snprintf(src_path, BUFF_SIZE, "%s/%s", src, dp->d_name);

            snprintf(dest_path, BUFF_SIZE, "%s/%s", dest, dp->d_name);

            struct stat sbuf_src;
            stat(src_path, &sbuf_src);
            time_t src_mtime = sbuf_src.st_mtime;

            struct stat sbuf_dest;
            if(stat(dest_path, &sbuf_dest) == 0){
                time_t dest_mtime = sbuf_dest.st_mtime;
                if(src_mtime > dest_mtime){
                    printf("Copying %s to %s\n", src_path, dest_path);
                    unlink(dest_path);
                    link(src_path, dest_path);
                }
            }
            else{
                printf("Copying %s to %s\n", src_path, dest_path);
                link(src_path, dest_path);
            }

            if(S_ISDIR(sbuf_src.st_mode)){
                synchronize(src_path, dest_path);
            }
        }
    }
    closedir(dir);
}