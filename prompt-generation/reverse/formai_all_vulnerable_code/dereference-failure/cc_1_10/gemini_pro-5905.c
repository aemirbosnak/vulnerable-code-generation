//GEMINI-pro DATASET v1.0 Category: Temperature monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>
#include <errno.h>

#define TEMP_FILE "/sys/class/thermal/thermal_zone0/temp"
#define POLL_TIMEOUT 1000 // ms

int main(int argc, char **argv) {
    int fd = open(TEMP_FILE, O_RDONLY);
    if (fd < 0) {
        perror("open");
        return EXIT_FAILURE;
    }

    struct pollfd pfd = {
        .fd = fd,
        .events = POLLIN,
    };

    while (1) {
        int ret = poll(&pfd, 1, POLL_TIMEOUT);
        if (ret < 0) {
            if (errno == EINTR) {
                continue;
            } else {
                perror("poll");
                return EXIT_FAILURE;
            }
        } else if (ret == 0) {
            // Timeout
        } else {
            // Data available to read
            char buf[16];
            int bytes_read = read(fd, buf, sizeof(buf));
            if (bytes_read < 0) {
                perror("read");
                return EXIT_FAILURE;
            }

            // Parse the temperature
            long temp = strtol(buf, NULL, 10);
            if (temp < 0) {
                fprintf(stderr, "Invalid temperature: %s\n", buf);
                return EXIT_FAILURE;
            }

            // Print the temperature
            printf("Temperature: %ld\n", temp);
        }
    }

    close(fd);

    return EXIT_SUCCESS;
}