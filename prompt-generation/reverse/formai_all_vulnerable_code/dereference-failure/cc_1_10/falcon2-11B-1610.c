//Falcon2-11B DATASET v1.0 Category: File Backup System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/signal.h>

typedef struct file_info {
    char* filename;
    char* backup_filename;
    int file_size;
    time_t file_creation_time;
} file_info;

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: backup <source_directory> <destination_directory>\n");
        exit(1);
    }
    
    int src_fd, dest_fd;
    struct stat src_stat, dest_stat;
    
    src_fd = open(argv[1], O_RDONLY);
    dest_fd = open(argv[2], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    
    fstat(src_fd, &src_stat);
    fstat(dest_fd, &dest_stat);
    
    char* backup_filename = malloc(strlen(argv[1]) + 8);
    sprintf(backup_filename, "%s.backup", argv[1]);
    
    if (dest_stat.st_dev!= src_stat.st_dev || dest_stat.st_ino!= src_stat.st_ino) {
        close(src_fd);
        close(dest_fd);
        printf("Error: source and destination filesystems are not the same.\n");
        exit(1);
    }
    
    file_info info;
    info.filename = argv[1];
    info.backup_filename = backup_filename;
    info.file_size = src_stat.st_size;
    info.file_creation_time = src_stat.st_mtime;
    
    char* cmd = "cp -p ";
    strcat(cmd, argv[1]);
    strcat(cmd, " ");
    strcat(cmd, backup_filename);
    
    pid_t pid = fork();
    
    if (pid == 0) {
        execlp("cp", "cp", argv[1], backup_filename, NULL);
        exit(1);
    } else if (pid < 0) {
        perror("Fork failed");
        exit(1);
    } else {
        int status;
        waitpid(pid, &status, 0);
        
        if (WIFEXITED(status)) {
            if (WEXITSTATUS(status) == 0) {
                printf("Backup of %s to %s successful.\n", argv[1], backup_filename);
            } else {
                printf("Error: failed to create backup of %s to %s.\n", argv[1], backup_filename);
            }
        } else if (WIFSIGNALED(status)) {
            printf("Error: backup of %s to %s failed due to signal %d.\n", argv[1], backup_filename, WTERMSIG(status));
        } else {
            printf("Error: unknown failure during backup of %s to %s.\n", argv[1], backup_filename);
        }
        
        close(src_fd);
        close(dest_fd);
        free(backup_filename);
    }
    
    return 0;
}