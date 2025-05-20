//Falcon2-11B DATASET v1.0 Category: Smart home automation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10

int num_clients;
pthread_mutex_t lock;

void *client_handler(void *arg) {
    int client_sock, valread;
    char buffer[1024];
    struct sockaddr_in client_addr;
    struct hostent *server;

    client_sock = (int)arg;
    printf("New connection from %s\n", inet_ntoa(client_addr.sin_addr));

    while (1) {
        bzero(buffer, sizeof(buffer));
        valread = read(client_sock, buffer, sizeof(buffer));
        if (valread <= 0) {
            printf("Client %d disconnected\n", client_sock);
            break;
        }
        printf("Message from client %d: %s\n", client_sock, buffer);
        send(client_sock, "Hello from server\n", strlen("Hello from server\n"), 0);
    }

    close(client_sock);
}

void *server_handler(void *arg) {
    int server_sock, valread;
    char buffer[1024];
    struct sockaddr_in client_addr;
    struct hostent *server;

    server_sock = (int)arg;
    printf("Server listening on port %d\n", PORT);

    while (1) {
        bzero(buffer, sizeof(buffer));
        memset(&client_addr, 0, sizeof(client_addr));
        server = gethostbyname("localhost");
        client_addr.sin_family = AF_INET;
        client_addr.sin_port = htons(PORT);
        client_addr.sin_addr = *((struct in_addr *)server->h_addr);
        client_addr.sin_addr.s_addr = htonl(INADDR_ANY);
        valread = sizeof(struct sockaddr_in);
        if ((server_sock = accept(server_sock, (struct sockaddr *)&client_addr, &valread)) < 0) {
            perror("accept");
            continue;
        }
        pthread_t thread;
        pthread_create(&thread, NULL, client_handler, (void *)server_sock);
        pthread_detach(thread);
    }
}

int main(int argc, char *argv[]) {
    int server_sock, valread;
    struct sockaddr_in server_addr;
    struct hostent *server;

    signal(SIGPIPE, SIG_IGN);

    server = gethostbyname("localhost");
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr = *((struct in_addr *)server->h_addr);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }
    if (listen(server_sock, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(1);
    }
    pthread_mutex_init(&lock, NULL);
    pthread_t server_thread;
    pthread_create(&server_thread, NULL, server_handler, (void *)server_sock);
    pthread_detach(server_thread);

    while (1) {
        sleep(1000);
    }

    return 0;
}