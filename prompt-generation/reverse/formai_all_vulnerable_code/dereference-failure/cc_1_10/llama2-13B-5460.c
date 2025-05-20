//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024  // range of ports to scan (1024-65535)
#define MAX_HOSTS 1024    // maximum number of hosts to scan
#define BUFFER_SIZE 1024  // buffer size for reading and writing

struct host_info {
    char *host;    // hostname or IP address
    int port;     // open port number
};

void init_hosts(struct host_info *hosts, int max_hosts) {
    int i;
    for (i = 0; i < max_hosts; i++) {
        hosts[i].host = NULL;
        hosts[i].port = 0;
    }
}

void add_host(struct host_info *hosts, char *host, int port) {
    int i;
    for (i = 0; i < MAX_HOSTS; i++) {
        if (hosts[i].host == NULL || hosts[i].port == 0) {
            break;
        }
    }
    if (i == MAX_HOSTS) {
        printf("Error: maximum number of hosts reached (%d)\n", MAX_HOSTS);
        return;
    }
    hosts[i].host = strdup(host);
    hosts[i].port = port;
}

void scan_ports(struct host_info *hosts, int max_hosts) {
    int sock, port;
    char buffer[BUFFER_SIZE];

    // create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    // set address and port
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(0);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    // connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect() failed");
        exit(EXIT_FAILURE);
    }

    // scan ports
    for (port = 1; port < PORT_RANGE; port++) {
        // send query packet
        struct sockaddr_in client_addr;
        client_addr.sin_family = AF_INET;
        client_addr.sin_port = htons(port);
        inet_pton(AF_INET, hosts[0].host, &client_addr.sin_addr);
        sendto(sock, "QUERY", 5, 0, (struct sockaddr *)&client_addr, sizeof(client_addr));

        // receive response packet
        recvfrom(sock, buffer, BUFFER_SIZE, 0, NULL, NULL);

        // check if response is "OPEN"
        if (strcmp(buffer, "OPEN") == 0) {
            // found open port, print it
            printf("%d (%s:%s)\n", port, hosts[0].host, hosts[0].port);
        }
    }

    // close socket
    close(sock);
}

int main(int argc, char *argv[]) {
    struct host_info hosts[MAX_HOSTS];
    int max_hosts = argc;

    // parse command line arguments
    if (argc < 2) {
        printf("Usage: %s <host1> [<host2> ...]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    for (int i = 1; i < argc; i++) {
        add_host(hosts, argv[i], 0);
    }

    // scan ports
    scan_ports(hosts, max_hosts);

    return 0;
}