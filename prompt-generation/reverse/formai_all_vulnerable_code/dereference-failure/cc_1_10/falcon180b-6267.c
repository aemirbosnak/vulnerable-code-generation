//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_HOSTNAME_LEN 256
#define MAX_DATA_LEN 64
#define DEFAULT_PORT "80"

/* Function to print usage instructions */
void print_usage() {
    printf("Usage:./ping <hostname> [port]\n");
    printf("  <hostname>: Hostname or IP address to ping\n");
    printf("  [port]:      Port number (default: 80)\n");
}

/* Function to send a ping request and receive a response */
int send_ping_request(int sock, char* hostname, int port) {
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        printf("Error: Invalid hostname or IP address\n");
        return -1;
    }

    char send_buf[MAX_DATA_LEN] = "PING";
    send(sock, send_buf, strlen(send_buf), 0);

    char recv_buf[MAX_DATA_LEN];
    memset(recv_buf, 0, sizeof(recv_buf));
    int recv_len = recv(sock, recv_buf, sizeof(recv_buf), 0);

    if (recv_len <= 0) {
        printf("Error: No response from server\n");
        return -1;
    }

    printf("Response: %s\n", recv_buf);
    return 0;
}

/* Main function */
int main(int argc, char* argv[]) {
    if (argc < 2) {
        print_usage();
        return 1;
    }

    char* hostname = argv[1];
    int port = strcmp(argv[2], "")? atoi(argv[2]) : 80;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error: Failed to create socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        printf("Error: Invalid hostname or IP address\n");
        close(sock);
        return 1;
    }

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Failed to connect to server\n");
        close(sock);
        return 1;
    }

    send_ping_request(sock, hostname, port);

    close(sock);
    return 0;
}