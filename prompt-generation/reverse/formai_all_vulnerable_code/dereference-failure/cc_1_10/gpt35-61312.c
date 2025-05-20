//FormAI DATASET v1.0 Category: File Backup System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

void backup_file(char *src, char *dst);

int main(int argc, char *argv[]) {

    char *src_dir = "/home/user/files/";
    char *dst_dir = "/mnt/backup/";

    DIR *dp;
    struct dirent *dirp;
    char file_name[256];

    if ((dp = opendir(src_dir)) == NULL) {
        perror("Error opening source directory");
        exit(1);
    }

    while ((dirp = readdir(dp)) != NULL) {
        if (strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0)
            continue; 

        memset(file_name, 0, sizeof(file_name));
        strcat(file_name, src_dir);
        strcat(file_name, dirp->d_name);

        backup_file(file_name, dst_dir);
    }

    closedir(dp);
    return 0;
}

void backup_file(char *src, char *dst) {

    int src_fd, dst_fd, n;
    char buf[1024];

    src_fd = open(src, O_RDONLY);
    if (src_fd < 0) {
        perror("Error opening source file");
        return;
    }

    char backup_file[256];
    memset(backup_file, 0, sizeof(backup_file));
    strcat(backup_file, dst);
    strcat(backup_file, basename(src)); 

    dst_fd = open(backup_file, O_WRONLY | O_CREAT, 0644); 
    if (dst_fd < 0) {
        perror("Error creating destination file");
        return;
    }

    while ((n = read(src_fd, buf, sizeof(buf))) > 0) {
        if (write(dst_fd, buf, n) != n) {
            perror("Error writing to destination file");
            return;
        }
    }

    if (n < 0) {
        perror("Error reading source file");
        return;
    }

    close(src_fd);
    close(dst_fd); 

    printf("File %s backed up successfully to %s\n", src, backup_file);
}