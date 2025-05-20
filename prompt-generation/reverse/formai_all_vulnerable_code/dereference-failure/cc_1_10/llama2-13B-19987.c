//LLAMA2-13B DATASET v1.0 Category: Firewall ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define MAX_CONNECTIONS 1024
#define PORT 8080

struct connection {
    int sock;
    struct sockaddr_in client_addr;
    char client_ip[16];
};

void initialize_connection(struct connection *con);
void handle_connection(struct connection *con);
void close_connection(struct connection *con);

int main(void) {
    int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in listen_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(listen_sock, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(listen_sock, 3) < 0) {
        perror("listen failed");
        exit(1);
    }

    printf("Listening on port %d...\n", PORT);

    while (1) {
        struct connection *con;
        socklen_t client_len = sizeof(struct sockaddr_in);
        int client_sock = accept(listen_sock, (struct sockaddr *)&listen_addr, &client_len);

        if (client_sock < 0) {
            perror("accept failed");
            continue;
        }

        con = malloc(sizeof(struct connection));
        con->sock = client_sock;
        con->client_addr = listen_addr;
        inet_ntop(AF_INET, &con->client_addr.sin_addr, con->client_ip, sizeof(con->client_ip));

        initialize_connection(con);

        while (1) {
            handle_connection(con);
        }
    }

    return 0;
}

void initialize_connection(struct connection *con) {
    printf("Connection established from IP %s, port %d...\n", con->client_ip, con->client_addr.sin_port);
}

void handle_connection(struct connection *con) {
    char buffer[1024];
    int bytes_read = recv(con->sock, buffer, 1024, 0);

    if (bytes_read < 0) {
        perror("recv failed");
        close_connection(con);
        return;
    }

    printf("Received message: %s\n", buffer);

    if (strcmp(buffer, "HELLO") == 0) {
        printf("Hello received from IP %s, port %d...\n", con->client_ip, con->client_addr.sin_port);
    } else {
        printf("Invalid message received from IP %s, port %d...\n", con->client_ip, con->client_addr.sin_port);
        close_connection(con);
    }
}

void close_connection(struct connection *con) {
    close(con->sock);
    free(con);
}