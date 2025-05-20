//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

// Structure to represent a smart home device
typedef struct {
    char name[32];
    int type; // 0: light, 1: thermostat, 2: door lock
    int state; // 0: off, 1: on
} device;

// Array of smart home devices
device devices[] = {
    {"Living Room Light", 0, 0},
    {"Kitchen Light", 0, 0},
    {"Bedroom Light", 0, 0},
    {"Thermostat", 1, 20},
    {"Front Door Lock", 2, 0}
};

// Function to handle incoming connections
void handle_connection(int sockfd) {
    char buffer[BUFFER_SIZE];
    int n;
    
    // Receive the command from the client
    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n < 0) {
        perror("recv");
        close(sockfd);
        return;
    }
    
    // Parse the command
    char *command = strtok(buffer, " ");
    char *argument = strtok(NULL, " ");
    
    // Find the corresponding device
    int i;
    for (i = 0; i < sizeof(devices) / sizeof(device); i++) {
        if (strcmp(devices[i].name, argument) == 0) {
            break;
        }
    }
    
    // Execute the command
    if (strcmp(command, "on") == 0) {
        devices[i].state = 1;
        printf("%s turned on\n", devices[i].name);
    } else if (strcmp(command, "off") == 0) {
        devices[i].state = 0;
        printf("%s turned off\n", devices[i].name);
    } else if (strcmp(command, "status") == 0) {
        if (devices[i].state == 0) {
            printf("%s is off\n", devices[i].name);
        } else if (devices[i].state == 1) {
            printf("%s is on\n", devices[i].name);
        }
    } else {
        printf("Invalid command\n");
    }
    
    // Send the response to the client
    strcpy(buffer, "OK");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("send");
        close(sockfd);
        return;
    }
    
    // Close the connection
    close(sockfd);
}

int main() {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    struct sockaddr_in serv_addr, cli_addr;
    
    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }
    
    // Set the port number
    portno = 5000;
    
    // Bind the socket to the port
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(1);
    }
    
    // Listen for incoming connections
    listen(sockfd, 5);
    
    while (1) {
        // Accept a new connection
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("accept");
            exit(1);
        }
        
        // Handle the connection in a separate thread
        pthread_t thread;
        pthread_create(&thread, NULL, (void *)handle_connection, (void *)newsockfd);
    }
    
    // Close the socket
    close(sockfd);
    
    return 0;
}