//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: innovative
// Welcome to the Smart Home Automation Hub!

#include <stdio.h>
#include <stdlib.h>

// Data declarations
enum appliance_type { LIGHT, FAN, AC };
struct appliance {
    enum appliance_type type;
    char *name;
    int power_consumption;
    int status; // 0 = off, 1 = on
};
struct room {
    char *name;
    struct appliance *appliances;
    int num_appliances;
};

// Function declarations
void create_home(struct room **home, int num_rooms);
void create_room(struct room *room, char *name);
void create_appliance(struct room *room, struct appliance *appliance, enum appliance_type type, char *name, int power_consumption);
void print_home(struct room *home, int num_rooms);
void toggle_appliance(struct appliance *appliance);
void turn_on_all_appliances(struct room *room);
void turn_off_all_appliances(struct room *room);

int main() {
    // Create the Smart Home
    struct room *home;
    create_home(&home, 3);

    // Create the rooms
    create_room(&home[0], "Living Room");
    create_room(&home[1], "Bedroom");
    create_room(&home[2], "Kitchen");

    // Create the appliances
    create_appliance(&home[0], &home[0].appliances[0], LIGHT, "Living Room Light", 10);
    create_appliance(&home[0], &home[0].appliances[1], FAN, "Living Room Fan", 20);
    create_appliance(&home[0], &home[0].appliances[2], AC, "Living Room AC", 100);

    create_appliance(&home[1], &home[1].appliances[0], LIGHT, "Bedroom Light", 10);
    create_appliance(&home[1], &home[1].appliances[1], FAN, "Bedroom Fan", 20);

    create_appliance(&home[2], &home[2].appliances[0], LIGHT, "Kitchen Light", 10);
    create_appliance(&home[2], &home[2].appliances[1], AC, "Kitchen AC", 100);

    // Print the Smart Home
    print_home(home, 3);

    // Toggle the Living Room Light
    toggle_appliance(&home[0].appliances[0]);

    // Turn on all appliances in the Bedroom
    turn_on_all_appliances(&home[1]);

    // Turn off all appliances in the Kitchen
    turn_off_all_appliances(&home[2]);

    // Print the updated Smart Home
    print_home(home, 3);

    // Free the memory
    for (int i = 0; i < 3; i++) {
        free(home[i].name);
        for (int j = 0; j < home[i].num_appliances; j++) {
            free(home[i].appliances[j].name);
        }
        free(home[i].appliances);
    }
    free(home);

    return 0;
}

void create_home(struct room **home, int num_rooms) {
    *home = (struct room *)malloc(sizeof(struct room) * num_rooms);
    for (int i = 0; i < num_rooms; i++) {
        home[i]->name = NULL;
        home[i]->appliances = NULL;
        home[i]->num_appliances = 0;
    }
}

void create_room(struct room *room, char *name) {
    room->name = (char *)malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(room->name, name);
}

void create_appliance(struct room *room, struct appliance *appliance, enum appliance_type type, char *name, int power_consumption) {
    room->num_appliances++;
    room->appliances = (struct appliance *)realloc(room->appliances, sizeof(struct appliance) * room->num_appliances);
    appliance->type = type;
    appliance->name = (char *)malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(appliance->name, name);
    appliance->power_consumption = power_consumption;
    appliance->status = 0;
}

void print_home(struct room *home, int num_rooms) {
    for (int i = 0; i < num_rooms; i++) {
        printf("Room: %s\n", home[i].name);
        for (int j = 0; j < home[i].num_appliances; j++) {
            printf("\t%s: %s - %s - %d watts\n", home[i].appliances[j].name,
                   home[i].appliances[j].status ? "On" : "Off",
                   home[i].appliances[j].type == LIGHT ? "Light" :
                   home[i].appliances[j].type == FAN ? "Fan" : "AC",
                   home[i].appliances[j].power_consumption);
        }
    }
}

void toggle_appliance(struct appliance *appliance) {
    appliance->status = !appliance->status;
}

void turn_on_all_appliances(struct room *room) {
    for (int i = 0; i < room->num_appliances; i++) {
        room->appliances[i].status = 1;
    }
}

void turn_off_all_appliances(struct room *room) {
    for (int i = 0; i < room->num_appliances; i++) {
        room->appliances[i].status = 0;
    }
}