//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct appointment {
    int id;
    char *description;
    int start_time;
    int end_time;
} appointment_t;

static appointment_t *appointments = NULL;
static int num_appointments = 0;

static void print_appointment(appointment_t *appointment) {
    printf("Appointment ID: %d\n", appointment->id);
    printf("Description: %s\n", appointment->description);
    printf("Start time: %d\n", appointment->start_time);
    printf("End time: %d\n\n", appointment->end_time);
}

static void add_appointment(int id, char *description, int start_time, int end_time) {
    appointments = realloc(appointments, (num_appointments + 1) * sizeof(appointment_t));
    appointments[num_appointments].id = id;
    appointments[num_appointments].description = strdup(description);
    appointments[num_appointments].start_time = start_time;
    appointments[num_appointments].end_time = end_time;
    num_appointments++;
}

static void remove_appointment(int id) {
    int i;
    for (i = 0; i < num_appointments; i++) {
        if (appointments[i].id == id) {
            free(appointments[i].description);
            memmove(&appointments[i], &appointments[i + 1], (num_appointments - i - 1) * sizeof(appointment_t));
            num_appointments--;
            break;
        }
    }
}

static void print_all_appointments() {
    int i;
    for (i = 0; i < num_appointments; i++) {
        print_appointment(&appointments[i]);
    }
}

static void handle_command(char *command) {
    char *argv[4];
    int argc = 0;
    char *token = strtok(command, " ");
    while (token != NULL && argc < 4) {
        argv[argc++] = token;
        token = strtok(NULL, " ");
    }

    if (strcmp(argv[0], "add") == 0) {
        add_appointment(atoi(argv[1]), argv[2], atoi(argv[3]), atoi(argv[4]));
        printf("Appointment added!\n");
    } else if (strcmp(argv[0], "remove") == 0) {
        remove_appointment(atoi(argv[1]));
        printf("Appointment removed!\n");
    } else if (strcmp(argv[0], "list") == 0) {
        print_all_appointments();
    } else {
        printf("Invalid command!\n");
    }
}

int main() {
    char command[100];
    printf("Welcome to the Appointment Scheduler!\n");
    printf("Type \"help\" for a list of commands.\n");
    while (1) {
        printf("> ");
        fgets(command, 100, stdin);
        if (strcmp(command, "quit\n") == 0) {
            break;
        } else if (strcmp(command, "help\n") == 0) {
            printf("Commands:\n");
            printf("  add <id> <description> <start_time> <end_time>\n");
            printf("  remove <id>\n");
            printf("  list\n");
            printf("  quit\n");
        } else {
            handle_command(command);
        }
    }
    printf("Goodbye!\n");
    return 0;
}