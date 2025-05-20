//Falcon2-11B DATASET v1.0 Category: File Backup System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: backup_file_system source_dir dest_dir\n");
        return 1;
    }
    
    int source_dir_fd = open(argv[1], O_RDONLY);
    if (source_dir_fd == -1) {
        perror("open");
        return 1;
    }
    
    int dest_dir_fd = open(argv[2], O_CREAT | O_WRONLY, S_IRWXU);
    if (dest_dir_fd == -1) {
        perror("open");
        return 1;
    }
    
    DIR *source_dir = opendir(argv[1]);
    if (source_dir == NULL) {
        perror("opendir");
        return 1;
    }
    
    struct dirent *entry;
    while ((entry = readdir(source_dir))!= NULL) {
        char entry_name[PATH_MAX];
        strcpy(entry_name, entry->d_name);
        char dest_entry_name[PATH_MAX];
        snprintf(dest_entry_name, PATH_MAX, "%s/%s", argv[2], entry_name);
        int entry_fd = open(entry_name, O_RDONLY);
        if (entry_fd == -1) {
            perror("open");
            continue;
        }
        
        int dest_entry_fd = open(dest_entry_name, O_WRONLY);
        if (dest_entry_fd == -1) {
            perror("open");
            continue;
        }
        
        char buffer[4096];
        int bytes_read = read(entry_fd, buffer, sizeof(buffer));
        while (bytes_read > 0) {
            write(dest_entry_fd, buffer, bytes_read);
            bytes_read = read(entry_fd, buffer, sizeof(buffer));
        }
        
        close(entry_fd);
        close(dest_entry_fd);
    }
    
    closedir(source_dir);
    close(source_dir_fd);
    close(dest_dir_fd);
    
    return 0;
}