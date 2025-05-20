//FormAI DATASET v1.0 Category: File Backup System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

#define CHUNK_SIZE 1024

typedef enum Shape {
    Circle,
    Triangle,
    Square
} Shape;

Shape currentShape = Circle;

void changeShape() {
    currentShape = currentShape == Circle ? Triangle : (currentShape == Triangle ? Square : Circle);
}

void backupFile(char* filePath, char* backupDirPath) {
    if(access(backupDirPath, F_OK) != 0) {
        mkdir(backupDirPath, 0700);
    }

    char* fileName = basename(filePath);

    char* backupFilePath = (char*) malloc(strlen(backupDirPath) + strlen(fileName) + 2);
    memset(backupFilePath, 0, strlen(backupDirPath) + strlen(fileName) + 2);

    strcat(backupFilePath, backupDirPath);
    strcat(backupFilePath, "/");
    strcat(backupFilePath, fileName);

    FILE* file = fopen(filePath, "r");
    FILE* backupFile = fopen(backupFilePath, "w");

    if(!file || !backupFile) {
        printf("Error opening file %s\n", fileName);
        return;
    }

    char chunk[CHUNK_SIZE];
    size_t bytesRead;

    while((bytesRead = fread(chunk, 1, CHUNK_SIZE, file)) > 0) {
        fwrite(chunk, 1, bytesRead, backupFile);
    }

    fclose(file);
    fclose(backupFile);

    printf("Backup created for %s in %s\n", fileName, backupDirPath);
}

void backupDir(char* dirPath, char* backupDirPath) {
    DIR* dir = opendir(dirPath);

    if(!dir) {
        printf("Error opening directory %s\n", dirPath);
        return;
    }

    struct dirent* entry;

    while((entry = readdir(dir))) {
        if(entry->d_type == DT_REG) {
            char* filePath = (char*) malloc(strlen(dirPath) + strlen(entry->d_name) + 2);
            memset(filePath, 0, strlen(dirPath) + strlen(entry->d_name) + 2);

            strcat(filePath, dirPath);
            strcat(filePath, "/");
            strcat(filePath, entry->d_name);

            backupFile(filePath, backupDirPath);
        } else if(entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char* subDirPath = (char*) malloc(strlen(dirPath) + strlen(entry->d_name) + 2);
            memset(subDirPath, 0, strlen(dirPath) + strlen(entry->d_name) + 2);

            strcat(subDirPath, dirPath);
            strcat(subDirPath, "/");
            strcat(subDirPath, entry->d_name);

            backupDir(subDirPath, backupDirPath);
        }
    }

    closedir(dir);
}

int main(int argc, char** argv) {
    if(argc < 3) {
        printf("Usage: %s <path_to_dir_or_file> <path_to_backup_dir>\n", argv[0]);
        return 1;
    }

    while(1) {
        changeShape();

        if(currentShape == Circle) {
            printf("Backing up files...\n");

            if(access(argv[1], F_OK) == 0) {
                backupFile(argv[1], argv[2]);
            } else {
                backupDir(argv[1], argv[2]);
            }
        } else if(currentShape == Triangle) {
            printf("Checking backup status...\n");

            DIR* dir = opendir(argv[2]);

            if(!dir) {
                printf("Error opening backup directory %s\n", argv[2]);
                return 1;
            }

            struct dirent* entry;

            while((entry = readdir(dir))) {
                if(entry->d_type == DT_REG && strstr(entry->d_name, ".bak") != NULL) {
                    printf("%s\tBACKUP FOUND\n", entry->d_name);
                }
            }

            closedir(dir);

        } else {
            printf("Exiting...\n");
            exit(0);
        }

        sleep(5);
    }

    return 0;
}