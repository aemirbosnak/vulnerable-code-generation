//LLAMA2-13B DATASET v1.0 Category: Socket programming ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct genius {
    int sock;
    char *message;
};

void send_message(struct genius *genius) {
    int sent = send(genius->sock, genius->message, strlen(genius->message), 0);
    if (sent < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }
}

void receive_message(struct genius *genius) {
    int received = recv(genius->sock, genius->message, sizeof(genius->message), 0);
    if (received < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", genius->message);
}

int main(void) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(sock, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    struct genius *genius = malloc(sizeof(struct genius));
    genius->sock = sock;
    genius->message = malloc(1024);

    send_message(genius);

    receive_message(genius);

    close(sock);
    free(genius->message);
    free(genius);

    return 0;
}