//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: complete
#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>

int main() {
    int sockfd, portno;
    struct sockaddr_in server;
    struct hostent *server_host;
    char *host = "127.0.0.1";
    char *service = "80";

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        return 1;
    }

    server_host = gethostbyname(host);
    if (server_host == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        return 1;
    }

    portno = htons(atoi(service));
    server.sin_family = AF_INET;
    server.sin_port = portno;
    bcopy((char *)server_host->h_addr, (char *)&server.sin_addr.s_addr, server_host->h_length);

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("ERROR connecting");
        return 1;
    }

    printf("Connected to server\n");
    char message[] = "Hello, World!";
    if (send(sockfd, message, strlen(message), 0) < 0) {
        perror("ERROR sending message");
        return 1;
    }

    printf("Message sent\n");
    char buffer[1024];
    if (recv(sockfd, buffer, 1024, 0) < 0) {
        perror("ERROR receiving message");
        return 1;
    }

    printf("Received message: %s\n", buffer);
    return 0;
}