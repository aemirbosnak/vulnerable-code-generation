//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024

struct port_scan_result {
    int port;
    char *host;
};

void *scan_ports(int sock, struct port_scan_result *results) {
    struct sockaddr_in server_addr;
    socklen_t server_len = sizeof(server_addr);
    int i, j, k;
    char buffer[256];

    for (i = 0; i < PORT_RANGE; i++) {
        server_addr.sin_port = htons(i);
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = INADDR_ANY;

        if (connect(sock, (struct sockaddr *)&server_addr, server_len) < 0) {
            continue;
        }

        // send a SYN packet to the server
        send(sock, "SYN", 3, 0);

        // wait for the server's response
        recv(sock, buffer, 256, 0);

        // parse the server's response
        for (j = 0; j < 256; j++) {
            if (buffer[j] == '\n') {
                break;
            }
        }

        // extract the server's IP address and port number
        k = strcspn(buffer, "\n");
        results[i].host = (char *)malloc(k + 1);
        strncpy(results[i].host, buffer, k);
        results[i].port = atoi(buffer + k + 1);

        // close the connection
        close(sock);
    }

    return results;
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct port_scan_result *results = NULL;

    // scan the range of ports
    results = scan_ports(sock, results);

    // print the scan results
    for (int i = 0; results[i].host != NULL; i++) {
        printf("%d - %s\n", results[i].port, results[i].host);
    }

    // close the socket
    close(sock);

    return 0;
}