//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

// Function to print usage information
void print_usage() {
    printf("Usage:./tcp_client <host> <port>\n");
    printf("Example:./tcp_client example.com 80\n");
    exit(1);
}

// Function to connect to a server
int connect_to_server(const char* host, int port) {
    int sockfd;
    struct sockaddr_in server;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(1);
    }

    // Set up the server address
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &server.sin_addr) <= 0) {
        perror("Invalid address");
        exit(1);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("Connection failed");
        exit(1);
    }

    return sockfd;
}

// Function to send a message to the server
int send_message(int sockfd, const char* message) {
    int n = write(sockfd, message, strlen(message));
    if (n <= 0) {
        perror("Write failed");
        exit(1);
    }
    return n;
}

// Function to receive a message from the server
int receive_message(int sockfd, char* message, int max_len) {
    int n = read(sockfd, message, max_len);
    if (n <= 0) {
        perror("Read failed");
        exit(1);
    }
    return n;
}

// Main program
int main(int argc, char* argv[]) {
    if (argc!= 3) {
        print_usage();
    }

    int sockfd = connect_to_server(argv[1], atoi(argv[2]));

    if (sockfd < 0) {
        perror("Failed to connect");
        exit(1);
    }

    char message[100];
    printf("Enter a message to send: ");
    fgets(message, sizeof(message), stdin);

    int n = send_message(sockfd, message);
    if (n < 0) {
        perror("Failed to send message");
        exit(1);
    }

    int echo_len = receive_message(sockfd, message, sizeof(message));
    if (echo_len < 0) {
        perror("Failed to receive echo");
        exit(1);
    }

    printf("Received echo: %s\n", message);

    close(sockfd);
    return 0;
}