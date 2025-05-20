//Falcon2-11B DATASET v1.0 Category: Network Packet Monitoring ; Style: romantic
#include <stdio.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <string.h>
#include <sys/select.h>

int main()
{
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Create a server address/port
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);
    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Send data to the server
    char buf[256] = "GET / HTTP/1.1\r\nHost: localhost\r\n\r\n";
    send(sockfd, buf, strlen(buf), 0);

    // Receive data from the server
    bzero(buf, 256);
    n = recv(sockfd, buf, 255, 0);
    if (n < 0) {
        perror("ERROR receiving data");
        exit(1);
    }
    buf[n] = '\0';

    // Print the received data
    printf("Received: %s\n", buf);

    // Close the socket
    close(sockfd);

    return 0;
}