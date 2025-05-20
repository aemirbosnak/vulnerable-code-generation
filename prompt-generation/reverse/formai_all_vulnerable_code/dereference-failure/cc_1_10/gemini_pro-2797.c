//GEMINI-pro DATASET v1.0 Category: System event logger ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/eventfd.h>
#include <unistd.h>

#define EVENT_SIZE 64

static int efd;

static void setup_logger(void) {
    efd = eventfd(0, EFD_NONBLOCK);
    if (efd == -1) {
        perror("eventfd");
        exit(EXIT_FAILURE);
    }
}

static void write_event(const char *event) {
    int ret;
    size_t len = strlen(event);

    if (len > EVENT_SIZE) {
        fprintf(stderr, "Event too long: %s\n", event);
        return;
    }

    ret = write(efd, event, len);
    if (ret == -1) {
        perror("write");
        return;
    }
}

static void read_events(void) {
    char buffer[EVENT_SIZE];
    int ret;

    while (1) {
        ret = read(efd, buffer, sizeof(buffer));
        if (ret == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        printf("Received event: %s\n", buffer);
    }
}

int main(int argc, char **argv) {
    setup_logger();

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <event>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    write_event(argv[1]);

    read_events();

    return EXIT_SUCCESS;
}