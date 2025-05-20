//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define TRUE    1
#define FALSE   0
#define PORT    80
#define MAX     100

int main(int argc, char *argv[])
{
    int sockfd, numbytes;
    char sendline[MAX];
    char recvline[MAX];
    struct hostent *server;
    struct sockaddr_in serveraddr;

    printf("Enter the IP address of the server: ");
    scanf("%s", sendline);

    server = gethostbyname(sendline);

    if (server == NULL) {
        printf("Error: Invalid server IP address\n");
        exit(1);
    }

    printf("Enter the domain name of the server: ");
    scanf("%s", sendline);

    strcpy(recvline, sendline);

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(PORT);
    serveraddr.sin_addr = *((struct in_addr *)server->h_addr);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error: Could not create socket\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        printf("Error: Could not connect to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (TRUE) {
        printf("Enter a string to send: ");
        scanf("%s", sendline);

        numbytes = send(sockfd, sendline, strlen(sendline), 0);

        if (numbytes <= 0) {
            printf("Error: Could not send data\n");
            exit(1);
        }

        numbytes = recv(sockfd, recvline, MAX, 0);

        if (numbytes <= 0) {
            printf("Error: Could not receive data\n");
            exit(1);
        }

        printf("Received data: %s\n", recvline);
    }

    close(sockfd);

    return 0;
}