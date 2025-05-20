//Falcon2-11B DATASET v1.0 Category: QR code reader ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <zlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>

#define BUF_SIZE 1024

typedef struct {
    char *data;
    int length;
} QrData;

typedef struct {
    int fd;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
} QrReader;

void *read_qr_thread(void *arg) {
    QrReader *reader = (QrReader *)arg;
    char buf[BUF_SIZE];
    int ret;

    while (1) {
        pthread_mutex_lock(&reader->mutex);
        while (reader->fd == -1) {
            pthread_cond_wait(&reader->cond, &reader->mutex);
        }

        ret = read(reader->fd, buf, BUF_SIZE);
        if (ret == -1) {
            perror("read error");
            exit(1);
        }

        pthread_mutex_unlock(&reader->mutex);

        if (ret == 0) {
            printf("No more QR code data\n");
            break;
        }

        QrData data;
        data.data = (char *)malloc(ret);
        data.length = ret;
        memcpy(data.data, buf, ret);

        pthread_mutex_lock(&reader->mutex);
        reader->fd = -1;
        pthread_cond_signal(&reader->cond);
        pthread_mutex_unlock(&reader->mutex);
    }

    return NULL;
}

void *write_qr_thread(void *arg) {
    QrReader *reader = (QrReader *)arg;
    char buf[BUF_SIZE];
    int ret;

    while (1) {
        pthread_mutex_lock(&reader->mutex);
        while (reader->fd == -1) {
            pthread_cond_wait(&reader->cond, &reader->mutex);
        }

        ret = write(reader->fd, buf, BUF_SIZE);
        if (ret == -1) {
            perror("write error");
            exit(1);
        }

        pthread_mutex_unlock(&reader->mutex);
    }

    return NULL;
}

int main(int argc, char **argv) {
    QrReader reader;
    int fd;
    pthread_t read_thread, write_thread;
    char *qr_data;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        exit(1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open error");
        exit(1);
    }

    reader.fd = fd;
    pthread_mutex_init(&reader.mutex, NULL);
    pthread_cond_init(&reader.cond, NULL);

    qr_data = (char *)malloc(BUF_SIZE);
    read(fd, qr_data, BUF_SIZE);

    pthread_create(&read_thread, NULL, read_qr_thread, (void *)&reader);
    pthread_create(&write_thread, NULL, write_qr_thread, (void *)&reader);

    while (1) {
        pthread_mutex_lock(&reader.mutex);
        if (reader.fd == -1) {
            pthread_mutex_unlock(&reader.mutex);
            break;
        }
        pthread_mutex_unlock(&reader.mutex);

        printf("QR code data: %s\n", qr_data);

        free(qr_data);
        qr_data = (char *)malloc(BUF_SIZE);
        read(fd, qr_data, BUF_SIZE);
    }

    close(fd);

    pthread_join(read_thread, NULL);
    pthread_join(write_thread, NULL);

    return 0;
}