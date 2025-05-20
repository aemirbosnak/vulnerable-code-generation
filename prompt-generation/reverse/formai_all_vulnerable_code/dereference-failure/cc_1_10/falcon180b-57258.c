//Falcon-180B DATASET v1.0 Category: Chat server ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define TRUE   1
#define FALSE  0
#define PORT 8888
#define BACKLOG 10
#define MAX_LINE 1024

struct user_data {
    int sock;
    char *name;
};

void *thread_fun(void *param);

int main() {
    int listen_sock;
    struct sockaddr_in serv_addr;
    int opt = TRUE;
    int addrlen = sizeof(serv_addr);

    setsockopt(listen_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    listen(listen_sock, BACKLOG);

    while (TRUE) {
        int client_sock = accept(listen_sock, (struct sockaddr *) NULL, NULL);
        pthread_t thread_id;

        if (client_sock == -1) {
            printf("Error accepting client\n");
            continue;
        }

        pthread_create(&thread_id, NULL, thread_fun, (void *) client_sock);
    }

    close(listen_sock);

    return 0;
}

void *thread_fun(void *param) {
    int sock = *(int *) param;
    char buffer[MAX_LINE];
    struct user_data *user_data = malloc(sizeof(struct user_data));

    user_data->sock = sock;
    user_data->name = NULL;

    send(sock, "Enter your name: ", strlen("Enter your name: "), 0);

    while (TRUE) {
        int bytes_recv = recv(sock, buffer, MAX_LINE, 0);

        if (bytes_recv <= 0) {
            printf("Client disconnected\n");
            close(sock);
            free(user_data);
            break;
        }

        buffer[bytes_recv] = '\0';
        printf("%s\n", buffer);

        if (user_data->name == NULL) {
            user_data->name = strdup(buffer);
            send(sock, "Welcome to the chat, ", strlen("Welcome to the chat, "), 0);
            send(sock, user_data->name, strlen(user_data->name), 0);
        }
    }
}