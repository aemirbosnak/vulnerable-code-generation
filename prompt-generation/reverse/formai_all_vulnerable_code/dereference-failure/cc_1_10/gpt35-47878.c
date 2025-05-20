//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("Usage: %s <server_ip> <port>\n", argv[0]);
        return 1;
    }

    char *server_ip = argv[1];
    int server_port = atoi(argv[2]);
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (sock == -1) {
        printf("Error: Socket creation failed.\n");
        return 1;
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(server_ip);
    server_address.sin_port = htons(server_port);

    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        printf("Error: Connection failed.\n");
        return 1;
    }

    printf("Connected to %s:%d\n", server_ip, server_port);

    char buffer[1024] = {0};
    char message[1024] = {0};
    sprintf(message, "GET / HTTP/1.1\r\nHost: %s:%d\r\nConnection: close\r\n\r\n", server_ip, server_port);

    if (send(sock, message, strlen(message), 0) == -1) {
        printf("Error: Send failed.\n");
        return 1;
    }

    printf("Request Sent:\n%s\n", message);

    while (1) {
        int bytes_received = recv(sock, buffer, sizeof(buffer), 0);
        if (bytes_received == -1) {
            printf("Error: Receive failed.\n");
            return 1;
        }
        if (bytes_received == 0) {
            break;
        }
        printf("%.*s", bytes_received, buffer);
        memset(buffer, 0, sizeof(buffer));
    }

    close(sock);
    printf("Connection closed.\n");
    
    return 0;
}