//FormAI DATASET v1.0 Category: Socket programming ; Style: peaceful
/*
 * This peaceful C Socket programming example program creates a server that
 * listens on a specified port for incoming connections from client programs.
 * 
 * Once a client connects, the server sends a welcoming message to the client.
 * The client can then send a message to the server, which the server will
 * echo back to the client. This will continue until the client disconnects.
 *
 * Let's spread peaceful vibes with this server-client chat program!
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024 // buffer size for message passing

void error_handling(char *message);

int main(int argc, char *argv[]) {
    int serv_sock, clnt_sock;
    struct sockaddr_in serv_addr, clnt_addr;
    socklen_t clnt_addr_size;
    char message[BUF_SIZE];
    int str_len, i;

    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    // create a socket for the server
    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (serv_sock == -1)
        error_handling("socket() error");

    // set the address information for the server
    memset(&serv_addr, 0, sizeof(serv_addr)); // zero out the structure
    serv_addr.sin_family = AF_INET; // address family is IPv4
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); // accept any incoming address
    serv_addr.sin_port = htons(atoi(argv[1])); // specified port number

    // bind the socket to the specified address and port
    if (bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
        error_handling("bind() error");

    // listen on the specified port for incoming connections
    if (listen(serv_sock, 5) == -1)
        error_handling("listen() error");

    // main server loop
    while (1) {
        // accept incoming connections and return a new socket for this connection
        clnt_addr_size = sizeof(clnt_addr);
        clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_addr, &clnt_addr_size);
        if (clnt_sock == -1)
            error_handling("accept() error");

        // send a welcoming message to the client
        snprintf(message, BUF_SIZE, "Welcome, client %d!", clnt_sock);
        write(clnt_sock, message, strlen(message));

        // echo any messages from the client
        while ((str_len = read(clnt_sock, message, BUF_SIZE)) != 0) {
            write(clnt_sock, message, str_len);
        }

        // close the client socket
        close(clnt_sock);
    }

    // close the server socket
    close(serv_sock);

    return 0;
}

void error_handling(char *message) {
    perror(message);
    exit(1);
}