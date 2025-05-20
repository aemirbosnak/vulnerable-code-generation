//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for map size
#define MAP_WIDTH 50
#define MAP_HEIGHT 25

// Define constants for room and corridor size
#define ROOM_MIN_SIZE 3
#define ROOM_MAX_SIZE 8
#define MAX_ROOMS 10
#define CORRIDOR_WIDTH 3

// Define structs for tiles, rooms, and corridors
struct Tile {
    int x, y;
    int type;   // 0 = wall, 1 = floor
};
typedef struct Tile Tile;

struct Room {
    int x, y;
    int width, height;
};
typedef struct Room Room;

struct Corridor {
    int start_x, start_y;
    int end_x, end_y;
};
typedef struct Corridor Corridor;

// Prototypes for functions
void init_map(Tile* map[MAP_HEIGHT][MAP_WIDTH]);
void print_map(Tile* map[MAP_HEIGHT][MAP_WIDTH]);
void create_room(Tile* map[MAP_HEIGHT][MAP_WIDTH], Room room);
void create_corridor(Tile* map[MAP_HEIGHT][MAP_WIDTH], Corridor corridor);
int get_random_int(int min, int max);

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Create the map
    Tile* map[MAP_HEIGHT][MAP_WIDTH];
    init_map(map);
    
    // Create rooms and corridors
    Room rooms[MAX_ROOMS];
    Corridor corridors[MAX_ROOMS-1];
    int num_rooms = 0;
    int num_corridors = 0;
    
    for (int i = 0; i < MAX_ROOMS; i++) {
        // Get random position and size for room
        int x = get_random_int(0, MAP_WIDTH - ROOM_MAX_SIZE);
        int y = get_random_int(0, MAP_HEIGHT - ROOM_MAX_SIZE);
        int width = get_random_int(ROOM_MIN_SIZE, ROOM_MAX_SIZE);
        int height = get_random_int(ROOM_MIN_SIZE, ROOM_MAX_SIZE);
        
        // Check if room overlaps with any existing rooms
        int is_overlapping = 0;
        for (int j = 0; j < num_rooms; j++) {
            if (x < rooms[j].x + rooms[j].width &&
                x + width > rooms[j].x &&
                y < rooms[j].y + rooms[j].height &&
                y + height > rooms[j].y) {
                is_overlapping = 1;
                break;
            }
        }
        if (is_overlapping) {
            continue;
        }
        
        // Create the room
        Room room = {x, y, width, height};
        create_room(map, room);
        rooms[num_rooms] = room;
        num_rooms++;
        
        // Create corridor to connect to previous room
        if (num_rooms > 1) {
            int prev_x = rooms[num_rooms-2].x + rooms[num_rooms-2].width/2;
            int prev_y = rooms[num_rooms-2].y + rooms[num_rooms-2].height/2;
            int curr_x = rooms[num_rooms-1].x + rooms[num_rooms-1].width/2;
            int curr_y = rooms[num_rooms-1].y + rooms[num_rooms-1].height/2;
            
            Corridor corridor;
            if (get_random_int(0, 1) == 0) {
                corridor.start_x = prev_x;
                corridor.start_y = prev_y;
                corridor.end_x = curr_x;
                corridor.end_y = curr_y;
            } else {
                corridor.start_x = prev_x;
                corridor.start_y = curr_y;
                corridor.end_x = curr_x;
                corridor.end_y = prev_y;
            }
            create_corridor(map, corridor);
            corridors[num_corridors] = corridor;
            num_corridors++;
        }
    }
    
    // Print the map
    print_map(map);
    
    return 0;
}

// Function to initialize the map with walls
void init_map(Tile* map[MAP_HEIGHT][MAP_WIDTH]) {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            Tile* tile = malloc(sizeof(Tile));
            tile->x = x;
            tile->y = y;
            tile->type = 0;
            map[y][x] = tile;
        }
    }
}

// Function to print the map
void print_map(Tile* map[MAP_HEIGHT][MAP_WIDTH]) {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            printf("%c", map[y][x]->type == 0 ? '#' : '.');
        }
        printf("\n");
    }
}

// Function to create a room
void create_room(Tile* map[MAP_HEIGHT][MAP_WIDTH], Room room) {
    for (int y = room.y; y < room.y + room.height; y++) {
        for (int x = room.x; x < room.x + room.width; x++) {
            map[y][x]->type = 1;
        }
    }
}

// Function to create a corridor
void create_corridor(Tile* map[MAP_HEIGHT][MAP_WIDTH], Corridor corridor) {
    if (corridor.start_x == corridor.end_x) {
        // Vertical corridor
        int start_y = corridor.start_y < corridor.end_y ? corridor.start_y : corridor.end_y;
        int end_y = corridor.start_y > corridor.end_y ? corridor.start_y : corridor.end_y;
        for (int y = start_y; y <= end_y; y++) {
            for (int x = corridor.start_x - CORRIDOR_WIDTH/2; x <= corridor.start_x + CORRIDOR_WIDTH/2; x++) {
                map[y][x]->type = 1;
            }
        }
    } else {
        // Horizontal corridor
        int start_x = corridor.start_x < corridor.end_x ? corridor.start_x : corridor.end_x;
        int end_x = corridor.start_x > corridor.end_x ? corridor.start_x : corridor.end_x;
        for (int x = start_x; x <= end_x; x++) {
            for (int y = corridor.start_y - CORRIDOR_WIDTH/2; y <= corridor.start_y + CORRIDOR_WIDTH/2; y++) {
                map[y][x]->type = 1;
            }
        }
    }
}

// Function to get a random integer in a range
int get_random_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}