//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 4096

int connect_to_server(const char *server_address, int server_port) 
{
    int sockfd, retcode;
    struct sockaddr_in server;

    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(server_address);
    server.sin_port = htons(server_port);

    retcode = connect(sockfd, (struct sockaddr*)&server, sizeof(server));
    if (retcode < 0) {
        perror("Error connecting to IMAP server");
        exit(1);
    }

    return sockfd;
}

int receive_data(int sockfd)
{
    char buf[BUFSIZE];
    int numBytes;

    numBytes = recv(sockfd, buf, BUFSIZE-1, 0);
    if (numBytes < 0) {
        perror("Error receiving data from server");
        exit(1);
    }

    buf[numBytes] = '\0';
    printf("%s", buf);

    return numBytes;
}

int send_data(int sockfd, const char *data)
{
    int numBytes = send(sockfd, data, strlen(data), 0);
    if (numBytes < strlen(data)) {
        perror("Error sending data to server");
        exit(1);
    }

    return numBytes;
}

int main(int argc, char *argv[])
{
    int sockfd, numBytes;
    char buf[BUFSIZE];
    char username[BUFSIZE];
    char password[BUFSIZE];

    if (argc != 3) {
        perror("Usage: ./imap_client address port");
        exit(1);
    }

    sockfd = connect_to_server(argv[1], atoi(argv[2]));

    receive_data(sockfd);

    send_data(sockfd, "A001 LOGIN user@domain.com password\r\n");
    receive_data(sockfd);

    send_data(sockfd, "A002 SELECT INBOX\r\n");
    receive_data(sockfd);

    send_data(sockfd, "A003 FETCH 1 BODY[HEADER]\r\n");
    while (1) {
        numBytes = receive_data(sockfd);
        if (strstr(buf, "OK FETCH completed") != NULL) {
            break;
        }
    }

    send_data(sockfd, "A004 LOGOUT\r\n");
    receive_data(sockfd);

    close(sockfd);

    return 0;
}