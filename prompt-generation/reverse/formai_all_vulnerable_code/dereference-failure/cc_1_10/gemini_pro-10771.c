//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/resource.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>

#define MAX_PATH_LEN 1024

static void view_process(pid_t pid, const char *path)
{
    struct stat st;
    char buf[MAX_PATH_LEN];
    FILE *fp;
    int fd;

    if (stat(path, &st) < 0) {
        perror("stat");
        return;
    }
    if (!S_ISDIR(st.st_mode)) {
        fprintf(stderr, "%s is not a directory\n", path);
        return;
    }

    snprintf(buf, MAX_PATH_LEN, "%s/%d/cmdline", path, pid);
    if ((fd = open(buf, O_RDONLY)) < 0) {
        perror("open");
        return;
    }
    if ((fp = fdopen(fd, "r")) == NULL) {
        perror("fdopen");
        close(fd);
        return;
    }
    if (fgets(buf, MAX_PATH_LEN, fp) == NULL) {
        perror("fgets");
        fclose(fp);
        return;
    }
    fclose(fp);

    printf("Process %d: %s\n", pid, buf);
}

int main(int argc, char *argv[])
{
    DIR *dir;
    struct dirent *entry;
    char path[MAX_PATH_LEN];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if ((dir = opendir(argv[1])) == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        snprintf(path, MAX_PATH_LEN, "%s/%s", argv[1], entry->d_name);
        view_process(atoi(entry->d_name), path);
    }

    closedir(dir);

    return EXIT_SUCCESS;
}