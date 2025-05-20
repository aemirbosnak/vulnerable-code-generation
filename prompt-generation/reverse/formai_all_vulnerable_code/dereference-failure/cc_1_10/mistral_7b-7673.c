//MISTRAL-7B DATASET v1.0 Category: Recursive ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAX_TOWER_HEIGHT 5
#define ENCHANTMENT_FILE_EXT ".ench"
#define KNIGHT_NAME "brave_knight.txt"

typedef struct {
    int height;
    char enchantment[100];
} Tower;

void create_tower(Tower *tower, int height) {
    if (height > 0) {
        tower->height = height;
        sprintf(tower->enchantment, "tower_%d%s", height, ENCHANTMENT_FILE_EXT);
        create_tower(tower + 1, height - 1);
    }
}

void read_enchantment(Tower *tower) {
    int fd = open(tower->enchantment, O_RDONLY);
    char buffer[100];

    if (fd > 0) {
        read(fd, buffer, sizeof(buffer));
        printf("Enchantment of tower %d:\n%s\n", tower->height, buffer);
        close(fd);
    } else {
        printf("Could not read enchantment from tower %d.\n", tower->height);
    }
}

void climb_tower(Tower *tower) {
    if (tower->height > 0) {
        printf("Knight %s approaches tower %d.\n", KNIGHT_NAME, tower->height);
        read_enchantment(tower);
        climb_tower(tower + 1);
    }
}

int main() {
    Tower tower;

    create_tower(&tower, MAX_TOWER_HEIGHT);
    climb_tower(&tower);

    return 0;
}