//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in serveraddr;
    char buf[BUF_SIZE];

    // Connect to the server
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        printf("Error creating socket\n");
        exit(1);
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(110);
    serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1)
    {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Send USER command
    sprintf(buf, "USER %s\r\n", argv[1]);
    write(sockfd, buf, strlen(buf));

    // Send PASS command
    sprintf(buf, "PASS %s\r\n", argv[2]);
    write(sockfd, buf, strlen(buf));

    // Receive server response
    memset(buf, 0, BUF_SIZE);
    read(sockfd, buf, BUF_SIZE);
    printf("Server response: %s", buf);

    // Send LIST command
    sprintf(buf, "LIST\r\n");
    write(sockfd, buf, strlen(buf));

    // Receive server response
    memset(buf, 0, BUF_SIZE);
    read(sockfd, buf, BUF_SIZE);
    printf("Server response: %s", buf);

    // Send RETR command
    sprintf(buf, "RETR %d\r\n", atoi(argv[3]));
    write(sockfd, buf, strlen(buf));

    // Receive server response
    memset(buf, 0, BUF_SIZE);
    read(sockfd, buf, BUF_SIZE);
    printf("Server response: %s", buf);

    // Send DELE command
    sprintf(buf, "DELE %d\r\n", atoi(argv[3]));
    write(sockfd, buf, strlen(buf));

    // Receive server response
    memset(buf, 0, BUF_SIZE);
    read(sockfd, buf, BUF_SIZE);
    printf("Server response: %s", buf);

    // Send QUIT command
    sprintf(buf, "QUIT\r\n");
    write(sockfd, buf, strlen(buf));

    // Receive server response
    memset(buf, 0, BUF_SIZE);
    read(sockfd, buf, BUF_SIZE);
    printf("Server response: %s", buf);

    // Close the socket
    close(sockfd);

    return 0;
}