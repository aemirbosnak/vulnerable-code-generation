//FormAI DATASET v1.0 Category: File Synchronizer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void synchronize(char *source_path, char *destination_path){
    DIR *source_directory, *destination_directory;
    struct dirent *toc;
    struct stat st;
    char buffer[BUFFER_SIZE];
    char source[1024];
    char destination[1024];

    source_directory = opendir(source_path);
    destination_directory = opendir(destination_path);

    if(source_directory == NULL || destination_directory == NULL){
        printf("Error opening directory.\n");
        exit(EXIT_FAILURE);
    }

    while((toc = readdir(source_directory)) != NULL){
        if(strcmp(toc->d_name, ".") != 0 && strcmp(toc->d_name, "..") != 0){
            sprintf(source, "%s/%s", source_path, toc->d_name);
            sprintf(destination, "%s/%s", destination_path, toc->d_name);

            if(stat(source, &st) == -1){
                printf("Error getting status of %s\n", source);
                continue;
            }

            if(S_ISREG(st.st_mode)){
                FILE *source_file, *destination_file;
                source_file = fopen(source, "rb");

                if(source_file == NULL){
                    printf("Error opening file %s\n", source);
                    continue;
                }

                destination_file = fopen(destination, "rb");

                if(destination_file == NULL){
                    destination_file = fopen(destination, "wb");

                    if(destination_file == NULL){
                        printf("Error opening file %s\n", destination);
                        fclose(source_file);
                        continue;
                    }
                }

                fseek(destination_file, 0L, SEEK_END);
                long dest_size = ftell(destination_file);
                fseek(destination_file, 0L, SEEK_SET);
                long src_size = st.st_size;

                if(src_size != dest_size){
                    printf("The sizes of %s and %s differ. Copying...\n", source, destination);
                    fseek(source_file, 0L, SEEK_END);
                    long fileSize = ftell(source_file);
                    fseek(source_file, 0L, SEEK_SET);

                    while(fileSize > 0){
                        int bytesRead = fread(buffer, 1, BUFFER_SIZE, source_file);
                        fwrite(buffer, 1, bytesRead, destination_file);
                        fileSize -= bytesRead;
                    }

                    printf("File copied successfully.\n");
                }
                else{
                    printf("File already exists in destination directory. Skipping...\n");
                }
            }
            else if(S_ISDIR(st.st_mode)){
                mkdir(destination, 0700);
                synchronize(source, destination);
            }
        }
    }

    closedir(source_directory);
    closedir(destination_directory);
}

int main(int argc, char **argv){
    if(argc < 3){
        printf("Not enough arguments provided.\n");
        printf("Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *source_path = argv[1];
    char *destination_path = argv[2];

    synchronize(source_path, destination_path);

    printf("Synchronization complete.\n");

    return 0;
}