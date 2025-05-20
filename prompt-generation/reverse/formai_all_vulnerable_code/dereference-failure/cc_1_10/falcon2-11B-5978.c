//Falcon2-11B DATASET v1.0 Category: Website Uptime Monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main() {
    struct hostent* host = NULL;
    struct sockaddr_in addr;
    int sockfd;

    char* hostname = getenv("HOSTNAME");
    if (hostname == NULL) {
        hostname = "localhost";
    }

    if ((host = gethostbyname(hostname)) == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(80);
    memcpy(&addr.sin_addr.s_addr, host->h_addr, host->h_length);

    int ttl = 1;
    char buffer[INET_ADDRSTRLEN];
    while (1) {
        int bytes_sent = sendto(sockfd, "GET / HTTP/1.0\r\n\r\n", 45, 0, (struct sockaddr*)&addr, sizeof(addr));
        if (bytes_sent == 0) {
            perror("sendto");
            exit(EXIT_FAILURE);
        }

        int bytes_received = recvfrom(sockfd, buffer, sizeof(buffer), 0, NULL, NULL);
        if (bytes_received == 0) {
            perror("recvfrom");
            exit(EXIT_FAILURE);
        }

        printf("Ping response from %s: %s\n", hostname, buffer);
        sleep(1);
    }

    return 0;
}