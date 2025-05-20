//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in server_addr;
    char send_buffer[BUFFER_SIZE], recv_buffer[BUFFER_SIZE];
    int opt = 1;

    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Number>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        perror("socket failed");
        exit(1);
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    printf("Connected to %s:%d\n", inet_ntoa(server_addr.sin_addr), ntohs(server_addr.sin_port));

    while (1) {
        memset(send_buffer, 0, BUFFER_SIZE);
        memset(recv_buffer, 0, BUFFER_SIZE);

        printf("Enter a message to send: ");
        fgets(send_buffer, BUFFER_SIZE, stdin);

        n = send(sockfd, send_buffer, strlen(send_buffer), 0);

        if (n < 0) {
            perror("send failed");
            exit(1);
        }

        n = recv(sockfd, recv_buffer, BUFFER_SIZE, 0);

        if (n < 0) {
            perror("recv failed");
            exit(1);
        }

        printf("Received message: %s\n", recv_buffer);
    }

    close(sockfd);
    return 0;
}