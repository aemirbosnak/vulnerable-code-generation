//Falcon-180B DATASET v1.0 Category: URL Sanitizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define PORT 8080
#define SERVER_IP "127.0.0.1"

void sanitize_url(char *url) {
    char *sanitized_url = malloc(strlen(url) + 1);
    int i = 0, j = 0;

    while (url[i]!= '\0') {
        if (isalnum(url[i])) {
            sanitized_url[j++] = tolower(url[i]);
        }
        i++;
    }

    sanitized_url[j] = '\0';
    strcpy(url, sanitized_url);
    free(sanitized_url);
}

int main() {
    int sockfd, newsockfd, addrlen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER_IP, &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        bzero(buffer, BUFFER_SIZE);
        printf("Enter a URL: ");
        fgets(buffer, BUFFER_SIZE, stdin);

        sanitize_url(buffer);

        send(sockfd, buffer, strlen(buffer), 0);

        bzero(buffer, BUFFER_SIZE);
        recv(sockfd, buffer, BUFFER_SIZE, 0);

        printf("Server response: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}