//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFSIZE 1024
#define PROC_DIR "/proc/"

typedef struct {
    char **argv;
    int argc;
    pid_t pid;
} proc_info;

int get_proc_info(proc_info *info, pid_t pid) {
    char path[BUFSIZE];
    int fd;
    char buf[BUFSIZE];
    int i;

    snprintf(path, BUFSIZE, PROC_DIR "%d/cmdline", pid);

    if ((fd = open(path, O_RDONLY)) < 0) {
        return -1;
    }

    if (read(fd, buf, BUFSIZE) < 0) {
        close(fd);
        return -1;
    }

    close(fd);

    info->pid = pid;

    // count the number of arguments
    info->argc = 0;
    for (i = 0; buf[i] != '\0'; i++) {
        if (buf[i] == '\0') {
            info->argc++;
        }
    }

    // allocate memory for the arguments
    info->argv = malloc(sizeof(char *) * (info->argc + 1));
    if (info->argv == NULL) {
        return -1;
    }

    // parse the arguments
    i = 0;
    info->argv[0] = buf;
    for (i = 1; i < info->argc; i++) {
        info->argv[i] = strchr(info->argv[i - 1] + 1, '\0') + 1;
    }
    info->argv[i] = NULL;

    return 0;
}

void free_proc_info(proc_info *info) {
    if (info->argv != NULL) {
        free(info->argv);
    }
}

int main(int argc, char **argv) {
    pid_t pid;
    proc_info info;
    int i;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <pid>\n", argv[0]);
        return EXIT_FAILURE;
    }

    pid = atoi(argv[1]);

    if (get_proc_info(&info, pid) < 0) {
        perror("get_proc_info");
        return EXIT_FAILURE;
    }

    printf("Process %d: %s\n", info.pid, info.argv[0]);
    for (i = 1; i < info.argc; i++) {
        printf("  %s\n", info.argv[i]);
    }

    free_proc_info(&info);

    return EXIT_SUCCESS;
}