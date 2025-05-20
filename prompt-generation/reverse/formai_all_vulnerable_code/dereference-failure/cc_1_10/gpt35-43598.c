//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 1024

void print_usage() {
    printf("Usage: qos-monitor [hostname] [port]\n");
    exit(0);
}

void check_server(const char *hostname, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Failed to create socket");
        exit(1);
    }

    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR: Unable to resolve hostname %s.\n", hostname);
        exit(2);
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    if (connect(sock, (const struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Failed to connect to server");
        exit(3);
    }

    printf("Connected to server %s:%d\n", hostname, port);

    clock_t start = clock();
    char buffer[BUFFER_SIZE];
    for (int i = 0; i < BUFFER_SIZE; i++) {
        buffer[i] = 'a' + rand() % 26;
    }

    long long total_bytes_sent = 0;
    while (total_bytes_sent < 1000000) {
        int bytes_sent = send(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_sent < 0) {
            perror("Failed to send data");
            exit(4);
        }
        total_bytes_sent += bytes_sent;
    }

    clock_t end = clock();
    double elapsed_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    double transfer_rate = (double) total_bytes_sent / elapsed_time;
    printf("Sent %lld bytes in %f seconds. Transfer rate: %f bytes/sec\n", total_bytes_sent, elapsed_time, transfer_rate);

    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
    }

    const char *hostname = argv[1];
    int port = atoi(argv[2]);

    check_server(hostname, port);

    return 0;
}