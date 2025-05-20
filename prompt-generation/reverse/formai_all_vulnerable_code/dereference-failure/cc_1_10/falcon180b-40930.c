//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/mman.h>

#define I2C_SLAVE 0x70
#define TEMP_REG 0x00
#define CONFIG_REG 0x01
#define RESOLUTION_12BIT 0b1100

int main(void) {
    int file;
    char *dev_mem;
    int mem_size;
    int i;
    int temp;
    int config;
    int resolution;

    file = open("/dev/mem", O_RDWR|O_SYNC);
    if (file == -1) {
        printf("Failed to open /dev/mem\n");
        exit(1);
    }

    dev_mem = mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_SHARED, file, 0x48004000);
    if (dev_mem == MAP_FAILED) {
        printf("Failed to map /dev/mem\n");
        exit(1);
    }

    mem_size = 4096;
    for (i = 0; i < mem_size; i += 4) {
        if (dev_mem[i] == 0x50) {
            printf("Found I2C device at 0x%X\n", (unsigned int)dev_mem + i);
            break;
        }
    }

    if (i == mem_size) {
        printf("I2C device not found\n");
        exit(1);
    }

    config = dev_mem[i + 6];
    resolution = (config >> 4) & 0b111;
    if (resolution!= RESOLUTION_12BIT) {
        printf("Unsupported temperature resolution\n");
        exit(1);
    }

    while (1) {
        temp = dev_mem[i + 2] << 4 | (dev_mem[i + 3] >> 4);
        printf("Temperature: %d.%d C\n", temp / 16, temp % 16);
        usleep(100000);
    }

    munmap(dev_mem, mem_size);
    close(file);

    return 0;
}