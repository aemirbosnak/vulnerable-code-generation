//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// define constant variables
#define FLOOR_MIN 1
#define FLOOR_MAX 10
#define ELEVATOR_CAPACITY 10

// define structs
typedef struct floor_node FloorNode;
typedef struct floor_node {
    int number;
    FloorNode* next;
    FloorNode* prev;
} FloorNode;

typedef struct elevator Elevator;
typedef struct elevator {
    int current_floor;
    int current_capacity;
    bool going_up;
    bool has_passengers;
    FloorNode* stops;
} Elevator;


// function prototypes
FloorNode* create_floor_node(int);
FloorNode* insert_floor_node(FloorNode*, int);
void display_floor_nodes(FloorNode*);
FloorNode* remove_floor_node(FloorNode*, int);
bool is_floor_in_list(FloorNode*, int);
Elevator* create_elevator();
void display_elevator_info(Elevator*);
void move_elevator(Elevator*);
bool check_elevator_stop(Elevator*);
void enter_elevator(Elevator*);
void exit_elevator(Elevator*);


int main() {
    // create floors
    FloorNode* floors = create_floor_node(1);
    for(int i = FLOOR_MIN+1; i <= FLOOR_MAX; i++) {
        floors = insert_floor_node(floors, i);
    }
    display_floor_nodes(floors);
    
    // create elevator
    Elevator* elevator = create_elevator();
    display_elevator_info(elevator);

    // elevator operation
    while(true) {
        // move elevator
        move_elevator(elevator);
        display_elevator_info(elevator);

        // check if elevator should stop on this floor
        if(check_elevator_stop(elevator)) {
            enter_elevator(elevator);
            exit_elevator(elevator);
        }
    }

    return 0;
}


FloorNode* create_floor_node(int number) {
    FloorNode* new_floor = (FloorNode*) malloc(sizeof(FloorNode));
    new_floor->number = number;
    new_floor->next = NULL;
    new_floor->prev = NULL;
    return new_floor;
}

FloorNode* insert_floor_node(FloorNode* head, int number) {
    FloorNode* new_floor = create_floor_node(number);
    if(head == NULL) {
        head = new_floor;
    } else {
        FloorNode* current = head;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = new_floor;
        new_floor->prev = current;
    }
    return head;
}

void display_floor_nodes(FloorNode* head) {
    printf("Floors: ");
    while(head != NULL) {
        printf("%d ", head->number);
        head = head->next;
    }
    printf("\n");
}

FloorNode* remove_floor_node(FloorNode* head, int number) {
    FloorNode* current = head;

    // check if head node should be removed
    if(head->number == number) {
        head = head->next;
        head->prev = NULL;
        free(current);
        return head;
    }

    while(current != NULL) {
        if(current->number == number) {
            if(current->next != NULL) {
                current->next->prev = current->prev;
            }
            current->prev->next = current->next;
            free(current);
            break;
        }
        current = current->next;
    }

    return head;
}

bool is_floor_in_list(FloorNode* head, int number) {
    while(head != NULL) {
        if(head->number == number) {
            return true;
        }
        head = head->next;
    }
    return false;
}

Elevator* create_elevator() {
    Elevator* new_elevator = (Elevator*) malloc(sizeof(Elevator));
    new_elevator->current_floor = 1;
    new_elevator->current_capacity = 0;
    new_elevator->going_up = true;
    new_elevator->has_passengers = false;
    new_elevator->stops = NULL;
    return new_elevator;
}

void display_elevator_info(Elevator* elevator) {
    printf("Elevator is at floor %d, going %s, has %d passengers\n", 
        elevator->current_floor, elevator->going_up ? "up" : "down", elevator->current_capacity);
}

void move_elevator(Elevator* elevator) {
    if(elevator->going_up) {
        // check if elevator is at top floor
        if(elevator->current_floor == FLOOR_MAX) {
            elevator->going_up = false;
        } else {
            elevator->current_floor++;
        }
    } else {
        // check if elevator is at bottom floor
        if(elevator->current_floor == FLOOR_MIN) {
            elevator->going_up = true;
        } else {
            elevator->current_floor--;
        }
    }
}

bool check_elevator_stop(Elevator* elevator) {
    // check if elevator has reached a stop
    if(elevator->stops != NULL && elevator->stops->number == elevator->current_floor) {
        return true;
    }
    return false;
}

void enter_elevator(Elevator* elevator) {
    // check if there are passengers waiting on this floor
    if(is_floor_in_list(elevator->stops, elevator->current_floor)) {
        return;
    }

    // check if there is enough capacity
    if(elevator->current_capacity == ELEVATOR_CAPACITY) {
        return;
    }

    // add stop
    elevator->stops = insert_floor_node(elevator->stops, elevator->current_floor);

    // update elevator information
    elevator->current_capacity++;
    elevator->has_passengers = true;
}

void exit_elevator(Elevator* elevator) {
    // check if elevator has passengers
    if(!elevator->has_passengers) {
        return;
    }

    // check if this floor is a stop
    if(!is_floor_in_list(elevator->stops, elevator->current_floor)) {
        return;
    }

    // remove stop
    elevator->stops = remove_floor_node(elevator->stops, elevator->current_floor);

    // update elevator information
    elevator->current_capacity--;
    if(elevator->current_capacity == 0) {
        elevator->has_passengers = false;
    }
}