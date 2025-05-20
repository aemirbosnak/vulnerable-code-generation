//MISTRAL-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#define MAX_RETRIES 3
#define TIMEOUT 5000
#define BUFFER_SIZE 1024

typedef struct {
    char hostname[256];
    int port;
    int (*check_function)(int sockfd);
} monitor_t;

int check_website(int sockfd) {
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (bytes_received > 0) {
        return 1;
    }
    return 0;
}

int recursive_check_website(monitor_t *monitor, int retries_left) {
    int sockfd, status = 0;
    struct sockaddr_in server_address;
    if (retries_left <= 0) {
        fprintf(stderr, "Failed to connect to %s:%d after %d retries\n",
                monitor->hostname, monitor->port, MAX_RETRIES);
        return 0;
    }
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation error");
        return 0;
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(monitor->port);

    if (inet_pton(AF_INET, monitor->hostname, &server_address.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        close(sockfd);
        return 0;
    }

    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Connection failed");
        close(sockfd);
        return recursive_check_website(monitor, retries_left - 1);
    }

    status = monitor->check_function(sockfd);

    close(sockfd);
    return status;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    monitor_t monitor = {.hostname = argv[1], .port = atoi(argv[2])};
    monitor.check_function = check_website;

    int status = recursive_check_website(&monitor, MAX_RETRIES);
    printf("Website %s:%d is %sup%s\n", argv[1], argv[2], status ? "" : "down", status ? "" : " ");

    return 0;
}