//FormAI DATASET v1.0 Category: Port Scanner ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_PORT 65535
#define BUF_SIZE 1024

bool is_port_open(const char *host, int port) {
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sock_fd < 0) {
        perror("socket() failed");
        exit(1);
    }
    
    struct hostent *server = gethostbyname(host);
    
    if (server == NULL) {
        perror("gethostbyname() failed");
        exit(1);
    }
    
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    
    int connected = connect(sock_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
    close(sock_fd);
    
    if (connected == 0) {
        return true;
    } else {
        return false;
    }
}

int main(int argc, char **argv) {
    char *host = argv[1];
    
    printf("Scanning ports on %s...\n", host);
    
    for (int port = 1; port <= MAX_PORT; port++) {
        if (is_port_open(host, port)) {
            printf("Port %d is open\n", port);
        }
    }
    
    printf("Scan complete\n");
    return 0;
}