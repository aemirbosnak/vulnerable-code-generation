//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_GUESTS 100

typedef struct {
    char name[50];
    int roomNumber;
    char checkInDate[20];
    char checkOutDate[20];
} Guest;

typedef struct {
    char roomNumber[10];
    char roomType[20];
    int rate;
} Room;

typedef struct {
    int totalGuests;
    int totalRooms;
    int totalRevenue;
} Hotel;

Guest* createGuest() {
    Guest* g = (Guest*) malloc(sizeof(Guest));
    strcpy(g->name, "");
    g->roomNumber = -1;
    strcpy(g->checkInDate, "");
    strcpy(g->checkOutDate, "");
    return g;
}

void destroyGuest(Guest* g) {
    free(g);
}

Room* createRoom() {
    Room* r = (Room*) malloc(sizeof(Room));
    strcpy(r->roomNumber, "");
    strcpy(r->roomType, "");
    r->rate = -1;
    return r;
}

void destroyRoom(Room* r) {
    free(r);
}

Hotel* createHotel() {
    Hotel* h = (Hotel*) malloc(sizeof(Hotel));
    h->totalGuests = 0;
    h->totalRooms = 0;
    h->totalRevenue = 0;
    return h;
}

void destroyHotel(Hotel* h) {
    free(h);
}

int main() {
    srand(time(NULL));
    Hotel* h = createHotel();
    for (int i = 0; i < MAX_ROOMS; i++) {
        Room* r = createRoom();
        r->rate = rand() % 100 + 1;
        printf("Created room %d with rate %d\n", i, r->rate);
        destroyRoom(r);
    }
    for (int i = 0; i < MAX_GUESTS; i++) {
        Guest* g = createGuest();
        strcpy(g->name, "Guest ");
        strcat(g->name, (char*) malloc(10 * sizeof(char)));
        g->checkInDate[0] = '0' + rand() % 10;
        g->checkInDate[1] = '0' + rand() % 10;
        g->checkInDate[2] = '0' + rand() % 10;
        g->checkInDate[3] = '0' + rand() % 10;
        g->checkInDate[4] = '0' + rand() % 10;
        g->checkInDate[5] = '0' + rand() % 10;
        g->checkInDate[6] = '0' + rand() % 10;
        g->checkInDate[7] = '0' + rand() % 10;
        g->checkInDate[8] = '0' + rand() % 10;
        g->checkInDate[9] = '0' + rand() % 10;
        g->checkOutDate[0] = '0' + rand() % 10;
        g->checkOutDate[1] = '0' + rand() % 10;
        g->checkOutDate[2] = '0' + rand() % 10;
        g->checkOutDate[3] = '0' + rand() % 10;
        g->checkOutDate[4] = '0' + rand() % 10;
        g->checkOutDate[5] = '0' + rand() % 10;
        g->checkOutDate[6] = '0' + rand() % 10;
        g->checkOutDate[7] = '0' + rand() % 10;
        g->checkOutDate[8] = '0' + rand() % 10;
        g->checkOutDate[9] = '0' + rand() % 10;
        printf("Created guest %d with check-in date %s and check-out date %s\n", i, g->checkInDate, g->checkOutDate);
        destroyGuest(g);
    }
    destroyHotel(h);
    return 0;
}