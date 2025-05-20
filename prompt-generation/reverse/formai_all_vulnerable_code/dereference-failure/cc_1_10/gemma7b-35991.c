//Gemma-7B DATASET v1.0 Category: Simple HTTP Proxy ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/ioctl.h>

#define MAX_BUFFER_SIZE 4096

typedef struct ProxyState {
    int sockfd;
    char ip[16];
    char host[256];
    char path[256];
    struct ProxyState* next;
} ProxyState;

ProxyState* proxy_head = NULL;

void proxy_add(char* host, char* path) {
    ProxyState* new_state = malloc(sizeof(ProxyState));
    strcpy(new_state->ip, "127.0.0.1");
    new_state->sockfd = -1;
    strcpy(new_state->host, host);
    strcpy(new_state->path, path);
    new_state->next = NULL;

    if (proxy_head) {
        proxy_head->next = new_state;
    } else {
        proxy_head = new_state;
    }
}

int main() {
    proxy_add("google.com", "/");
    proxy_add("facebook.com", "/");

    char buffer[MAX_BUFFER_SIZE];
    int sockfd = socket(AF_INET, SOCK_STREAM, htons(80));

    while (1) {
        int client_sockfd = accept(sockfd, NULL, NULL);

        ProxyState* state = proxy_head;
        while (state) {
            if (strcmp(state->host, client_sockfd) == 0) {
                break;
            }
            state = state->next;
        }

        if (state) {
            printf("Client connected to: %s\n", state->host);
            printf("Client path: %s\n", state->path);

            int num_read = read(client_sockfd, buffer, MAX_BUFFER_SIZE);
            write(state->sockfd, buffer, num_read);
        } else {
            printf("No matching proxy state\n");
        }

        close(client_sockfd);
    }

    return 0;
}