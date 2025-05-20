//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024 // range of ports to scan
#define MAX_CONNECTIONS 100 // maximum number of connections to keep open

struct connection {
    int sock; // socket descriptor
    char *host; // hostname or IP address
    unsigned short port; // port number
};

void start_scan(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <host>\n", argv[0]);
        return;
    }

    char *host = argv[1];
    int i = 0;

    while (i < PORT_RANGE) {
        struct connection *conn = malloc(sizeof(struct connection));
        conn->sock = socket(AF_INET, SOCK_STREAM, 0);
        conn->host = host;
        conn->port = htons(i);

        if (connect(conn->sock, (struct sockaddr *)&conn->host, sizeof(struct sockaddr_in)) < 0) {
            printf("Error connecting to %s on port %d\n", host, i);
            close(conn->sock);
            free(conn);
        } else {
            printf("Connected to %s on port %d\n", host, i);
            i++;
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <host>\n", argv[0]);
        return 1;
    }

    start_scan(argc, argv);

    return 0;
}