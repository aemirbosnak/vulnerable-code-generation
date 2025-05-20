//Falcon2-11B DATASET v1.0 Category: Checkers Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

void send_message(int sockfd, char *msg)
{
    int sent = send(sockfd, msg, strlen(msg), 0);
    if (sent < 0)
        error("send() failed");
}

void receive_message(int sockfd, char *msg, int len)
{
    int recv_len = recv(sockfd, msg, len, 0);
    if (recv_len < 0)
        error("recv() failed");
    else if (recv_len == 0)
        error("connection closed");
}

int main()
{
    struct sockaddr_in addr;
    struct hostent *host;

    int sockfd, portno;
    char msg[256];

    if ((host = gethostbyname("localhost")) == NULL)
        error("gethostbyname() failed");

    memset((char *)&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    bcopy((char *)host->h_addr, (char *)&addr.sin_addr.s_addr, host->h_length);
    addr.sin_port = htons(portno);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
        error("ERROR connecting");

    while (1) {
        printf("Enter your move (e.g. 'a4 b5'): ");
        fgets(msg, 255, stdin);

        send_message(sockfd, msg);

        receive_message(sockfd, msg, 256);

        printf("Your opponent's move: %s\n", msg);
    }

    close(sockfd);
    return 0;
}