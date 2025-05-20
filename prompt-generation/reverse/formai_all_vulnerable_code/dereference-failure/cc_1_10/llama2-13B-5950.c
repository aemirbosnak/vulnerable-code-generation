//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct chat_message {
    char *message;
    struct chat_message *next;
};

struct chat_session {
    int sock;
    char *username;
    struct chat_message *messages;
};

void chat_server_init(struct chat_session *session) {
    session->sock = socket(AF_INET, SOCK_STREAM, 0);
    if (session->sock < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    session->username = malloc(10 * sizeof(char));
    if (session->username == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    session->messages = NULL;
}

void chat_server_listen(struct chat_session *session) {
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(session->sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(session->sock, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
}

void chat_server_accept(struct chat_session *session) {
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int client_sock = accept(session->sock, (struct sockaddr *)&client_addr, &client_len);

    if (client_sock < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    struct chat_message *new_message = malloc(10 * sizeof(char));
    if (new_message == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    new_message->message = "Welcome to the chat server!";
    new_message->next = session->messages;
    session->messages = new_message;
}

void chat_server_send(struct chat_session *session, const char *message) {
    char *send_message = malloc(strlen(message) + 1 * sizeof(char));
    if (send_message == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    strcpy(send_message, message);

    if (send(session->sock, send_message, strlen(message), 0) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    free(send_message);
}

void chat_server_run(struct chat_session *session) {
    while (1) {
        chat_server_listen(session);
        chat_server_accept(session);
        chat_server_send(session, "Hello, client!");
    }
}

int main() {
    struct chat_session session = {
        .sock = -1,
        .username = NULL,
        .messages = NULL
    };

    chat_server_init(&session);
    chat_server_run(&session);

    return 0;
}