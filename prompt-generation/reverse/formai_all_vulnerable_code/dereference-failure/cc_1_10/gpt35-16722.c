//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void scanDirectory(char *dirPath, char *extension);
void scanFile(char *filePath);

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Please provide directory path and file extension\n");
        exit(1);
    }

    scanDirectory(argv[1], argv[2]);

    printf("\nScan Complete\n");

    return 0;
}

void scanDirectory(char *dirPath, char *extension) {
    DIR *dir = opendir(dirPath);
    struct dirent *entry;

    if(dir == NULL) {
        printf("Error: Directory could not be opened\n");
        exit(1);
    }

    while((entry = readdir(dir)) != NULL) {
        char *absPath = malloc(strlen(dirPath) + strlen(entry->d_name) + 2);
        sprintf(absPath, "%s/%s", dirPath, entry->d_name);

        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            free(absPath);
            continue;
        }

        if(entry->d_type == DT_DIR) {
            scanDirectory(absPath, extension);
            free(absPath);
        } else {
            if(strstr(entry->d_name, extension) != NULL) {
                printf("Scanning: %s\n", absPath);
                scanFile(absPath);
            }
            free(absPath);
        }
    }

    closedir(dir);
}

void scanFile(char *filePath) {
    FILE *fp = fopen(filePath, "r");

    if(fp == NULL) {
        printf("Error: File could not be opened: %s\n", filePath);
        return;
    }

    char c;
    int isVirus = 0;

    while((c = fgetc(fp)) != EOF) {
        if(c == 'v') {
            isVirus = 1;
        } else if(c == 'i' && isVirus == 1) {
            isVirus = 2;
        } else if(c == 'r' && isVirus == 2) {
            printf("Virus Detected in %s\n", filePath);
            fclose(fp);
            return;
        } else {
            isVirus = 0;
        }
    }

    fclose(fp);
}