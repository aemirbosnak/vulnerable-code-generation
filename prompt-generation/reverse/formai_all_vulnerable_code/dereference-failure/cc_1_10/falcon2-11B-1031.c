//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: curious
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <target> <port>\n", argv[0]);
        exit(1);
    }

    char target[256] = {0};
    char port[5] = {0};

    strcpy(target, argv[1]);
    strcpy(port, argv[2]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(port));
    server.sin_addr.s_addr = inet_addr(target);

    connect(sock, (struct sockaddr *)&server, sizeof(server));

    printf("Connection established to %s:%s\n", target, port);
    printf("Please wait while I scan your ports...\n");
    printf("-------------------------------------\n");

    // Scan for open ports
    for (int i = 1; i <= 65535; i++) {
        int port = i;
        int val = 1;
        setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
        struct sockaddr_in client;
        client.sin_family = AF_INET;
        client.sin_port = htons(port);
        client.sin_addr.s_addr = INADDR_ANY;
        bind(sock, (struct sockaddr *)&client, sizeof(client));

        if (listen(sock, 1) == -1) {
            perror("listen");
            exit(1);
        }

        if (accept(sock, NULL, NULL) == -1) {
            perror("accept");
            exit(1);
        }

        printf("Port %d is open\n", port);
    }

    close(sock);

    return 0;
}