//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: complex
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_CONNECTIONS 5
#define SERVER_PORT 8080

int main(int argc, char *argv[]) {
    int server_fd, conn_fd, portno, n;
    struct sockaddr_in server_addr, client_addr;
    struct hostent *server;

    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR: Unknown host\n");
        return 1;
    }

    portno = htons(SERVER_PORT);
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = portno;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        fprintf(stderr, "ERROR: Failed to create socket\n");
        return 1;
    }

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "ERROR: Failed to bind socket\n");
        return 1;
    }

    listen(server_fd, MAX_CONNECTIONS);

    for (;;) {
        conn_fd = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t *)&n);
        if (conn_fd < 0) {
            fprintf(stderr, "ERROR: Failed to accept connection\n");
            return 1;
        }

        printf("Connection from %s\n", inet_ntoa(client_addr.sin_addr));

        // Read data from client
        if (recv(conn_fd, &n, sizeof(n), 0) < 0) {
            fprintf(stderr, "ERROR: Failed to read from client\n");
            close(conn_fd);
            continue;
        }

        printf("Received %d bytes from client\n", n);

        // Send response back to client
        if (send(conn_fd, "Response from server\n", strlen("Response from server\n"), 0) < 0) {
            fprintf(stderr, "ERROR: Failed to send response\n");
            close(conn_fd);
            continue;
        }

        printf("Sent response to client\n");

        close(conn_fd);
    }

    return 0;
}