//Falcon2-11B DATASET v1.0 Category: Firewall ; Style: surprised
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <IP> <Port>\n", argv[0]);
        exit(1);
    }

    struct sockaddr_in addr;
    int sockfd;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[2]));
    addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("connect");
        exit(1);
    }

    char buffer[1024];
    int bytes_read;

    while (1) {
        bytes_read = recv(sockfd, buffer, sizeof(buffer), 0);
        if (bytes_read < 0) {
            perror("recv");
            exit(1);
        }

        printf("Received data: %s\n", buffer);

        if (strcmp(buffer, "bye") == 0) {
            break;
        }

        char response[1024];
        snprintf(response, sizeof(response), "Hello, %s! How are you doing today?", buffer);

        if (send(sockfd, response, sizeof(response), 0) < 0) {
            perror("send");
            exit(1);
        }
    }

    close(sockfd);
    return 0;
}