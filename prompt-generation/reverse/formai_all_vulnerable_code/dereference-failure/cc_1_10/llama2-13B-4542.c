//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024 // range of ports to scan
#define MAX_PLAYERS 10 // maximum number of players
#define PLAYER_NAME_LEN 20 // maximum length of player name

struct player {
    char name[PLAYER_NAME_LEN];
    int port;
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <target_host>\n", argv[0]);
        return 1;
    }

    // create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        return 1;
    }

    // set up the target host and port range
    struct sockaddr_in target;
    target.sin_family = AF_INET;
    target.sin_port = htons(8080); // default port
    target.sin_addr.s_addr = inet_addr(argv[1]);

    // scan for open ports
    struct player *players = malloc(MAX_PLAYERS * sizeof(struct player));
    int i = 0;
    for (int port = 1; port < PORT_RANGE; port++) {
        // create a connection to the target host on the current port
        if (connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0) {
            // if the connection is successful, add the player to the list
            players[i].port = port;
            strcpy(players[i].name, "Player ");
            i++;
        }
    }

    // display the list of open ports and player names
    printf("Open Ports: \n");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (players[i].port != 0) {
            printf("Player %d: %d\n", i + 1, players[i].port);
        }
    }

    // clean up
    free(players);
    close(sock);
    return 0;
}