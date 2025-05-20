//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <poll.h>
#include <time.h>
#include <signal.h>

#define MAX_NAME_LEN 50
#define MAX_VOTES 100
#define MAX_VOTERS 100

struct vote {
    int voter;
    int candidate;
};

struct voter {
    char name[MAX_NAME_LEN];
    int votes[MAX_VOTES];
};

int main(int argc, char *argv[]) {
    int fd, pid;
    int opt = 0;
    int nvotes = 0;
    int nvoters = 0;
    struct voter voters[MAX_VOTERS];
    struct vote votes[MAX_VOTES];

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <file> <votes>\n", argv[0]);
        exit(1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    struct stat statbuf;
    if (fstat(fd, &statbuf) == -1) {
        perror("fstat");
        exit(1);
    }

    char *data = (char *)malloc(statbuf.st_size);
    if (data == NULL) {
        perror("malloc");
        exit(1);
    }

    if (read(fd, data, statbuf.st_size)!= statbuf.st_size) {
        perror("read");
        exit(1);
    }

    nvotes = atoi(argv[2]);
    nvoters = atoi(data);

    for (int i = 0; i < nvotes; i++) {
        votes[i].voter = atoi(data);
        votes[i].candidate = atoi(data);
        data += 2;
    }

    printf("Election Results:\n");

    for (int i = 0; i < nvotes; i++) {
        printf("%s: %d\n", voters[votes[i].voter].name, votes[i].candidate);
    }

    close(fd);
    return 0;
}