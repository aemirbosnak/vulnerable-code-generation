//Falcon2-11B DATASET v1.0 Category: Interprocess communication ; Style: scientific
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int server_fd, client_fd, port_no;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port_no);

    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        return 1;
    }

    if (listen(server_fd, 5) < 0) {
        perror("listen");
        return 1;
    }

    client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &opt);
    if (client_fd < 0) {
        perror("accept");
        return 1;
    }

    printf("Connected to client\n");
    while (1) {
        int n = read(client_fd, NULL, 1024);
        if (n <= 0) {
            break;
        }
        printf("Received data from client: %s\n", NULL);
        n = write(client_fd, "Message sent to client\n", 27);
        if (n < 0) {
            perror("write");
            return 1;
        }
    }

    close(client_fd);
    close(server_fd);
    return 0;
}