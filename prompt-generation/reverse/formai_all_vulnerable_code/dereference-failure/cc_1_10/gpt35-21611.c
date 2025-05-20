//FormAI DATASET v1.0 Category: File Synchronizer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Function to compare two files
int compareFiles(FILE* file1, FILE* file2) {
    char buffer1[BUFFER_SIZE];
    char buffer2[BUFFER_SIZE];
    size_t n1, n2;
    
    while ((n1 = fread(buffer1, 1, sizeof(buffer1), file1)) > 0 &&
           (n2 = fread(buffer2, 1, sizeof(buffer2), file2)) > 0) {
        if (n1 != n2 || memcmp(buffer1, buffer2, n1)) {
            return 0;
        }
    }
    
    if (ferror(file1) || ferror(file2)) {
        return 0;
    }
    
    return 1;
}

// Function to synchronize two files
int syncFiles(char* path1, char* path2) {
    struct stat stat1, stat2;
    FILE* file1, * file2;
    int result = 0;
    
    if (stat(path1, &stat1) == -1) {
        fprintf(stderr, "Error: cannot find file %s\n", path1);
        return -1;
    }
    
    if (stat(path2, &stat2) == -1) {
        fprintf(stderr, "Error: cannot find file %s\n", path2);
        return -1;
    }
    
    if (stat1.st_mode & S_IFDIR) {
        DIR* dir1, * dir2;
        struct dirent* entry1, * entry2;
        char* path1new, * path2new;
        
        if ((dir1 = opendir(path1)) == NULL) {
            fprintf(stderr, "Error: cannot open directory %s\n", path1);
            return -1;
        }
        
        if ((dir2 = opendir(path2)) == NULL) {
            fprintf(stderr, "Error: cannot open directory %s\n", path2);
            return -1;
        }
        
        while ((entry1 = readdir(dir1)) != NULL) {
            if (!strcmp(entry1->d_name, ".") || !strcmp(entry1->d_name, "..")) {
                continue;
            }
            
            path1new = (char*) malloc(strlen(path1) + strlen(entry1->d_name) + 2);
            strcpy(path1new, path1);
            strcat(path1new, "/");
            strcat(path1new, entry1->d_name);
            
            path2new = (char*) malloc(strlen(path2) + strlen(entry1->d_name) + 2);
            strcpy(path2new, path2);
            strcat(path2new, "/");
            strcat(path2new, entry1->d_name);
            
            // Recursively synchronize subdirectories and files
            syncFiles(path1new, path2new);
            
            free(path1new);
            free(path2new);
        }
        
        while ((entry2 = readdir(dir2)) != NULL) {
            if (!strcmp(entry2->d_name, ".") || !strcmp(entry2->d_name, "..")) {
                continue;
            }
            
            path1new = (char*) malloc(strlen(path1) + strlen(entry2->d_name) + 2);
            strcpy(path1new, path1);
            strcat(path1new, "/");
            strcat(path1new, entry2->d_name);
            
            path2new = (char*) malloc(strlen(path2) + strlen(entry2->d_name) + 2);
            strcpy(path2new, path2);
            strcat(path2new, "/");
            strcat(path2new, entry2->d_name);
            
            // Recursively synchronize subdirectories and files
            syncFiles(path2new, path1new);
            
            free(path1new);
            free(path2new);
        }
        
        closedir(dir1);
        closedir(dir2);
    }
    else {
        // Compare files and copy if necessary
        if (!compareFiles(fopen(path1, "rb"), fopen(path2, "rb"))) {
            if ((file1 = fopen(path1, "rb")) == NULL) {
                fprintf(stderr, "Error: cannot open file %s\n", path1);
                return -1;
            }
            
            if ((file2 = fopen(path2, "wb")) == NULL) {
                fprintf(stderr, "Error: cannot open file %s\n", path2);
                return -1;
            }
            
            char buffer[BUFFER_SIZE];
            size_t n;
            
            while ((n = fread(buffer, 1, sizeof(buffer), file1)) > 0) {
                if (fwrite(buffer, 1, n, file2) != n) {
                    fprintf(stderr, "Error: write failed\n");
                    result = -1;
                    break;
                }
            }
            
            if (ferror(file1) || ferror(file2)) {
                fprintf(stderr, "Error: read/write error\n");
                result = -1;
            }
            
            fclose(file1);
            fclose(file2);
        }
    }
    
    return result;
}

int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dir1> <dir2>\n", argv[0]);
        return -1;
    }
    
    if (syncFiles(argv[1], argv[2]) != 0) {
        fprintf(stderr, "Error: synchronization failed\n");
        return -1;
    }
    
    printf("Synchronization successful\n");
    return 0;
}