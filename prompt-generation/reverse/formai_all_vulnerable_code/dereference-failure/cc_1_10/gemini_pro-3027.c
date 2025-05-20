//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Could not resolve hostname %s\n", hostname);
        return 1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, host->h_addr, host->h_length);
    serv_addr.sin_port = htons(80);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        close(sockfd);
        return 1;
    }

    char *request = "GET / HTTP/1.1\r\nHost: %s\r\n\r\n";
    char buffer[1024];
    sprintf(buffer, request, hostname);
    write(sockfd, buffer, strlen(buffer));

    int bytes_read = read(sockfd, buffer, sizeof(buffer));
    if (bytes_read < 0) {
        perror("read");
        close(sockfd);
        return 1;
    }

    buffer[bytes_read] = '\0';
    printf("%s\n", buffer);

    close(sockfd);
    return 0;
}