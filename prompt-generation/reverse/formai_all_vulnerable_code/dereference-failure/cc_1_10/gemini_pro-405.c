//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

#define MAX_DEVICES 10
#define MAX_USERS 10
#define MAX_ACTIONS 10
#define MAX_ROOMS 10

typedef struct {
    int id;
    char *name;
    int room_id;
    bool state;
} device_t;

typedef struct {
    int id;
    char *name;
    char *password;
    int room_id;
} user_t;

typedef struct {
    int id;
    char *name;
    char *description;
} action_t;

typedef struct {
    int id;
    char *name;
    device_t *devices[MAX_DEVICES];
    int num_devices;
} room_t;

typedef struct {
    device_t *devices[MAX_DEVICES];
    int num_devices;
    user_t *users[MAX_USERS];
    int num_users;
    action_t *actions[MAX_ACTIONS];
    int num_actions;
    room_t *rooms[MAX_ROOMS];
    int num_rooms;
} home_t;

home_t home;

void init_home() {
    home.num_devices = 0;
    home.num_users = 0;
    home.num_actions = 0;
    home.num_rooms = 0;
}

void add_device(device_t *device) {
    if (home.num_devices >= MAX_DEVICES) {
        fprintf(stderr, "Error: Maximum number of devices reached.\n");
        return;
    }

    home.devices[home.num_devices++] = device;
}

void add_user(user_t *user) {
    if (home.num_users >= MAX_USERS) {
        fprintf(stderr, "Error: Maximum number of users reached.\n");
        return;
    }

    home.users[home.num_users++] = user;
}

void add_action(action_t *action) {
    if (home.num_actions >= MAX_ACTIONS) {
        fprintf(stderr, "Error: Maximum number of actions reached.\n");
        return;
    }

    home.actions[home.num_actions++] = action;
}

void add_room(room_t *room) {
    if (home.num_rooms >= MAX_ROOMS) {
        fprintf(stderr, "Error: Maximum number of rooms reached.\n");
        return;
    }

    home.rooms[home.num_rooms++] = room;
}

void print_home() {
    int i;

    printf("Devices:\n");
    for (i = 0; i < home.num_devices; i++) {
        printf("\t%d: %s (%s)\n", home.devices[i]->id, home.devices[i]->name, home.devices[i]->state ? "on" : "off");
    }

    printf("Users:\n");
    for (i = 0; i < home.num_users; i++) {
        printf("\t%d: %s (%s)\n", home.users[i]->id, home.users[i]->name, home.users[i]->password);
    }

    printf("Actions:\n");
    for (i = 0; i < home.num_actions; i++) {
        printf("\t%d: %s (%s)\n", home.actions[i]->id, home.actions[i]->name, home.actions[i]->description);
    }

    printf("Rooms:\n");
    for (i = 0; i < home.num_rooms; i++) {
        printf("\t%d: %s (%d devices)\n", home.rooms[i]->id, home.rooms[i]->name, home.rooms[i]->num_devices);
    }
}

int main() {
    device_t *device1 = malloc(sizeof(device_t));
    device1->id = 1;
    device1->name = "Light 1";
    device1->room_id = 1;
    device1->state = false;

    device_t *device2 = malloc(sizeof(device_t));
    device2->id = 2;
    device2->name = "Light 2";
    device2->room_id = 1;
    device2->state = false;

    user_t *user1 = malloc(sizeof(user_t));
    user1->id = 1;
    user1->name = "John Doe";
    user1->password = "password";
    user1->room_id = 1;

    action_t *action1 = malloc(sizeof(action_t));
    action1->id = 1;
    action1->name = "Turn on lights";
    action1->description = "Turns on all the lights in the room.";

    room_t *room1 = malloc(sizeof(room_t));
    room1->id = 1;
    room1->name = "Living room";
    room1->devices[0] = device1;
    room1->devices[1] = device2;
    room1->num_devices = 2;

    init_home();
    add_device(device1);
    add_device(device2);
    add_user(user1);
    add_action(action1);
    add_room(room1);

    print_home();

    return 0;
}