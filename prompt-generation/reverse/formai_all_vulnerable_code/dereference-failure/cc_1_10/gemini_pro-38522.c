//GEMINI-pro DATASET v1.0 Category: Networking ; Style: genius
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

// Constants
#define MAX_BUFFER_SIZE 1024

// Function to get the IP address of a given hostname
char *get_ip_address(char *hostname) {
    struct hostent *host_info = gethostbyname(hostname);
    if (host_info == NULL) {
        return NULL;
    }

    struct in_addr **addresses = (struct in_addr **)host_info->h_addr_list;
    char *ip_address = inet_ntoa(*addresses[0]);
    return ip_address;
}

// Function to send a message to a given IP address and port
int send_message(char *ip_address, int port, char *message) {
    // Create a socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("socket");
        return -1;
    }

    // Set up the server address
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = inet_addr(ip_address);

    // Connect to the server
    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("connect");
        close(socket_fd);
        return -1;
    }

    // Send the message
    if (send(socket_fd, message, strlen(message), 0) == -1) {
        perror("send");
        close(socket_fd);
        return -1;
    }

    // Close the socket
    close(socket_fd);
    return 0;
}

// Function to receive a message from a given IP address and port
char *receive_message(char *ip_address, int port) {
    // Create a socket
    int socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (socket_fd == -1) {
        perror("socket");
        return NULL;
    }

    // Set up the server address
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = inet_addr(ip_address);

    // Bind the socket to the server address
    if (bind(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("bind");
        close(socket_fd);
        return NULL;
    }

    // Receive the message
    char buffer[MAX_BUFFER_SIZE];
    socklen_t addr_len = sizeof(server_address);
    int bytes_received = recvfrom(socket_fd, buffer, MAX_BUFFER_SIZE, 0, (struct sockaddr *)&server_address, &addr_len);
    if (bytes_received == -1) {
        perror("recvfrom");
        close(socket_fd);
        return NULL;
    }

    // Close the socket
    close(socket_fd);

    // Return the message
    return strndup(buffer, bytes_received);
}

// Main function
int main(int argc, char **argv) {
    // Check if the correct number of arguments have been provided
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <port> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the IP address of the hostname
    char *ip_address = get_ip_address(argv[1]);
    if (ip_address == NULL) {
        fprintf(stderr, "Error: Could not get IP address for hostname %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Convert the port to an integer
    int port = atoi(argv[2]);

    // Send the message
    if (send_message(ip_address, port, argv[3]) == -1) {
        fprintf(stderr, "Error: Could not send message\n");
        return EXIT_FAILURE;
    }

    // Receive the response
    char *response = receive_message(ip_address, port);
    if (response == NULL) {
        fprintf(stderr, "Error: Could not receive response\n");
        return EXIT_FAILURE;
    }

    // Print the response
    printf("Response: %s\n", response);

    // Free the response
    free(response);

    return EXIT_SUCCESS;
}