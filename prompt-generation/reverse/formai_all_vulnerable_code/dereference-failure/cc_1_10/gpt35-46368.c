//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

// define a struct for the file/directory information
struct fileInfo {
    char *name;
    long size;
};

// function to recursively search for files
void searchDir(char *path, struct fileInfo *fileData, int *count) {
    DIR *dir = opendir(path);
    struct dirent *entry;
    char buffer[512];
    
    if(dir == NULL) {
        fprintf(stderr, "Error: Cannot open directory %s\n", path);
        return;
    }
    
    while((entry = readdir(dir)) != NULL) {
        if(strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            sprintf(buffer, "%s/%s", path, entry->d_name);
            if(entry->d_type == DT_DIR) {
                searchDir(buffer, fileData, count);
            }
            else {
                struct fileInfo info;
                info.name = malloc(strlen(entry->d_name) + 1);
                strcpy(info.name, entry->d_name);
                FILE *file = fopen(buffer, "rb");
                if(file != NULL) {
                    fseek(file, 0, SEEK_END);
                    info.size = ftell(file);
                    fclose(file);
                    fileData[*count] = info;
                    (*count)++;
                }
            }
        }
    }
    
    closedir(dir);
}

// function to compare file sizes for qsort
int compare(const void *v1, const void *v2) {
    const struct fileInfo *f1 = v1;
    const struct fileInfo *f2 = v2;
    return f2->size - f1->size;
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    char *path = argv[1];
    struct fileInfo *fileData = malloc(sizeof(struct fileInfo) * 1000);
    int count = 0;
    searchDir(path, fileData, &count);
    qsort(fileData, count, sizeof(struct fileInfo), compare);
    
    printf("%-20s %s\n", "FILENAME", "SIZE");
    printf("------------------------------------\n");
    for(int i = 0; i < count; i++) {
        printf("%-20s %ld bytes\n", fileData[i].name, fileData[i].size);
        free(fileData[i].name);
    }
    
    free(fileData);
    
    return 0;
}