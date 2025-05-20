//MISTRAL-7B DATASET v1.0 Category: Smart home light control ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <linux/i2c.h>

#define I2C_ADDR 0x3F
#define LED_ON 0x01
#define LED_OFF 0x00

int main(void) {
    int i2c_fd, i;
    char buf[2];
    char *map_base;

    i2c_fd = open("/dev/i2c-1", O_RDWR);
    if (i2c_fd < 0) {
        perror("Failed to open I2C bus");
        exit(1);
    }

    if (ioctl(i2c_fd, I2C_SLAVE, I2C_ADDR) < 0) {
        perror("Failed to open slave address");
        exit(1);
    }

    map_base = mmap(NULL, 1024, PROT_READ | PROT_WRITE, MAP_PRIVATE, i2c_fd, 0);
    if (map_base == MAP_FAILED) {
        perror("Failed to map i2c memory");
        exit(1);
    }

    signal(SIGINT, SIG_IGN);

    while (1) {
        buf[0] = LED_ON;
        write(i2c_fd, buf, 1);
        usleep(500000); // wait for half second

        buf[0] = LED_OFF;
        write(i2c_fd, buf, 1);
        usleep(500000); // wait for half second

        for (i = 0; i < 1024; i++) { // read i2c memory
            printf("%x ", ((char *)map_base)[i]);
        }
        printf("\n");
    }

    munmap(map_base, 1024);
    close(i2c_fd);
    return 0;
}