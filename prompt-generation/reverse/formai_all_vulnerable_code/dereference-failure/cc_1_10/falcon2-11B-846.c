//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080

int main(int argc, char **argv) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(1);
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "gethostbyname failed\n");
        exit(1);
    }

    portno = htons(PORT);

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = portno;

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    printf("Socket connected to server\n");

    char buffer[1024];
    bzero(buffer, sizeof(buffer));

    while (1) {
        n = read(sockfd, buffer, sizeof(buffer) - 1);
        if (n < 0) {
            perror("read");
            exit(1);
        }
        buffer[n] = '\0';
        printf("Received: %s\n", buffer);
        if (strcmp(buffer, "quit") == 0)
            break;
        write(sockfd, buffer, strlen(buffer));
    }

    close(sockfd);

    return 0;
}