//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024  // range of ports to scan
#define MAX_HOSTS 1024    // maximum number of hosts to scan

// structure to hold host and port information
typedef struct {
    char *host;
    uint16_t port;
} host_port_t;

// function to scan a host and port
void scan_host(host_port_t *hosts, int sock, char *host, uint16_t port) {
    // create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        return;
    }

    // set address and port
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    // connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connection failed");
        return;
    }

    // send a packet and listen for a response
    char packet[] = "Hello, world!";
    send(sock, packet, strlen(packet), 0);
    char buffer[1024];
    recv(sock, buffer, 1024, 0);

    // print the response
    printf("Response from %s:%d: %s\n", host, port, buffer);

    // close the socket
    close(sock);
}

// main function
int main(int argc, char *argv[]) {
    // check if there are any command line arguments
    if (argc < 2) {
        printf("Usage: %s <host>[:port]\n", argv[0]);
        return 1;
    }

    // create an array to hold host and port information
    host_port_t *hosts = (host_port_t *)calloc(MAX_HOSTS, sizeof(host_port_t));

    // loop through command line arguments
    for (int i = 1; i < argc; i++) {
        // get the host and port from the argument
        char *host = argv[i];
        int port = strcspn(argv[i], ":");

        // add the host and port to the array
        hosts[i - 1].host = host;
        hosts[i - 1].port = htons(port);

        // scan the host and port
        scan_host(hosts, 0, host, port);
    }

    return 0;
}