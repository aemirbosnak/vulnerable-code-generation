//Falcon2-11B DATASET v1.0 Category: System event logger ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <dirent.h>
#include <sys/time.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(1);
    }

    char *logdir = argv[1];
    char *logfile = NULL;
    char *logprefix = "log";
    char *logsuffix = ".log";

    struct timeval tv;
    gettimeofday(&tv, NULL);
    int t = tv.tv_sec % 100;

    if ((logfile = (char *)malloc(sizeof(char) * (strlen(logdir) + strlen(logprefix) + strlen(logsuffix) + 1))) == NULL) {
        fprintf(stderr, "Error: unable to allocate memory for logfile\n");
        exit(1);
    }

    sprintf(logfile, "%s/%s%s%s%d.log", logdir, logprefix, t? t : "0", logsuffix);

    int logfd = open(logfile, O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0644);
    if (logfd == -1) {
        fprintf(stderr, "Error: unable to open logfile '%s'\n", logfile);
        exit(1);
    }

    int i;
    for (i = 0; i < 1000000; i++) {
        fprintf(logfd, "%d\n", i);
    }

    close(logfd);

    return 0;
}