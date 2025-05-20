//Falcon2-11B DATASET v1.0 Category: Networking ; Style: complete
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// Function to create a TCP client socket
int createClientSocket(int port) {
    int sockfd, portno, n;
    struct sockaddr_in serveraddr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Assign a port number to the socket
    portno = port;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(portno);
    serveraddr.sin_addr.s_addr = INADDR_ANY;

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Function to send data to the server
void sendData(int sockfd, char *data) {
    int n;

    // Send the data
    n = send(sockfd, data, strlen(data), 0);
    if (n < 0) {
        perror("Error sending data");
        exit(EXIT_FAILURE);
    }
}

// Function to receive data from the server
char* receiveData(int sockfd) {
    char buffer[100];
    int n;

    // Receive the data
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n < 0) {
        perror("Error receiving data");
        exit(EXIT_FAILURE);
    }

    // Convert the received data to a string
    char* receivedData = (char*)malloc(n * sizeof(char));
    memcpy(receivedData, buffer, n);
    return receivedData;
}

int main() {
    int sockfd, portno;
    struct hostent *server;
    char *receivedData;

    // Specify the port number to connect to the server
    portno = 8080;

    // Create a client socket
    sockfd = createClientSocket(portno);
    if (sockfd < 0) {
        perror("Error creating client socket");
        exit(EXIT_FAILURE);
    }

    // Send a message to the server
    char message[] = "Hello, Server!";
    sendData(sockfd, message);

    // Receive the response from the server
    receivedData = receiveData(sockfd);
    printf("Server's response: %s\n", receivedData);

    // Close the socket
    close(sockfd);

    return 0;
}