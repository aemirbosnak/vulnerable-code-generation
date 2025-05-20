//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/time.h>
#include <errno.h>
#include <signal.h>

int main() {
    int sockfd, numbytes, portnum, i, status, valread;
    struct sockaddr_in serveraddr;
    struct hostent *server;
    char buffer[256], message[256], hostname[256];

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Get the IP address and port number of the server
    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(EXIT_FAILURE);
    }
    portnum = htons(5000);

    // Connect to the server
    memset((char *) &serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serveraddr.sin_addr.s_addr, server->h_length);
    serveraddr.sin_port = htons(portnum);
    if ((status = connect(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr))) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // Send a message to the server
    printf("Enter your message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0;
    numbytes = send(sockfd, message, strlen(message), 0);
    if (numbytes < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    // Receive the response from the server
    memset(buffer, 0, sizeof(buffer));
    valread = recv(sockfd, buffer, sizeof(buffer), 0);
    if (valread < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }
    printf("Server response: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}