//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} position;

void printRoom(char** room, position playerPos);
position createRandomPosition(int maxRow, int maxCol);
int canMove(char** room, position pos);
void movePlayer(char** room, position* playerPos, char direction);
void haunt(char** room, position ghostPos);

int main() {
    srand(time(NULL));
    const int ROWS = 10;
    const int COLS = 10;

    char** room = (char**) malloc(sizeof(char*) * ROWS);
    for (int i = 0; i < ROWS; i++) {
        room[i] = (char*) malloc(sizeof(char) * COLS);
    }

    // initializing room
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            room[i][j] = '.';
        }
    }

    // initializing player position
    position playerPos = createRandomPosition(ROWS, COLS);
    room[playerPos.x][playerPos.y] = '@';

    // initializing ghost position
    position ghostPos = createRandomPosition(ROWS, COLS);
    room[ghostPos.x][ghostPos.y] = 'G';

    // game loop
    while (1) {
        system("clear");
        printRoom(room, playerPos);

        char input;
        printf(">> ");
        scanf(" %c", &input);

        if (input == 'q')
            break;

        movePlayer(room, &playerPos, input);

        if (playerPos.x == ghostPos.x && playerPos.y == ghostPos.y) {
            haunt(room, ghostPos);
            break;
        }

        ghostPos = createRandomPosition(ROWS, COLS);
        room[ghostPos.x][ghostPos.y] = 'G';
    }

    // freeing allocated space
    for (int i = 0; i < ROWS; i++) {
        free(room[i]);
    }
    free(room);

    return 0;
}

void printRoom(char** room, position playerPos) {
    for (int i = 0; i < 50; i++) {
        printf("\n");
    }
    printf("Use W, S, A, D to move. Q to quit.\n");
    printf("------------\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == playerPos.x && j == playerPos.y) {
                printf("@ ");
            }
            else {
                printf("%c ", room[i][j]);
            }
        }
        printf("\n");
    }
    printf("------------\n");
}

position createRandomPosition(int maxRow, int maxCol) {
    position pos;
    pos.x = rand() % maxRow;
    pos.y = rand() % maxCol;
    return pos;
}

int canMove(char** room, position pos) {
    if (pos.x < 0 || pos.x >= 10 || pos.y < 0 || pos.y >= 10) {
        return 0;
    }

    if (room[pos.x][pos.y] == '#') {
        return 0;
    }

    return 1;
}

void movePlayer(char** room, position* playerPos, char direction) {
    position newPos = *playerPos;

    switch (direction) {
        case 'w':
            newPos.x--;
            break;
        case 's':
            newPos.x++;
            break;
        case 'a':
            newPos.y--;
            break;
        case 'd':
            newPos.y++;
            break;
    }

    if (canMove(room, newPos)) {
        room[(*playerPos).x][(*playerPos).y] = '.';
        *playerPos = newPos;
        room[(*playerPos).x][(*playerPos).y] = '@';
    }
}

void haunt(char** room, position ghostPos) {
    room[ghostPos.x][ghostPos.y] = 'X';
    printf("\n\n\n\n\n");
    printf("You have been haunted by the ghost :( \n\n\n");
}