//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <unistd.h>

#define MAX_HOSTNAME_LENGTH 256
#define MAX_PACKET_SIZE 64
#define DEFAULT_TIMEOUT 1000

typedef struct {
    char *hostname;
    int port;
    int timeout;
} ping_target;

void print_usage() {
    printf("Usage: cyberpunk_ping <hostname> [port] [timeout]\n");
    printf("hostname: IP address or hostname of the target\n");
    printf("port: Port number to ping (default: 80)\n");
    printf("timeout: Timeout in milliseconds (default: 1000)\n");
    exit(1);
}

int create_socket(ping_target target) {
    struct sockaddr_in addr;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }
    addr.sin_family = AF_INET;
    addr.sin_port = htons(target.port);
    addr.sin_addr.s_addr = inet_addr(target.hostname);
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        exit(1);
    }
    return sock;
}

void send_ping(int sock, char *message) {
    int bytes_sent = send(sock, message, strlen(message), 0);
    if (bytes_sent == -1) {
        perror("send");
        exit(1);
    }
}

void receive_ping(int sock, char *buffer, int size) {
    int bytes_received = recv(sock, buffer, size, 0);
    if (bytes_received == -1) {
        perror("recv");
        exit(1);
    }
    buffer[bytes_received] = '\0';
}

double calculate_rtt(struct timeval start, struct timeval end) {
    return (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_usage();
    }

    ping_target target;
    target.hostname = argv[1];
    target.port = 80;
    target.timeout = DEFAULT_TIMEOUT;

    if (argc >= 3) {
        target.port = atoi(argv[2]);
    }

    if (argc >= 4) {
        target.timeout = atoi(argv[3]);
    }

    int sock = create_socket(target);

    char message[] = "PING";
    char buffer[MAX_PACKET_SIZE];

    struct timeval start, end;

    while (1) {
        gettimeofday(&start, NULL);
        send_ping(sock, message);
        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(sock, &read_fds);
        struct timeval timeout;
        timeout.tv_sec = target.timeout / 1000;
        timeout.tv_usec = (target.timeout % 1000) * 1000;
        int select_result = select(sock + 1, &read_fds, NULL, NULL, &timeout);
        if (select_result == -1) {
            perror("select");
            exit(1);
        }
        if (FD_ISSET(sock, &read_fds)) {
            receive_ping(sock, buffer, MAX_PACKET_SIZE);
            gettimeofday(&end, NULL);
            double rtt = calculate_rtt(start, end);
            printf("Received ping from %s: %s (RTT: %.2f ms)\n", target.hostname, buffer, rtt);
        } else {
            printf("Timeout: No response from %s\n", target.hostname);
        }
        sleep(1);
    }

    close(sock);

    return 0;
}