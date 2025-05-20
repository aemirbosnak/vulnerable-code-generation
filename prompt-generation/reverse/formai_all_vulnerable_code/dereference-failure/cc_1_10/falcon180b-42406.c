//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>
#include <netinet/in.h>

int main(int argc, char **argv)
{
    int sockfd, portno, n, timeout;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];
    struct timeval tv;
    fd_set readfds;

    if (argc!= 3) {
        printf("Usage: %s <host> <timeout>\n", argv[0]);
        exit(1);
    }

    timeout = atoi(argv[2]);
    portno = 80;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        printf("Error: No such host\n");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy(server->h_addr, &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);

    tv.tv_sec = timeout;
    tv.tv_usec = 0;

    printf("Waiting for response...\n");

    n = select(sockfd + 1, &readfds, NULL, NULL, &tv);

    if (n <= 0) {
        printf("No response from server\n");
        exit(1);
    }

    n = read(sockfd, buffer, sizeof(buffer));

    if (n <= 0) {
        printf("Error reading from socket\n");
        exit(1);
    }

    printf("Response from server:\n%s\n", buffer);

    close(sockfd);

    return 0;
}