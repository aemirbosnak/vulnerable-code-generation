//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct guest{
    char name[50];
    char address[100];
    char phone[20];
    char email[50];
    int room_number;
    int nights_staying;
    float bill_amount;
};

struct hotel{
    char name[50];
    char address[100];
    char phone[20];
    char email[50];
    int num_rooms;
    struct guest *guests;
};

struct hotel *create_hotel(char *name, char *address, char *phone, char *email, int num_rooms){
    struct hotel *h = (struct hotel *)malloc(sizeof(struct hotel));
    strcpy(h->name, name);
    strcpy(h->address, address);
    strcpy(h->phone, phone);
    strcpy(h->email, email);
    h->num_rooms = num_rooms;
    h->guests = (struct guest *)malloc(num_rooms * sizeof(struct guest));
    return h;
}

void add_guest(struct hotel *h, struct guest *g){
    for(int i = 0; i < h->num_rooms; i++){
        if(h->guests[i].room_number == 0){
            h->guests[i] = *g;
            return;
        }
    }
    printf("No rooms available\n");
}

void remove_guest(struct hotel *h, int room_number){
    for(int i = 0; i < h->num_rooms; i++){
        if(h->guests[i].room_number == room_number){
            h->guests[i].room_number = 0;
            return;
        }
    }
    printf("No guest found in room %d\n", room_number);
}

void print_guest(struct guest *g){
    printf("Name: %s\n", g->name);
    printf("Address: %s\n", g->address);
    printf("Phone: %s\n", g->phone);
    printf("Email: %s\n", g->email);
    printf("Room number: %d\n", g->room_number);
    printf("Nights staying: %d\n", g->nights_staying);
    printf("Bill amount: %.2f\n", g->bill_amount);
}

void print_hotel(struct hotel *h){
    printf("Name: %s\n", h->name);
    printf("Address: %s\n", h->address);
    printf("Phone: %s\n", h->phone);
    printf("Email: %s\n", h->email);
    printf("Number of rooms: %d\n", h->num_rooms);
    for(int i = 0; i < h->num_rooms; i++){
        if(h->guests[i].room_number != 0){
            print_guest(&h->guests[i]);
        }
    }
}

int main(){
    struct guest g1 = {"John Doe", "123 Main Street", "555-1212", "john.doe@email.com", 101, 3, 150.00};
    struct guest g2 = {"Jane Doe", "456 Elm Street", "555-2323", "jane.doe@email.com", 102, 2, 100.00};
    struct hotel *h = create_hotel("The Grand Hotel", "789 Park Avenue", "555-3434", "the.grand.hotel@email.com", 10);
    add_guest(h, &g1);
    add_guest(h, &g2);
    print_hotel(h);
    remove_guest(h, 102);
    print_hotel(h);
    return 0;
}