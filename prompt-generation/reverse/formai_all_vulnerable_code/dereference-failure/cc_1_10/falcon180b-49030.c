//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFLEN 1024
#define TRUE 1
#define FALSE 0
#define PORT 7

int main(int argc, char* argv[]) {
    int sockfd, n;
    struct hostent* server;
    struct sockaddr_in server_addr;
    char buffer[BUFLEN];
    int host_len;
    int status;
    char* hostname;

    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    hostname = argv[1];
    host_len = strlen(hostname);

    server = gethostbyname(hostname);
    if (server == NULL) {
        printf("No such host\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("socket failed\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    memcpy(&server_addr.sin_addr, server->h_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("connect failed\n");
        exit(1);
    }

    printf("Connected to %s\n", hostname);

    while (TRUE) {
        memset(buffer, 0, BUFLEN);
        n = read(sockfd, buffer, BUFLEN-1);
        if (n <= 0) {
            printf("Disconnected\n");
            break;
        }
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}