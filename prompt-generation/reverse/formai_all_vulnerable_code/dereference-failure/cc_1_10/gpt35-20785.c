//FormAI DATASET v1.0 Category: Port Scanner ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

void scan_ports(char *host, int start_port, int end_port) {

    int sock;
    struct sockaddr_in target_addr;
    struct hostent *target_host;

    memset(&target_addr, 0, sizeof(target_addr));

    target_host = gethostbyname(host);

    if(target_host == NULL) {
        printf("Could not resolve host\n");
        return;
    }

    target_addr.sin_family = AF_INET;
    target_addr.sin_addr.s_addr = *((unsigned long*) target_host->h_addr_list[0]);

    for(int port = start_port; port <= end_port; port++) {

        target_addr.sin_port = htons(port);
        sock = socket(AF_INET, SOCK_STREAM, 0);

        if(connect(sock, (struct sockaddr*)&target_addr, sizeof(target_addr)) == 0) {
            printf("Port %d open.\n", port);
            close(sock);
        }
    }

}

int main(int argc, char **argv) {

    if(argc < 3) {
        printf("Usage: %s [host] [start port] [end port]\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    printf("Scanning host %s from port %d to %d\n", host, start_port, end_port);
    scan_ports(host, start_port, end_port);

    return 0;

}