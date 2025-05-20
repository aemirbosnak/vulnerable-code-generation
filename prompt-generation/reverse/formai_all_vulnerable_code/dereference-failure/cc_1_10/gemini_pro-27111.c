//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <aio.h>

#define BUFFSIZE 1024

struct my_aiocb {
    struct aiocb aio;
    char *buf;
    size_t len;
};

void aio_read_done(struct my_aiocb *aiocb) {
    int ret;
    
    ret = aio_error(&aiocb->aio);
    if (ret != 0) {
        perror("aio_error");
        return;
    }

    ret = aio_return(&aiocb->aio);
    if (ret != aiocb->len) {
        fprintf(stderr, "aio_return returned %d, expected %zu\n", ret, aiocb->len);
        return;
    }

    printf("%s\n", aiocb->buf);
    free(aiocb->buf);
    free(aiocb);
}

void aio_write_done(struct my_aiocb *aiocb) {
    int ret;
    
    ret = aio_error(&aiocb->aio);
    if (ret != 0) {
        perror("aio_error");
        return;
    }

    ret = aio_return(&aiocb->aio);
    if (ret != aiocb->len) {
        fprintf(stderr, "aio_return returned %d, expected %zu\n", ret, aiocb->len);
        return;
    }

    free(aiocb->buf);
    free(aiocb);
}

int main(int argc, char **argv) {
    int fd;
    int ret;
    struct my_aiocb *aiocb;
    struct sigevent event;
    char *buf;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    buf = malloc(BUFFSIZE);
    if (buf == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    aiocb = malloc(sizeof(struct my_aiocb));
    if (aiocb == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    memset(&event, 0, sizeof(event));
    event.sigev_notify = SIGEV_THREAD;
    event.sigev_notify_function = aio_read_done;
    event.sigev_notify_attributes = NULL;
    event.sigev_value.sival_ptr = aiocb;

    aiocb->aio.aio_fildes = fd;
    aiocb->aio.aio_buf = buf;
    aiocb->aio.aio_nbytes = BUFFSIZE;
    aiocb->aio.aio_offset = 0;
    aiocb->aio.aio_sigevent = event;

    ret = aio_read(&aiocb->aio);
    if (ret == -1) {
        perror("aio_read");
        return EXIT_FAILURE;
    }

    fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    aiocb = malloc(sizeof(struct my_aiocb));
    if (aiocb == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    memset(&event, 0, sizeof(event));
    event.sigev_notify = SIGEV_THREAD;
    event.sigev_notify_function = aio_write_done;
    event.sigev_notify_attributes = NULL;
    event.sigev_value.sival_ptr = aiocb;

    aiocb->aio.aio_fildes = fd;
    aiocb->aio.aio_buf = buf;
    aiocb->aio.aio_nbytes = BUFFSIZE;
    aiocb->aio.aio_offset = 0;
    aiocb->aio.aio_sigevent = event;

    ret = aio_write(&aiocb->aio);
    if (ret == -1) {
        perror("aio_write");
        return EXIT_FAILURE;
    }

    while (aio_error(&aiocb->aio) == EINPROGRESS) {
        sleep(1);
    }

    close(fd);
    return EXIT_SUCCESS;
}