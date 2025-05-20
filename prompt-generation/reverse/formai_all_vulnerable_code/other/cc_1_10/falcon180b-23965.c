//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_COMMANDS 10

struct command {
    char *name;
    void (*func)(void);
};

void init(void) {
    srand(time(NULL));
}

void move(int dx, int dy) {
    printf("Moving %d,%d\n", dx, dy);
}

void attack(int target_x, int target_y) {
    printf("Attacking %d,%d\n", target_x, target_y);
}

void defend(void) {
    printf("Defending\n");
}

int main(int argc, char *argv[]) {
    init();

    struct command commands[MAX_COMMANDS] = {
        {"move", move},
        {"attack", attack},
        {"defend", defend}
    };

    int player_x = 0;
    int player_y = 0;

    while (1) {
        printf("Player at %d,%d\n", player_x, player_y);

        char input[64];
        fgets(input, sizeof(input), stdin);

        char *token = strtok(input, " ");
        if (token == NULL)
            continue;

        for (int i = 0; i < MAX_COMMANDS; i++) {
            if (strcmp(token, commands[i].name) == 0) {
                commands[i].func();
                break;
            }
        }
    }

    return 0;
}