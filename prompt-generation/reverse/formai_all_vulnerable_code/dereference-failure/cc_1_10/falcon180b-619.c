//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, port;
    struct hostent *server;
    char *ip;
    char buffer[BUFFER_SIZE];

    if (argc!= 3) {
        printf("Usage:./client <server_ip> <port>\n");
        exit(1);
    }

    ip = argv[1];
    port = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server = gethostbyname(ip);

    if (server == NULL) {
        printf("Error resolving hostname\n");
        exit(1);
    }

    memcpy(&(server->h_addr), &(server->h_addr_list[0]),
            server->h_length);

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = *(unsigned long *)server->h_addr;

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    char message[BUFFER_SIZE];
    sprintf(message, "HELO %s\r\n", "localhost");
    send(sockfd, message, strlen(message), 0);

    while (1) {
        bzero(buffer, BUFFER_SIZE);
        if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
            printf("Error receiving data\n");
            exit(1);
        }

        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}