//FormAI DATASET v1.0 Category: File Synchronizer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void synchronize(char *source, char *destination){
    struct dirent *entry;
    DIR *dir = opendir(source);
    if(dir == NULL){
        printf("Source directory cannot be opened.\n");
        return;
    }

    mkdir(destination, 0700); //Create the destination directory if it doesn't exist

    while((entry = readdir(dir)) != NULL){
        char path_src[1024];
        char path_dst[1024];

        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0){
            continue;
        }

        sprintf(path_src, "%s/%s", source, entry->d_name);
        sprintf(path_dst, "%s/%s", destination, entry->d_name);

        struct stat stat_src;
        if(stat(path_src, &stat_src) == -1){
            printf("Error reading file stats: %s.\n", path_src);
            continue;
        }

        if(S_ISDIR(stat_src.st_mode)){ //If the entry is a directory, recursively synchronize it
            synchronize(path_src, path_dst);
        }
        else if(S_ISREG(stat_src.st_mode)){ //If the entry is a regular file, copy it to the destination directory
            FILE *fsrc = fopen(path_src, "rb");
            if(fsrc == NULL){
                printf("Error opening source file: %s.\n", path_src);
                continue;
            }

            FILE *fdst = fopen(path_dst, "wb");
            if(fdst == NULL){
                printf("Error opening destination file: %s.\n", path_dst);
                continue;
            }

            while(1){
                char buffer[1024];
                size_t bytes_read = fread(buffer, 1, sizeof(buffer), fsrc);
                if(bytes_read == 0){ //EOF reached
                    break;
                }

                fwrite(buffer, 1, bytes_read, fdst);
            }

            fclose(fsrc);
            fclose(fdst);

            printf("File copied: %s.\n", path_src);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]){
    if(argc < 3){
        printf("Usage: ./sync <source directory> <destination directory>\n");
        return 1;
    }

    synchronize(argv[1], argv[2]);

    printf("Synchronization complete!\n");

    return 0;
}