//Falcon2-11B DATASET v1.0 Category: Disk space analyzer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <math.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }
    
    char *dir = argv[1];
    if (access(dir, F_OK)!= 0) {
        fprintf(stderr, "%s: No such file or directory\n", dir);
        return 1;
    }
    
    struct dirent *dp;
    DIR *dirp;
    if ((dirp = opendir(dir)) == NULL) {
        fprintf(stderr, "%s: Cannot open directory\n", dir);
        return 1;
    }
    
    while ((dp = readdir(dirp))!= NULL) {
        if (dp->d_type == DT_DIR) {
            if (access(dp->d_name, F_OK) == 0) {
                char *subdir = malloc(strlen(dp->d_name) + 1);
                strcpy(subdir, dp->d_name);
                int status = 0;
                int pid = fork();
                if (pid == 0) {
                    char *command = "du -s ";
                    char *args[2];
                    args[0] = command;
                    args[1] = subdir;
                    execlp("du", "du", "-s", subdir, NULL);
                    _exit(1);
                } else if (pid > 0) {
                    waitpid(pid, &status, 0);
                } else {
                    fprintf(stderr, "Fork failed\n");
                }
                free(subdir);
            }
        }
    }
    
    closedir(dirp);
    return 0;
}