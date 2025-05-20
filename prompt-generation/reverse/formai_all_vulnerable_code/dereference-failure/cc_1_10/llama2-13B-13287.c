//LLAMA2-13B DATASET v1.0 Category: Chat server ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct user {
    char name[50];
    char message[100];
};

int main(int argc, char *argv[]) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(1);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    listen(sock, 3);

    struct user *user = (struct user *)malloc(sizeof(struct user));
    user->name[0] = '\0';
    user->message[0] = '\0';

    while (1) {
        int client_sock = accept(sock, NULL, NULL);
        if (client_sock < 0) {
            perror("accept failed");
            exit(1);
        }

        printf("New client connected from IP address %s\n", inet_ntoa(server_addr.sin_addr));

        char message[100];
        read(client_sock, message, 100);
        printf("Client message: %s\n", message);

        char *ptr = strtok(message, " ");
        while (ptr != NULL) {
            if (strcmp(ptr, "!name") == 0) {
                char *name = strtok(NULL, " ");
                strcpy(user->name, name);
            } else if (strcmp(ptr, "!message") == 0) {
                char *message = strtok(NULL, " ");
                strcpy(user->message, message);
            }
            ptr = strtok(NULL, " ");
        }

        send(client_sock, user->message, strlen(user->message), 0);
        printf("Sent message to client\n");

        close(client_sock);
    }

    free(user);
    close(sock);

    return 0;
}