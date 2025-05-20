//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char send_buffer[BUFFER_SIZE];
    char recv_buffer[BUFFER_SIZE];

    if (argc!= 4) {
        printf("Usage:./smtp_client <server_ip> <server_port> <email_message>\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: socket failed\n");
        return 1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        printf("Error: connect failed\n");
        close(sockfd);
        return 1;
    }

    printf("Connected to server\n");

    strcpy(send_buffer, argv[3]);
    n = strlen(send_buffer);
    send(sockfd, send_buffer, n, 0);

    memset(recv_buffer, 0, BUFFER_SIZE);
    n = recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
    if (n <= 0) {
        printf("Error: recv failed\n");
        close(sockfd);
        return 1;
    }

    printf("Server response:\n%s\n", recv_buffer);

    close(sockfd);
    return 0;
}