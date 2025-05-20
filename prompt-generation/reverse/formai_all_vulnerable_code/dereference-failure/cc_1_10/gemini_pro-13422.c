//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

typedef struct {
    int x;
    int y;
    int z;
    int yaw;
    int pitch;
    int roll;
} Drone;

void print_drone(Drone *drone) {
    printf("x: %d, y: %d, z: %d, yaw: %d, pitch: %d, roll: %d\n", drone->x, drone->y, drone->z, drone->yaw, drone->pitch, drone->roll);
}

int main() {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        return EXIT_FAILURE;
    }

    char buffer[BUFFER_SIZE];
    int addr_len = sizeof(addr);

    while (1) {
        // Receive data from the client
        int recv_len = recvfrom(sock, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&addr, &addr_len);
        if (recv_len < 0) {
            perror("recvfrom");
            return EXIT_FAILURE;
        }

        // Parse the data
        char *tokens[6];
        int i = 0;
        char *token = strtok(buffer, ",");
        while (token != NULL) {
            tokens[i++] = token;
            token = strtok(NULL, ",");
        }

        // Create a drone object
        Drone drone;
        drone.x = atoi(tokens[0]);
        drone.y = atoi(tokens[1]);
        drone.z = atoi(tokens[2]);
        drone.yaw = atoi(tokens[3]);
        drone.pitch = atoi(tokens[4]);
        drone.roll = atoi(tokens[5]);

        // Print the drone object
        print_drone(&drone);
    }

    return 0;
}