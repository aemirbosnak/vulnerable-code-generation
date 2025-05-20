//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Structure for baggage
struct baggage {
    int id;
    char destination[20];
};

// Function to generate random ID
void generate_id(int *id) {
    *id = rand() % 1000;
}

// Function to generate random destination
void generate_destination(char *destination) {
    strcpy(destination, "City");
    int len = strlen(destination);
    for (int i = 0; i < 3; i++) {
        int rand_num = rand() % 26;
        char rand_char = (char) (rand_num + 'A');
        destination[len + i] = rand_char;
    }
}

// Function to print baggage details
void print_baggage(struct baggage *baggage) {
    printf("Baggage ID: %d\n", baggage->id);
    printf("Destination: %s\n", baggage->destination);
}

// Function to simulate baggage handling
void baggage_handling(struct baggage *baggage, int num_baggage) {
    srand(time(NULL));
    for (int i = 0; i < num_baggage; i++) {
        generate_id(&baggage[i].id);
        generate_destination(baggage[i].destination);
    }
    printf("Baggage Handling Simulation\n");
    printf("=================================\n");
    for (int i = 0; i < num_baggage; i++) {
        print_baggage(&baggage[i]);
    }
}

int main() {
    int num_baggage;
    printf("Enter the number of baggage: ");
    scanf("%d", &num_baggage);
    struct baggage baggage[num_baggage];
    baggage_handling(baggage, num_baggage);
    return 0;
}