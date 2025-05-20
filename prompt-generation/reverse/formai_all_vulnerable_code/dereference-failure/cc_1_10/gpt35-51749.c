//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <time.h>

#define PORT 8080
#define INTERVAL 1 // in seconds
#define MAX_DATA_SIZE 50

void print_usage();
int create_socket(char *ip);
int check_qos(int sock);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage();
        return 1;
    }

    int sock_fd, res;
    char *ip = argv[1];
    fd_set fds;
    struct timeval tv;

    sock_fd = create_socket(ip);

    while (1) {
        FD_ZERO(&fds);
        FD_SET(sock_fd, &fds);

        tv.tv_sec = INTERVAL;
        tv.tv_usec = 0;

        res = select(sock_fd + 1, &fds, NULL, NULL, &tv);

        if (res == -1) {
            perror("select error");
            close(sock_fd);
            return 1;
        } else if (res == 0) {
            printf("No data received from server in the last %d seconds.\n", INTERVAL);
        } else {
            if (check_qos(sock_fd) == 0) {
                printf("Network Quality of Service is poor.\n");
            } else {
                printf("Network Quality of Service is good.\n");
            }
        }
    }

    close(sock_fd);
    return 0;
}

void print_usage() {
    printf("usage: ./qos_monitor <ip_address>\n");
}

int create_socket(char *ip) {
    int sock_fd;
    struct sockaddr_in server_address;
    struct hostent *server;

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (sock_fd == -1) {
        perror("socket creation failed");
        exit(1);
    }

    server = gethostbyname(ip);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char *)&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *)server->h_addr_list[0], (char *)&server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(PORT);

    if (connect(sock_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("connection failed");
        exit(1);
    }

    return sock_fd;
}

int check_qos(int sock) {
    char buffer[MAX_DATA_SIZE];
    int n, bytes_sent, bytes_received;
    double start_time, end_time, rtt;

    bzero(buffer, MAX_DATA_SIZE);
    strcpy(buffer, "qos_test");

    start_time = clock();
    bytes_sent = send(sock, buffer, strlen(buffer), 0);
    if (bytes_sent < 0) {
        perror("failed to send data");
        return -1;
    }

    bzero(buffer, MAX_DATA_SIZE);
    bytes_received = recv(sock, buffer, MAX_DATA_SIZE - 1, 0);
    if (bytes_received < 0) {
        perror("failed to receive data");
        return -1;
    }
    end_time = clock();

    rtt = (end_time - start_time) / CLOCKS_PER_SEC; // in seconds
    if (rtt > 0.5) {
        return 0; // Poor QoS
    } else {
        return 1; // Good QoS
    }
}