//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>

#define PORT 21
#define BUFFER_SIZE 1024

void error_handling(char *message);

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    int n;
    char *username = "anonymous";
    char *password = "anonymous@example.com";

    if (argc < 3) {
        printf("Usage: %s <server_ip> <port_number>\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("ERROR opening socket");
        exit(0);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(portno);

    connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    printf("Connected to %s on port %d\n", argv[1], portno);

    send(sockfd, username, strlen(username), 0);
    send(sockfd, password, strlen(password), 0);

    while (1) {
        bzero(buffer, BUFFER_SIZE);
        n = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (n <= 0)
            break;
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}

void error_handling(char *message) {
    perror(message);
    exit(0);
}