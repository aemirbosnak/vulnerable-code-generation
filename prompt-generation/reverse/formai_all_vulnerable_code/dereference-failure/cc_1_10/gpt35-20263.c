//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, port, n;
    struct hostent *server;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    if (argc < 2) {
        fprintf(stderr, "usage %s hostname port\n", argv[0]);
        exit(1);
    }
    port = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR: socket creation failed");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR: no such host\n");
        exit(1);
    }

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(port);

    if (connect(sockfd,(struct sockaddr *)&server_addr,sizeof(server_addr)) < 0) {
        perror("ERROR: connection failed");
        exit(1);
    }

    // write network command to server
    bzero(buffer, BUFFER_SIZE);
    strcpy(buffer, "network");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR: could not write to socket");
        exit(1);
    }

    // read and print network map from server
    bzero(buffer, BUFFER_SIZE);
    while ((n = read(sockfd, buffer, BUFFER_SIZE - 1)) > 0) {
        printf("%s", buffer);
        bzero(buffer, BUFFER_SIZE);
    }
    printf("\n");

    if (n < 0) {
        perror("ERROR: could not read from socket");
        exit(1);
    }

    close(sockfd);
    return 0;
}