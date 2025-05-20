//GEMINI-pro DATASET v1.0 Category: Networking ; Style: random
// The Lounge, where all the cool C cats hang out

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

// A lounge worth visiting should have a welcoming atmosphere
#define GREETING "Welcome to The Lounge, where C cats hang out!\n"

// Every lounge has its regulars, and we keep track of them here
#define MAX_CLI 5

// The lounge has a certain ambience, and we set it using this function
void set_sockaddr(struct sockaddr_in *addr, int port) {
    memset(addr, 0, sizeof(*addr));
    addr->sin_family = AF_INET;
    addr->sin_port = htons(port);
    addr->sin_addr.s_addr = INADDR_ANY;
}

// No lounge is complete without some music, and this function plays the welcome tune
void greet_client(int sockfd) {
    send(sockfd, GREETING, strlen(GREETING), 0);
}

// The lounge is a place for cats to chill, and this function handles the chit-chat
void handle_client(int sockfd) {
    char buffer[256];
    while (1) {
        int len = recv(sockfd, buffer, sizeof(buffer), 0);
        if (len <= 0) {
            break;
        }
        send(sockfd, buffer, len, 0);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    // The lounge needs a door, and we set it up here
    int port = atoi(argv[1]);
    struct sockaddr_in server_addr;
    set_sockaddr(&server_addr, port);
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // A lounge needs to be open for business, and we do that here
    if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        return 1;
    }
    if (listen(sockfd, MAX_CLI) < 0) {
        perror("listen");
        return 1;
    }

    // The lounge is open, and we wait for guests to arrive
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sockfd = accept(sockfd, (struct sockaddr *) &client_addr, &client_addr_len);
        if (client_sockfd < 0) {
            perror("accept");
            continue;
        }

        // A new guest has arrived, and we welcome them to the lounge
        greet_client(client_sockfd);

        // The guest has settled in, and we let them enjoy the lounge
        handle_client(client_sockfd);

        // The guest has left the lounge, and we bid them farewell
        close(client_sockfd);
    }

    // The lounge is closing, and we bid farewell to our guests
    close(sockfd);
    return 0;
}