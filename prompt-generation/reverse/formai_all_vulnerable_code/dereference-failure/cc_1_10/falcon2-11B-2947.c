//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_MESSAGE_SIZE 100

int main() {
    // Create a UDP socket
    int socket_desc = socket(AF_INET, SOCK_DGRAM, 0);
    if (socket_desc == -1) {
        perror("Error creating socket");
        return 1;
    }

    // Create a sockaddr_in structure
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Replace with the IP address you want to ping
    server_addr.sin_port = htons(53); // Replace with the port number you want to ping

    // Send a UDP message to the server
    char message[MAX_MESSAGE_SIZE];
    sprintf(message, "Ping: %s", "Test");
    int message_size = strlen(message);
    int sent = sendto(socket_desc, message, message_size, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (sent == -1) {
        perror("Error sending message");
        return 1;
    }

    // Receive a UDP message from the server
    char buffer[MAX_MESSAGE_SIZE];
    int recv_size = recvfrom(socket_desc, buffer, MAX_MESSAGE_SIZE, 0, NULL, NULL);
    if (recv_size == -1) {
        perror("Error receiving message");
        return 1;
    }

    // Print the received message
    printf("Received: %s\n", buffer);

    // Close the socket
    close(socket_desc);

    return 0;
}