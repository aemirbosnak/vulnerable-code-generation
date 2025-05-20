//Falcon2-11B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_map(char** map, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

void create_map(char** map, int width, int height) {
    for (int i = 0; i < height; i++) {
        map[i] = (char*)malloc(width * sizeof(char));
        for (int j = 0; j < width; j++) {
            map[i][j] = '.';
        }
    }
}

void fill_map(char** map, int width, int height) {
    int num_rooms = 4;
    int num_exits = 2;
    int min_room_size = 5;
    int max_room_size = 10;
    int min_door_size = 3;
    int max_door_size = 6;

    srand(time(NULL));

    for (int i = 0; i < num_rooms; i++) {
        int room_x = rand() % (width - min_room_size - max_room_size) + min_room_size;
        int room_y = rand() % (height - min_room_size - max_room_size) + min_room_size;
        int room_size = rand() % (max_room_size - min_room_size + 1) + min_room_size;

        for (int j = 0; j < room_size; j++) {
            for (int k = 0; k < room_size; k++) {
                map[room_y + j][room_x + k] = '#';
            }
        }

        for (int j = 0; j < room_size; j++) {
            for (int k = 0; k < room_size; k++) {
                map[room_y + j][room_x + k] = '#';
            }
        }
    }

    for (int i = 0; i < num_exits; i++) {
        int exit_x = rand() % (width - min_door_size - max_door_size) + min_door_size;
        int exit_y = rand() % (height - min_door_size - max_door_size) + min_door_size;
        int door_size = rand() % (max_door_size - min_door_size + 1) + min_door_size;

        for (int j = 0; j < door_size; j++) {
            for (int k = 0; k < door_size; k++) {
                map[exit_y + j][exit_x + k] = '.';
            }
        }

        for (int j = 0; j < door_size; j++) {
            for (int k = 0; k < door_size; k++) {
                map[exit_y + j][exit_x + k] = '.';
            }
        }
    }
}

int main() {
    int width = 50;
    int height = 50;
    srand(time(NULL));

    char** map = (char**)malloc(height * sizeof(char*));
    for (int i = 0; i < height; i++) {
        map[i] = (char*)malloc(width * sizeof(char));
    }

    create_map(map, width, height);
    fill_map(map, width, height);

    print_map(map, width, height);

    free(map);

    return 0;
}