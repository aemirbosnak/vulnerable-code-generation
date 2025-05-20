//GPT-4o-mini DATASET v1.0 Category: Smart home light control ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int is_on;
} Light;

typedef struct {
    char name[20];
    Light *lights;
    int light_count;
} Room;

void toggle_light(Light *light) {
    light->is_on = !light->is_on;
}

void print_light_status(Light *light) {
    printf("Light %s is %s\n", light->name, light->is_on ? "ON" : "OFF");
}

void print_room_status(Room *room) {
    printf("Status of room: %s\n", room->name);
    for (int i = 0; i < room->light_count; i++) {
        print_light_status(&room->lights[i]);
    }
}

Room* create_room(const char *name, int light_count) {
    Room *room = (Room *)malloc(sizeof(Room));
    strcpy(room->name, name);
    room->light_count = light_count;
    room->lights = (Light *)malloc(sizeof(Light) * light_count);
    
    for (int i = 0; i < light_count; i++) {
        sprintf(room->lights[i].name, "Light%d", i + 1);
        room->lights[i].is_on = 0; // Initialize lights to OFF
    }
    
    return room;
}

void free_room(Room *room) {
    free(room->lights);
    free(room);
}

int main() {
    int room_count = 3;
    Room **rooms = (Room **)malloc(sizeof(Room *) * room_count);
    rooms[0] = create_room("Living Room", 3);
    rooms[1] = create_room("Kitchen", 2);
    rooms[2] = create_room("Bedroom", 4);

    int choice, room_num, light_num;

    do {
        printf("\nSmart Home Light Control System\n");
        printf("1. Toggle a Light\n");
        printf("2. Get Room Status\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Choose a room (1-%d): ", room_count);
                scanf("%d", &room_num);
                if (room_num < 1 || room_num > room_count) {
                    printf("Invalid room number!\n");
                    break;
                }
                printf("Choose a light (1-%d): ", rooms[room_num - 1]->light_count);
                scanf("%d", &light_num);
                if (light_num < 1 || light_num > rooms[room_num - 1]->light_count) {
                    printf("Invalid light number!\n");
                    break;
                }
                toggle_light(&rooms[room_num - 1]->lights[light_num - 1]);
                printf("Toggled %s\n", rooms[room_num - 1]->lights[light_num - 1].name);
                break;
                
            case 2:
                printf("Choose a room (1-%d): ", room_count);
                scanf("%d", &room_num);
                if (room_num < 1 || room_num > room_count) {
                    printf("Invalid room number!\n");
                    break;
                }
                print_room_status(rooms[room_num - 1]);
                break;

            case 3:
                printf("Exiting the program.\n");
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 3);
    
    for (int i = 0; i < room_count; i++) {
        free_room(rooms[i]);
    }
    free(rooms);
    
    return 0;
}