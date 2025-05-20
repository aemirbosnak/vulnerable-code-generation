//FormAI DATASET v1.0 Category: Image Steganography ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pthread.h>

#define BUFFER_SIZE 512

typedef struct {
    uint8_t *data;
    size_t size;
} image_t;

typedef struct {
    char *msg;
    size_t msg_size;
    image_t image;
} steganography_data_t;

static int read_image(const char *filename, image_t *image) {
    struct stat st;
    int fd;

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return -1;
    }

    if (fstat(fd, &st) == -1) {
        perror("fstat");
        close(fd);
        return -1;
    }

    if (!S_ISREG(st.st_mode)) {
        fprintf(stderr, "%s is not a regular file\n", filename);
        close(fd);
        return 0;
    }

    image->size = st.st_size;
    image->data = malloc(image->size);
    if (!image->data) {
        perror("malloc");
        close(fd);
        return -1;
    }

    if (read(fd, image->data, image->size) != image->size) {
        perror("read");
        free(image->data);
        close(fd);
        return -1;
    }

    close(fd);

    return 0;
}

static int write_image(const char *filename, image_t *image) {
    int fd;

    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        return -1;
    }

    if (write(fd, image->data, image->size) != image->size) {
        perror("write");
        close(fd);
        return -1;
    }

    close(fd);

    return 0;
}

static void *steganography_thread(void *arg) {
    const steganography_data_t *data = (steganography_data_t *)arg;
    int msgpos, bitpos;
    size_t imagepos;
    uint8_t bit;
    uint8_t *imgptr;
    uint8_t *msgptr;

    msgpos = 0;
    bitpos = 0;
    imagepos = 0;
    imgptr = data->image.data;
    msgptr = data->msg;

    while (msgpos < data->msg_size) {
        if (bitpos >= 8) {
            ++msgpos;
            bitpos = 0;
            ++msgptr;
        }

        if (imagepos >= data->image.size) {
            fprintf(stderr, "not enough space in image for message\n");
            break;
        }

        bit = (*msgptr & (1 << bitpos)) >> bitpos;
        *imgptr = (*imgptr & 0xfe) | bit;

        ++imagepos;
        ++bitpos;
        ++imgptr;
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    const char *input_file, *output_file;
    const char *message;
    size_t message_size;
    pthread_t thread;
    steganography_data_t data;
    int ret;

    if (argc < 4) {
        fprintf(stderr, "usage: %s <input_file> <output_file> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    input_file = argv[1];
    output_file = argv[2];
    message = argv[3];
    message_size = strlen(message);

    printf("reading image '%s'\n", input_file);
    if (read_image(input_file, &data.image) == -1) {
        fprintf(stderr, "could not read input file '%s'\n", input_file);
        return EXIT_FAILURE;
    }

    if (message_size > data.image.size) {
        fprintf(stderr, "message is too large to fit in image\n");
        return EXIT_FAILURE;
    }

    data.msg = malloc(message_size);
    if (!data.msg) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    memcpy(data.msg, message, message_size);
    data.msg_size = message_size;

    printf("embedding message in image\n");
    ret = pthread_create(&thread, NULL, steganography_thread, &data);
    if (ret != 0) {
        fprintf(stderr, "could not create thread: %s\n", strerror(ret));
        return EXIT_FAILURE;
    }

    pthread_join(thread, NULL);

    printf("writing image to '%s'\n", output_file);
    if (write_image(output_file, &data.image) == -1) {
        fprintf(stderr, "could not write output file '%s'\n", output_file);
        return EXIT_FAILURE;
    }

    free(data.msg);
    free(data.image.data);

    printf("done\n");

    return EXIT_SUCCESS;
}