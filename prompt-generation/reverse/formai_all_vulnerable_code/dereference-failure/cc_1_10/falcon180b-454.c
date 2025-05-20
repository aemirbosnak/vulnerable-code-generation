//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct hostent *server;
    struct sockaddr_in serv_addr;
    char buffer[1024];
    char *ptr;

    if (argc!= 3) {
        printf("Usage:./ping <hostname/IP address> <port number>\n");
        exit(0);
    }

    strcpy(buffer, argv[1]);
    portno = atoi(argv[2]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error: Unable to create socket\n");
        exit(0);
    }

    // Resolve host name
    server = gethostbyname(buffer);

    if (server == NULL) {
        printf("Error: Unable to resolve host name\n");
        exit(0);
    }

    // Fill in server address structure
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr = *((struct in_addr *)server->h_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Unable to connect to server\n");
        exit(0);
    }

    // Send data to server
    n = write(sockfd, "PING", 5);

    if (n < 0) {
        printf("Error: Unable to send data to server\n");
        exit(0);
    }

    // Receive response from server
    n = read(sockfd, buffer, 1024);

    if (n < 0) {
        printf("Error: Unable to receive data from server\n");
        exit(0);
    }

    // Close socket
    close(sockfd);

    // Print response
    printf("Server response: %s\n", buffer);

    return 0;
}