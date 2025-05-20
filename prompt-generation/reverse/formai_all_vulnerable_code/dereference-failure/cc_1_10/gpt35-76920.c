//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: scientific
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_BUFFER_LENGTH 2048

void scanFile(char* filename);
void scanDirectory(char* path);

int isInfected(char* buffer);

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Invalid arguments! Usage: ./antivirus <path>\n");
        exit(1);
    }

    char* path = argv[1];

    scanDirectory(path);

    printf("Scan completed!\n");

    return 0;
}

void scanFile(char* filename) {
    FILE* file = fopen(filename, "r");

    if(file == NULL) {
        printf("Unable to open file: %s\n", filename);
        return;
    }

    char buffer[MAX_BUFFER_LENGTH];

    if(fgets(buffer, MAX_BUFFER_LENGTH, file)) {
        if(isInfected(buffer)) {
            printf("Virus found in file: %s\n", filename);
            fclose(file);
            return;
        }
    }

    fclose(file);
}

void scanDirectory(char* path) {
    DIR* directory = opendir(path);

    if(directory != NULL) {
        struct dirent* entry = readdir(directory);

        while(entry) {
            if(entry->d_type == DT_REG) {
                char* filename = entry->d_name;
                if(strlen(filename) < MAX_FILENAME_LENGTH) {
                    char filepath[MAX_FILENAME_LENGTH];
                    strcpy(filepath, path);
                    strcat(filepath, "/");
                    strcat(filepath, filename);

                    scanFile(filepath);
                }
            } else if(entry->d_type == DT_DIR) {
                char* dirname = entry->d_name;
                if(strcmp(dirname, ".") != 0 && strcmp(dirname, "..") != 0) {
                    char dirpath[MAX_FILENAME_LENGTH];
                    strcpy(dirpath, path);
                    strcat(dirpath, "/");
                    strcat(dirpath, dirname);

                    scanDirectory(dirpath);
                }
            }
            entry = readdir(directory);
        }

        closedir(directory);
    }
}

int isInfected(char* buffer) {
    char* virusSignature = "6c616d7283bb1dbca63b9e5c0e5cf90b";

    if(strstr(buffer, virusSignature)) {
        return 1;
    }

    return 0;
}