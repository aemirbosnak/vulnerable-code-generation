//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <hostname/IP address>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    struct hostent *host = gethostbyname(hostname);

    if (host == NULL) {
        printf("Host not found.\n");
        return 1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Socket creation failed.\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    inet_pton(AF_INET, host->h_addr, &server_addr.sin_addr);

    int status = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (status == -1) {
        printf("Connection failed.\n");
        close(sockfd);
        return 1;
    }

    char send_buffer[BUF_SIZE] = "GET / HTTP/1.0\r\n\r\n";
    send(sockfd, send_buffer, strlen(send_buffer), 0);

    char recv_buffer[BUF_SIZE];
    memset(recv_buffer, 0, BUF_SIZE);
    int bytes_received = recv(sockfd, recv_buffer, BUF_SIZE, 0);

    printf("Received response: %s\n", recv_buffer);

    close(sockfd);
    return 0;
}