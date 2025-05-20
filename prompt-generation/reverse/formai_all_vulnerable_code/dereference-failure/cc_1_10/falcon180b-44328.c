//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_HOST_LEN 256
#define MAX_DATA_LEN 1024

void print_usage(char *prog_name) {
    fprintf(stderr, "Usage: %s <hostname>\n", prog_name);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        print_usage(argv[0]);
        return 1;
    }

    char hostname[MAX_HOST_LEN];
    strcpy(hostname, argv[1]);

    struct hostent *host_info = gethostbyname(hostname);

    if (host_info == NULL) {
        fprintf(stderr, "Error: Host %s not found.\n", hostname);
        return 1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        fprintf(stderr, "Error: Failed to create socket.\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(7);
    inet_pton(AF_INET, inet_ntoa(*(struct in_addr *)host_info->h_addr), &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Error: Failed to connect to host.\n");
        close(sockfd);
        return 1;
    }

    char send_data[MAX_DATA_LEN] = "PING";
    send(sockfd, send_data, strlen(send_data), 0);

    char recv_data[MAX_DATA_LEN];
    memset(recv_data, 0, sizeof(recv_data));

    int bytes_received = recv(sockfd, recv_data, sizeof(recv_data), 0);

    if (bytes_received <= 0) {
        fprintf(stderr, "Error: Failed to receive data from host.\n");
        close(sockfd);
        return 1;
    }

    fprintf(stdout, "Received response: %s\n", recv_data);

    close(sockfd);
    return 0;
}