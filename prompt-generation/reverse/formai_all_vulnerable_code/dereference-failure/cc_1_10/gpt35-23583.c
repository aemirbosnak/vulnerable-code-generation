//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>

void scan_file(char*);
void scan_directory(char*);

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <path_of_file_or_directory>\n", argv[0]);
        exit(1);
    }

    struct stat s;
    if(stat(argv[1], &s) == -1) {
        printf("Invalid path\n");
        exit(1);
    }

    if(S_ISDIR(s.st_mode)) {
        scan_directory(argv[1]);
    } else {
        scan_file(argv[1]);
    }

    return 0;
}

void scan_file(char *file_path) {
    FILE *file_pointer = fopen(file_path, "r");
    if(file_pointer == NULL) {
        printf("Cannot open file: %s\n", file_path);
        return;
    }

    char buffer[100];
    while(fgets(buffer, 100, file_pointer) != NULL) {
        if(strstr(buffer, "virus")) {
            printf("Virus detected in file: %s\n", file_path);
            fclose(file_pointer);
            return;
        }
    }

    fclose(file_pointer);
}

void scan_directory(char *dir_path) {
    DIR *dir_pointer = opendir(dir_path);
    if(dir_pointer == NULL) {
        printf("Cannot open directory: %s\n", dir_path);
        return;
    }

    struct dirent *dir_entry;
    while((dir_entry=readdir(dir_pointer)) != NULL) {
        if(strcmp(dir_entry->d_name, ".") != 0 && strcmp(dir_entry->d_name, "..") != 0) {
            char path[100];
            strcpy(path, dir_path);
            strcat(path, "/");
            strcat(path, dir_entry->d_name);
            
            struct stat s;
            if(stat(path, &s) == -1) {
                printf("Invalid path\n");
                exit(1);
            }

            if(S_ISDIR(s.st_mode)) {
                scan_directory(path);
            } else {
                scan_file(path);
            }
        }
    }

    closedir(dir_pointer);
}