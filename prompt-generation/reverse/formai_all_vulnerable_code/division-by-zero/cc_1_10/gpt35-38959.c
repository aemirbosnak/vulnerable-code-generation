//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

struct player {
    int id;
    int socket;
    int latency;
};

int main(int argc, char *argv[]) {
    int num_players = argc-1;
    struct player players[num_players];

    // create sockets for each player and store into players array
    for (int i = 0; i < num_players; i++) {
        int player_socket = socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in server_address;
        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(10000);
        inet_pton(AF_INET, argv[i+1], &server_address.sin_addr);
        connect(player_socket, (struct sockaddr *) &server_address, sizeof(server_address));
        players[i].id = i;
        players[i].socket = player_socket;
    }

    // send latency check
    for (int i = 0; i < num_players; i++) {
        for (int j = 0; j < num_players; j++) {
            if (i != j) {
                char message[] = "ping";
                send(players[i].socket, message, sizeof(message), 0);
            }
        }
    }

    // receive latency and update players' structs
    for (int i = 0; i < num_players; i++) {
        for (int j = 0; j < num_players; j++) {
            if (i != j) {
                char buffer[1024] = {0};
                recv(players[i].socket, buffer, 1024, 0);
                players[i].latency += atoi(buffer);
            }
        }
        players[i].latency /= num_players-1; // calculate average latency
        printf("Player %d has an average latency of %d ms\n", players[i].id, players[i].latency);
    }

    return 0;
}