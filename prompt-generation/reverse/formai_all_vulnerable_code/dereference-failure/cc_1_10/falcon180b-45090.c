//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define MAX_SIZE 100

typedef struct {
    int id;
    char name[MAX_SIZE];
} Person;

Person* create_person(int id, char* name) {
    Person* person = (Person*)malloc(sizeof(Person));
    person->id = id;
    strncpy(person->name, name, MAX_SIZE);
    return person;
}

void print_person(Person* person) {
    printf("ID: %d, Name: %s\n", person->id, person->name);
}

int main() {
    int pipe_fds[2];
    pid_t child_pid;

    // Create pipe
    if (pipe(pipe_fds) == -1) {
        fprintf(stderr, "Pipe failed\n");
        return 1;
    }

    // Fork process
    child_pid = fork();

    if (child_pid == 0) {
        // Child process
        close(pipe_fds[0]); // Close reading end of pipe

        Person* person = create_person(42, "Sherlock Holmes");
        write(pipe_fds[1], person, sizeof(Person));
        close(pipe_fds[1]);
        exit(0);
    } else if (child_pid > 0) {
        // Parent process
        close(pipe_fds[1]); // Close writing end of pipe

        Person* person;
        read(pipe_fds[0], person, sizeof(Person));
        print_person(person);
        close(pipe_fds[0]);
    } else {
        // Fork failed
        fprintf(stderr, "Fork failed\n");
        return 1;
    }

    return 0;
}