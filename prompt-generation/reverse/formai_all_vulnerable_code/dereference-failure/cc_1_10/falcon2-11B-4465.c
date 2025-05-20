//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main(int argc, char *argv[]) {
    int sockfd, new_socket, portno, n;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1024];

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Set up the server address struct
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(argv[1]));

    // Bind the socket to the address
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    // Listen for incoming connections
    listen(sockfd, 5);

    // Accept the incoming connection
    if ((new_socket = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&portno)) < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    // Send the input number to the client
    send(new_socket, argv[1], strlen(argv[1]), 0);

    // Receive the output number from the client
    recv(new_socket, buffer, 1024, 0);
    n = atoi(buffer);

    // Calculate the factorial of the input number
    int fact = factorial(n);

    // Send the factorial result back to the client
    send(new_socket, &fact, sizeof(int), 0);

    // Close the socket
    close(new_socket);
    close(sockfd);

    return 0;
}