//Gemma-7B DATASET v1.0 Category: Simple HTTP Proxy ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>

#define MAX_BUFFER_SIZE 4096

typedef struct ProxyState {
    int sockfd;
    char buf[MAX_BUFFER_SIZE];
    int read_bytes;
    int write_bytes;
    struct ProxyState* next;
} ProxyState;

ProxyState* proxy_head = NULL;

void add_proxy_state(int sockfd) {
    ProxyState* new_state = malloc(sizeof(ProxyState));
    new_state->sockfd = sockfd;
    new_state->read_bytes = 0;
    new_state->write_bytes = 0;
    new_state->next = proxy_head;
    proxy_head = new_state;
}

void handle_client(int clientfd) {
    add_proxy_state(clientfd);

    ProxyState* state = proxy_head;
    while (state) {
        if (state->sockfd == clientfd) {
            break;
        }
        state = state->next;
    }

    char* buffer = state->buf;
    int read_bytes = read(clientfd, buffer, MAX_BUFFER_SIZE);
    state->read_bytes += read_bytes;

    int write_bytes = write(state->sockfd, buffer, read_bytes);
    state->write_bytes += write_bytes;

    close(clientfd);
}

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, htons(8080));
    bind(sockfd, NULL, 0);

    while (1) {
        int clientfd = accept(sockfd, NULL, NULL);
        handle_client(clientfd);
    }

    return 0;
}