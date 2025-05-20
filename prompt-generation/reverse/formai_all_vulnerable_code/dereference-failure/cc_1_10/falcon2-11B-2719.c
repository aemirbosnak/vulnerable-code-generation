//Falcon2-11B DATASET v1.0 Category: System process viewer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

void print_processes(const char *path) {
    DIR *dirp;
    struct dirent *dirp_ent;
    char buffer[256];

    if ((dirp = opendir(path)) == NULL) {
        fprintf(stderr, "Could not open directory %s: %s\n", path, strerror(errno));
        exit(1);
    }

    while ((dirp_ent = readdir(dirp))!= NULL) {
        if (dirp_ent->d_type == DT_DIR) {
            if (strcmp(dirp_ent->d_name, ".") == 0 || strcmp(dirp_ent->d_name, "..") == 0)
                continue;
            print_processes(path + strlen(path) + 1);
        } else if (dirp_ent->d_type == DT_REG && strcmp(dirp_ent->d_name, "PID") == 0) {
            sprintf(buffer, "%s%s%s%s%s%s%s", path, dirp_ent->d_name, "/", dirp_ent->d_name, "/", dirp_ent->d_name, "/");
            int pid = open(buffer, O_RDONLY);
            if (pid == -1) {
                fprintf(stderr, "Error opening process %s: %s\n", dirp_ent->d_name, strerror(errno));
                exit(1);
            }
            waitpid(pid, NULL, 0);
        }
    }

    closedir(dirp);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        exit(1);
    }

    print_processes(argv[1]);

    return 0;
}