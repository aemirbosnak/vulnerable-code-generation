//Falcon2-11B DATASET v1.0 Category: Firewall ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char **argv) {
    int sockfd, new_sockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "ERROR opening socket\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "ERROR connecting\n");
        exit(1);
    }

    for (;;) {
        new_sockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *)&portno);
        if (new_sockfd < 0) {
            fprintf(stderr, "ERROR accepting connection\n");
            exit(1);
        }

        printf("Incoming connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
        while (1) {
            char buffer[1024];
            ssize_t n;

            n = recv(new_sockfd, buffer, sizeof(buffer), 0);
            if (n < 0) {
                fprintf(stderr, "ERROR receiving data\n");
                exit(1);
            } else if (n == 0) {
                printf("Client disconnected\n");
                close(new_sockfd);
                break;
            } else {
                printf("Received %zd bytes of data\n", n);
                send(new_sockfd, buffer, n, 0);
            }
        }

        close(new_sockfd);
    }

    return 0;
}