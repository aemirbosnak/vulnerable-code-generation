//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: Alan Turing
#include <stdio.h>  // For printf, scanf
#include <stdlib.h> // For malloc, free

// Turing machine state
typedef enum {
    HALT,
    READ,
    WRITE,
    MOVE
} State;

// Turing machine tape
typedef struct {
    int *cells;  // Array of cells
    int size;    // Size of the tape
    int head;    // Position of the head
} Tape;

// Turing machine
typedef struct {
    State state;    // Current state
    Tape *tape;     // Tape
    char *program;  // Program
    int pc;         // Program counter
} Machine;

// Create a new tape
Tape *tape_new(int size) {
    Tape *tape = malloc(sizeof(Tape));
    tape->cells = malloc(size * sizeof(int));
    tape->size = size;
    tape->head = 0;
    return tape;
}

// Free a tape
void tape_free(Tape *tape) {
    free(tape->cells);
    free(tape);
}

// Read a cell from the tape
int tape_read(Tape *tape) {
    return tape->cells[tape->head];
}

// Write a cell to the tape
void tape_write(Tape *tape, int value) {
    tape->cells[tape->head] = value;
}

// Move the head of the tape
void tape_move(Tape *tape, int direction) {
    tape->head += direction;
}

// Create a new machine
Machine *machine_new(char *program, int size) {
    Machine *machine = malloc(sizeof(Machine));
    machine->state = READ;
    machine->tape = tape_new(size);
    machine->program = program;
    machine->pc = 0;
    return machine;
}

// Free a machine
void machine_free(Machine *machine) {
    tape_free(machine->tape);
    free(machine);
}

// Run the machine
void machine_run(Machine *machine) {
    while (machine->state != HALT) {
        switch (machine->state) {
            case READ:
                machine->state = machine->program[machine->pc++];
                break;
            case WRITE:
                tape_write(machine->tape, machine->program[machine->pc++]);
                break;
            case MOVE:
                tape_move(machine->tape, machine->program[machine->pc++]);
                break;
            case HALT:
                break;
        }
    }
}

// Print the tape
void tape_print(Tape *tape) {
    for (int i = 0; i < tape->size; i++) {
        printf("%d", tape->cells[i]);
    }
    printf("\n");
}

// Main function
int main() {
    // Create a machine
    Machine *machine = machine_new("RWRW", 10);

    // Run the machine
    machine_run(machine);

    // Print the tape
    tape_print(machine->tape);

    // Free the machine
    machine_free(machine);

    return 0;
}