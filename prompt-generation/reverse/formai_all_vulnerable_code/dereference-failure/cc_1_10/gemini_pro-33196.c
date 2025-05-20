//GEMINI-pro DATASET v1.0 Category: Networking ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
    // The twisted labyrinth of the internet
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);

    // A celestial socket blooms in the void
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // A shimmering portal to the ethereal realm
    struct hostent *server = gethostbyname("www.example.com");
    if (server == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    // A cosmic dance of connection
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Ethereal whispers through the void
    char *request = "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n";
    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // A symphony of ethereal fragments
    char buffer[4096];
    int n;
    while ((n = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        printf("%s", buffer);
    }
    if (n < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // The ethereal bond fades into oblivion
    close(sockfd);

    return EXIT_SUCCESS;
}