//FormAI DATASET v1.0 Category: File Synchronizer ; Style: systematic
/*
* C File Synchronizer Example Program:
* This program synchronizes two directories. It compares two directories (source and destination),
* and copies any files from the source directory to the destination directory, if they are not already there,
* or if they have been modified since the last synchronization. It also deletes any files in the destination
* directory that no longer exist in the source directory.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

// function prototypes
void synchronize(char* source_dir, char* dest_dir);
void copy_file(char* source_path, char* dest_path);
void delete_file(char* file_path);
int is_directory(char* path);
int is_hidden(char* file_name);
int is_newer(char* path1, char* path2);

// the main function
int main(int argc, char* argv[]) {
    if(argc != 3) {
        printf("Usage: ./sync [source directory] [destination directory]\n");
        return 0;
    }

    char* source_dir = argv[1];
    char* dest_dir = argv[2];

    // check if source directory exists and is a directory
    struct stat s;
    if(stat(source_dir, &s) != 0) {
        printf("Source directory does not exist.\n");
        return 0;
    } else if(!S_ISDIR(s.st_mode)) {
        printf("Source is not a directory.\n");
        return 0;
    }

    // check if destination directory exists and is a directory
    if(stat(dest_dir, &s) != 0) {
        printf("Destination directory does not exist.\n");
        return 0;
    } else if(!S_ISDIR(s.st_mode)) {
        printf("Destination is not a directory.\n");
        return 0;
    }

    synchronize(source_dir, dest_dir);
    printf("Synchronization complete.\n");

    return 0;
}

// function that synchronizes two directories
void synchronize(char* source_dir, char* dest_dir) {
    DIR* source_dp = opendir(source_dir);
    if(source_dp == NULL) {
        printf("Error opening source directory.\n");
        return;
    }

    DIR* dest_dp = opendir(dest_dir);
    if(dest_dp == NULL) {
        printf("Error opening destination directory.\n");
        return;
    }

    struct dirent* source_entry;
    while((source_entry = readdir(source_dp)) != NULL) {
        char* source_name = source_entry->d_name;
        if(strlen(source_name) <= 2 || is_hidden(source_name)) {
            continue;
        }

        char source_path[256];
        sprintf(source_path, "%s/%s", source_dir, source_name);

        if(is_directory(source_path)) {
            // recurse on subdirectories
            char dest_path[256];
            sprintf(dest_path, "%s/%s", dest_dir, source_name);
            if(!is_directory(dest_path)) {
                mkdir(dest_path, 0777); // create subdirectory if it does not exist
            }
            synchronize(source_path, dest_path);
        } else {
            char dest_path[256];
            sprintf(dest_path, "%s/%s", dest_dir, source_name);
            struct stat s_dest;
            if(stat(dest_path, &s_dest) != 0 || is_newer(source_path, dest_path)) {
                copy_file(source_path, dest_path); // copy file if it does not exist in destination directory or if it has been modified
            }
        }
    }

    struct dirent* dest_entry;
    while((dest_entry = readdir(dest_dp)) != NULL) {
        char* dest_name = dest_entry->d_name;
        if(strlen(dest_name) <= 2 || is_hidden(dest_name)) {
            continue;
        }

        char dest_path[256];
        sprintf(dest_path, "%s/%s", dest_dir, dest_name);

        if(is_directory(dest_path)) {
            // do nothing
        } else {
            char source_path[256];
            sprintf(source_path, "%s/%s", source_dir, dest_name);
            struct stat s_source;
            if(stat(source_path, &s_source) != 0) {
                delete_file(dest_path); // delete file if it doesn't exist in source directory
            }
        }
    }

    closedir(source_dp);
    closedir(dest_dp);
}

// function that copies a file from source path to destination path
void copy_file(char* source_path, char* dest_path) {
    char buffer[1024];
    FILE* source = fopen(source_path, "rb");
    FILE* dest = fopen(dest_path, "wb");
    if(source == NULL || dest == NULL) {
        printf("Error opening file.\n");
        return;
    }

    size_t nread;
    while((nread = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, nread, dest);
    }

    fclose(source);
    fclose(dest);
}

// function that deletes a file at a given path
void delete_file(char* file_path) {
    remove(file_path);
}

// function that checks whether a given path is a directory
int is_directory(char* path) {
    struct stat s;
    if(stat(path, &s) != 0) {
        return 0;
    } else {
        return S_ISDIR(s.st_mode);
    }
}

// function that checks whether a given file name is a hidden file
int is_hidden(char* file_name) {
    if(file_name[0] == '.') {
        return 1;
    } else {
        return 0;
    }
}

// function that checks whether a file at path1 is newer than a file at path2
int is_newer(char* path1, char* path2) {
    struct stat s1, s2;
    if(stat(path1, &s1) != 0 || stat(path2, &s2) != 0) {
        return 0;
    } else {
        return difftime(s1.st_mtime, s2.st_mtime) > 0;
    }
}