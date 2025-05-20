//LLAMA2-13B DATASET v1.0 Category: Firewall ; Style: synchronous
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <stdio.h>

#define PORT 8080

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        return 1;
    }

    if (listen(sock, 3) < 0) {
        perror("listen failed");
        return 1;
    }

    printf("Listening on port %d...\n", PORT);

    while (1) {
        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(sock, &read_fds);

        select(sock + 1, &read_fds, NULL, NULL, NULL);

        if (FD_ISSET(sock, &read_fds)) {
            socklen_t client_len = sizeof(struct sockaddr_in);
            int client_sock = accept(sock, (struct sockaddr*)&server_addr, &client_len);

            if (client_sock < 0) {
                perror("accept failed");
                continue;
            }

            printf("Connection from %s:%d...\n",
                   inet_ntoa(server_addr.sin_addr), ntohs(server_addr.sin_port));

            // Block incoming connections on port 8080
            if (listen(client_sock, 1) < 0) {
                perror("listen failed");
                close(client_sock);
            }
        }
    }

    return 0;
}