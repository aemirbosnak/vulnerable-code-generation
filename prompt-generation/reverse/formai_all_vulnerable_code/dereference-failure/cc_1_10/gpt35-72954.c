//FormAI DATASET v1.0 Category: Socket programming ; Style: relaxed
/* 

This is a C socket programming example program that connects to a TCP server using IP address and port number.

The program first initializes the socket with the socket() function, then connects to the server with the connect() function,
and finally sends a message to the server using the send() function.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main() {

    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];
    printf("Enter message: ");
    fgets(buffer, 255, stdin);

    portno = 8080;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    server = gethostbyname("localhost");

    if (server == NULL) {
        printf("Error, no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    n = send(sockfd, buffer, strlen(buffer), 0);

    if (n < 0) {
        printf("Error sending message\n");
        exit(1);
    }

    close(sockfd);

    return 0;
}