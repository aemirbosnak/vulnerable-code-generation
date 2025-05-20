//MISTRAL-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>

#define RC_MEM_SIZE 0x1000
#define RC_DEVICE "/dev/rcvehicle"

typedef struct {
    char id;
    char mode;
    char ch_a;
    char ch_b;
    char ch_c;
} rc_packet_t;

int main() {
    int fd;
    char *map_base;
    rc_packet_t *packet;

    fd = open(RC_DEVICE, O_RDWR | O_SYNC);
    if (fd < 0) {
        perror("Error opening rcvehicle device");
        exit(EXIT_FAILURE);
    }

    if (ftruncate(fd, RC_MEM_SIZE) < 0) {
        perror("Error truncating rcvehicle device");
        exit(EXIT_FAILURE);
    }

    map_base = mmap(NULL, RC_MEM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (map_base == MAP_FAILED) {
        perror("Error mmaping rcvehicle device memory");
        exit(EXIT_FAILURE);
    }

    packet = (rc_packet_t *) map_base;

    while (1) {
        // Set vehicle mode to remote control
        packet->mode = 1;

        // Set channel A to full throttle forward
        packet->ch_a = 100;

        // Set channel B to full steering left
        packet->ch_b = 100;

        // Set channel C to neutral
        packet->ch_c = 50;

        write(fd, packet, sizeof(rc_packet_t));

        usleep(100000); // Delay for 100ms to prevent packet flooding

        // Set channel A to full throttle backward
        packet->ch_a = -100;

        // Set channel B to full steering right
        packet->ch_b = -100;

        // Set channel C to full throttle
        packet->ch_c = 100;

        write(fd, packet, sizeof(rc_packet_t));
    }

    munmap(map_base, RC_MEM_SIZE);
    close(fd);

    return EXIT_SUCCESS;
}