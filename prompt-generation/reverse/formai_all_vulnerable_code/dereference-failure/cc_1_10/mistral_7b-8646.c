//MISTRAL-7B DATASET v1.0 Category: Internet Speed Test Application ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <math.h>

#define SERVER_PORT 4321
#define BUFFER_SIZE 1024
#define NUM_PACKETS 10
#define DATA_SIZE 1024

void send_data(int socket_desc, char *data) {
    send(socket_desc, data, strlen(data), 0);
    fflush(stdout);
}

int main(int argc, char *argv[]) {
    int socket_desc, read_size, i;
    char server_ip[INET_ADDRSTRLEN];
    char *data = malloc(DATA_SIZE * sizeof(char));
    struct sockaddr_in server;

    if (argc != 2) {
        printf("Usage: %s <server_ip>\n", argv[0]);
        return -1;
    }

    strcpy(server.sin_addr.s_addr, inet_addr(argv[1]));
    server.sin_family = AF_INET;
    server.sin_port = htons(SERVER_PORT);

    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    connect(socket_desc, (struct sockaddr *)&server, sizeof(server));

    clock_t start, end;
    double elapsed_time, total_time, transfer_rate;

    start = clock();
    for (i = 0; i < NUM_PACKETS; i++) {
        memset(data, 'a', DATA_SIZE);
        send_data(socket_desc, data);
        read_size = recv(socket_desc, data, DATA_SIZE, 0);
    }
    end = clock();

    total_time = (double)(end - start) / CLOCKS_PER_SEC;
    transfer_rate = (double)DATA_SIZE * NUM_PACKETS / total_time;

    printf("Transfer rate: %.2f MB/s\n", transfer_rate / (1024 * 1024));

    close(socket_desc);
    free(data);

    return 0;
}