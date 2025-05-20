//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <time.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char sendbuf[1024];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <server-name>\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(12345);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));

    while (1) {
        printf("Enter a message (type 'quit' to exit): ");
        fgets(sendbuf, sizeof(sendbuf), stdin);
        if (strcmp(sendbuf, "quit") == 0) {
            break;
        }
        n = write(sockfd, sendbuf, strlen(sendbuf));
        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }
        printf("Message sent: %s\n", sendbuf);
        sleep(1);
    }

    close(sockfd);
    return 0;
}