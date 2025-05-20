//FormAI DATASET v1.0 Category: Port Scanner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_PORTS 65535
#define MAX_CONNECTIONS 100
#define TIMEOUT 5

bool is_port_open(int port, char* ip_address) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("ERROR opening socket\n");
        return false;
    }
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip_address);
    serv_addr.sin_port = htons(port);
    fcntl(sockfd, F_SETFL, O_NONBLOCK);

    int connect_status = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (connect_status == -1 && errno != EINPROGRESS) {
        printf("ERROR connecting to port %d: %s\n", port, strerror(errno));
        close(sockfd);
        return false;
    }

    fd_set fdset;
    FD_ZERO(&fdset);
    FD_SET(sockfd, &fdset);
    struct timeval tv;
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;

    int select_status = select(sockfd + 1, NULL, &fdset, NULL, &tv);
    if (select_status == -1) {
        printf("ERROR selecting port %d: %s\n", port, strerror(errno));
        close(sockfd);
        return false;
    } else if (select_status == 0) {
        printf("Port %d timed out\n", port);
        close(sockfd);
        return false;
    }

    int optval;
    socklen_t optlen = sizeof(optval);
    int getsockopt_status = getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &optval, &optlen);
    if (getsockopt_status == -1) {
        printf("ERROR getting socket option: %s\n", strerror(errno));
        close(sockfd);
        return false;
    }

    if (optval != 0) {
        printf("ERROR with socket option value: %s\n", strerror(optval));
        close(sockfd);
        return false;
    }

    close(sockfd);
    return true;
}

int main(int argc, char *argv[]) {
    char* ip_address = "127.0.0.1";
    int start_port = 1, end_port = MAX_PORTS;

    if (argc > 1) {
        ip_address = argv[1];
    }
    if (argc > 2) {
        start_port = atoi(argv[2]);
    }
    if (argc > 3) {
        end_port = atoi(argv[3]);
    }

    if (start_port > MAX_PORTS || end_port > MAX_PORTS) {
        printf("Invalid port range!\n");
        return 0;
    }

    int open_ports[MAX_PORTS];
    int num_open_ports = 0;

    printf("Scanning ports %d to %d on %s...\n", start_port, end_port, ip_address);
    printf("Timeout set to %d seconds.\n\n", TIMEOUT);

    for (int port = start_port; port <= end_port; port++) {
        if (is_port_open(port, ip_address)) {
            open_ports[num_open_ports] = port;
            num_open_ports++;
        }
    }

    printf("Found %d open ports:\n", num_open_ports);
    for (int i = 0; i < num_open_ports; i++) {
        printf("%d\n", open_ports[i]);
    }

    return 0;
}