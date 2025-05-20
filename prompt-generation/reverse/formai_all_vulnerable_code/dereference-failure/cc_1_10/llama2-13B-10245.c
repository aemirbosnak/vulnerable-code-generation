//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024  // range of ports to scan
#define MAX_HOSTS 1000    // maximum number of hosts to scan

// struct to store host and port information
struct host_port {
    char *host;
    int port;
};

// function to scan a host and port
void scan_host(struct host_port *host_list, int host_count, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        return;
    }

    // create a socket address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    // connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        close(sock);
        return;
    }

    // send a request to the server
    char request[1024];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", host_list[host_count].host);
    send(sock, request, strlen(request), 0);

    // receive the response
    char response[1024];
    recv(sock, response, 1024, 0);

    // print the response
    printf("Response from %s:%d:\n%s\n", host_list[host_count].host, host_list[host_count].port, response);

    // close the socket
    close(sock);
}

int main(int argc, char *argv[]) {
    // parse command line arguments
    if (argc < 2) {
        printf("Usage: %s <host> [<port>]", argv[0]);
        return 1;
    }

    struct host_port *host_list = calloc(MAX_HOSTS, sizeof(struct host_port));
    int host_count = 0;

    // parse host and port arguments
    char *host = argv[1];
    int port = (argc > 2) ? atoi(argv[2]) : 80;

    // add host to the list
    host_list[host_count].host = host;
    host_list[host_count].port = port;
    host_count++;

    // scan the host and port
    scan_host(host_list, host_count, port);

    // free memory
    free(host_list);

    return 0;
}