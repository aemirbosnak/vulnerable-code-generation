//LLAMA2-13B DATASET v1.0 Category: Simple Web Server ; Style: irregular
//! webserver.c - A most irregular web server 😜

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>

#define PORT 8080

struct server_state {
    int sock;   // socket descriptor
    struct sockaddr_in client; // client address
    char buffer[1024]; // buffer for incoming data
};

//! Function to handle incoming connections
void handle_connection(int sock) {
    struct server_state *state;
    state = malloc(sizeof(struct server_state));
    state->sock = sock;
    state->client.sin_family = AF_INET;
    state->client.sin_addr.s_addr = INADDR_ANY;
    state->client.sin_port = htons(PORT);

    //! Print a funny message to the client
    printf("Welcome to the most irregular web server ever! 😜\n");

    //! Loop until the client closes the connection
    while (1) {
        //! Read data from the client
        read(sock, state->buffer, 1024);

        //! Check if the client sent a "QUIT" command
        if (strcmp(state->buffer, "QUIT\n") == 0) {
            break;
        }

        //! Send a funny response back to the client
        printf("You said: %s\n", state->buffer);
        send(sock, "😂👍", 5, 0);
    }

    //! Close the socket and free memory
    close(sock);
    free(state);
}

int main() {
    int sock; // socket descriptor
    struct server_state *state;

    //! Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(1);
    }

    //! Bind the socket to a specific address and port
    socklen_t len = sizeof(struct sockaddr_in);
    getsockname(sock, (struct sockaddr *)&state->client, &len);
    printf("Listening on port %d...\n", state->client.sin_port);

    //! Listen for incoming connections
    listen(sock, 3);

    //! Accept an incoming connection
    sock = accept(sock, NULL, NULL);
    state = malloc(sizeof(struct server_state));
    state->sock = sock;
    handle_connection(sock);

    return 0;
}