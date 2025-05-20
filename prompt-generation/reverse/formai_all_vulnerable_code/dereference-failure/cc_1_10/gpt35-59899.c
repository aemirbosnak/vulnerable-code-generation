//FormAI DATASET v1.0 Category: Smart home light control ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>

// Define the number of lights and their corresponding ports
#define NUM_LIGHTS 4
#define LIGHT1_PORT 3001
#define LIGHT2_PORT 3002
#define LIGHT3_PORT 3003
#define LIGHT4_PORT 3004

// Define a struct to hold information about each light
struct light {
    int port;
    int state;
};

// Define an array of lights
struct light lights[NUM_LIGHTS] = {
    {LIGHT1_PORT, 0},
    {LIGHT2_PORT, 0},
    {LIGHT3_PORT, 0},
    {LIGHT4_PORT, 0}
};

// Method to toggle the state of a light
void toggle_light(int index) {
    lights[index].state = !lights[index].state;
    printf("Light %d is now %s\n", index+1, (lights[index].state ? "on" : "off"));
}

// Method to handle incoming messages from the client
void handle_message(int sock, char* message, struct sockaddr_in client_addr) {
    // Parse the message
    int light_index = message[0] - '0' - 1;
    if (light_index < 0 || light_index >= NUM_LIGHTS) {
        printf("Invalid light index\n");
        return;
    }
    char command = message[1];

    // Handle the command
    switch (command) {
        case '0': // Turn off the light
            lights[light_index].state = 0;
            printf("Light %d is now off\n", light_index+1);
            break;
        case '1': // Turn on the light
            lights[light_index].state = 1;
            printf("Light %d is now on\n", light_index+1);
            break;
        case 't': // Toggle the state of the light
            toggle_light(light_index);
            break;
        default:
            printf("Invalid command\n");
            return;
    }

    // Send the updated state of the light back to the client
    char* response = (lights[light_index].state ? "on" : "off");
    if (sendto(sock, response, strlen(response), 0, (struct sockaddr*)&client_addr, sizeof(client_addr)) < 0) {
        printf("Failed to send response back to client: %s\n", strerror(errno));
    }
}

int main() {
    // Create sockets for each light
    int light_socks[NUM_LIGHTS];
    for (int i = 0; i < NUM_LIGHTS; i++) {
        if ((light_socks[i] = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
            printf("Failed to create socket for light %d: %s\n", i+1, strerror(errno));
            return 1;
        }
        struct sockaddr_in light_addr;
        memset(&light_addr, 0, sizeof(light_addr));
        light_addr.sin_family = AF_INET;
        light_addr.sin_port = htons(lights[i].port);
        light_addr.sin_addr.s_addr = htonl(INADDR_ANY);
        if (bind(light_socks[i], (struct sockaddr*)&light_addr, sizeof(light_addr)) < 0) {
            printf("Failed to bind socket for light %d: %s\n", i+1, strerror(errno));
            return 1;
        }
    }

    // Listen for incoming messages from clients
    int sock;
    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        printf("Failed to create socket for server: %s\n", strerror(errno));
        return 1;
    }
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(3000);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("Failed to bind socket for server: %s\n", strerror(errno));
        return 1;
    }
    while (1) {
        char message[2];
        struct sockaddr_in client_addr;
        unsigned int client_addr_len = sizeof(client_addr);
        if (recvfrom(sock, message, sizeof(message), 0, (struct sockaddr*)&client_addr, &client_addr_len) < 0) {
            printf("Failed to receive message from client: %s\n", strerror(errno));
            continue;
        }
        handle_message(light_socks[message[0]-'0'-1], message+1, client_addr);
    }

    // Close the sockets
    for (int i = 0; i < NUM_LIGHTS; i++) {
        close(light_socks[i]);
    }
    close(sock);

    return 0;
}