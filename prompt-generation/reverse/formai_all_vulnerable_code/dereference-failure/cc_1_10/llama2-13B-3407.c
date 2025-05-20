//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024

struct port_info {
    int port;
    char *host;
};

void print_usage(void) {
    printf("Usage: %s <host> [<port>..<port>]\n", strrchr(__FILE__, '/') + 1);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_usage();
        return 1;
    }

    struct port_info *ports = calloc(argc - 1, sizeof(struct port_info));
    int i = 0;

    for (i = 1; i < argc; i++) {
        char *port_str = argv[i];
        int port;

        if (sscanf(port_str, "%d", &port) == 1) {
            ports[i - 1].port = port;
            ports[i - 1].host = argv[0];
        } else {
            printf("Invalid port number: %s\n", port_str);
            return 1;
        }
    }

    for (i = 0; i < argc - 1; i++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in server_addr;
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(ports[i].port);
        inet_pton(AF_INET, ports[i].host, &server_addr.sin_addr);

        if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            perror("connect");
            exit(1);
        }

        char buffer[1024];
        recv(sock, buffer, 1024, 0);
        printf("%s\n", buffer);

        close(sock);
    }

    free(ports);
    return 0;
}