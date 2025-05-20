//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <pthread.h>

#define IOCTL_VIRUS_SCAN _IOW('v', 0, int)

struct virus_scan_request {
    char *filename;
    int fd;
    int result;
};

static void *virus_scan_thread(void *arg)
{
    struct virus_scan_request *req = arg;

    req->result = ioctl(req->fd, IOCTL_VIRUS_SCAN);
    if (req->result < 0) {
        perror("ioctl(IOCTL_VIRUS_SCAN)");
        req->result = -1;
    }

    close(req->fd);
    free(req->filename);
    free(req);

    return NULL;
}

int main(int argc, char **argv)
{
    int i;
    pthread_t *threads;
    struct virus_scan_request *reqs;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file1> <file2> ...\n", argv[0]);
        return EXIT_FAILURE;
    }

    threads = malloc(sizeof(pthread_t) * (argc - 1));
    reqs = malloc(sizeof(struct virus_scan_request) * (argc - 1));
    if (!threads || !reqs) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    for (i = 1; i < argc; i++) {
        reqs[i - 1].filename = strdup(argv[i]);
        reqs[i - 1].fd = open(argv[i], O_RDONLY);
        if (reqs[i - 1].fd < 0) {
            perror("open");
            return EXIT_FAILURE;
        }

        if (pthread_create(&threads[i - 1], NULL, virus_scan_thread, &reqs[i - 1]) != 0) {
            perror("pthread_create");
            return EXIT_FAILURE;
        }
    }

    for (i = 1; i < argc; i++) {
        pthread_join(threads[i - 1], NULL);
        if (reqs[i - 1].result == 0) {
            printf("%s: clean\n", reqs[i - 1].filename);
        } else if (reqs[i - 1].result == 1) {
            printf("%s: infected\n", reqs[i - 1].filename);
        } else {
            printf("%s: error\n", reqs[i - 1].filename);
        }
    }

    free(threads);
    free(reqs);

    return EXIT_SUCCESS;
}