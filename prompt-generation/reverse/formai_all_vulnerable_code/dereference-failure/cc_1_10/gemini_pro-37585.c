//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LENGTH 50

typedef struct hotel {
    char name[MAX_NAME_LENGTH];
    int num_rooms;
    struct hotel *next;
} hotel_t;

hotel_t *create_hotel(char *name, int num_rooms) {
    hotel_t *new_hotel = malloc(sizeof(hotel_t));
    if (new_hotel == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    strcpy(new_hotel->name, name);
    new_hotel->num_rooms = num_rooms;
    new_hotel->next = NULL;
    return new_hotel;
}

void add_hotel(hotel_t **head, hotel_t *new_hotel) {
    if (*head == NULL) {
        *head = new_hotel;
    } else {
        add_hotel(&(*head)->next, new_hotel);
    }
}

hotel_t *find_hotel_by_name(hotel_t *head, char *name) {
    if (head == NULL) {
        return NULL;
    } else if (strcmp(head->name, name) == 0) {
        return head;
    } else {
        return find_hotel_by_name(head->next, name);
    }
}

void print_hotels(hotel_t *head) {
    if (head == NULL) {
        printf("No hotels to print.\n");
    } else {
        printf("%s (%d rooms)\n", head->name, head->num_rooms);
        print_hotels(head->next);
    }
}

void free_hotels(hotel_t *head) {
    if (head == NULL) {
        return;
    } else {
        free_hotels(head->next);
        free(head);
    }
}

int main() {
    hotel_t *head = NULL;  
    add_hotel(&head, create_hotel("Hilton", 100));
    add_hotel(&head, create_hotel("Marriott", 200));
    add_hotel(&head, create_hotel("Hyatt", 300));
    print_hotels(head);
    printf("Searching for hotel named 'Marriott':\n");
    hotel_t *found_hotel = find_hotel_by_name(head, "Marriott");
    if (found_hotel != NULL) {
        printf("Found hotel '%s' with %d rooms.\n", found_hotel->name, found_hotel->num_rooms);
    } else {
        printf("No hotel found with the name 'Marriott'.\n");
    }
    free_hotels(head);
    return 0;
}