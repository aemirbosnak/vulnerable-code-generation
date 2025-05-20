//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_PORTS 10000
#define MAX_PORT_LEN 5
#define MAX_ADDR_LEN 16

void print_usage() {
    printf("Usage:./portscanner <host> [<port>...]\n");
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_usage();
    }

    char host[MAX_ADDR_LEN];
    char port[MAX_PORT_LEN];
    int port_count = 0;

    for (int i = 1; i < argc; i++) {
        if (strlen(argv[i]) > MAX_PORT_LEN) {
            printf("Invalid port number: %s\n", argv[i]);
            print_usage();
        }

        strcpy(port, argv[i]);
        port_count++;
    }

    struct hostent *host_ent = gethostbyname(host);
    if (host_ent == NULL) {
        printf("Could not resolve host name: %s\n", host);
        exit(1);
    }

    int sockfd;
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port_count);
    memcpy(&serv_addr.sin_addr.s_addr, host_ent->h_addr, host_ent->h_length);

    int num_ports = port_count;

    for (int i = 0; i < num_ports; i++) {
        if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
            printf("Port %d is closed\n", i + 1);
        } else {
            printf("Port %d is open\n", i + 1);
            close(sockfd);
        }
    }

    return 0;
}