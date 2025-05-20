//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

int main() {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[1024];

    // Initialize variables
    sockfd = -1;
    portno = 0;
    server = NULL;

    // Get the host name and port number from user input
    printf("Enter the host name: ");
    scanf("%s", server->h_name);
    printf("Enter the port number: ");
    scanf("%d", &portno);

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Set up the server address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    bzero((char *) &serv_addr.sin_zero, 8);

    // Resolve the server name
    if (inet_aton(server->h_addr_list[0], &serv_addr.sin_addr) < 0) {
        fprintf(stderr, "ERROR, cannot resolve server name\n");
        exit(1);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Send the ping request
    sprintf(buffer, "PING %s (%s:%d)\r\n", server->h_name, inet_ntoa(serv_addr.sin_addr), portno);
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive the response
    recv(sockfd, buffer, 1024, 0);

    // Close the socket
    close(sockfd);

    return 0;
}