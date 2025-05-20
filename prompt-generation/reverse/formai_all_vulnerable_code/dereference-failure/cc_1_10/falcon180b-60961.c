//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_PORTS 65535

void scan_ports(char* hostname, int start_port, int end_port);

int main(int argc, char** argv) {
    if(argc!= 4) {
        printf("Usage: %s <hostname> <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    char* hostname = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    scan_ports(hostname, start_port, end_port);

    return 0;
}

void scan_ports(char* hostname, int start_port, int end_port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct hostent* server = gethostbyname(hostname);
    if(server == NULL) {
        printf("Error resolving hostname\n");
        exit(1);
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(start_port);
    serv_addr.sin_addr = *((struct in_addr*)server->h_addr);

    if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
        printf("Error connecting to host\n");
        exit(1);
    }

    for(int i = start_port; i <= end_port; i++) {
        serv_addr.sin_port = htons(i);

        if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == 0) {
            printf("Port %d is open\n", i);
            close(sock);
            sock = socket(AF_INET, SOCK_STREAM, 0);
        } else {
            printf("Port %d is closed\n", i);
        }
    }

    close(sock);
}