//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

struct user {
    char name[50];
    char password[50];
};

int main() {
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

    if (listen(sock, 5) < 0) {
        perror("listen failed");
        exit(1);
    }

    printf("Server listening on port %d...\n", PORT);

    struct user *user;
    while (1) {
        user = malloc(sizeof(struct user));
        if (recv(sock, user, BUFFER_SIZE, 0) < 0) {
            perror("recv failed");
            free(user);
        } else {
            printf("Received message from client: %s\n", user->name);
            if (strcmp(user->name, "Sir_Hugh") == 0) {
                printf("Welcome, Sir_Hugh! You have been granted access to the kingdom's secret stash of ale.\n");
                send(sock, "You have been granted access to the kingdom's secret stash of ale.\n", 25, 0);
            } else {
                printf("Thou art not Sir_Hugh, thou art a mere mortal. Thy pleas for ale shall fall upon deaf ears.\n");
            }
            free(user);
        }
    }

    close(sock);
    return 0;
}