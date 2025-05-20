//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define BUFFER_SIZE 1024
#define POP3_PORT 110
#define POP3_USER "your_username"
#define POP3_PASSWORD "your_password"
#define POP3_SERVER "pop3.example.com"

int pop3_socket = -1;
char *username = POP3_USER;
char *password = POP3_PASSWORD;
char *server = POP3_SERVER;

void *pop3_thread(void *arg);

int main(int argc, char **argv) {
    pthread_t thread_id;

    if (argc > 3) {
        username = argv[1];
        password = argv[2];
        server = argv[3];
    }

    pop3_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (pop3_socket == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    inet_pton(AF_INET, server, &server_addr.sin_addr);

    if (connect(pop3_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server: %s\n", strerror(errno));
        close(pop3_socket);
        return 1;
    }

    printf("Connected to server\n");

    pthread_create(&thread_id, NULL, pop3_thread, NULL);

    while (1) {
        char buffer[BUFFER_SIZE];
        int bytes_received = recv(pop3_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Disconnected from server\n");
            close(pop3_socket);
            pthread_join(thread_id, NULL);
            break;
        }

        printf("Received data: %s\n", buffer);
    }

    return 0;
}

void *pop3_thread(void *arg) {
    char username_buffer[BUFFER_SIZE];
    char password_buffer[BUFFER_SIZE];

    sprintf(username_buffer, "USER %s\r\n", username);
    send(pop3_socket, username_buffer, strlen(username_buffer), 0);

    sprintf(password_buffer, "PASS %s\r\n", password);
    send(pop3_socket, password_buffer, strlen(password_buffer), 0);

    char buffer[BUFFER_SIZE];
    while (1) {
        int bytes_received = recv(pop3_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Disconnected from server\n");
            close(pop3_socket);
            break;
        }

        printf("Received data: %s\n", buffer);
    }

    return NULL;
}