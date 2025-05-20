//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[100];

    // Create socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(1);
    }

    // Assign the port number
    portno = atoi(argv[1]);

    // Assign the server's address and port number to the sockaddr structure
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind the socket to the port number
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    while (1) {
        // Accept a connection
        if ((n = accept(sockfd, NULL, NULL)) < 0) {
            perror("accept");
            exit(1);
        }

        // Read data from the client
        if ((n = read(sockfd, buffer, 100)) < 0) {
            perror("read");
            exit(1);
        }

        // Print the received data
        printf("Received: %s\n", buffer);

        // Send data to the client
        n = write(sockfd, "Thank you for connecting!", 21);
        if (n < 0) {
            perror("write");
            exit(1);
        }

        // Close the connection
        close(sockfd);
    }

    return 0;
}