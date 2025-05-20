//Falcon2-11B DATASET v1.0 Category: Network Packet Monitoring ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    // create a TCP socket
    int sockfd, numbytes;
    struct sockaddr_in server;
    struct hostent *server_host;

    // check for correct usage
    if (argc!= 2) {
        fprintf(stderr, "usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    // create the socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // fill in the address of the server
    server_host = gethostbyname(argv[1]);
    if (server_host == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }
    memcpy((char *)&server, server_host->h_addr, server_host->h_length);

    // connect to the server
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // loop forever, reading packets and printing them out
    char buffer[BUFSIZE];
    while (1) {
        if ((numbytes = recv(sockfd, buffer, BUFSIZE, 0)) < 0) {
            perror("ERROR receiving data");
            exit(1);
        }
        printf("received packet: %s\n", buffer);
    }
    return 0;
}