//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char hostname[] = "speedtest.net";
    int port = 80;
    int sockfd;
    struct hostent *host;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int len;
    double speed;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        fprintf(stderr, "Error creating socket\n");
        exit(1);
    }

    host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Error resolving hostname\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error connecting to server\n");
        exit(1);
    }

    while (1) {
        len = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (len <= 0) {
            fprintf(stderr, "Error receiving data\n");
            exit(1);
        }

        speed = (double)len / (double)BUFFER_SIZE;
        printf("Download speed: %.2f bytes/sec\n", speed);
    }

    close(sockfd);
    return 0;
}