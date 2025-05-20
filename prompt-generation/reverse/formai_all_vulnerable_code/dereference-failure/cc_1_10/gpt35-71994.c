//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: enthusiastic
//Welcome to the Elevator Simulation program!
//This program simulates an elevator with 4 floors and 1 elevator.
//The elevator moves up and down based on user input.
//Let's get started!

#include <stdio.h>
#include <stdlib.h>

#define FLOORS 4    //number of floors in the building
#define MAX_PEOPLE 10   //maximum number of people allowed in the elevator
#define WAIT_TIME 5 //time for elevator to wait at a floor (in seconds)

typedef struct {
    int floor;      //current floor of person
    int dest_floor; //destination floor of person
} Person;

typedef struct {
    int curr_floor; //current floor of the elevator
    int num_people; //number of people in elevator
    Person people[MAX_PEOPLE];  //list of people in elevator
} Elevator;

//function to print the current status of the elevator
void print_status(Elevator *e) {
    printf("Elevator is currently at floor %d with %d people: ", e->curr_floor, e->num_people);
    for(int i=0; i<e->num_people; i++) {
        printf("{ Floor: %d, Destination: %d }", e->people[i].floor, e->people[i].dest_floor);
        if(i != e->num_people-1) {
            printf(", ");
        }
    }
    printf("\n");
}

//function to move the elevator up one floor
void move_up(Elevator *e) {
    if(e->curr_floor < FLOORS) {
        e->curr_floor++;
        printf("Elevator is moving up to floor %d\n", e->curr_floor);
    }
}

//function to move the elevator down one floor
void move_down(Elevator *e) {
    if(e->curr_floor > 1) {
        e->curr_floor--;
        printf("Elevator is moving down to floor %d\n", e->curr_floor);
    }
}

//function to add a person to the elevator
void add_person(Elevator *e, int floor, int dest_floor) {
    if(e->num_people < MAX_PEOPLE) {
        Person p = { floor, dest_floor };
        e->people[e->num_people] = p;
        e->num_people++;
        printf("Person added to elevator.\n");
    } else {
        printf("Elevator is at maximum capacity.\n");
    }
}

//function to remove a person from the elevator
void remove_person(Elevator *e, int index) {
    for(int i=index; i<e->num_people-1; i++) {
        e->people[i] = e->people[i+1];
    }
    e->num_people--;
    printf("Person removed from elevator.\n");
}

int main() {
    Elevator e = { 1, 0, {} };  //initialize elevator at ground floor with no people
    int choice, floor, dest_floor, person_index;

    printf("Welcome to the Elevator Simulation!\n");

    do {
        printf("\nCurrent Status:\n");
        print_status(&e);

        //ask user for input
        printf("\nEnter a choice:\n");
        printf("1. Move elevator up\n");
        printf("2. Move elevator down\n");
        printf("3. Add person to elevator\n");
        printf("4. Remove person from elevator\n");
        printf("5. Quit program\n");
        printf("Choice: ");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                move_up(&e);
                break;
            case 2:
                move_down(&e);
                break;
            case 3:
                printf("Enter person's current floor: ");
                scanf("%d", &floor);
                printf("Enter person's destination floor: ");
                scanf("%d", &dest_floor);
                add_person(&e, floor, dest_floor);
                break;
            case 4:
                printf("Enter index of person to remove: ");
                scanf("%d", &person_index);
                remove_person(&e, person_index);
                break;
            case 5:
                printf("Thank you for using the Elevator Simulation!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        //wait for elevator to reach floor
        printf("Waiting at floor %d...\n", e.curr_floor);
        sleep(WAIT_TIME);

        //remove people who have reached their destination
        for(int i=0; i<e.num_people; i++) {
            if(e.people[i].dest_floor == e.curr_floor) {
                remove_person(&e, i);
            }
        }
    } while(choice != 5);

    return 0;
}