//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <string.h>

#define MAX_MSG_SIZE 1024

typedef struct {
    int fd;
    char *buf;
    size_t buf_size;
    size_t buf_pos;
} Image;

int init_image(Image *img, const char *path) {
    int fd = open(path, O_RDONLY);
    if (fd < 0) {
        perror("open");
        return -1;
    }
    struct stat st;
    if (fstat(fd, &st) < 0) {
        perror("fstat");
        return -1;
    }
    char *buf = malloc(st.st_size);
    if (!buf) {
        perror("malloc");
        return -1;
    }
    if (read(fd, buf, st.st_size) != st.st_size) {
        perror("read");
        return -1;
    }
    img->fd = fd;
    img->buf = buf;
    img->buf_size = st.st_size;
    img->buf_pos = 0;
    return 0;
}

void deinit_image(Image *img) {
    close(img->fd);
    free(img->buf);
}

int read_byte(Image *img) {
    if (img->buf_pos >= img->buf_size) {
        return -1;
    }
    return img->buf[img->buf_pos++];
}

int write_byte(Image *img, unsigned char byte) {
    if (img->buf_pos >= img->buf_size) {
        return -1;
    }
    img->buf[img->buf_pos++] = byte;
    return 0;
}

int hide_msg(Image *img, const char *msg) {
    size_t msg_len = strlen(msg);
    if (msg_len > MAX_MSG_SIZE) {
        fprintf(stderr, "Message too long\n");
        return -1;
    }
    unsigned char msg_len_byte = msg_len;
    if (write_byte(img, msg_len_byte) < 0) {
        return -1;
    }
    for (size_t i = 0; i < msg_len; i++) {
        if (write_byte(img, msg[i]) < 0) {
            return -1;
        }
    }
    return 0;
}

char *reveal_msg(Image *img) {
    unsigned char msg_len_byte = read_byte(img);
    if (msg_len_byte == -1) {
        return NULL;
    }
    char *msg = malloc(msg_len_byte + 1);
    if (!msg) {
        return NULL;
    }
    for (size_t i = 0; i < msg_len_byte; i++) {
        int byte = read_byte(img);
        if (byte == -1) {
            free(msg);
            return NULL;
        }
        msg[i] = byte;
    }
    msg[msg_len_byte] = '\0';
    return msg;
}

int main() {
    Image img;
    if (init_image(&img, "image.jpg") < 0) {
        return -1;
    }
    if (hide_msg(&img, "Hello world") < 0) {
        deinit_image(&img);
        return -1;
    }
    char *msg = reveal_msg(&img);
    if (!msg) {
        deinit_image(&img);
        return -1;
    }
    printf("Message: %s\n", msg);
    free(msg);
    deinit_image(&img);
    return 0;
}