//Falcon2-11B DATASET v1.0 Category: Temperature monitor ; Style: automated
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#define FNULL "/dev/null"

int main(int argc, char **argv) {
    int fd, i, ret, t = 0, lastt = 0;
    char buf[128];

    if (argc!= 2) {
        fprintf(stderr, "usage: %s <interval>\n", argv[0]);
        exit(1);
    }

    t = atoi(argv[1]);
    fd = open("/sys/class/thermal/thermal_zone0/temp", O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "failed to open temp sensor: %s\n", strerror(errno));
        exit(1);
    }

    for (;;) {
        ret = read(fd, buf, 128);
        if (ret == 0) {
            fprintf(stderr, "failed to read from temp sensor: %s\n", strerror(errno));
            exit(1);
        }

        if (ret!= 128) {
            fprintf(stderr, "invalid temperature value\n");
            exit(1);
        }

        if (lastt!= t) {
            printf("%d ", buf[0] - '0');
            lastt = t;
        }

        if (t!= 0)
            sleep(t);

        t = atoi(buf);
    }

    close(fd);
    return 0;
}