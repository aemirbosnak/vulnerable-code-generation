//Falcon2-11B DATASET v1.0 Category: System process viewer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>

#define MAX_PATH_LENGTH 256

void display_process_statistics() {
    DIR *dir;
    struct dirent *ent;
    struct stat st;

    int fd;
    char path[MAX_PATH_LENGTH];

    printf("Process Statistics\n");
    printf("--------------------\n");

    dir = opendir("/proc");
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_name[0] == '.') {
            continue;
        }

        sprintf(path, "/proc/%s", ent->d_name);
        fd = open(path, O_RDONLY);
        if (fd == -1) {
            perror("open");
            continue;
        }

        if (fstat(fd, &st) == -1) {
            perror("fstat");
            continue;
        }

        printf("%s\t%ld\t%ld\t%ld\n", ent->d_name, st.st_uid, st.st_mode, st.st_size);

        close(fd);
    }

    closedir(dir);
}

int main() {
    display_process_statistics();
    return 0;
}