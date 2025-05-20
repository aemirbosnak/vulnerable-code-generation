//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int client_sock, server_sock, port_no, n;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in client_addr, server_addr;
    socklen_t client_len = sizeof(client_addr);

    // Check if user provides port number
    if (argc < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }

    // Create a socket for the client
    client_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (client_sock < 0) {
        error("ERROR opening client socket");
    }

    // Setup client address
    bzero((char *) &client_addr, sizeof(client_addr));
    port_no = atoi(argv[1]);
    client_addr.sin_family = AF_INET;
    client_addr.sin_addr.s_addr = INADDR_ANY;
    client_addr.sin_port = htons(port_no);

    // Bind the socket to the client address
    if (bind(client_sock, (struct sockaddr *) &client_addr, sizeof(client_addr)) < 0 ) {
        error("ERROR on binding client");
    }

    // Start listening for incoming connections from clients
    listen(client_sock, 5);
    printf("Proxy server started on port %d\n", port_no);

    while (1) {
        // Wait for incoming connection from client
        server_sock = accept(client_sock, (struct sockaddr *) &server_addr, &client_len);
        if (server_sock < 0) {
            error("ERROR on accept");
        }

        // Create a new child process to handle connection
        pid_t pid = fork();
        if (pid < 0) {
            error("ERROR in new process creation");
        }

        if (pid == 0) {
            close(client_sock);

            // Forward request to server
            bzero(buffer, BUFFER_SIZE);
            n = read(server_sock, buffer, BUFFER_SIZE);
            if (n < 0) {
                error("ERROR reading from client");
            }

            // Edit request as required
            // For example, to change the user agent, you could do:
            // char new_user_agent[] = "Mozilla/5.0";
            // char *ua_pos = strstr(buffer, "User-Agent");
            // char *end_pos = strstr(ua_pos, "\r\n");
            // int ua_len = end_pos - ua_pos;
            // strncpy(ua_pos, new_user_agent, strlen(new_user_agent));
            // strncpy(ua_pos+strlen(new_user_agent), end_pos, strlen(end_pos)-ua_len);

            // Connect to server
            int server_len = sizeof(server_addr);
            if (connect(server_sock, (struct sockaddr *) &server_addr, server_len) < 0) {
                error("ERROR connecting to server");
            }

            // Forward request to server
            n = write(server_sock, buffer, strlen(buffer));
            if (n < 0) {
                error("ERROR writing to server");
            }

            // Forward response to client
            bzero(buffer, BUFFER_SIZE);
            int total = 0;
            while ((n = read(server_sock, buffer+total, BUFFER_SIZE-total)) > 0) {
                total += n;
            }
            if (n < 0) {
                error("ERROR reading from server");
            }
            n = write(server_sock, buffer, total);
            if (n < 0) {
                error("ERROR writing to client");
            }

            // Close sockets and exit child process
            close(server_sock);
            exit(0);
        }
        else {
            close(server_sock);
        }
    }

    // Close client socket
    close(client_sock);

    return 0;
}