//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    struct sockaddr_in server_addr;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    int bind_result = bind(sock, (struct sockaddr *) &server_addr, sizeof(server_addr));
    if (bind_result == -1) {
        perror("bind");
        return 1;
    }

    listen(sock, 5);

    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int client_sock = accept(sock, (struct sockaddr *) &client_addr, &client_addr_len);
    if (client_sock == -1) {
        perror("accept");
        return 1;
    }

    char filename[1024];
    strcpy(filename, argv[1]);

    char buffer[1024];
    int bytes_read;

    while ((bytes_read = read(client_sock, buffer, sizeof(buffer))) > 0) {
        write(client_sock, buffer, bytes_read);
    }

    close(client_sock);
    close(sock);

    return 0;
}