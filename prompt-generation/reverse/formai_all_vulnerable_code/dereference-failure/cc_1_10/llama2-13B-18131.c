//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024  // range of ports to scan (1-65535)
#define MAX_HOSTNAME_LEN 100 // max length of hostname
#define MAX_PORTS 1000 // max number of ports to scan

// structure to hold host and port information
struct host_port {
    char *hostname;
    int port;
};

// function to parse command line arguments
void parse_args(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <hostname> <port_range>\n", argv[0]);
        exit(1);
    }

    // store hostname and port range in struct
    struct host_port *host_port = malloc(sizeof(struct host_port));
    host_port->hostname = argv[1];
    host_port->port = atoi(argv[2]);
}

// function to perform port scan
void scan_ports(struct host_port *host_port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket() failed");
        exit(1);
    }

    // loop through ports in range
    for (int i = host_port->port; i <= host_port->port + PORT_RANGE; i++) {
        struct sockaddr_in serv_addr;
        memset(&serv_addr, 0, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(i);
        serv_addr.sin_addr.s_addr = inet_addr(host_port->hostname);

        // connect to port
        if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
            perror("connect() failed");
            continue;
        }

        // print open ports
        printf("%s:%d is open\n", host_port->hostname, i);

        // close connection
        close(sock);
    }
}

int main(int argc, char *argv[]) {
    // parse command line arguments
    parse_args(argc, argv);

    // perform port scan
    struct host_port host_port;
    scan_ports(&host_port);

    return 0;
}