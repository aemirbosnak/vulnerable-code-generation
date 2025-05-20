//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int fd, i, n;
    char filename[BUFFER_SIZE];
    char buffer[BUFFER_SIZE];
    struct rusage usage;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    strcpy(filename, argv[1]);

    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }

    while (1) {
        getrusage(RUSAGE_SELF, &usage);
        n = read(fd, buffer, BUFFER_SIZE);
        if (n < 0) {
            printf("Error: Cannot read file %s\n", filename);
            exit(1);
        }
        if (n == 0) {
            printf("End of file reached\n");
            break;
        }
        for (i = 0; i < n; i++) {
            printf("%c", buffer[i]);
        }
        fflush(stdout);
    }

    close(fd);
    return 0;
}