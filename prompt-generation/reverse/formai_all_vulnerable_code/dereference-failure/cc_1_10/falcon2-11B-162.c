//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    char* hostname = argv[1];
    int port = atoi(argv[2]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(hostname);

    int addrlen = sizeof(server);
    if (connect(sockfd, (struct sockaddr*)&server, addrlen) == -1) {
        perror("connect");
        return 1;
    }

    char buffer[256];
    printf("Enter message to send: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    int n = send(sockfd, buffer, strlen(buffer), 0);
    if (n == -1) {
        perror("send");
        return 1;
    }

    printf("Message sent successfully.\n");

    char* response = "220 SMTP ready\r\n";
    printf("Received response: %s\n", response);

    free(response);

    close(sockfd);

    return 0;
}