//FormAI DATASET v1.0 Category: File Synchronizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUF_SIZE 1024

void syncFiles(char *dir1, char *dir2);
void syncDir(char *dir1, char *dir2);
void syncFile(char *file1, char *file2);
int fileExists(char *filePath);

int main(int argc, char **argv) {
    if(argc != 3) {
        printf("Usage: %s <dir1> <dir2>\n", argv[0]);
        exit(1);
    }
    
    syncFiles(argv[1], argv[2]);
    
    return 0;
}

void syncFiles(char *dir1, char *dir2) {
    DIR *d1 = opendir(dir1);
    DIR *d2 = opendir(dir2);
    
    if(d1 == NULL || d2 == NULL) {
        printf("Error: Could not open directories for synchronization\n");
        exit(1);
    }
    
    struct dirent *entry1;
    struct dirent *entry2;
    
    while((entry1 = readdir(d1)) != NULL) {
        if(strcmp(".", entry1->d_name) == 0 || strcmp("..", entry1->d_name) == 0) {
            continue;
        }
        
        char path1[BUF_SIZE];
        char path2[BUF_SIZE];
        
        sprintf(path1, "%s/%s", dir1, entry1->d_name);
        sprintf(path2, "%s/%s", dir2, entry1->d_name);
        
        if((entry2 = opendir(path2)) != NULL) {
            syncDir(path1, path2);
            closedir(entry2);
        }
        else {
            if(fileExists(path2)) {
                syncFile(path1, path2);
            }
            else {
                printf("Copying %s to %s\n", path1, path2);
                
                FILE *f1 = fopen(path1, "rb");
                FILE *f2 = fopen(path2, "wb");
                
                if(f1 == NULL || f2 == NULL) {
                    printf("Error: Could not open files for copying\n");
                    exit(1);
                }
                
                char buf[BUF_SIZE];
                size_t read;
                
                while((read = fread(buf, 1, sizeof(buf), f1)) > 0) {
                    fwrite(buf, 1, read, f2);
                }
                
                fclose(f1);
                fclose(f2);
            }
        }
    }
    
    closedir(d1);
    closedir(d2);
}

void syncDir(char *dir1, char *dir2) {
    DIR *d1 = opendir(dir1);
    DIR *d2 = opendir(dir2);
    
    if(d1 == NULL || d2 == NULL) {
        printf("Error: Could not open directories for synchronization\n");
        exit(1);
    }
    
    struct dirent *entry1;
    struct dirent *entry2;
    
    while((entry1 = readdir(d1)) != NULL) {
        if(strcmp(".", entry1->d_name) == 0 || strcmp("..", entry1->d_name) == 0) {
            continue;
        }
        
        char path1[BUF_SIZE];
        char path2[BUF_SIZE];
        
        sprintf(path1, "%s/%s", dir1, entry1->d_name);
        sprintf(path2, "%s/%s", dir2, entry1->d_name);
        
        if((entry2 = opendir(path2)) != NULL) {
            syncDir(path1, path2);
            closedir(entry2);
        }
        else {
            if(fileExists(path2)) {
                syncFile(path1, path2);
            }
            else {
                printf("Copying %s to %s\n", path1, path2);
                
                FILE *f1 = fopen(path1, "rb");
                FILE *f2 = fopen(path2, "wb");
                
                if(f1 == NULL || f2 == NULL) {
                    printf("Error: Could not open files for copying\n");
                    exit(1);
                }
                
                char buf[BUF_SIZE];
                size_t read;
                
                while((read = fread(buf, 1, sizeof(buf), f1)) > 0) {
                    fwrite(buf, 1, read, f2);
                }
                
                fclose(f1);
                fclose(f2);
            }
        }
    }
    
    while((entry2 = readdir(d2)) != NULL) {
        if(strcmp(".", entry2->d_name) == 0 || strcmp("..", entry2->d_name) == 0) {
            continue;
        }
        
        char path1[BUF_SIZE];
        char path2[BUF_SIZE];
        
        sprintf(path1, "%s/%s", dir1, entry2->d_name);
        sprintf(path2, "%s/%s", dir2, entry2->d_name);
        
        if((entry1 = opendir(path1)) != NULL) {
            syncDir(path1, path2);
            closedir(entry1);
        }
        else {
            if(!fileExists(path1)) {
                printf("Deleting %s\n", path2);
                remove(path2);
            }
        }
    }
    
    closedir(d1);
    closedir(d2);
}

void syncFile(char *file1, char *file2) {
    struct stat s1, s2;
    stat(file1, &s1);
    stat(file2, &s2);
    
    if(s1.st_mtime > s2.st_mtime) {
        printf("Updating %s to %s\n", file2, file1);
        
        FILE *f1 = fopen(file1, "rb");
        FILE *f2 = fopen(file2, "wb");
        
        if(f1 == NULL || f2 == NULL) {
            printf("Error: Could not open files for copying\n");
            exit(1);
        }
        
        char buf[BUF_SIZE];
        size_t read;
        
        while((read = fread(buf, 1, sizeof(buf), f1)) > 0) {
            fwrite(buf, 1, read, f2);
        }
        
        fclose(f1);
        fclose(f2);
    }
}

int fileExists(char *filePath) {
    struct stat s;
    return stat(filePath, &s) == 0;
}