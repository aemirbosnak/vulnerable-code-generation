//MISTRAL-7B DATASET v1.0 Category: Elevator Simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct {
    int floor;
    bool direction;
    struct Node* next;
} Command;

typedef struct {
    int current_floor;
    Command* commands;
    size_t capacity;
    size_t size;
} Elevator;

void print_elevator(const Elevator* elevator) {
    printf("Elevator: Current floor %d\n", elevator->current_floor);
    printf("Commands: ");
    Command* command = elevator->commands;
    while (command != NULL) {
        printf("(%d, %d) ", command->floor, command->direction);
        command = command->next;
    }
    printf("\n");
}

void add_command(Elevator* elevator, int floor, bool direction) {
    Command* new_command = (Command*)malloc(sizeof(Command));
    new_command->floor = floor;
    new_command->direction = direction;
    new_command->next = elevator->commands;
    elevator->commands = new_command;
    elevator->size++;

    if (elevator->size >= elevator->capacity) {
        elevator->capacity *= 2;
        elevator->commands = realloc(elevator->commands, elevator->capacity * sizeof(Command));
    }
}

void execute_commands(Elevator* elevator) {
    Command* command = elevator->commands;

    while (command != NULL) {
        if (command->floor == elevator->current_floor) {
            if (command->direction) {
                if (elevator->current_floor < 12) {
                    elevator->current_floor++;
                }
            } else {
                if (elevator->current_floor > 1) {
                    elevator->current_floor--;
                }
            }
        }

        command = command->next;
    }
}

void elevator_main(int* args, int argc) {
    Elevator elevator = { .current_floor = 1, .capacity = 16, .commands = NULL };

    // Add commands
    add_command(&elevator, 3, true);
    add_command(&elevator, 7, false);
    add_command(&elevator, 1, true);
    add_command(&elevator, 10, false);

    // Print initial state
    print_elevator(&elevator);

    // Execute commands
    execute_commands(&elevator);

    // Print final state
    print_elevator(&elevator);

    free(elevator.commands);
}

int main(int argc, char* argv[]) {
    int* args = (int*)calloc(argc, sizeof(int));
    for (int i = 0; i < argc; i++) {
        args[i] = atoi(argv[i]);
    }
    elevator_main(args, argc);
    free(args);
    return 0;
}