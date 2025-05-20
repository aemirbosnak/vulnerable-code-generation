//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[256];
    int opt = 1;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(1);
    }

    // Forcefully attaching socket to the port number
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        perror("setsockopt");
        exit(1);
    }

    // Assigning port number to socket
    portno = atoi(argv[1]);

    // Assigning IP address to socket
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Forcefully attaching socket to the port number
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1) {
        perror("bind failed");
        exit(1);
    }

    // Forcefully attaching socket to the port number
    if (listen(sockfd, 5) == -1) {
        perror("listen");
        exit(1);
    }

    // Accepting connection from client
    if ((n = accept(sockfd, NULL, NULL)) == -1) {
        perror("accept");
        exit(1);
    }

    // Receiving data from client
    bzero(buffer, 256);
    n = recv(n, buffer, 256, 0);
    buffer[n] = '\0';

    // Displaying received data
    printf("Received data from client: %s\n", buffer);

    // Closing the socket
    close(sockfd);

    return 0;
}