//LLAMA2-13B DATASET v1.0 Category: Client Server Application ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8888

struct particle {
    int id;
    double mass;
    double position[3];
    double velocity[3];
};

int main(int argc, char *argv[]) {
    int sock;
    struct particle particles[10];
    int i;

    // Create the server socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Set address and port number
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    // Bind the socket to the address and port
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sock, 3) < 0) {
        perror("Error listening for incoming connections");
        exit(1);
    }

    printf("Server listening on port %d...\n", PORT);

    // Create the client socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error creating client socket");
        exit(1);
    }

    // Connect the client to the server
    struct sockaddr_in client_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };
    if (connect(sock, (struct sockaddr *)&client_addr, sizeof(client_addr)) < 0) {
        perror("Error connecting to the server");
        exit(1);
    }

    // Send the number of particles to the server
    char num_particles_str[10];
    sprintf(num_particles_str, "%d", sizeof(particles) / sizeof(particles[0]));
    if (send(sock, num_particles_str, strlen(num_particles_str), 0) < 0) {
        perror("Error sending number of particles to the server");
        exit(1);
    }

    // Receive the particles from the server
    for (i = 0; i < sizeof(particles) / sizeof(particles[0]); i++) {
        if (recv(sock, &particles[i], sizeof(particles[0]), 0) < 0) {
            perror("Error receiving particles from the server");
            exit(1);
        }
    }

    // Print the received particles
    for (i = 0; i < sizeof(particles) / sizeof(particles[0]); i++) {
        printf("Particle %d: id = %d, mass = %.2f kg, position = (%.2f, %.2f, %.2f) m, velocity = (%.2f, %.2f, %.2f) m/s\n",
            i, particles[i].id, particles[i].mass, particles[i].position[0], particles[i].position[1], particles[i].position[2],
            particles[i].velocity[0], particles[i].velocity[1], particles[i].velocity[2]);
    }

    // Close the sockets
    close(sock);

    return 0;
}