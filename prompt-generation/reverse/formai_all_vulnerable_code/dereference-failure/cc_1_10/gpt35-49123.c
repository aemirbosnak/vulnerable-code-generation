//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[])
{
    struct sockaddr_in server_address;
    int socket_fd, connection_status;
    int buffer_size = 1000000; // 1 MB
    char *buffer = malloc(buffer_size);
    memset(buffer, '\0', buffer_size);

    if (argc < 2) {
        printf("Usage: ./internet_speed_test <IP_ADDRESS>\n");
        return 1;
    }

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        printf("Error: Unable to create socket.\n");
        return 1;
    }

    memset(&server_address, '\0', sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(argv[1]);
    server_address.sin_port = htons(80);

    connection_status = connect(socket_fd, (struct sockaddr*) &server_address, sizeof(server_address));
    if (connection_status < 0) {
        printf("Error: Unable to connect to server.\n");
        return 1;
    }

    clock_t start_time, end_time;
    double execution_time;

    start_time = clock();
    send(socket_fd, "GET /speedtest/random1M.bin HTTP/1.1\r\nHost: speedtest.net\r\nConnection: close\r\n\r\n", strlen("GET /speedtest/random1M.bin HTTP/1.1\r\nHost: speedtest.net\r\nConnection: close\r\n\r\n"), 0);
    recv(socket_fd, buffer, buffer_size, 0);
    end_time = clock();

    execution_time = (double) (end_time - start_time) / CLOCKS_PER_SEC;
    double speed = (double) (strlen(buffer) / 1048576) / execution_time;

    printf("Download speed: %.2f MB/s\n", speed);

    close(socket_fd);
    free(buffer);

    return 0;
}