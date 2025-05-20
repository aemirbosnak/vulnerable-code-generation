//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define MAX 100

int main(int argc, char *argv[]) {
    int sd, new_sd, addrlen, retval;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX];
    int opt = 1;

    // Create socket
    if ((sd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(1);
    }

    // Set options on the socket
    if (setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt))) {
        perror("setsockopt");
        exit(1);
    }

    // Fill in server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(sd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    while (TRUE) {
        // Accept a connection
        addrlen = sizeof(client_addr);
        if ((new_sd = accept(sd, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(1);
        }

        // Receive data from client
        retval = recv(new_sd, buffer, MAX, 0);
        if (retval <= 0) {
            printf("Connection closed by client\n");
            close(new_sd);
            continue;
        }

        // Send data back to client
        send(new_sd, buffer, strlen(buffer), 0);

        // Close the socket
        close(new_sd);
    }

    return 0;
}