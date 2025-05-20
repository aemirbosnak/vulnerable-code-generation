//FormAI DATASET v1.0 Category: Port Scanner ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

char *services[1024];

void initialize_services() {
    FILE *fp = fopen("/etc/services", "r");
    char line[256];
    while(fgets(line, sizeof(line), fp)) {
        char *service_name = strtok(line, "\t");
        int service_port = atoi(strtok(NULL, "/tcp"));
        services[service_port] = service_name;
    }
    fclose(fp);
}

int open_socket(const char *hostname, int port) {
    struct addrinfo hints, *result;
    int sock;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    char port_string[6];
    snprintf(port_string, sizeof(port_string), "%d", port);

    if(getaddrinfo(hostname, port_string, &hints, &result) != 0)
        return -1;

    sock = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if(sock == -1)
        return -1;

    // set socket to non-blocking mode
    int flags = fcntl(sock, F_GETFL, 0);
    if(flags == -1 || fcntl(sock, F_SETFL, flags | O_NONBLOCK) == -1) {
        close(sock);
        return -1;
    }

    if(connect(sock, result->ai_addr, result->ai_addrlen) == -1)
        if(errno != EINPROGRESS) {
            close(sock);
            return -1;
        }

    return sock;
}

int main(int argc, char **argv) {
    if(argc < 2) {
        printf("Usage: %s hostname\n", argv[0]);
        return 1;
    }

    initialize_services();

    printf("Scanning ports on %s...\n", argv[1]);
    for(int port = 1; port <= 65535; port++) {
        int sock = open_socket(argv[1], port);
        if(sock != -1) {
            printf("%d: %s\n", port, services[port] ? services[port] : "Unknown");
            close(sock);
        }
    }

    return 0;
}