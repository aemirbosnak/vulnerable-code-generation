//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/wait.h>

#define PORT 8080
#define MAX_NODES 100
#define MAX_DATA_SIZE 1024

struct node {
    int id;
    int sock;
    char *data;
};

struct message {
    int id;
    int type;
    char *data;
};

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    listen(sock, MAX_NODES);

    printf("Listening for connections...\n");

    while (1) {
        struct node *node;
        int client_sock = accept(sock, NULL, NULL);

        node = malloc(sizeof(struct node));
        node->id = getpid();
        node->sock = client_sock;

        send(client_sock, "Hello, client!", 13, 0);

        while (1) {
            struct message *message;
            message = malloc(sizeof(struct message));
            message->id = node->id;
            message->type = 1; // search request
            message->data = "some_data";

            send(client_sock, message, sizeof(struct message), 0);

            recv(client_sock, message, sizeof(struct message), 0);

            if (message->type == 2) { // search result
                printf("Received search result: %s\n", message->data);
                break;
            }
        }

        close(client_sock);
        free(node);
    }

    return 0;
}

int get_random_id(int id) {
    return id % MAX_NODES;
}

void send_message(int sock, int id, int type, char *data) {
    struct message *message = malloc(sizeof(struct message));
    message->id = id;
    message->type = type;
    message->data = data;

    send(sock, message, sizeof(struct message), 0);
}

int main_worker(int sock) {
    int id = get_random_id(sock);
    char *data = malloc(MAX_DATA_SIZE);

    recv(sock, data, MAX_DATA_SIZE, 0);

    if (data[0] == 1) { // search request
        int i = 0;
        char *ptr = data + 1;
        char *end = data + MAX_DATA_SIZE - 1;

        while (i < MAX_DATA_SIZE) {
            if (*ptr == '\0') {
                break;
            }

            i++;
            ptr++;
        }

        char *result = malloc(i + 1);
        memcpy(result, data + 1, i);
        result[i] = '\0';

        send_message(sock, id, 2, result); // send search result
    }

    free(data);
    return 0;
}