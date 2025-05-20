//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_DATA_SIZE 1024
#define DEFAULT_TIMEOUT 5

int main(int argc, char **argv) {
    int sock;
    struct sockaddr_in server_addr;
    char data[MAX_DATA_SIZE];
    int data_size;
    int timeout;
    int status;
    time_t start_time, end_time;

    if (argc!= 4) {
        printf("Usage: %s <IP address> <port number> <timeout in seconds>\n", argv[0]);
        exit(1);
    }

    strcpy(server_addr.sin_zero, "\0\0\0\0\0\0\0\0");
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: Could not create socket\n");
        exit(1);
    }

    status = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (status == -1) {
        printf("Error: Could not connect to server\n");
        exit(1);
    }

    timeout = atoi(argv[3]);
    if (timeout <= 0) {
        timeout = DEFAULT_TIMEOUT;
    }

    start_time = time(NULL);
    data_size = send(sock, "PING", strlen("PING"), 0);
    if (data_size == -1) {
        printf("Error: Could not send data\n");
        exit(1);
    }
    end_time = time(NULL);

    if (difftime(end_time, start_time) > timeout) {
        printf("Timeout: No response from server\n");
    } else {
        memset(data, '\0', MAX_DATA_SIZE);
        data_size = recv(sock, data, MAX_DATA_SIZE, 0);
        if (data_size == -1) {
            printf("Error: Could not receive data\n");
            exit(1);
        }
        printf("Response: %s\n", data);
    }

    close(sock);
    exit(0);
}