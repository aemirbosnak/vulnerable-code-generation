//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Appointment {
    int id;
    char name[50];
    char date[20];
    char time[20];
};

struct Node {
    struct Appointment appt;
    struct Node* next;
};

void addAppointment(struct Node** head, struct Appointment appt) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->appt = appt;
    new_node->next = *head;
    *head = new_node;
}

void printAppointments(struct Node* head) {
    printf("ID  | Name              | Date        | Time\n");
    printf("------------------------------------------\n");
    while(head != NULL) {
        printf("%-3d | %-18s | %-10s | %-8s\n", 
            head->appt.id, head->appt.name, head->appt.date, head->appt.time);
        head = head->next;
    }
}

void deleteAppointment(struct Node** head, int id) {
    struct Node* temp = *head, *prev;
    if (temp != NULL && temp->appt.id == id) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->appt.id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Appointment with ID %d not found.\n", id);
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void saveAppointments(struct Node* head, char* filename) {
    FILE* fp = fopen(filename, "w");
    while (head != NULL) {
        fprintf(fp, "%d,%s,%s,%s\n", 
            head->appt.id, head->appt.name, head->appt.date, head->appt.time);
        head = head->next;
    }
    fclose(fp);
}

void loadAppointments(struct Node** head, char* filename) {
    FILE* fp = fopen(filename, "r");
    char buffer[100];
    while (fgets(buffer, 100, fp)) {
        struct Appointment appt;
        char* id_str = strtok(buffer, ",");
        char* name = strtok(NULL, ",");
        char* date = strtok(NULL, ",");
        char* time = strtok(NULL, "\n");

        appt.id = atoi(id_str);
        strcpy(appt.name, name);
        strcpy(appt.date, date);
        strcpy(appt.time, time);

        addAppointment(head, appt);
    }
    fclose(fp);
}

int main() {
    struct Node* head = NULL;
    char filename[] = "appointments.txt";
    loadAppointments(&head, filename);
    int choice;
    do {
        printf("\nAPPOINTMENT SCHEDULER\n");
        printf("1. Add Appointment\n");
        printf("2. Print Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Save Appointments\n");
        printf("0. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                struct Appointment new_appt;
                printf("Enter Appointment ID: ");
                scanf("%d", &new_appt.id);
                printf("Enter Name: ");
                scanf("%s", new_appt.name);
                printf("Enter Date (YYYY-MM-DD): ");
                scanf("%s", new_appt.date);
                printf("Enter Time (HH:MM): ");
                scanf("%s", new_appt.time);
                addAppointment(&head, new_appt);
                printf("Appointment added.\n");
                break;
            }
            case 2: {
                printAppointments(head);
                break;
            }
            case 3: {
                int id;
                printf("Enter Appointment ID: ");
                scanf("%d", &id);
                deleteAppointment(&head, id);
                break;
            }
            case 4: {
                saveAppointments(head, filename);
                printf("Appointments saved to %s.\n", filename);
                break;
            }
            case 0: {
                break;
            }
            default: {
                printf("Invalid choice.\n");
                break;
            }
        }
    } while (choice != 0);
    printf("Goodbye!");
    return 0;
}