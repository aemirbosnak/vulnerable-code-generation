//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <pthread.h>

#define BUFFER_SIZE 1024
#define PORT 9000

// Function to calculate and display the network quality of service
void qos_monitor(int packet_loss, int latency) {
    // Calculate the QoS score
    int qos_score = (100 - packet_loss) - (latency / 10);

    // Print the QoS statistics
    printf("Packet Loss: %d%% \n", packet_loss);
    printf("Latency: %dms \n", latency);
    printf("QoS Score: %d/100 \n", qos_score);

    // Check the QoS score against a predetermined threshold
    if (qos_score < 70) {
        printf("Warning: Poor QoS score detected! \n");
    } else if (qos_score < 85) {
        printf("Notice: Moderate QoS score detected. \n");
    } else {
        printf("Great! Excellent QoS score detected! \n");
    }
}

// Thread function to receive packets from the server
void* receive_packets(void* socket_desc) {
    char buffer[BUFFER_SIZE];
    int sock = *(int*) socket_desc;
    int latency, packet_loss;

    while(1) {
        // Receive the packet from the server
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);

        if (bytes_received < 0) {
            printf("Error: Failed to receive packet from server. \n");
            pthread_exit(NULL);
        } else if (bytes_received == 0) {
            printf("Warning: Server has disconnected! \n");
            pthread_exit(NULL);
        } else {
            // Parse the packet data
            sscanf(buffer, "%d,%d", &packet_loss, &latency);
            // Call the QoS monitor function
            qos_monitor(packet_loss, latency);
        }
    }
}

int main() {
    int sock;
    struct sockaddr_in server_addr;
    struct hostent *server;

    printf("Welcome to the Network QoS Monitor! \n");

    // Get the server address
    server = gethostbyname("localhost");

    if (server == NULL) {
        printf("Error: Failed to resolve server address. \n");
        exit(0);
    }

    // Create a TCP socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0) {
        printf("Error: Failed to create socket. \n");
        exit(0);
    }

    // Set the socket options
    int optval = 1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (const void *)&optval, sizeof(int));

    // Set up the server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);

    // Connect to the server
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error: Failed to connect to server. \n");
        exit(0);
    }

    printf("Connected to server successfully! \n");
    printf("Waiting for packets... \n");

    // Create a new thread to receive packets from the server
    pthread_t thread;
    if (pthread_create(&thread, NULL, receive_packets, (void*)&sock) != 0) {
        printf("Error: Failed to create thread. \n");
        exit(0);
    }

    // Wait for the thread to finish
    pthread_join(thread, NULL);

    // Close the socket
    close(sock);

    return 0;
}