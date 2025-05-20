//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENT_LENGTH 1024
#define MAX_CONVERSATIONS 10

struct conversation {
    int sock;
    char name[50];
    char message[100];
    struct conversation *next;
};

struct conversation *conversations = NULL;

void init_conversations() {
    conversations = malloc(sizeof(struct conversation));
    conversations->sock = -1;
    conversations->name[0] = '\0';
    conversations->message[0] = '\0';
    conversations->next = NULL;
}

void add_conversation(int sock, char *name, char *message) {
    struct conversation *new_conversation = malloc(sizeof(struct conversation));
    new_conversation->sock = sock;
    strcpy(new_conversation->name, name);
    strcpy(new_conversation->message, message);
    new_conversation->next = conversations;
    conversations = new_conversation;
}

void send_message(int sock, char *message) {
    char buffer[100];
    strcpy(buffer, message);
    send(sock, buffer, strlen(buffer), 0);
}

void close_conversation(int sock) {
    struct conversation *conversation = conversations;
    while (conversation != NULL) {
        if (conversation->sock == sock) {
            break;
        }
        conversation = conversation->next;
    }
    if (conversation != NULL) {
        conversation->sock = -1;
        free(conversation);
    }
}

int main() {
    int listen_sock, client_sock;
    struct sockaddr_in listen_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[100];

    init_conversations();

    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock < 0) {
        perror("socket failed");
        exit(1);
    }

    memset(&listen_addr, 0, sizeof(listen_addr));
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_addr.s_addr = INADDR_ANY;
    listen_addr.sin_port = htons(1234);

    if (bind(listen_sock, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(listen_sock, 3) < 0) {
        perror("listen failed");
        exit(1);
    }

    printf("Listening for connections...\n");

    while (1) {
        client_sock = accept(listen_sock, (struct sockaddr *)&client_addr, &client_len);
        if (client_sock < 0) {
            perror("accept failed");
            exit(1);
        }

        printf("New client connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        add_conversation(client_sock, "Client", "Hello, world!");

        while (1) {
            recv(client_sock, buffer, 100, 0);
            if (buffer[0] == '\0') {
                break;
            }
            send_message(client_sock, buffer);
        }

        close_conversation(client_sock);
    }

    return 0;
}