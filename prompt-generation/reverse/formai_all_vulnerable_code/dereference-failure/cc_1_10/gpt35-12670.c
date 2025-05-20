//FormAI DATASET v1.0 Category: File Synchronizer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>

// function to compare the files
int compare_files(FILE *file1, FILE *file2) {
    int byte1, byte2;
    do {
        byte1 = getc(file1);
        byte2 = getc(file2);
    } while ((byte1 != EOF) && (byte1 == byte2));
    return (byte1 == byte2);
}

// function to copy file
void copy_file(char *src_path, char *dest_path){
    FILE *src_file, *dest_file;

    // open the source file in read mode and destination file in write mode
    src_file = fopen(src_path, "r");
    dest_file = fopen(dest_path, "w");

    // copy the contents
    int c;
    while ((c = getc(src_file)) != EOF){
        putc(c, dest_file);
    }

    // close the opened files
    fclose(src_file);
    fclose(dest_file);
}

// function to recursively traverse the directories
void traverse_and_copy(char *src_dir, char *dest_dir){
    DIR *dir;
    struct dirent *entry;
    char *src_file_path = malloc(sizeof(char *));
    char *dest_file_path = malloc(sizeof(char *));

    // open the source directory
    if ((dir = opendir(src_dir)) != NULL) {
        // loop through all the files and directories
        while ((entry = readdir(dir)) != NULL) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                // create source and destination file paths
                sprintf(src_file_path, "%s/%s", src_dir, entry->d_name);
                sprintf(dest_file_path, "%s/%s", dest_dir, entry->d_name);
                
                if (entry->d_type == DT_DIR) {
                    // if it is a directory, create the same directory in the destination folder
                    mkdir(dest_file_path, 0777);
                    // recursively call the traverse function on the new directory
                    traverse_and_copy(src_file_path, dest_file_path);
                } else if (entry->d_type == DT_REG) {
                    // if it is a file, check if it exists in destination folder
                    FILE *src_file, *dest_file;
                    src_file = fopen(src_file_path, "r");
                    dest_file = fopen(dest_file_path, "r");
                    if (dest_file == NULL) {
                        // if the file does not exist, copy it to destination folder
                        copy_file(src_file_path, dest_file_path);
                        printf("Copied %s to %s\n", src_file_path, dest_file_path);
                    } else {
                        // if the file exists, compare the contents of the files
                        if (!compare_files(src_file, dest_file)) {
                            // if the contents are different, copy the file to destination folder
                            copy_file(src_file_path, dest_file_path);
                            printf("Copied %s to %s\n", src_file_path, dest_file_path);
                        }
                    }
                    fclose(src_file);
                    fclose(dest_file);
                }
            }
        }
        closedir(dir);
    } else {
        perror("Error: ");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Invalid arguments\n");
        printf("Usage: %s [Source Directory] [Destination Directory]\n", argv[0]);
    } else {
        // traverse the source directory and copy the files to the destination directory
        traverse_and_copy(argv[1], argv[2]);
        printf("Files synchronized successfully\n");
    }
    return 0;
}