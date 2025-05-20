//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_GUESTS 2

typedef struct Room {
  int room_no;
  char status;
  char guest_name[MAX_GUESTS];
  struct Room* next;
} Room;

typedef struct Hotel {
  Room* head;
  int num_rooms;
  int num_guests;
} Hotel;

Hotel* create_hotel() {
  Hotel* h = malloc(sizeof(Hotel));
  h->head = NULL;
  h->num_rooms = 0;
  h->num_guests = 0;
  return h;
}

void add_room(Hotel* h) {
  Room* r = malloc(sizeof(Room));
  r->room_no = h->num_rooms + 1;
  r->status = 'O';
  r->guest_name[0] = '\0';
  r->next = h->head;
  h->head = r;
  h->num_rooms++;
}

void add_guest(Hotel* h, char* name) {
  Room* r = h->head;
  while (r) {
    if (r->status == 'O' && strcmp(r->guest_name, name) == 0) {
      strcpy(r->guest_name, name);
      h->num_guests++;
      return;
    }
    r = r->next;
  }
  printf("No room available for guest.\n");
}

int main() {
  Hotel* h = create_hotel();
  add_room(h);
  add_room(h);
  add_guest(h, "John Doe");
  add_guest(h, "Jane Doe");
  add_guest(h, "Peter Pan");

  Room* r = h->head;
  while (r) {
    printf("Room No.: %d, Status: %c, Guest Name: %s\n", r->room_no, r->status, r->guest_name);
    r = r->next;
  }

  return 0;
}