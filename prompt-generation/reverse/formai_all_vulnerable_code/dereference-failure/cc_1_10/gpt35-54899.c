//FormAI DATASET v1.0 Category: File Synchronizer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdbool.h>

const int BUFFER_SIZE = 1024;

bool isDirectory(const char* path) {
    struct stat path_stat;
    if (stat(path, &path_stat) != 0) {
        printf("[ERROR] Cannot stat file '%s'.\n", path);
        return false;
    }
    return S_ISDIR(path_stat.st_mode);
}

void copyFile(const char* src, const char* dst) {
    FILE* fsrc = fopen(src, "r");
    if (fsrc == NULL) {
        printf("[ERROR] Could not open file '%s'.\n", src);
        return;
    }
    
    FILE* fdst = fopen(dst, "w");
    if (fdst == NULL) {
        fclose(fsrc);
        printf("[ERROR] Could not create file '%s'.\n", dst);
        return;
    }
    
    char buffer[BUFFER_SIZE];
    int bytesRead;
    while ((bytesRead = fread(buffer, sizeof(char), BUFFER_SIZE, fsrc)) > 0) {
        fwrite(buffer, sizeof(char), bytesRead, fdst);
    }
    
    fclose(fsrc);
    fclose(fdst);
}

void synchronizeDir(const char* srcDir, const char* dstDir) {
    DIR* dir = opendir(srcDir);
    if (dir == NULL) {
        printf("[ERROR] Cannot open directory '%s'.\n", srcDir);
        return;
    }
    
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        char srcPath[BUFFER_SIZE];
        char dstPath[BUFFER_SIZE];
        sprintf(srcPath, "%s/%s", srcDir, entry->d_name);
        sprintf(dstPath, "%s/%s", dstDir, entry->d_name);
        
        if (isDirectory(srcPath)) {
            printf("[INFO] Syncing directory '%s'...\n", srcPath);
            synchronizeDir(srcPath, dstPath);
        } else {
            printf("[INFO] Syncing file '%s'...\n", srcPath);
            copyFile(srcPath, dstPath);
        }
    }
    
    closedir(dir);
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("[ERROR] Invalid arguments. Usage: %s <src dir> <dst dir>\n", argv[0]);
        return 1;
    }
    
    printf("[INFO] Syncing '%s' with '%s'...\n", argv[1], argv[2]);
    synchronizeDir(argv[1], argv[2]);
    printf("[INFO] Sync complete.\n");
    
    return 0;
}