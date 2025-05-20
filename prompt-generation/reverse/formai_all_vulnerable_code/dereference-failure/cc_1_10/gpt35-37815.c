//FormAI DATASET v1.0 Category: Firewall ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>

#define BUFFER_SIZE 1024

struct arguments {
    int client_socket;
    int *blocked_ips;
    int ip_count;
};

void *handle_client(void *arg);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s [port] [block list]\n", argv[0]);
        exit(-1);
    }

    int port = atoi(argv[1]);

    int blocked_ips[argc-2];
    int ip_count = 0;

    for (int i = 2; i < argc; i++) {
        struct in_addr addr;
        if (inet_pton(AF_INET, argv[i], &addr) == 1) {
            blocked_ips[ip_count++] = addr.s_addr;
        }
    }

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));

    listen(server_socket, 5);

    while (1) {
        struct sockaddr_in client_address;
        socklen_t client_address_len = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_len);

        struct arguments *args = (struct arguments *) malloc(sizeof(struct arguments));
        args->client_socket = client_socket;
        args->blocked_ips = blocked_ips;
        args->ip_count = ip_count;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, args);
        pthread_detach(thread_id);
    }

    return 0;
}

void *handle_client(void *arg) {
    struct arguments *args = arg;
    int client_socket = args->client_socket;
    int *blocked_ips = args->blocked_ips;
    int ip_count = args->ip_count;
    free(arg);

    struct sockaddr_in client_address;
    socklen_t client_address_len = sizeof(client_address);
    getpeername(client_socket, (struct sockaddr *) &client_address, &client_address_len);

    char client_ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &client_address.sin_addr, client_ip, INET_ADDRSTRLEN);

    int is_blocked = 0;
    for (int i = 0; i < ip_count; i++) {
        if (client_address.sin_addr.s_addr == blocked_ips[i]) {
            is_blocked = 1;
            break;
        }
    }

    if (is_blocked) {
        char message[BUFFER_SIZE] = "Your IP address has been blocked.";
        send(client_socket, message, strlen(message), 0);
    } else {
        char message[BUFFER_SIZE] = "Welcome to the server!";
        send(client_socket, message, strlen(message), 0);
    }

    close(client_socket);
    return NULL;
}