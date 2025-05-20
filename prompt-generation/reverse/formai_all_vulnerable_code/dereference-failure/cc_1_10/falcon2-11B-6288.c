//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void file_sync(char* source_dir, char* target_dir) {
    DIR* dir = opendir(source_dir);
    struct dirent* ent;
    if (dir == NULL) {
        printf("Error opening source directory: %s\n", source_dir);
        return;
    }
    
    struct stat st;
    int dir_count = 0;
    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_DIR) {
            if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)
                continue;
            
            char path[100];
            sprintf(path, "%s/%s", source_dir, ent->d_name);
            
            if (stat(path, &st) == -1) {
                printf("Error accessing file: %s\n", path);
                continue;
            }
            
            if (stat(path, &st) == 0) {
                if (S_ISDIR(st.st_mode)) {
                    file_sync(path, target_dir);
                    dir_count++;
                } else {
                    if (stat(target_dir, &st) == 0 && S_ISDIR(st.st_mode)) {
                        char target_path[100];
                        sprintf(target_path, "%s/%s", target_dir, ent->d_name);
                        FILE* source_file = fopen(path, "r");
                        FILE* target_file = fopen(target_path, "w");
                        if (source_file == NULL || target_file == NULL) {
                            printf("Error opening source or target file: %s\n", target_path);
                            continue;
                        }
                        
                        char buf[100];
                        while (fgets(buf, sizeof(buf), source_file)!= NULL) {
                            fprintf(target_file, "%s", buf);
                        }
                        
                        fclose(source_file);
                        fclose(target_file);
                    } else {
                        printf("Error accessing file: %s\n", path);
                    }
                }
            }
        }
    }
    
    closedir(dir);
    printf("Total files synchronized: %d\n", dir_count);
}

int main() {
    char source_dir[100];
    char target_dir[100];
    
    printf("Source directory: ");
    fgets(source_dir, sizeof(source_dir), stdin);
    printf("Target directory: ");
    fgets(target_dir, sizeof(target_dir), stdin);
    
    file_sync(source_dir, target_dir);
    
    return 0;
}