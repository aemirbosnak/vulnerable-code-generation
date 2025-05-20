//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/timeb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[MAX_BUFFER];
    char *message = "Hello, world! ";

    if (argc < 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(0);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(0);
    }

    printf("Connected to server\n");

    while (1) {
        memset(buffer, '\0', MAX_BUFFER);
        printf("Enter message to send: ");
        fgets(buffer, MAX_BUFFER, stdin);

        if (strcmp(buffer, "quit") == 0) {
            send(sockfd, "QUIT", strlen("QUIT"), 0);
            break;
        }

        send(sockfd, buffer, strlen(buffer), 0);
    }

    close(sockfd);
    return 0;
}