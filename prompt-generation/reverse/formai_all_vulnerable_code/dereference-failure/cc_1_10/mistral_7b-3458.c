//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define VOTE_FILE "/etc/voting.dat"
#define BUF_SIZE 1024

int main(int argc, char **argv) {
    int fd, i, len, vote;
    char cmd[100], buf[BUF_SIZE];
    char *candidates[] = {"Candidate1", "Candidate2", "Candidate3"};

    if (argc != 3) {
        printf("Usage: %s <vote> <password>\n", argv[0]);
        return 1;
    }

    fd = open(VOTE_FILE, O_RDWR);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    if (strcmp(argv[2], "password123") != 0) {
        printf("Incorrect password!\n");
        close(fd);
        return 1;
    }

    printf("Voting started...\n");

    for (i = 0; i < 3; i++) {
        if (strcmp(argv[1], candidates[i]) == 0) {
            lseek(fd, i * sizeof(int), SEEK_SET);
            read(fd, &vote, sizeof(int));
            vote++;
            write(fd, &vote, sizeof(int));
            printf("Your vote has been recorded for %s.\n", candidates[i]);
            break;
        }
    }

    if (i == 3) {
        printf("Invalid candidate!\n");
    }

    close(fd);

    sprintf(cmd, "rm /tmp/%s%d.log", argv[1], getpid());
    system(cmd);

    return 0;
}