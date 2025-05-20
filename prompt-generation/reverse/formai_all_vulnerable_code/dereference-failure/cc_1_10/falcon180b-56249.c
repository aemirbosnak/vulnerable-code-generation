//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return 1;
    }

    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        printf("Error: Invalid IP address\n");
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: Failed to create socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(7);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Failed to connect to %s\n", argv[1]);
        close(sock);
        return 1;
    }

    char send_buf[BUF_SIZE] = "PING";
    send(sock, send_buf, strlen(send_buf), 0);

    char recv_buf[BUF_SIZE];
    int bytes_received = recv(sock, recv_buf, BUF_SIZE, 0);
    if (bytes_received <= 0) {
        printf("Error: Failed to receive data from %s\n", argv[1]);
        close(sock);
        return 1;
    }

    printf("Data received from %s: %s\n", argv[1], recv_buf);

    close(sock);
    return 0;
}