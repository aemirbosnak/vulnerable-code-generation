//Falcon2-11B DATASET v1.0 Category: Network Packet Monitoring ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <errno.h>

int main() {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[1024];

    printf("Enter server IP address: ");
    scanf("%s", &buffer);
    printf("Enter server port: ");
    scanf("%d", &portno);

    server = gethostbyname(buffer);
    if (server == NULL) {
        fprintf(stderr, "Hostname could not be resolved\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    while (1) {
        if (read(sockfd, buffer, 1024) < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        printf("%s", buffer);
    }

    return 0;
}