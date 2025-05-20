//LLAMA2-13B DATASET v1.0 Category: System administration ; Style: visionary
// The Great Computer Awakens

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENT_LENGTH 1024
#define MAX_SERVER_LENGTH 2048

struct server_context {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[MAX_CLIENT_LENGTH];
};

struct client_context {
    int sock;
    struct sockaddr_in client_addr;
    char buffer[MAX_CLIENT_LENGTH];
};

void *server_thread(void *arg) {
    struct server_context *sc = arg;
    listen(sc->sock, 3);
    printf("Listening for clients...\n");

    while (1) {
        int client_sock = accept(sc->sock, NULL, NULL);
        struct client_context *cc = malloc(sizeof(struct client_context));
        cc->sock = client_sock;
        cc->client_addr = sc->server_addr;
        read(client_sock, cc->buffer, MAX_CLIENT_LENGTH);
        printf("Client message: %s\n", cc->buffer);
        send(client_sock, "Hello, client!", 13, 0);
        free(cc);
    }
    return NULL;
}

void *client_thread(void *arg) {
    struct client_context *cc = arg;
    char dest_ip[] = "192.168.1.100";
    char dest_port = '8080';
    struct sockaddr_in client_addr;
    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(dest_port);
    inet_pton(AF_INET, dest_ip, &client_addr.sin_addr);
    connect(cc->sock, (struct sockaddr *)&client_addr, sizeof(client_addr));
    printf("Connected to server...\n");

    while (1) {
        char send_buf[] = "Hello, server!";
        send(cc->sock, send_buf, strlen(send_buf), 0);
        char recv_buf[MAX_CLIENT_LENGTH];
        recv(cc->sock, recv_buf, MAX_CLIENT_LENGTH, 0);
        printf("Server message: %s\n", recv_buf);
    }
    return NULL;
}

int main() {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    struct server_context sc;
    sc.sock = server_sock;
    sc.server_addr.sin_family = AF_INET;
    sc.server_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "192.168.1.100", &sc.server_addr.sin_addr);
    listen(sc.sock, 3);
    printf("Server listening...\n");

    pthread_t server_thread_id, client_thread_id;
    struct server_context *sc_ptr = &sc;
    struct client_context *cc_ptr = NULL;

    pthread_create(&server_thread_id, NULL, server_thread, sc_ptr);
    pthread_create(&client_thread_id, NULL, client_thread, cc_ptr);

    pthread_join(server_thread_id, NULL);
    pthread_join(client_thread_id, NULL);

    close(server_sock);
    return 0;
}