//FormAI DATASET v1.0 Category: File Synchronizer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

void sync_files(const char *src_path, const char *dest_path) {
    DIR *dir = opendir(src_path);
    if (dir == NULL) {
        printf("Could not open directory %s\n", src_path);
        return;
    }
    
    struct dirent *entry;
    while ((entry = readdir(dir))) {
        if (entry->d_name[0] == '.') continue;
        
        char src_file_path[256], dest_file_path[256];
        sprintf(src_file_path, "%s/%s", src_path, entry->d_name);
        sprintf(dest_file_path, "%s/%s", dest_path, entry->d_name);
        
        struct stat src_stat, dest_stat;
        stat(src_file_path, &src_stat);
        stat(dest_file_path, &dest_stat);

        if (S_ISDIR(src_stat.st_mode)) {
            mkdir(dest_file_path, src_stat.st_mode);
            sync_files(src_file_path, dest_file_path);
        } else {
            if (src_stat.st_mtime > dest_stat.st_mtime) {
                int src_fd = open(src_file_path, O_RDONLY);
                int dest_fd = open(dest_file_path, O_WRONLY|O_TRUNC);

                char buffer[4096];
                ssize_t bytes_read;
                while ((bytes_read = read(src_fd, buffer, sizeof(buffer)))) {
                    write(dest_fd, buffer, bytes_read);
                }

                close(src_fd);
                close(dest_fd);
            }
        }
    }
}

int main() {
    printf("Welcome to the C File Synchronizer!\n");
    printf("Enter source directory path: ");
    char src_path[256];
    scanf("%s", src_path);
    
    printf("Enter destination directory path: ");
    char dest_path[256];
    scanf("%s", dest_path);
    
    printf("Syncing files...\n");
    sync_files(src_path, dest_path);
    printf("Syncing complete!\n");
    
    return 0;
}