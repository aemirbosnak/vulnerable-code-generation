//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <errno.h>

#define MAX_IP_LEN 16
#define MAX_HOSTNAME_LEN 256
#define BUFFER_SIZE 1024

struct host_info {
    char ip[MAX_IP_LEN];
    char hostname[MAX_HOSTNAME_LEN];
};

void validate_ip(const char *ip_address, struct host_info *host) {
    struct sockaddr_in sa;
    if (inet_pton(AF_INET, ip_address, &(sa.sin_addr)) != 1) {
        printf("Invalid IP address: %s\n", ip_address);
    } else {
        strncpy(host->ip, ip_address, MAX_IP_LEN);
    }
}

void validate_hostname(const char *hostname, struct host_info *host) {
    struct addrinfo hints, *info;
    int ret;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_CANONNAME;

    ret = getaddrinfo(hostname, NULL, &hints, &info);
    if (ret != 0) {
        printf("Error getting address info for %s: %s\n", hostname, gai_strerror(ret));
    } else {
        struct sockaddr_in *addr = (struct sockaddr_in *) info->ai_addr;
        inet_ntop(AF_INET, &(addr->sin_addr), host->ip, MAX_IP_LEN);
        strncpy(host->hostname, info->ai_canonname, MAX_HOSTNAME_LEN);
    }
}

void print_usage() {
    printf("USAGE: topo_mapper IP_ADDRESS HOSTNAME\n");
    printf("IP_ADDRESS: IP address to get hostname for\n");
    printf("HOSTNAME: Hostname to get IP address for\n");
}

int main(int argc, char *argv[]) {
    int sock_fd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    if (argc != 3) {
        print_usage();
        return 1;
    }

    // validate IP address or hostname input and get host info
    struct host_info host;
    memset(&host, 0, sizeof(host));
    validate_ip(argv[1], &host);
    validate_hostname(argv[2], &host);

    // create TCP socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    // set up server address struct
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    inet_pton(AF_INET, host.ip, &(server_addr.sin_addr));

    // establish a TCP connection
    if (connect(sock_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server: %s\n", strerror(errno));
        return 1;
    }

    // send HTTP GET request for hostname to server
    snprintf(buffer, BUFFER_SIZE, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", host.hostname);
    if (send(sock_fd, buffer, strlen(buffer), 0) == -1) {
        printf("Error sending message to server: %s\n", strerror(errno));
        return 1;
    }

    // read server response
    while ((bytes_read = read(sock_fd, buffer, BUFFER_SIZE - 1)) > 0) {
        buffer[bytes_read] = '\0';
        printf("%s", buffer);
    }

    printf("\n");

    // close socket
    if (close(sock_fd) == -1) {
        printf("Error closing socket: %s\n", strerror(errno));
        return 1;
    }

    return 0;
}