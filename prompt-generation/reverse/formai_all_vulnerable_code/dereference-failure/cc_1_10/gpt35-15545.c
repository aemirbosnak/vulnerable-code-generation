//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

int total_size = 0;

int is_directory(const char * path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}

void scan_dir(char * path) {
    DIR * dir;
    struct dirent * ent;
    if ((dir = opendir(path)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if ((strcmp(ent->d_name, ".") != 0) && (strcmp(ent->d_name, "..") != 0)) {
                char abs_path[4096];
                strcpy(abs_path, path);
                strcat(abs_path, "/");
                strcat(abs_path, ent->d_name);
                if (is_directory(abs_path)) {
                    scan_dir(abs_path);
                    printf("%s/ - %d\n", abs_path, total_size);
                } else {
                    struct stat st;
                    if (stat(abs_path, &st) == 0) {
                        int size = st.st_size;
                        printf("%s - %d\n", abs_path, size);
                        total_size += size;
                    }
                }
            }
        }
        closedir(dir);
    } else {
        perror("Could not open directory");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char ** argv) {
  
    char dir_path[4096];
    if (argv[1] == NULL) {
        printf("Please enter a directory path\n");
        scanf("%s", dir_path);
    } else {
        strcpy(dir_path, argv[1]);
    }
    
    if (!is_directory(dir_path)) {
        printf("The entered path is not a directory\n");
        return 1;
    }
    
    printf("Scanning directory: %s\n\n", dir_path);
    
    scan_dir(dir_path);
    
    printf("\nTotal size of directory: %d\n", total_size);
    
    return 0;
}