//Falcon2-11B DATASET v1.0 Category: Drone Remote Control ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <netdb.h>

#define PORT 8080

int main(int argc, char *argv[])
{
    int sockfd, n, optval = 1;
    struct sockaddr_in serveraddr;
    struct hostent *server;

    // create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // specify the server address and port number
    server = gethostbyname("localhost");
    if (server == NULL)
    {
        fprintf(stderr, "no such host\n");
        exit(EXIT_FAILURE);
    }

    memset((char *) &serveraddr, '\0', sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(PORT);
    memcpy((char *) &serveraddr.sin_addr.s_addr, (char *) server->h_addr, server->h_length);

    // connect to the server
    if (connect(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0)
    {
        perror("connection failed");
        exit(EXIT_FAILURE);
    }

    char buf[100];
    int len;

    // read input from stdin
    printf("Enter command: ");
    fgets(buf, sizeof(buf), stdin);

    // send the command to the server
    if (send(sockfd, buf, strlen(buf), 0) < 0)
    {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    // read the response from the server
    if ((len = recv(sockfd, buf, sizeof(buf), 0)) < 0)
    {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }
    buf[len] = '\0';

    printf("%s", buf);

    // close the socket
    close(sockfd);

    return 0;
}