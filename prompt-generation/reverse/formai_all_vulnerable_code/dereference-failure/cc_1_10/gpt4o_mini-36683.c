//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_FILES 100
#define FILE_NAME_LEN 256

typedef struct {
    char name[FILE_NAME_LEN];
    time_t mod_time;
} FileInfo;

void getFileList(const char *dir_name, FileInfo *files, int *file_count) {
    struct dirent *entry;
    struct stat file_stat;
    DIR *dir = opendir(dir_name);

    if (!dir) {
        perror("Failed to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Only regular files
            char path[FILE_NAME_LEN];
            snprintf(path, sizeof(path), "%s/%s", dir_name, entry->d_name);
            stat(path, &file_stat);
            strcpy(files[*file_count].name, entry->d_name);
            files[*file_count].mod_time = file_stat.st_mtime;
            (*file_count)++;
        }
    }
    closedir(dir);
}

void syncFiles(const FileInfo *local_files, int local_count, const FileInfo *peer_files, int peer_count) {
    for (int i = 0; i < local_count; i++) {
        int found = 0;
        for (int j = 0; j < peer_count; j++) {
            if (strcmp(local_files[i].name, peer_files[j].name) == 0) {
                found = 1;
                if (local_files[i].mod_time > peer_files[j].mod_time) {
                    printf("Syncing %s from local to peer\n", local_files[i].name);
                    // Implement the file copy logic here
                } else if (local_files[i].mod_time < peer_files[j].mod_time) {
                    printf("Syncing %s from peer to local\n", local_files[i].name);
                    // Implement the file copy logic here
                }
                break;
            }
        }
        if (!found) {
            printf("File %s is new in local\n", local_files[i].name);
        }
    }
    
    for (int j = 0; j < peer_count; j++) {
        int found = 0;
        for (int i = 0; i < local_count; i++) {
            if (strcmp(peer_files[j].name, local_files[i].name) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("File %s is new in peer\n", peer_files[j].name);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <local_directory> <peer_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FileInfo local_files[MAX_FILES];
    FileInfo peer_files[MAX_FILES];
    int local_count = 0, peer_count = 0;

    getFileList(argv[1], local_files, &local_count);
    getFileList(argv[2], peer_files, &peer_count);
    
    printf("Local file count: %d\n", local_count);
    printf("Peer file count: %d\n", peer_count);
    
    syncFiles(local_files, local_count, peer_files, peer_count);
    
    return EXIT_SUCCESS;
}