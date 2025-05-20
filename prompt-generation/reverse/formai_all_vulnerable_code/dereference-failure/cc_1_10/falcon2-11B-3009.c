//Falcon2-11B DATASET v1.0 Category: Smart home automation ; Style: innovative
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 2) {
        fprintf(stderr, "Usage %s port\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[1]);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(0);
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "No such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(0);
    }

    printf("Connected to server\n");

    while (1) {
        n = read(sockfd, &n, sizeof(n));
        if (n <= 0) {
            printf("Error reading from socket\n");
            break;
        }

        write(sockfd, &n, sizeof(n));
        printf("Sent data to server\n");

        sleep(1);
    }

    close(sockfd);
    return 0;
}