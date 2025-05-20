//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024  // range of ports to scan (1-65535)
#define MAX_HOSTS 1024    // maximum number of hosts to scan
#define BUFFER_SIZE 1024   // size of buffer for storing host and port info

// structure to store host and port information
typedef struct {
    char *host;
    unsigned short port;
} host_port_t;

// function to scan a single host and port
void scan_host(int sock, char *host, unsigned short port) {
    // create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // set address and port
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    // connect to the host and port
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // send a packet and receive a response
    char packet[] = "Hello, world!";
    send(sock, packet, strlen(packet), 0);
    char buffer[BUFFER_SIZE];
    recv(sock, buffer, BUFFER_SIZE, 0);

    // print the host and port information
    printf("%s:%d\n", host, ntohs(server_addr.sin_port));

    // close the socket
    close(sock);
}

// main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <host> [<port>]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // initialize the list of hosts to scan
    host_port_t *hosts = calloc(MAX_HOSTS, sizeof(host_port_t));
    if (!hosts) {
        perror("calloc failed");
        exit(EXIT_FAILURE);
    }

    // loop through the command line arguments
    for (int i = 1; i < argc; i++) {
        // extract the host and port from the argument
        char *host = argv[i];
        unsigned short port = atoi(argv[i + 1]);

        // add the host and port to the list
        hosts[i - 1].host = host;
        hosts[i - 1].port = port;

        // scan the host and port
        scan_host(0, host, port);
    }

    // free the list of hosts
    free(hosts);

    return 0;
}