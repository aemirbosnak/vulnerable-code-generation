//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: all-encompassing
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Returns 1 if file is virus, 0 if not
int isVirus(char* filePath) {
    FILE* fp = fopen(filePath, "r");
    if (fp == NULL) {
        printf("Error in opening file\n");
        return 1;
    }
    char c;
    int count = 0;
    // Analyzing file for viruses
    while ((c = fgetc(fp)) != EOF) {
        if (isalpha(c)) {
            count++;
        }
    }
    fclose(fp);
    if (count > 0 && count < 20) {
        printf("%s is a virus!\n", filePath);
        return 1;
    }
    return 0;
}

// Recursive function to traverse directories and scan files
void scanDirectory(char* path) {
    DIR* dir;
    struct dirent* entry;
    dir = opendir(path);
    if (dir != NULL) {
        while ((entry = readdir(dir)) != NULL) {
            // If it's a directory, skip '.' and '..' entries and recursively call function
            if (entry->d_type == DT_DIR) {
                if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                    continue;
                }
                char newPath[1024];
                sprintf(newPath, "%s/%s", path, entry->d_name);
                scanDirectory(newPath);
            }
            // If it's a file, scan for viruses
            else if (entry->d_type == DT_REG) {
                char filePath[1024];
                sprintf(filePath, "%s/%s", path, entry->d_name);
                if (isVirus(filePath)) {
                    printf("File path: %s\n", filePath);
                }
            }
        }
        closedir(dir);
    }
}

int main() {
    printf("C Antivirus Scanner\n");
    scanDirectory("/home/user/Documents");
    return 0;
}