//FormAI DATASET v1.0 Category: File Synchronizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>

void synchronize(char *source_dir, char *destination_dir);

int main(int argc, char *argv[])
{
    if(argc != 3){
        printf("Usage: ./sync <source directory> <destination directory>");
        exit(1);
    }

    char *source_dir = argv[1];
    char *destination_dir = argv[2];

    synchronize(source_dir, destination_dir);

    return 0;
}

void synchronize(char *source_dir, char *destination_dir)
{
    DIR *dir_source, *dir_destination;
    struct dirent *entry_source, *entry_destination;
    struct stat stat_source, stat_destination;
    char buffer[1024];

    // Open source directory
    if((dir_source = opendir(source_dir)) == NULL){
        printf("Error: Unable to open directory %s - %s\n", source_dir, strerror(errno));
        exit(1);
    }

    // Open destination directory
    if((dir_destination = opendir(destination_dir)) == NULL){
        printf("Error: Unable to open directory %s - %s\n", destination_dir, strerror(errno));
        exit(1);
    }

    // Iterate through source directory
    while((entry_source = readdir(dir_source)) != NULL){
        // Skip over "." and ".." directories
        if(strcmp(entry_source->d_name, ".") == 0 || strcmp(entry_source->d_name, "..") == 0){
            continue;
        }
        
        // Build full path for source file
        snprintf(buffer, sizeof(buffer), "%s/%s", source_dir, entry_source->d_name);

        // Get file status for source file
        if(stat(buffer, &stat_source) < 0){
            printf("Error: Unable to get status of file %s - %s\n", buffer, strerror(errno));
            continue;
        }

        // If source is a directory, recursively call synchronize function again
        if(S_ISDIR(stat_source.st_mode)){
            synchronize(buffer, destination_dir);
            continue;
        }

        // Build full path for destination file
        snprintf(buffer, sizeof(buffer), "%s/%s", destination_dir, entry_source->d_name);

        // Get file status for destination file
        if(stat(buffer, &stat_destination) < 0){
            // If destination file does not exist, copy the file over
            if(errno == ENOENT){
                FILE *source_file, *destination_file;
                if((source_file = fopen(entry_source->d_name, "rb")) == NULL){
                    printf("Error: Unable to open source file %s - %s\n", entry_source->d_name, strerror(errno));
                    continue;
                }

                if((destination_file = fopen(buffer, "wb")) == NULL){
                    printf("Error: Unable to open destination file %s - %s\n", buffer, strerror(errno));
                    fclose(source_file);
                    continue;
                }

                int read_size;
                char read_buffer[1024];
                while((read_size = fread(read_buffer, 1, sizeof(read_buffer), source_file)) > 0){
                    fwrite(read_buffer, 1, read_size, destination_file);
                }

                fclose(source_file);
                fclose(destination_file);
            }
            // If there's an error getting the status for any other reason, print an error
            else{
                printf("Error: Unable to get status of file %s - %s\n", buffer, strerror(errno));
                continue;
            }
        }
        // If destination file exists and is newer than source file, skip this file
        else if(stat_destination.st_mtime >= stat_source.st_mtime){
            continue;
        }
        // If destination file exists and is older than source file, open both files and copy the data over
        else{
            FILE *source_file, *destination_file;
            if((source_file = fopen(entry_source->d_name, "rb")) == NULL){
                printf("Error: Unable to open source file %s - %s\n", entry_source->d_name, strerror(errno));
                continue;
            }

            if((destination_file = fopen(buffer, "wb")) == NULL){
                printf("Error: Unable to open destination file %s - %s\n", buffer, strerror(errno));
                fclose(source_file);
                continue;
            }

            int read_size;
            char read_buffer[1024];
            while((read_size = fread(read_buffer, 1, sizeof(read_buffer), source_file)) > 0){
                fwrite(read_buffer, 1, read_size, destination_file);
            }

            fclose(source_file);
            fclose(destination_file);
        }
    }

    closedir(dir_source);
    closedir(dir_destination);
}