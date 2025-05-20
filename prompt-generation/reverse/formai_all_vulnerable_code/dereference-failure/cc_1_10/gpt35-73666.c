//FormAI DATASET v1.0 Category: Port Scanner ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Usage: %s <Hostname/IP> <Port Range>\n", argv[0]);
        exit(0);
    }

    struct hostent *he;
    struct in_addr **addr_list;
    if((he = gethostbyname(argv[1])) == NULL) {
        printf("Could not resolve hostname: %s\n", argv[1]);
        exit(1);
    }
    addr_list = (struct in_addr **)he->h_addr_list;

    int start_port, end_port;
    sscanf(argv[2], "%d-%d", &start_port, &end_port);

    printf("\nScanning %s (%s) from port %d to port %d\n\n", argv[1], inet_ntoa(*addr_list[0]), start_port, end_port);

    int sock, port, start = start_port, end = end_port;
    struct sockaddr_in target;

    for(port = start; port <= end; port++) {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if(sock < 0) {
            printf("Socket creation error\n");
            continue;
        }

        target.sin_family = AF_INET;
        target.sin_addr = *addr_list[0];
        target.sin_port = htons(port);

        if(connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0) {
            printf("Port %d - OPEN\n", port);
        } else {
            printf("Port %d - CLOSED\n", port);
        }
        close(sock);
    }

    printf("\nScan complete!\n");

    return 0;
}