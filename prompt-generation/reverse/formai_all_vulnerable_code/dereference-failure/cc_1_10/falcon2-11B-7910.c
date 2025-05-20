//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <time.h>

#define PORT 110
#define MAXLINE 1024

int main(int argc, char **argv)
{
    if(argc!= 2)
    {
        fprintf(stderr, "Usage: %s server_address\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sockfd, numbytes;
    struct sockaddr_in servaddr;
    char buffer[MAXLINE];

    struct hostent *server;
    char *hostname = argv[1];

    int portno = PORT;

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    memcpy((char *)&servaddr.sin_addr.s_addr, server->h_addr, server->h_length);
    servaddr.sin_port = htons(portno);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    char *command = "USER testuser\r\n";
    send(sockfd, command, strlen(command), 0);

    char *password = "testpass\r\n";
    send(sockfd, password, strlen(password), 0);

    char *list = "LIST\r\n";
    send(sockfd, list, strlen(list), 0);

    printf("Sending data: %s\n", buffer);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("Received data: %s\n", buffer);

    close(sockfd);
    return 0;
}