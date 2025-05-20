//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Ken Thompson
/**
 * Ken Thompson style implementation of a C Drone Remote Control program
 *
 * Description:
 * The program allows users to remotely control a drone using a custom protocol over a wireless network.
 * The drone has four rotors that can be independently controlled to move in different directions.
 * The program sends commands to the drone based on input from the user and receives status updates.
 *
 * Usage:
 * - The program should be compiled and run on a computer connected to a wireless network.
 * - The user should run the program and specify the IP address and port of the drone.
 * - The user can then control the drone using the following commands:
 *     - "takeoff": The drone takes off and hovers in place.
 *     - "land": The drone lands.
 *     - "up <distance>": The drone moves up by the specified distance (in meters).
 *     - "down <distance>": The drone moves down by the specified distance.
 *     - "left <distance>": The drone moves left by the specified distance.
 *     - "right <distance>": The drone moves right by the specified distance.
 *     - "forward <distance>": The drone moves forward by the specified distance.
 *     - "backward <distance>": The drone moves backward by the specified distance.
 *     - "rotate <angle>": The drone rotates clockwise by the specified angle (in degrees).
 *
 * Author: Your Name
 * Date: Today's Date 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUF_SIZE 512

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <ip_address> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Parse IP address and port
    struct sockaddr_in drone_addr;
    memset(&drone_addr, 0, sizeof(drone_addr));
    drone_addr.sin_family = AF_INET;
    drone_addr.sin_addr.s_addr = inet_addr(argv[1]);
    drone_addr.sin_port = htons(atoi(argv[2]));

    // Create socket
    int sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock_fd < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    // Connect to drone
    if (connect(sock_fd, (struct sockaddr *)&drone_addr, sizeof(drone_addr)) < 0) {
        perror("connect() failed");
        exit(EXIT_FAILURE);
    }

    // Main loop
    char buf[BUF_SIZE];
    while (1) {
        // Read user input
        printf(">> ");
        fflush(stdout);
        if (fgets(buf, BUF_SIZE, stdin) == NULL) {
            break;
        }
        if (strlen(buf) == 0) {
            continue;
        }

        // Send command to drone
        if (send(sock_fd, buf, strlen(buf), 0) != strlen(buf)) {
            perror("send() failed");
            break;
        }

        // Receive status update from drone
        if (recv(sock_fd, buf, BUF_SIZE-1, 0) <= 0) {
            perror("recv() failed");
            break;
        }

        // Print status update
        buf[BUF_SIZE-1] = '\0';
        printf("Status: %s\n", buf);
    }

    // Close socket
    close(sock_fd);

    return 0;
}