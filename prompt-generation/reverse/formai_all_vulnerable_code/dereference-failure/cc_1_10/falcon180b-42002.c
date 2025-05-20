//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 8192

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);

    int listener = socket(AF_INET, SOCK_STREAM, 0);
    if (listener == -1)
        error("socket");

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(listener, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
        error("bind");

    if (listen(listener, 5) == -1)
        error("listen");

    printf("Proxy server started on port %d\n", port);

    while (1) {
        int client = accept(listener, NULL, NULL);
        if (client == -1)
            error("accept");

        char buffer[BUF_SIZE];
        while (1) {
            int bytes_received = recv(client, buffer, BUF_SIZE, 0);
            if (bytes_received <= 0)
                break;

            send(client, buffer, bytes_received, 0);
        }

        close(client);
    }

    return 0;
}