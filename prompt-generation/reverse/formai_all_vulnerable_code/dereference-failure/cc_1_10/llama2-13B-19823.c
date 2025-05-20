//LLAMA2-13B DATASET v1.0 Category: Firewall ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct Pfwd {
    char *ip;
    unsigned short port;
};

int main(int argc, char *argv[]) {
    char *ip = NULL;
    unsigned short port = 0;

    if (argc < 3) {
        printf("Usage: %s <IP> <PORT>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    ip = argv[1];
    port = atoi(argv[2]);

    if (port > 65535) {
        printf("Port must be less than or equal to 65535\n");
        exit(EXIT_FAILURE);
    }

    struct Pfwd *pfwd = malloc(sizeof(struct Pfwd));
    pfwd->ip = ip;
    pfwd->port = htons(port);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, ip, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    recv(sock, buffer, 1024, 0);
    printf("Received message: %s\n", buffer);

    struct Pfwd *pfwd_new = malloc(sizeof(struct Pfwd));
    pfwd_new->ip = "127.0.0.1";
    pfwd_new->port = htons(8080);

    send(sock, (char *)pfwd_new, sizeof(struct Pfwd), 0);

    free(pfwd);
    close(sock);

    return 0;
}