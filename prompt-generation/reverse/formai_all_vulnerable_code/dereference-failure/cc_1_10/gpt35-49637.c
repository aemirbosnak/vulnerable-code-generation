//FormAI DATASET v1.0 Category: File Synchronizer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

int isDirectory(char *path) {
    struct stat s;
    if(stat(path, &s) == 0) {
        if(s.st_mode & S_IFDIR) {
            return 1;
        }
    }
    return 0;
}

void copy_file(char *source, char *destination) {
    FILE *src_file, *dest_file;
    char ch;
    
    src_file = fopen(source, "r");
    dest_file = fopen(destination, "w");

    while ((ch = fgetc(src_file)) != EOF) {
        fputc(ch, dest_file);
    }
    
    fclose(src_file);
    fclose(dest_file);
}

void sync_files_in_dir(char *dir1, char *dir2) {
    struct dirent *entry;
    DIR *dir = opendir(dir1);

    while ((entry = readdir(dir)) != NULL) {
        if(strcmp(entry->d_name, ".") && strcmp(entry->d_name, "..")) {
            char path1[100] = "", path2[100] = "";

            strcat(strcat(strcat(path1, dir1), "/"), entry->d_name);
            strcat(strcat(strcat(path2, dir2), "/"), entry->d_name);

            if(isDirectory(path1)) {
                if(!isDirectory(path2)) {
                    mkdir(path2, 0777);
                }
                sync_files_in_dir(path1, path2);
            } else {
                struct stat s1, s2;
                stat(path1, &s1);
                stat(path2, &s2);
                if(s1.st_mtime > s2.st_mtime) {
                    printf("Copying %s to %s\n", path1, path2);
                    copy_file(path1, path2);
                }
            }
        }
    }

    closedir(dir);
}

int main() {
    char dir1[100], dir2[100];

    printf("Enter first directory path: ");
    scanf("%s", dir1);

    printf("Enter second directory path: ");
    scanf("%s", dir2);

    sync_files_in_dir(dir1, dir2);

    printf("File Synchronization successful!\n");

    return 0;
}