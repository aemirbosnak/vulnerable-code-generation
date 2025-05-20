//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>

#define MAX_DATAGRAM_SIZE 1024
#define SERVER_PORT 5000


struct hostent* get_host_by_name(const char* name);

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <server_address> <duration_in_seconds>\n", argv[0]);
        exit(1);
    }

    char* server_address = argv[1];
    int duration = atoi(argv[2]);

    struct hostent* server = get_host_by_name(server_address);
    if (server == NULL) {
        fprintf(stderr, "Invalid server address\n");
        exit(1);
    }

    int server_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (server_socket == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = *(unsigned long*)server->h_addr;

    if (connect(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error connecting to server: %s\n", strerror(errno));
        exit(1);
    }

    char buffer[MAX_DATAGRAM_SIZE];
    int bytes_received;

    time_t start_time = time(NULL);
    double total_latency = 0;
    int total_packets = 0;

    while (duration > 0) {
        memset(buffer, 0, MAX_DATAGRAM_SIZE);
        snprintf(buffer, MAX_DATAGRAM_SIZE, "PING %d", total_packets++);

        if (send(server_socket, buffer, strlen(buffer), 0) == -1) {
            fprintf(stderr, "Error sending packet: %s\n", strerror(errno));
            exit(1);
        }

        if ((bytes_received = recv(server_socket, buffer, MAX_DATAGRAM_SIZE, 0)) == -1) {
            fprintf(stderr, "Error receiving packet: %s\n", strerror(errno));
            exit(1);
        }

        double latency = difftime(time(NULL), start_time) / total_packets;
        total_latency += latency;

        printf("Packet %d: Latency: %.2lf ms\n", total_packets, latency * 1000);

        if (strncmp(buffer, "PONG", 4)!= 0) {
            fprintf(stderr, "Invalid response from server\n");
            exit(1);
        }
    }

    close(server_socket);
    return 0;
}

struct hostent* get_host_by_name(const char* name) {
    struct hostent* result = gethostbyname(name);
    if (result == NULL) {
        herror("gethostbyname");
        exit(1);
    }
    return result;
}