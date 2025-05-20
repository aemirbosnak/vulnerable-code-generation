//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Baggage item struct
typedef struct baggage_item {
    int id;
    char *flight_number;
    char *destination;
    time_t arrival_time;
    struct baggage_item *next;
} baggage_item;

// Baggage carousel struct
typedef struct baggage_carousel {
    int id;
    int capacity;
    int num_items;
    baggage_item *head;
    baggage_item *tail;
} baggage_carousel;

// Airport struct
typedef struct airport {
    int num_carousels;
    baggage_carousel *carousels;
} airport;

// Function to create a new airport
airport *create_airport(int num_carousels) {
    airport *new_airport = malloc(sizeof(airport));
    new_airport->num_carousels = num_carousels;
    new_airport->carousels = malloc(sizeof(baggage_carousel) * num_carousels);
    for (int i = 0; i < num_carousels; i++) {
        new_airport->carousels[i].id = i + 1;
        new_airport->carousels[i].capacity = 10;
        new_airport->carousels[i].num_items = 0;
        new_airport->carousels[i].head = NULL;
        new_airport->carousels[i].tail = NULL;
    }
    return new_airport;
}

// Function to create a new baggage item
baggage_item *create_baggage_item(char *flight_number, char *destination) {
    baggage_item *new_item = malloc(sizeof(baggage_item));
    new_item->id = rand() % 1000 + 1;
    new_item->flight_number = strdup(flight_number);
    new_item->destination = strdup(destination);
    new_item->arrival_time = time(NULL);
    new_item->next = NULL;
    return new_item;
}

// Function to add a baggage item to a carousel
void add_baggage_item_to_carousel(baggage_carousel *carousel, baggage_item *item) {
    if (carousel->num_items == carousel->capacity) {
        printf("Carousel is full, cannot add item\n");
        return;
    }
    if (carousel->head == NULL) {
        carousel->head = item;
        carousel->tail = item;
    } else {
        carousel->tail->next = item;
        carousel->tail = item;
    }
    carousel->num_items++;
}

// Function to remove a baggage item from a carousel
baggage_item *remove_baggage_item_from_carousel(baggage_carousel *carousel) {
    if (carousel->num_items == 0) {
        return NULL;
    }
    baggage_item *item = carousel->head;
    carousel->head = carousel->head->next;
    if (carousel->head == NULL) {
        carousel->tail = NULL;
    }
    carousel->num_items--;
    return item;
}

// Function to print the contents of a carousel
void print_carousel(baggage_carousel *carousel) {
    printf("Carousel %d:\n", carousel->id);
    baggage_item *item = carousel->head;
    while (item != NULL) {
        printf("\tBaggage item %d: %s (%s)\n", item->id, item->flight_number, item->destination);
        item = item->next;
    }
}

// Main function
int main() {
    // Create an airport with 5 carousels
    airport *my_airport = create_airport(5);

    // Create some baggage items
    baggage_item *item1 = create_baggage_item("AA123", "New York");
    baggage_item *item2 = create_baggage_item("UA456", "San Francisco");
    baggage_item *item3 = create_baggage_item("DL789", "Los Angeles");
    baggage_item *item4 = create_baggage_item("WN1010", "Denver");
    baggage_item *item5 = create_baggage_item("B61212", "Boston");

    // Add the baggage items to the carousels
    add_baggage_item_to_carousel(&my_airport->carousels[0], item1);
    add_baggage_item_to_carousel(&my_airport->carousels[1], item2);
    add_baggage_item_to_carousel(&my_airport->carousels[2], item3);
    add_baggage_item_to_carousel(&my_airport->carousels[3], item4);
    add_baggage_item_to_carousel(&my_airport->carousels[4], item5);

    // Print the contents of each carousel
    for (int i = 0; i < my_airport->num_carousels; i++) {
        print_carousel(&my_airport->carousels[i]);
    }

    // Remove an item from each carousel
    baggage_item *removed_item1 = remove_baggage_item_from_carousel(&my_airport->carousels[0]);
    baggage_item *removed_item2 = remove_baggage_item_from_carousel(&my_airport->carousels[1]);
    baggage_item *removed_item3 = remove_baggage_item_from_carousel(&my_airport->carousels[2]);
    baggage_item *removed_item4 = remove_baggage_item_from_carousel(&my_airport->carousels[3]);
    baggage_item *removed_item5 = remove_baggage_item_from_carousel(&my_airport->carousels[4]);

    // Print the removed items
    printf("Removed items:\n");
    printf("\tBaggage item %d: %s (%s)\n", removed_item1->id, removed_item1->flight_number, removed_item1->destination);
    printf("\tBaggage item %d: %s (%s)\n", removed_item2->id, removed_item2->flight_number, removed_item2->destination);
    printf("\tBaggage item %d: %s (%s)\n", removed_item3->id, removed_item3->flight_number, removed_item3->destination);
    printf("\tBaggage item %d: %s (%s)\n", removed_item4->id, removed_item4->flight_number, removed_item4->destination);
    printf("\tBaggage item %d: %s (%s)\n", removed_item5->id, removed_item5->flight_number, removed_item5->destination);

    // Free the memory allocated for the baggage items and the airport
    free(item1);
    free(item2);
    free(item3);
    free(item4);
    free(item5);
    free(removed_item1);
    free(removed_item2);
    free(removed_item3);
    free(removed_item4);
    free(removed_item5);
    free(my_airport->carousels);
    free(my_airport);

    return 0;
}