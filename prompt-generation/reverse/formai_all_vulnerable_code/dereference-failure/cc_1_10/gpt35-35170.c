//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

#define K 1024
#define M K*K
#define G M*K

struct folder {
    char name[256];
    long long int size;
    struct folder *subfolders;
    int num_subfolders;
} current_folder;

char* size_format(long long int size) {
    char* format = (char*)malloc(sizeof(char)*16);
    if(size >= G) {
        sprintf(format, "%.2f GB", (float)size/G);
    }
    else if(size >= M) {
        sprintf(format, "%.2f MB", (float)size/M);
    }
    else if(size >= K) {
        sprintf(format, "%.2f KB", (float)size/K);
    }
    else {
        sprintf(format, "%lld B", size);
    }
    return format;
}

void analyze_folder(char* folder_name) {
    printf("Analyzing folder: %s\n", folder_name);
    
    DIR* dp;
    struct dirent* entry;
    struct stat file_stat;
    long long int total_size = 0;
    int num_subfolders = 0;
    struct folder* subfolders = NULL;

    dp = opendir(folder_name);
    if(dp == NULL) {
        printf("Error: Unable to open directory: %s\n", folder_name);
        return;
    }

    while((entry = readdir(dp))) {
        char entry_name[256];
        sprintf(entry_name, "%s/%s", folder_name, entry->d_name);

        if(stat(entry_name, &file_stat) == -1) {
            printf("Error: Unable to read file/folder: %s\n", entry_name);
            continue;
        }

        if(S_ISDIR(file_stat.st_mode)) {
            if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            num_subfolders++;
            subfolders = (struct folder*)realloc(subfolders, sizeof(struct folder)*num_subfolders);
            memset(&subfolders[num_subfolders-1], 0, sizeof(struct folder));
            strcpy(subfolders[num_subfolders-1].name, entry->d_name);

            analyze_folder(entry_name);

            total_size += subfolders[num_subfolders-1].size;
        }
        else if(S_ISREG(file_stat.st_mode)) {
            total_size += file_stat.st_size;
        }
    }

    closedir(dp);

    current_folder.size = total_size;
    current_folder.subfolders = subfolders;
    current_folder.num_subfolders = num_subfolders;

    printf("\nFolder: %s\nSize: %s\n", folder_name, size_format(total_size));

    for(int i=0; i<num_subfolders; i++) {
        printf("\nSubfolder: %s\nSize: %s\n", subfolders[i].name, size_format(subfolders[i].size));
    }
}

int main(int argc, char* argv[]) {
    if(argc < 2) {
        printf("Usage: ./disk_analyzer folder_path\n");
        return 1;
    }

    analyze_folder(argv[1]);

    return 0;
}