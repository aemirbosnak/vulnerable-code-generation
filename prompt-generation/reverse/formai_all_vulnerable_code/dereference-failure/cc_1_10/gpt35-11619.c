//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define BUFLEN 1024
#define DEFAULT_PORT 8888

/* Function to print error message and exit */
void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct timeval timeout;
    fd_set readfds;
    char buffer[BUFLEN];
    time_t start, end;
    double diff;

    if (argc < 2) {
        fprintf(stderr,"usage %s hostname [port]\n", argv[0]);
        exit(1);
    }
    portno = DEFAULT_PORT;
    if (argc > 2)
        portno = atoi(argv[2]);

    /* Create a socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    /* Set server address and port number */
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) < 1)
        error("ERROR invalid server address");

    /* Connect to server */
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    printf("Connected to server %s on port %d\n", argv[1], portno);

    /* Start timer */
    start = time(NULL);

    /* Send data to server */
    if (send(sockfd, "Hello, server\n", 15, 0) == -1)
        error("ERROR sending data to server");

    /* Wait for response from server */
    timeout.tv_sec = 5;
    timeout.tv_usec = 0;
    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);
    if (select(sockfd + 1, &readfds, NULL, NULL, &timeout) < 0)
        error("ERROR selecting from socket");
    if (!FD_ISSET(sockfd, &readfds))
        error("ERROR timed out waiting for response from server");
    memset(buffer, 0, BUFLEN);
    if ((n = recv(sockfd, buffer, BUFLEN - 1, 0)) <= 0)
        error("ERROR receiving response from server");

    printf("Response from server: %s\n", buffer);

    /* End timer */
    end = time(NULL);
    diff = difftime(end, start);
    printf("Round trip time: %f seconds\n", diff);

    /* Close socket */
    close(sockfd);

    return 0;
}