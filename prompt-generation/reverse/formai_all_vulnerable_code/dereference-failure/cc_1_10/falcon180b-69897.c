//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_BUFFER_SIZE 1024
#define POP3_PORT 110

typedef struct {
    int sock;
    char buffer[MAX_BUFFER_SIZE];
} POP3_CLIENT;

void *pop3_thread(void *arg) {
    POP3_CLIENT *client = (POP3_CLIENT *) arg;
    char *username = "your_username";
    char *password = "your_password";
    char *command = "USER ";
    strcat(command, username);
    strcat(command, "\r\n");
    send(client->sock, command, strlen(command), 0);
    char response[MAX_BUFFER_SIZE];
    recv(client->sock, response, MAX_BUFFER_SIZE, 0);
    printf("Response: %s\n", response);
    command = "PASS ";
    strcat(command, password);
    strcat(command, "\r\n");
    send(client->sock, command, strlen(command), 0);
    recv(client->sock, response, MAX_BUFFER_SIZE, 0);
    printf("Response: %s\n", response);
    pthread_exit(0);
}

int main() {
    int sock;
    struct sockaddr_in server_addr;
    POP3_CLIENT client;
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);
    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }
    client.sock = sock;
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, pop3_thread, &client);
    pthread_join(thread_id, NULL);
    close(sock);
    return 0;
}