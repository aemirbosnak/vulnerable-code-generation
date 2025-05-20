//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    if(argc!= 3) {
        printf("Usage: %s <IP Address> <Port Range>\n", argv[0]);
        exit(1);
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[2]) + 100;

    int sock;
    struct sockaddr_in server;
    struct hostent *host;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if(sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    host = gethostbyname(ip_address);

    if(host == NULL) {
        printf("Error resolving hostname\n");
        exit(1);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(start_port);
    server.sin_addr.s_addr = *(long *)host->h_addr;

    while(start_port <= end_port) {
        if(connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
            printf("Port %d is open\n", start_port);
        } else {
            printf("Port %d is closed\n", start_port);
        }
        start_port++;
    }

    close(sock);
    return 0;
}