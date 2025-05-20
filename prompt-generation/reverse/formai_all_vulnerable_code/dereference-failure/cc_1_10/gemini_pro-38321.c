//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct appointment {
    char *name;
    char *time;
    struct appointment *next;
} appointment;

appointment *new_appointment(char *name, char *time) {
    appointment *appt = malloc(sizeof(appointment));
    appt->name = strdup(name);
    appt->time = strdup(time);
    appt->next = NULL;
    return appt;
}

void free_appointment(appointment *appt) {
    free(appt->name);
    free(appt->time);
    free(appt);
}

void print_appointment(appointment *appt) {
    printf("%s at %s\n", appt->name, appt->time);
}

appointment *insert_appointment(appointment *head, appointment *new_appt) {
    if (head == NULL) {
        return new_appt;
    } else if (strcmp(new_appt->time, head->time) < 0) {
        new_appt->next = head;
        return new_appt;
    } else {
        head->next = insert_appointment(head->next, new_appt);
        return head;
    }
}

appointment *find_appointment(appointment *head, char *name) {
    if (head == NULL) {
        return NULL;
    } else if (strcmp(head->name, name) == 0) {
        return head;
    } else {
        return find_appointment(head->next, name);
    }
}

void delete_appointment(appointment **head, char *name) {
    if (*head == NULL) {
        return;
    } else if (strcmp((*head)->name, name) == 0) {
        appointment *temp = *head;
        *head = (*head)->next;
        free_appointment(temp);
    } else {
        delete_appointment(&(*head)->next, name);
    }
}

void print_appointments(appointment *head) {
    if (head == NULL) {
        return;
    } else {
        print_appointment(head);
        print_appointments(head->next);
    }
}

int main() {
    appointment *head = NULL;

    head = insert_appointment(head, new_appointment("John Doe", "10:00"));
    head = insert_appointment(head, new_appointment("Jane Doe", "11:00"));
    head = insert_appointment(head, new_appointment("Bob Smith", "12:00"));

    print_appointments(head);

    appointment *appt = find_appointment(head, "John Doe");
    if (appt != NULL) {
        print_appointment(appt);
    }

    delete_appointment(&head, "Jane Doe");

    print_appointments(head);

    return 0;
}