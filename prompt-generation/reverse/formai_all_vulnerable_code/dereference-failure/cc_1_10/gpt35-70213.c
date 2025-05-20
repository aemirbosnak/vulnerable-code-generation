//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#define MAX_BUFFER_SIZE 1024
#define MAX_FILENAME_SIZE 256
#define MAX_EXTENSION_SIZE 16

void scan_file(char *filename);
void scan_directory(char *dirname);

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: ./antivirus <directory_name>\n");
        exit(1);
    }

    char *dirname = argv[1];
    scan_directory(dirname);
    printf("Scanning completed.\n");

    return 0;
}

void scan_file(char *filename) {
    char buffer[MAX_BUFFER_SIZE];
    char extension[MAX_EXTENSION_SIZE];
    FILE *fp;

    fp = fopen(filename, "rb");
    if(fp == NULL) {
        return;
    }

    fgets(buffer, sizeof(buffer), fp);
    fclose(fp);

    // Check if file is infected
    if(strstr(buffer, "virus") != NULL) {
        printf("Infected file detected: %s\n", filename);
    }

    // Check file extension
    char *extension_ptr = strrchr(filename, '.');
    if(extension_ptr == NULL) {
        return;
    }

    strcpy(extension, extension_ptr+1);
    if(strcmp(extension, "exe") == 0) {
        printf("Executable file detected: %s\n", filename);
    }
}

void scan_directory(char *dirname) {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(dirname);
    if(dir == NULL) {
        return;
    }

    while((entry = readdir(dir)) != NULL) {
        char filepath[MAX_FILENAME_SIZE];
        strcpy(filepath, dirname);
        strcat(filepath, "/");
        strcat(filepath, entry->d_name);

        // Ignore hidden files and directories
        if(entry->d_name[0] == '.') {
            continue;
        }

        // Recursively scan subdirectories
        if(entry->d_type == DT_DIR) {
            scan_directory(filepath);
        }
        else {
            scan_file(filepath);
        }
    }

    closedir(dir);
}