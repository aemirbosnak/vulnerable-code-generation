//Falcon2-11B DATASET v1.0 Category: Terminal Based Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define MAX_ROOM 5
#define MAX_ROOM_NAME_LEN 20
#define MAX_DIRECTION 4

struct room {
    char name[MAX_ROOM_NAME_LEN];
    struct room* next;
};

struct room* rooms[MAX_ROOM];
int room_count = 0;

int direction_up, direction_down, direction_left, direction_right;

void display_room(struct room* room) {
    printf("%s\n", room->name);
}

void create_room(char* room_name) {
    struct room* new_room = malloc(sizeof(struct room));
    strcpy(new_room->name, room_name);

    new_room->next = rooms[room_count];
    rooms[room_count++] = new_room;
}

int get_input() {
    printf("Enter direction: ");
    char input[4];
    scanf("%s", input);

    for (int i = 0; i < 4; i++) {
        if (input[i] == 'U') {
            direction_up = 1;
        } else if (input[i] == 'D') {
            direction_down = 1;
        } else if (input[i] == 'L') {
            direction_left = 1;
        } else if (input[i] == 'R') {
            direction_right = 1;
        } else {
            return -1;
        }
    }

    return 0;
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < MAX_ROOM; i++) {
        rooms[i] = NULL;
    }

    create_room("Corridor");
    create_room("Engine Room");
    create_room("Bridge");
    create_room("Sick Bay");
    create_room("Storage");

    direction_up = direction_down = direction_left = direction_right = 0;

    int current_room = 0;

    while (1) {
        display_room(rooms[current_room]);
        printf("You are currently in the %s\n", rooms[current_room]->name);

        if (rooms[current_room]->next == NULL) {
            printf("You can't go any further.\n");
        } else {
            printf("You can go:\n");

            for (int i = 0; i < MAX_ROOM; i++) {
                if (rooms[i] && rooms[i]->next && rooms[i]->next->name[0]!= '\0') {
                    printf("%s\n", rooms[i]->next->name);
                }
            }

            printf("Enter direction: ");
            int input = get_input();

            if (input == -1) {
                printf("Invalid input, try again.\n");
                continue;
            }

            if (input == 1) {
                direction_up = 1;
            } else if (input == 2) {
                direction_down = 1;
            } else if (input == 3) {
                direction_left = 1;
            } else if (input == 4) {
                direction_right = 1;
            }

            if (direction_up && rooms[current_room]->next->name[0]!= '\0') {
                current_room = (current_room == 0)? 1 : current_room - 1;
                display_room(rooms[current_room]);
            } else if (direction_down && rooms[current_room]->next->name[0]!= '\0') {
                current_room = (current_room == MAX_ROOM - 1)? MAX_ROOM - 2 : current_room + 1;
                display_room(rooms[current_room]);
            } else if (direction_left && rooms[current_room]->next->name[0]!= '\0') {
                current_room = (current_room == 0)? MAX_ROOM - 1 : current_room - 1;
                display_room(rooms[current_room]);
            } else if (direction_right && rooms[current_room]->next->name[0]!= '\0') {
                current_room = (current_room == MAX_ROOM - 1)? 0 : current_room + 1;
                display_room(rooms[current_room]);
            } else {
                printf("You can't go that way.\n");
            }
        }
    }

    return 0;
}