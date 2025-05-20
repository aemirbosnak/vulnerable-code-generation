//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

void analyze_directory(char *path, int level, unsigned long *total_size) {
    DIR *dir;
    struct dirent *ent;
    struct stat st;
    char dir_path[1024];

    if ((dir = opendir(path)) == NULL) {
        printf("Error: Cannot open directory %s\n", path);
        return;
    }
    
    while ((ent = readdir(dir)) != NULL) {
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
            continue;
        }
        
        sprintf(dir_path, "%s/%s", path, ent->d_name);
        if (lstat(dir_path, &st) == -1) {
            printf("Error: Cannot get information of %s\n", dir_path);
            continue;
        }
        
        if (S_ISDIR(st.st_mode)) {
            printf("%*s- %s/\n", level*4, "", ent->d_name);
            analyze_directory(dir_path, level+1, total_size);
        } else {
            printf("%*s- %s (%lu bytes)\n", level*4, "", ent->d_name, st.st_size);
            *total_size += st.st_size;
        }
    }
    
    closedir(dir);
}

int main(int argc, char *argv[]) {
    unsigned long total_size = 0;
    char *path;

    if (argc < 2) {
        path = ".";
    } else {
        path = argv[1];
    }
    
    printf("Analyzing directory: %s\n", path);
    analyze_directory(path, 0, &total_size);
    printf("Total size of directory: %lu bytes\n", total_size);

    return 0;
}