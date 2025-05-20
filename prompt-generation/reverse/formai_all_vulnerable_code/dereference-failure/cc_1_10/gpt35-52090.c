//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_RECV_BUF_SIZE 1024
#define MAX_SEND_BUF_SIZE 1024

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char recvbuf[MAX_RECV_BUF_SIZE];
    char sendbuf[MAX_SEND_BUF_SIZE];

    if (argc < 3) {
        fprintf(stderr, "usage %s hostname port\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0)
        error("ERROR invalid hostname");

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR unable to connect to server");

    if (recv(sockfd, recvbuf, MAX_RECV_BUF_SIZE - 1, 0) < 0)
        error("ERROR unable to receive data from server");

    printf("%s", recvbuf);

    // send login credentials
    printf("Please enter your POP3 account credentials:\n");
    printf("Username: ");
    fgets(sendbuf, MAX_SEND_BUF_SIZE - 1, stdin);
    send(sockfd, sendbuf, strlen(sendbuf), 0);

    printf("Password: ");
    fgets(sendbuf, MAX_SEND_BUF_SIZE - 1, stdin);
    send(sockfd, sendbuf, strlen(sendbuf), 0);

    if (recv(sockfd, recvbuf, MAX_RECV_BUF_SIZE - 1, 0) < 0)
        error("ERROR unable to receive data from server");

    printf("%s", recvbuf);

    // list messages
    send(sockfd, "LIST\n", 5, 0);

    if (recv(sockfd, recvbuf, MAX_RECV_BUF_SIZE - 1, 0) < 0)
        error("ERROR unable to receive data from server");

    printf("%s", recvbuf);

    // retrieve individual message
    send(sockfd, "RETR 1\n", 8, 0);

    if (recv(sockfd, recvbuf, MAX_RECV_BUF_SIZE - 1, 0) < 0)
        error("ERROR unable to receive data from server");

    printf("%s", recvbuf);

    send(sockfd, "QUIT\n", 5, 0);

    close(sockfd);

    return 0;
}