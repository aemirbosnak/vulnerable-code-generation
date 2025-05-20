//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

#define HOST "www.google.com"
#define PORT 80

int main() {
    int sockfd, bytesRead, bytesWritten, retval;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    int opt = 1;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(HOST);

    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    retval = connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));

    if (retval < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    printf("Connected to %s\n", HOST);

    bytesRead = read(sockfd, &bytesWritten, sizeof(bytesWritten));
    printf("Received: %d bytes\n", bytesRead);

    printf("Packet loss rate: %f\n", (double) bytesRead / (double) sizeof(bytesWritten) * 100);

    close(sockfd);
    return 0;
}