//MISTRAL-7B DATASET v1.0 Category: Traffic Light Controller ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <linux/i2c.h>

#define I2C_ADDR 0x62

typedef struct {
    unsigned char red;
    unsigned char yellow;
    unsigned char green;
} RGB;

int main(int argc, char *argv[]) {
    int i2c_file;
    RGB colors;

    if (argc != 2) {
        printf("Usage: %s <mode>\n", argv[0]);
        return 1;
    }

    i2c_file = open("/dev/i2c-1", O_RDWR);
    if (i2c_file < 0) {
        perror("Error opening i2c bus");
        return 1;
    }

    if (ioctl(i2c_file, I2C_SLAVE, I2C_ADDR) < 0) {
        perror("Error accessing i2c slave");
        return 1;
    }

    switch(argv[1][0]) {
        case 'R':
            colors.red = 0xff;
            colors.yellow = 0x00;
            colors.green = 0x00;
            break;
        case 'Y':
            colors.red = 0x00;
            colors.yellow = 0xff;
            colors.green = 0x00;
            break;
        case 'G':
            colors.red = 0x00;
            colors.yellow = 0x00;
            colors.green = 0xff;
            break;
        default:
            printf("Invalid mode\n");
            return 1;
    }

    if (write(i2c_file, &colors, sizeof(RGB)) != sizeof(RGB)) {
        perror("Error writing to i2c device");
        return 1;
    }

    close(i2c_file);

    printf("Traffic light color set to %s\n", argv[1]);

    return 0;
}