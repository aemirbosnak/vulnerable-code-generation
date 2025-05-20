//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENT_CONNECTIONS 5
#define MAX_MESSAGE_LENGTH 1024

struct castle {
    int sock;
    char name[50];
    char message[1024];
};

void initialize_castle(struct castle *castles, int num_castles) {
    int i;
    for (i = 0; i < num_castles; i++) {
        castles[i].sock = socket(AF_INET, SOCK_STREAM, 0);
        if (castles[i].sock == -1) {
            perror("socket creation failed");
            exit(1);
        }
        printf("Castle %d listening on port %d...\n", i, castles[i].sock);
    }
}

void send_message(struct castle *castles, int num_castles, char *message) {
    int i;
    for (i = 0; i < num_castles; i++) {
        send(castles[i].sock, message, strlen(message), 0);
    }
}

void receive_message(struct castle *castles, int num_castles) {
    int i;
    for (i = 0; i < num_castles; i++) {
        recv(castles[i].sock, castles[i].message, MAX_MESSAGE_LENGTH, 0);
        printf("Castle %d received message: %s\n", i, castles[i].message);
    }
}

int main(int argc, char *argv[]) {
    struct castle castles[MAX_CLIENT_CONNECTIONS];
    int num_castles = 0;

    if (argc < 2) {
        printf("Usage: %s <number_of_castles>\n", argv[0]);
        exit(1);
    }

    num_castles = atoi(argv[1]);

    initialize_castle(castles, num_castles);

    char message[] = "Greetings, brave knights!";
    send_message(castles, num_castles, message);

    receive_message(castles, num_castles);

    return 0;
}