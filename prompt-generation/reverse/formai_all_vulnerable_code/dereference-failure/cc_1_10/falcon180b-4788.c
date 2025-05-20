//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char sendbuffer[BUFFER_SIZE];
    char recvbuffer[BUFFER_SIZE];

    if (argc!= 3) {
        printf("Usage: %s <server_address> <port_number>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        printf("Enter command: ");
        fgets(sendbuffer, BUFFER_SIZE, stdin);

        if (strcmp(sendbuffer, "QUIT") == 0) {
            break;
        }

        n = send(sockfd, sendbuffer, strlen(sendbuffer), 0);

        if (n == -1) {
            printf("Error sending command\n");
            exit(1);
        }

        memset(recvbuffer, 0, BUFFER_SIZE);
        n = recv(sockfd, recvbuffer, BUFFER_SIZE, 0);

        if (n == -1) {
            printf("Error receiving response\n");
            exit(1);
        }

        printf("Response: %s", recvbuffer);
    }

    close(sockfd);

    return 0;
}