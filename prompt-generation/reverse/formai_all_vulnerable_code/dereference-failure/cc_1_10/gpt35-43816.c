//FormAI DATASET v1.0 Category: Port Scanner ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <time.h>

#define NUM_PORTS 65536
#define TIMEOUT 1000 // in milliseconds

int open_socket(const char* address, int port);
void scan_port(const char* address, int port, int* open_ports);
void print_results(int* open_ports);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <address>\n", argv[0]);
        exit(1);
    }
    const char* address = argv[1];
    int open_ports[NUM_PORTS] = {0};
    srand(time(NULL));

    printf("Scanning ports on %s...\n", address);

    for (int i = 0; i < NUM_PORTS; i++) {
        int port = i;
        int r = rand() % NUM_PORTS;
        if (r == i) {
            r = (r + 1) % NUM_PORTS;
        }
        int tmp = open_ports[i];
        open_ports[i] = open_ports[r];
        open_ports[r] = tmp;
        scan_port(address, port, open_ports);
    }

    print_results(open_ports);
    return 0;
}

int open_socket(const char* address, int port) {
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_pton(AF_INET, address, &(addr.sin_addr));
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    int flags = fcntl(sock, F_GETFL, 0);
    fcntl(sock, F_SETFL, flags | O_NONBLOCK);
    connect(sock, (struct sockaddr*) &addr, sizeof(addr));
    return sock;
}

void scan_port(const char* address, int port, int* open_ports) {
    int sock = open_socket(address, port);
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT / 1000;
    timeout.tv_usec = (TIMEOUT % 1000) * 1000;
    fd_set fdset;
    FD_ZERO(&fdset);
    FD_SET(sock, &fdset);
    int status = select(sock + 1, NULL, &fdset, NULL, &timeout);
    if (status == -1) {
        perror("select");
        exit(1);
    }
    if (status == 0) {
        close(sock);
        return;
    }
    int error = 0;
    socklen_t len = sizeof(error);
    getsockopt(sock, SOL_SOCKET, SO_ERROR, &error, &len);
    if (error != 0) {
        close(sock);
        return;
    }
    open_ports[port] = 1;
    close(sock);
}

void print_results(int* open_ports) {
    printf("Open ports:\n");
    for (int i = 0; i < NUM_PORTS; i++) {
        if (open_ports[i]) {
            printf("%d\n", i);
        }
    }
}