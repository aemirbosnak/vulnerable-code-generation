//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_HOSTNAME 256
#define MAX_DATA 1024

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    char hostname[MAX_HOSTNAME];
    strncpy(hostname, argv[1], MAX_HOSTNAME);
    hostname[MAX_HOSTNAME - 1] = '\0';

    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "gethostbyname() failed: %s\n", hstrerror(h_errno));
        exit(1);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        fprintf(stderr, "socket() failed: %s\n", strerror(errno));
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(7);
    inet_pton(AF_INET, inet_ntoa(*(struct in_addr *)host->h_addr), &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "connect() failed: %s\n", strerror(errno));
        exit(1);
    }

    char send_data[MAX_DATA] = "PING";
    send(sockfd, send_data, strlen(send_data), 0);

    char recv_data[MAX_DATA];
    int bytes_received = 0;
    while (bytes_received < MAX_DATA) {
        int result = recv(sockfd, recv_data + bytes_received, MAX_DATA - bytes_received, 0);
        if (result <= 0) {
            break;
        }
        bytes_received += result;
    }

    close(sockfd);

    if (bytes_received > 0) {
        recv_data[bytes_received] = '\0';
        printf("Received: %s\n", recv_data);
    } else {
        printf("No data received.\n");
    }

    return 0;
}