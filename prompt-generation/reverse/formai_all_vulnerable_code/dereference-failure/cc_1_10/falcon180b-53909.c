//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netdb.h>

#define BUF_SIZE 1024
#define TIMEOUT 5

int main(int argc, char *argv[]) {
    int sockfd, ret;
    struct sockaddr_in dest_addr;
    struct hostent *host_info;
    char *host_name;
    char buffer[BUF_SIZE];
    int opt = 1;
    struct timeval timeout;

    if (argc!= 3) {
        printf("Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    host_name = argv[1];
    dest_addr.sin_port = htons(atoi(argv[2]));

    if ((host_info = gethostbyname(host_name)) == NULL) {
        printf("Error: Host not found\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error: Socket creation failed\n");
        exit(1);
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    if (connect(sockfd, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) == -1) {
        printf("Error: Connection failed\n");
        exit(1);
    }

    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;

    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

    ret = send(sockfd, "PING", strlen("PING"), 0);

    if (ret == -1) {
        printf("Error: Data send failed\n");
        exit(1);
    }

    memset(buffer, 0, BUF_SIZE);

    ret = recv(sockfd, buffer, BUF_SIZE, 0);

    if (ret == -1) {
        printf("Error: Data receive failed\n");
        exit(1);
    }

    printf("Response: %s\n", buffer);

    close(sockfd);

    return 0;
}