//Falcon2-11B DATASET v1.0 Category: Networking ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// Function to send data to the other end
void send_data(int sockfd, const char *data) {
    int n = write(sockfd, data, strlen(data));
    if (n < 0) {
        perror("Error sending data");
        exit(1);
    }
}

// Function to receive data from the other end
char* receive_data(int sockfd) {
    char buffer[1024];
    int n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("Error receiving data");
        exit(1);
    }
    return buffer;
}

int main() {
    int sockfd, portno, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1024];

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Fill in server's address information
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(12345);

    // Bind socket to the port
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error binding to port");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        perror("Error listening for connections");
        exit(1);
    }

    // Accept connection from client
    bzero((char *) &cli_addr, sizeof(cli_addr));
    clilen = sizeof(cli_addr);
    if ((portno = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen)) < 0) {
        perror("Error accepting connection");
        exit(1);
    }

    // Receive data from the client
    printf("From Romeo: ");
    char* data = receive_data(portno);
    printf("To Juliet: %s\n", data);
    free(data);

    // Send data to the client
    printf("From Juliet: ");
    send_data(portno, "What's in a name? That which we call a rose by any other name would smell as sweet.\n");
    printf("To Romeo: %s\n", receive_data(portno));
    free(receive_data(portno));

    // Clean up
    close(sockfd);

    return 0;
}