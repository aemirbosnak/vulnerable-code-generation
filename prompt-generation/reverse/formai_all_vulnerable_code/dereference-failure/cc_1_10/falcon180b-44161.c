//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_DATA_SIZE 1024

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <server_ip> <port_number>\n", argv[0]);
        exit(1);
    }

    char *server_ip = argv[1];
    int port_number = atoi(argv[2]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Failed to create socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_number);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Failed to connect to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    char send_data[MAX_DATA_SIZE];
    char recv_data[MAX_DATA_SIZE];

    while (1) {
        memset(send_data, 'A', MAX_DATA_SIZE);
        int bytes_sent = send(sock, send_data, MAX_DATA_SIZE, 0);

        int bytes_recv = recv(sock, recv_data, MAX_DATA_SIZE, 0);
        if (bytes_recv <= 0) {
            printf("Disconnected from server\n");
            break;
        }

        double speed = (double)bytes_sent / (double)bytes_recv;

        printf("Speed: %.2f KB/s\n", speed);

        usleep(100000);
    }

    close(sock);
    return 0;
}