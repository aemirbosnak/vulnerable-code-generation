//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_PLAYERS 4
#define MAX_ROOMS 10

struct player {
    int sockfd;
    char name[32];
    int room;
};

struct room {
    int id;
    char name[32];
    int num_players;
    struct player *players[MAX_PLAYERS];
};

struct haunted_house {
    int sockfd;
    struct player players[MAX_PLAYERS];
    struct room rooms[MAX_ROOMS];
    int num_players;
    int num_rooms;
};

void init_haunted_house(struct haunted_house *haunted_house) {
    haunted_house->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (haunted_house->sockfd == -1) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(haunted_house->sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(haunted_house->sockfd, 5) == -1) {
        perror("listen");
        exit(1);
    }

    haunted_house->num_players = 0;
    haunted_house->num_rooms = 0;

    for (int i = 0; i < MAX_ROOMS; i++) {
        haunted_house->rooms[i].id = i;
        sprintf(haunted_house->rooms[i].name, "Room %d", i);
        haunted_house->rooms[i].num_players = 0;
    }
}

void add_player(struct haunted_house *haunted_house, struct player *player) {
    haunted_house->players[haunted_house->num_players++] = *player;
}

void remove_player(struct haunted_house *haunted_house, struct player *player) {
    for (int i = 0; i < haunted_house->num_players; i++) {
        if (haunted_house->players[i].sockfd == player->sockfd) {
            haunted_house->players[i] = haunted_house->players[haunted_house->num_players - 1];
            haunted_house->num_players--;
            break;
        }
    }
}

void add_room(struct haunted_house *haunted_house, struct room *room) {
    haunted_house->rooms[haunted_house->num_rooms++] = *room;
}

void remove_room(struct haunted_house *haunted_house, struct room *room) {
    for (int i = 0; i < haunted_house->num_rooms; i++) {
        if (haunted_house->rooms[i].id == room->id) {
            haunted_house->rooms[i] = haunted_house->rooms[haunted_house->num_rooms - 1];
            haunted_house->num_rooms--;
            break;
        }
    }
}

void send_message(struct haunted_house *haunted_house, struct player *player, char *message) {
    send(player->sockfd, message, strlen(message), 0);
}

void broadcast_message(struct haunted_house *haunted_house, char *message) {
    for (int i = 0; i < haunted_house->num_players; i++) {
        send_message(haunted_house, &haunted_house->players[i], message);
    }
}

void handle_player(struct haunted_house *haunted_house, struct player *player) {
    char buffer[1024];
    while (1) {
        int n = recv(player->sockfd, buffer, sizeof(buffer), 0);
        if (n == -1) {
            perror("recv");
            remove_player(haunted_house, player);
            break;
        } else if (n == 0) {
            remove_player(haunted_house, player);
            break;
        }

        buffer[n] = '\0';

        char *command = strtok(buffer, " ");
        if (strcmp(command, "join") == 0) {
            char *room_name = strtok(NULL, " ");
            for (int i = 0; i < haunted_house->num_rooms; i++) {
                if (strcmp(haunted_house->rooms[i].name, room_name) == 0) {
                    player->room = haunted_house->rooms[i].id;
                    haunted_house->rooms[i].players[haunted_house->rooms[i].num_players++] = player;
                    send_message(haunted_house, player, "You have joined the room.\n");
                    broadcast_message(haunted_house, player->name);
                    break;
                }
            }
        } else if (strcmp(command, "leave") == 0) {
            for (int i = 0; i < haunted_house->num_rooms; i++) {
                if (player->room == haunted_house->rooms[i].id) {
                    for (int j = 0; j < haunted_house->rooms[i].num_players; j++) {
                        if (haunted_house->rooms[i].players[j] == player) {
                            haunted_house->rooms[i].num_players--;
                            break;
                        }
                    }
                    player->room = -1;
                    send_message(haunted_house, player, "You have left the room.\n");
                    broadcast_message(haunted_house, player->name);
                    break;
                }
            }
        } else if (strcmp(command, "say") == 0) {
            char *message = strtok(NULL, "");
            broadcast_message(haunted_house, player->name);
            broadcast_message(haunted_house, message);
        } else if (strcmp(command, "quit") == 0) {
            remove_player(haunted_house, player);
            break;
        } else {
            send_message(haunted_house, player, "Invalid command.\n");
        }
    }
}

int main() {
    struct haunted_house haunted_house;
    init_haunted_house(&haunted_house);

    while (1) {
        struct sockaddr_in addr;
        socklen_t addrlen = sizeof(addr);
        int newsockfd = accept(haunted_house.sockfd, (struct sockaddr *)&addr, &addrlen);
        if (newsockfd == -1) {
            perror("accept");
            continue;
        }

        struct player player;
        player.sockfd = newsockfd;
        strcpy(player.name, inet_ntoa(addr.sin_addr));
        player.room = -1;
        add_player(&haunted_house, &player);

        send_message(&haunted_house, &player, "Welcome to the haunted house!\n");
        broadcast_message(&haunted_house, player.name);

        handle_player(&haunted_house, &player);
    }

    return 0;
}