//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char send_buf[1024];
    char recv_buf[1024];

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Set up the server address
    server = gethostbyname("www.example.com");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(80); // Set port to 80 for HTTP

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Send a ping request
    sprintf(send_buf, "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n");
    send(sockfd, send_buf, strlen(send_buf), 0);

    // Receive the response
    bzero(recv_buf, sizeof(recv_buf));
    n = recv(sockfd, recv_buf, sizeof(recv_buf), 0);

    // Print the response
    printf("Received: %s\n", recv_buf);

    // Close the socket
    close(sockfd);

    return 0;
}