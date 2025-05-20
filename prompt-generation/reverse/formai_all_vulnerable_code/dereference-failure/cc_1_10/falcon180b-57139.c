//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_BUF_SIZE 1024

struct qos_data {
    int packet_count;
    int packet_loss;
    int jitter;
    int latency;
};

void get_qos_data(int sock, struct qos_data *qos_data) {
    char buf[MAX_BUF_SIZE];
    memset(buf, 0, MAX_BUF_SIZE);
    int bytes_received = recv(sock, buf, MAX_BUF_SIZE, 0);
    if (bytes_received <= 0) {
        printf("Error receiving data from socket.\n");
        exit(EXIT_FAILURE);
    }

    char *delimiter = ",";
    char *token = strtok(buf, delimiter);
    qos_data->packet_count = atoi(token);

    token = strtok(NULL, delimiter);
    qos_data->packet_loss = atoi(token);

    token = strtok(NULL, delimiter);
    qos_data->jitter = atoi(token);

    token = strtok(NULL, delimiter);
    qos_data->latency = atoi(token);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <server_ip> <port>\n", argv[0]);
        return 1;
    }

    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        printf("Error creating socket.\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        printf("Invalid server IP address.\n");
        close(sock);
        return 1;
    }

    while (1) {
        struct qos_data qos_data;
        get_qos_data(sock, &qos_data);
        printf("Packet count: %d\n", qos_data.packet_count);
        printf("Packet loss: %d%%\n", qos_data.packet_loss);
        printf("Jitter: %dms\n", qos_data.jitter);
        printf("Latency: %dms\n\n", qos_data.latency);

        sleep(5);
    }

    close(sock);
    return 0;
}