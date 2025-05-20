//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_DATA_SIZE 1024
#define MAX_HOST_NAME_LEN 1024
#define MAX_PORT_NUM 65535

int ping_host(char *hostname, int port);
void print_usage();

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        print_usage();
        exit(1);
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    int result = ping_host(hostname, port);

    if (result == 0) {
        printf("Host is alive\n");
    } else {
        printf("Host is not alive\n");
    }

    return 0;
}

void print_usage() {
    printf("Usage:./ping_test <hostname> <port>\n");
}

int ping_host(char *hostname, int port) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host_info;
    char buffer[MAX_DATA_SIZE];
    int bytes_received;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return -1;
    }

    host_info = gethostbyname(hostname);
    if (host_info == NULL) {
        printf("Host not found\n");
        close(sockfd);
        return -1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr, host_info->h_addr, host_info->h_length);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Connection failed\n");
        close(sockfd);
        return -1;
    }

    send(sockfd, "PING", strlen("PING"), 0);
    bytes_received = recv(sockfd, buffer, MAX_DATA_SIZE, 0);

    if (bytes_received > 0) {
        if (strncmp(buffer, "PONG", strlen("PONG")) == 0) {
            printf("Host is alive\n");
        } else {
            printf("Unexpected response from host\n");
        }
    } else {
        printf("No response from host\n");
    }

    close(sockfd);
    return 0;
}