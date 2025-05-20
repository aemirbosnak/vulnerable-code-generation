//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_HOST_LEN 1024
#define MAX_DATA_LEN 1024
#define PORT "80"
#define TIMEOUT 5
#define MAX_ATTEMPTS 3

int ping(char *host, int timeout, int max_attempts);

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <host>\n", argv[0]);
        return 1;
    }

    char host[MAX_HOST_LEN];
    strncpy(host, argv[1], MAX_HOST_LEN - 1);

    int result = ping(host, TIMEOUT, MAX_ATTEMPTS);

    if (result == 0) {
        printf("Host %s is reachable.\n", host);
    } else {
        printf("Host %s is not reachable (timeout).\n", host);
    }

    return 0;
}

int ping(char *host, int timeout, int max_attempts) {
    int sockfd, retval;
    struct sockaddr_in server_addr;
    struct hostent *host_info;
    char send_data[MAX_DATA_LEN] = "GET / HTTP/1.0\r\n\r\n";
    char recv_data[MAX_DATA_LEN];
    int data_len = strlen(send_data);
    int attempts = 0;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket.\n");
        return -1;
    }

    host_info = gethostbyname(host);
    if (host_info == NULL) {
        printf("Host not found.\n");
        close(sockfd);
        return -1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr, host_info->h_addr, host_info->h_length);
    server_addr.sin_port = htons(atoi(PORT));

    retval = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (retval == -1) {
        printf("Error connecting to host.\n");
        close(sockfd);
        return -1;
    }

    send(sockfd, send_data, data_len, 0);

    while (attempts < max_attempts) {
        retval = recv(sockfd, recv_data, MAX_DATA_LEN, 0);
        if (retval > 0) {
            close(sockfd);
            return 0;
        } else if (retval == 0) {
            printf("Connection closed by host.\n");
            close(sockfd);
            return -1;
        } else if (errno!= EINTR && errno!= EAGAIN) {
            printf("Error receiving data.\n");
            close(sockfd);
            return -1;
        }

        usleep(100000); // 100ms
        attempts++;
    }

    close(sockfd);
    return -1;
}