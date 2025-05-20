//Falcon2-11B DATASET v1.0 Category: Wireless Network Scanner ; Style: inquisitive
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int main() {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    struct in_addr *in_addr;
    char buffer[MAX_BUFFER_SIZE];

    server = gethostbyname("www.google.com");
    if (server == NULL) {
        fprintf(stderr, "ERROR: Unable to resolve host\n");
        return 1;
    }
    in_addr = (struct in_addr *)server->h_addr;

    portno = htons(80); // HTTP port

    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(in_addr->s_addr);
    serv_addr.sin_port = htons(portno);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting to server");
        return 1;
    }

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
        printf("Received: %s\n", buffer);
    }

    return 0;
}