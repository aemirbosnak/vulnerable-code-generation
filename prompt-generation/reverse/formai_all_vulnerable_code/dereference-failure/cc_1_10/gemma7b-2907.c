//Gemma-7B DATASET v1.0 Category: Traffic Light Controller ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>

#define SERVER_PORT 8080
#define NUM_CLIENTS 5

// Define traffic light status
enum TrafficLightStatus { RED, YELLOW, GREEN };

// Structure to represent a traffic light
typedef struct TrafficLight {
    enum TrafficLightStatus status;
    int clients_served;
} TrafficLight;

TrafficLight traffic_lights[NUM_CLIENTS];

void update_traffic_light(int client_fd) {
    // Get the current traffic light status
    TrafficLight *light = &traffic_lights[client_fd];
    switch (light->status) {
        case RED:
            light->status = YELLOW;
            break;
        case YELLOW:
            light->status = GREEN;
            break;
        case GREEN:
            light->status = RED;
            break;
    }

    // Increment the number of clients served
    light->clients_served++;

    // Send the new traffic light status to the client
    send(client_fd, &light->status, sizeof(enum TrafficLightStatus), 0);
}

int main() {
    // Create a socket for listening to clients
    int server_fd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
    if (server_fd == -1) {
        perror("Error creating socket");
        exit(1);
    }

    // Initialize the traffic lights
    for (int i = 0; i < NUM_CLIENTS; i++) {
        traffic_lights[i].status = RED;
        traffic_lights[i].clients_served = 0;
    }

    // Listen for clients
    while (1) {
        // Accept a client connection
        int client_fd = accept(server_fd, NULL, NULL);
        if (client_fd == -1) {
            perror("Error accepting client connection");
            continue;
        }

        // Update the traffic light status
        update_traffic_light(client_fd);

        // Close the client connection
        close(client_fd);
    }

    return 0;
}