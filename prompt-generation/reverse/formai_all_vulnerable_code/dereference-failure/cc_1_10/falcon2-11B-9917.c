//Falcon2-11B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];

    if (argc!= 3) {
        printf("Usage: %s hostname port\n", argv[0]);
        exit(0);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Unknown host\n");
        exit(0);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error in socket creation");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error in connection");
        exit(0);
    }

    printf("Connected to server.\n");

    while (1) {
        printf("Enter a command: ");
        fgets(buffer, sizeof(buffer), stdin);

        n = write(sockfd, buffer, strlen(buffer));
        if (n < 0) {
            perror("Error writing to socket");
            exit(0);
        }

        if (n!= strlen(buffer)) {
            fprintf(stderr, "Write error.\n");
            exit(0);
        }

        bzero(buffer, sizeof(buffer));

        n = read(sockfd, buffer, sizeof(buffer));
        if (n < 0) {
            perror("Error reading from socket");
            exit(0);
        }

        printf("%s\n", buffer);
    }

    close(sockfd);
    return 0;
}