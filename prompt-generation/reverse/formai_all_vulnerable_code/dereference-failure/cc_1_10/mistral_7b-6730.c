//MISTRAL-7B DATASET v1.0 Category: Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#define PORT 8080
#define BUFFER_SIZE 1024

typedef struct {
    int number;
    int guess;
    int correct;
} game_state;

void setup(int *client_socket, char *ip) {
    int server_socket, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(ip);
    address.sin_port = htons(PORT);

    if (connect(server_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    *client_socket = server_socket;
}

void game(int client_socket) {
    game_state state;
    int number, guess;

    state.number = rand() % 100 + 1;

    send(client_socket, &state.number, sizeof(state.number), 0);

    do {
        recv(client_socket, &guess, sizeof(guess), 0);
        state.guess = guess;
        state.correct = (state.number == guess);

        send(client_socket, &state.correct, sizeof(state.correct), 0);
    } while (!state.correct);

    printf("Client guessed the number: %d\n", state.number);

    close(client_socket);
}

int main(int argc, char const *argv[]) {
    int client_socket;
    char ip[INET_ADDRSTRLEN];

    if (argc < 2) {
        printf("Usage: %s <server_ip>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    strcpy(ip, argv[1]);

    setup(&client_socket, ip);
    game(client_socket);

    return 0;
}