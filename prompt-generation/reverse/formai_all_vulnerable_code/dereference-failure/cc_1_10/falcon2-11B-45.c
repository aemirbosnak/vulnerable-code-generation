//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

#define PORT 8080

int main(int argc, char *argv[]) {
    int server_fd, new_socket, n;
    struct sockaddr_in server_addr, client_addr;
    int yes = 1;

    if (argc!= 2) {
        printf("Usage: %s <server-port>\n", argv[0]);
        return 1;
    }

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        return 1;
    }

    if (listen(server_fd, 5) < 0) {
        perror("listen");
        return 1;
    }

    while (1) {
        new_socket = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t *)&n);

        if (new_socket < 0) {
            perror("accept");
            continue;
        }

        char buf[256];
        int nread;

        printf("Got connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while ((nread = read(new_socket, buf, sizeof(buf))) > 0) {
            printf("%s", buf);
            write(new_socket, buf, nread);
        }

        printf("Connection closed\n");

        close(new_socket);
    }

    return 0;
}