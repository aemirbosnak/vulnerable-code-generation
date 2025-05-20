//Falcon2-11B DATASET v1.0 Category: Chess engine ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char* color;
    char* name;
    int rank;
    int pieces[8];
} Player;

typedef struct {
    Player white;
    Player black;
} Game;

int check_color(char* color) {
    if (strlen(color)!= 1)
        return 1;
    else if (color[0] == 'w')
        return 1;
    else if (color[0] == 'b')
        return 1;
    else
        return 0;
}

int check_name(char* name) {
    if (strlen(name)!= 1)
        return 1;
    else if (name[0] == 'K')
        return 1;
    else if (name[0] == 'Q')
        return 1;
    else if (name[0] == 'R')
        return 1;
    else if (name[0] == 'N')
        return 1;
    else if (name[0] == 'B')
        return 1;
    else if (name[0] == 'P')
        return 1;
    else if (name[0] == 'K')
        return 1;
    else
        return 0;
}

int check_rank(int rank) {
    if (rank >= 1 && rank <= 8)
        return 1;
    else
        return 0;
}

int check_pieces(int pieces[8]) {
    int i;
    for (i = 0; i < 8; i++) {
        if (pieces[i] == 1)
            return 1;
        else if (pieces[i] == 2)
            return 1;
        else if (pieces[i] == 3)
            return 1;
        else if (pieces[i] == 4)
            return 1;
        else if (pieces[i] == 5)
            return 1;
        else if (pieces[i] == 6)
            return 1;
        else if (pieces[i] == 7)
            return 1;
        else
            return 0;
    }
    return 1;
}

void create_player(Player* player) {
    char color[2];
    char name[2];
    int rank;
    int pieces[8];
    srand(time(NULL));
    int i;

    for (i = 0; i < 8; i++)
        pieces[i] = rand() % 8 + 1;

    scanf("%s %s %d", color, name, &rank);

    if (check_color(color) && check_name(name) && check_rank(rank)) {
        player->color = color;
        player->name = name;
        player->rank = rank;
        player->pieces[0] = pieces[0];
        player->pieces[1] = pieces[1];
        player->pieces[2] = pieces[2];
        player->pieces[3] = pieces[3];
        player->pieces[4] = pieces[4];
        player->pieces[5] = pieces[5];
        player->pieces[6] = pieces[6];
        player->pieces[7] = pieces[7];
    }
}

void create_game(Game* game) {
    Player white;
    Player black;

    create_player(&white);
    create_player(&black);

    game->white = white;
    game->black = black;
}

int main() {
    Game game;
    create_game(&game);

    return 0;
}