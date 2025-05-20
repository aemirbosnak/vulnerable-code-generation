//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 8080
#define SERVER_ADDR "www.google.com"
#define BUFFER_SIZE 1024

void error_handling(char* message);

int main(int argc, char* argv[]) {
    int sockfd, bytes_received;
    struct sockaddr_in server_addr;
    char send_buffer[BUFFER_SIZE], recv_buffer[BUFFER_SIZE];

    if (argc!= 2) {
        printf("Usage:./program <filename>\n");
        return 1;
    }

    FILE* file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("Error: File not found.\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        error_handling("socket failed");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDR);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        error_handling("connect failed");
        return 1;
    }

    while (fread(send_buffer, 1, BUFFER_SIZE, file) > 0) {
        bytes_received = send(sockfd, send_buffer, strlen(send_buffer), 0);
        if (bytes_received <= 0) {
            error_handling("send failed");
            return 1;
        }
    }

    close(sockfd);
    fclose(file);

    return 0;
}

void error_handling(char* message) {
    perror(message);
    exit(1);
}