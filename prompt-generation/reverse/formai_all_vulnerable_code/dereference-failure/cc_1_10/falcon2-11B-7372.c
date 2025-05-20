//Falcon2-11B DATASET v1.0 Category: Temperature monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <signal.h>

#define I2C_SLAVE_ADDR 0x48
#define TEMP_REG 0x00
#define THRES_C 20
#define THRES_F 68

void read_temperature() {
    int fd;
    int ret;
    int ch;
    char buf[100];
    float temp_c, temp_f;

    fd = open("/dev/i2c-1", O_RDWR);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    ret = ioctl(fd, I2C_SLAVE, I2C_SLAVE_ADDR);
    if (ret < 0) {
        perror("ioctl");
        exit(1);
    }

    ret = read(fd, buf, 100);
    if (ret < 0) {
        perror("read");
        exit(1);
    }

    temp_c = (float)atoi(buf) / 1000;

    if (temp_c > THRES_C) {
        printf("Temperature is too high!\n");
        signal(SIGINT, SIG_IGN);
        exit(1);
    } else {
        temp_f = (temp_c * 9/5) + 32;
        printf("Temperature is %.1f C = %.1f F\n", temp_c, temp_f);
        exit(0);
    }
}

int main(int argc, char *argv[]) {
    signal(SIGINT, SIG_IGN);

    read_temperature();

    return 0;
}