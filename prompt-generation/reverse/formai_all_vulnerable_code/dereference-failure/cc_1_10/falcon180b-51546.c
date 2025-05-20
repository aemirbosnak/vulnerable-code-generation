//Falcon-180B DATASET v1.0 Category: Networking ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

const int BUFFER_SIZE = 1024;

// Function to print error message and exit program
void error(const char* msg) {
    perror(msg);
    exit(1);
}

// Function to print usage instructions
void usage() {
    printf("Usage:./program <ip_address> <port_number>\n");
}

// Function to establish a TCP connection with the server
int connect_to_server(const char* ip_address, int port_number) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        error("Error creating socket");
    }

    struct addrinfo hints, *servinfo;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(ip_address, NULL, &hints, &servinfo)!= 0) {
        error("Error resolving hostname");
    }

    struct sockaddr_in *addr = (struct sockaddr_in *)servinfo->ai_addr;
    sockfd = socket(addr->sin_family, SOCK_STREAM, 0);

    if (connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen) == -1) {
        error("Error connecting to server");
    }

    freeaddrinfo(servinfo);

    return sockfd;
}

// Function to send a message to the server
void send_message(int sockfd, const char* message) {
    send(sockfd, message, strlen(message), 0);
}

// Function to receive a message from the server
void receive_message(int sockfd, char* buffer) {
    memset(buffer, 0, BUFFER_SIZE);
    int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (bytes_received <= 0) {
        error("Error receiving message from server");
    }
}

// Function to handle the main logic of the program
int main(int argc, char* argv[]) {
    if (argc!= 3) {
        usage();
        return 1;
    }

    const char* ip_address = argv[1];
    int port_number = atoi(argv[2]);

    int sockfd = connect_to_server(ip_address, port_number);

    char buffer[BUFFER_SIZE];

    // Send a message to the server
    strcpy(buffer, "Hello, World!");
    send_message(sockfd, buffer);

    // Receive a message from the server
    receive_message(sockfd, buffer);

    printf("Received message from server: %s\n", buffer);

    close(sockfd);

    return 0;
}