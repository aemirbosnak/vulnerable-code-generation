//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: standalone
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

void analyzeDir(char *dirPath);
void analyzeFile(char *filePath);

int main(int argc, char *argv[]) {
    if(argc == 2) {
        analyzeDir(argv[1]);
    } else {
        printf("Usage: %s [directory_path]\n", argv[0]);
    }
    return 0;
}

void analyzeDir(char *dirPath) {
    DIR *dir = opendir(dirPath);
    if(dir == NULL) {
        printf("Error: Could not open directory %s\n", dirPath);
        return;
    }

    struct dirent *entry;
    while((entry = readdir(dir)) != NULL) {
        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        char path[1024];
        sprintf(path, "%s/%s", dirPath, entry->d_name);
        struct stat buffer;
        if(stat(path, &buffer) == 0 && S_ISDIR(buffer.st_mode)) {
            analyzeDir(path);
        } else {
            analyzeFile(path);
        }
    }
    closedir(dir);
}

void analyzeFile(char *filePath) {
    FILE *file = fopen(filePath, "r");
    if(file == NULL) {
        printf("Error: Could not open file %s\n", filePath);
        return;
    }

    fseek(file, 0L, SEEK_END);
    long int fileSize = ftell(file);
    fclose(file);

    printf("%s: %ld bytes\n", filePath, fileSize);
}