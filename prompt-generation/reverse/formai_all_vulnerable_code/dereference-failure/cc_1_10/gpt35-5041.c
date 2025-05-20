//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];

    struct hostent *he = gethostbyname(hostname);
    if (he == NULL) {
        printf("could not resolve %s\n", hostname);
        exit(1);
    }

    struct in_addr **addr_list = (struct in_addr **) he->h_addr_list;

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr = *addr_list[0];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("could not create socket\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("could not connect to server\n");
        exit(1);
    }

    const char *request =
        "GET / HTTP/1.1\r\n"
        "Host: %s\r\n"
        "\r\n";

    char buffer[1024];
    sprintf(buffer, request, hostname);

    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        printf("could not send request to server\n");
        exit(1);
    }

    int length = 0;
    char response[1024];
    while (length = recv(sockfd, response, sizeof(response) - 1, 0)) {
        if (length < 0) {
            printf("could not receive response from server\n");
            exit(1);
        }

        response[length] = '\0';
        printf("%s", response);
    }

    close(sockfd);

    return 0;
}