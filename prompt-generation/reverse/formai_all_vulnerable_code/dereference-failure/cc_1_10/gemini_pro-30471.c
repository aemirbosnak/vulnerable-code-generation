//GEMINI-pro DATASET v1.0 Category: QR code generator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <err.h>

#define QR_SIZE 21
#define QR_VERSION 1

void init_qr(unsigned char qr[QR_SIZE][QR_SIZE]) {
    memset(qr, 0, sizeof(qr));
    qr[7][7] = 1;
    qr[7][8] = 1;
    qr[7][9] = 1;
    qr[7][10] = 1;
    qr[7][11] = 1;
    qr[8][7] = 1;
    qr[9][7] = 1;
    qr[10][7] = 1;
    qr[11][7] = 1;
}

void print_qr(unsigned char qr[QR_SIZE][QR_SIZE]) {
    for (int i = 0; i < QR_SIZE; i++) {
        for (int j = 0; j < QR_SIZE; j++) {
            printf("%c", qr[i][j] ? '#' : '.');
        }
        printf("\n");
    }
}

void save_qr(unsigned char qr[QR_SIZE][QR_SIZE], const char *filename) {
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        err(1, "open(%s)", filename);
    }
    for (int i = 0; i < QR_SIZE; i++) {
        write(fd, qr[i], QR_SIZE);
        write(fd, "\n", 1);
    }
    close(fd);
    printf("QR code saved to %s\n", filename);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <string> <filename>\n", argv[0]);
        return 1;
    }
    char *string = argv[1];
    const char *filename = argv[2];
    size_t string_len = strlen(string);
    if (string_len > 255) {
        fprintf(stderr, "String too long (max 255 characters)\n");
        return 1;
    }
    unsigned char qr[QR_SIZE][QR_SIZE];
    init_qr(qr);
    // TODO: Implement QR code generation algorithm
    print_qr(qr);
    save_qr(qr, filename);
    return 0;
}