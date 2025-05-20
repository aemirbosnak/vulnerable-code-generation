//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080

void error_handling(char *message);

int main(int argc, char *argv[]) {
    int sockfd, numbytes;
    char send_buffer[BUFFER_SIZE];
    char recv_buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char *server_ip;

    if (argc!= 2) {
        printf("Usage: %s <server_ip>\n", argv[0]);
        return 1;
    }

    server_ip = argv[1];
    server = gethostbyname(server_ip);

    if (server == NULL) {
        printf("No such host\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        error_handling("socket failed");
        return 1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(SERVER_PORT);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error_handling("connect failed");
        return 1;
    }

    printf("Connected to %s:%d\n", server_ip, SERVER_PORT);

    while (1) {
        memset(send_buffer, 0, BUFFER_SIZE);
        memset(recv_buffer, 0, BUFFER_SIZE);

        printf("Enter a message to send: ");
        fgets(send_buffer, BUFFER_SIZE, stdin);

        if (send(sockfd, send_buffer, strlen(send_buffer), 0) < 0) {
            error_handling("send failed");
            return 1;
        }

        numbytes = recv(sockfd, recv_buffer, BUFFER_SIZE, 0);

        if (numbytes <= 0) {
            error_handling("recv failed");
            return 1;
        }

        recv_buffer[numbytes] = '\0';
        printf("Received message from server: %s\n", recv_buffer);
    }

    return 0;
}

void error_handling(char *message) {
    perror(message);
    exit(0);
}