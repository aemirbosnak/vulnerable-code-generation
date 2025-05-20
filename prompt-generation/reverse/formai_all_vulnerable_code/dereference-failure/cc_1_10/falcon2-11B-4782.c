//Falcon2-11B DATASET v1.0 Category: Networking ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/time.h>

int main(int argc, char **argv)
{
    struct sockaddr_in server_addr;
    struct hostent *server;
    int sockfd, portno;
    char sendbuf[256], recvbuf[256];
    int n, len;

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    portno = atoi(argv[1]);

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        return 1;
    }

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("ERROR connecting");
        return 1;
    }

    printf("Connected to server\n");

    while (1) {
        printf("Enter message: ");
        fgets(sendbuf, 256, stdin);
        if (strlen(sendbuf) == 0)
            break;

        n = send(sockfd, sendbuf, strlen(sendbuf), 0);
        if (n < 0) {
            perror("ERROR sending data");
            return 1;
        }

        len = recv(sockfd, recvbuf, 256, 0);
        if (len < 0) {
            perror("ERROR receiving data");
            return 1;
        }

        printf("Server: %s\n", recvbuf);
    }

    return 0;
}