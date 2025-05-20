//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

int main() {

    // Initialize variables
    int n = 1;
    int id = 100;
    int option = 0;

    // Allocate memory for struct
    struct Appointment {
        int id;
        char name[50];
        char date[20];
        char time[10];
    } *appointments = malloc(n * sizeof(struct Appointment));

    // Display menu
    printf("Welcome to the Appointment Scheduler!\n");
    printf("1) Add an appointment\n");
    printf("2) View all appointments\n");
    printf("3) Exit\n");

    // Get user option
    scanf("%d", &option);

    // Process user option
    while (option != 3) {

        // Add an appointment
        if (option == 1) {

            // Get appointment details
            printf("Enter appointment name: ");
            scanf("%s", appointments[n-1].name);
            printf("Enter appointment date (YYYY-MM-DD): ");
            scanf("%s", appointments[n-1].date);
            printf("Enter appointment time (HH:MM): ");
            scanf("%s", appointments[n-1].time);

            // Generate appointment ID
            appointments[n-1].id = id + n;

            // Increment n and allocate memory for new struct
            n++;
            appointments = realloc(appointments, n * sizeof(struct Appointment));

            // Confirm appointment creation
            printf("Appointment created successfully!\n");

        // View all appointments
        } else if (option == 2) {

            // Loop through appointments and print details
            printf("Appointment ID | Appointment Name | Appointment Date | Appointment Time\n");
            for (int i = 0; i < n-1; i++) {
                printf("%d | %s | %s | %s\n", appointments[i].id, appointments[i].name, appointments[i].date, appointments[i].time);
            }

        // Invalid option
        } else {

            // Make the user wait for 5 seconds before exiting
            printf("Calculating...");
            sleep(5);
            printf("You did not choose a valid option. Exiting...\n");
            return 0;

        }

        // Display menu and get user option
        printf("\n1) Add an appointment\n");
        printf("2) View all appointments\n");
        printf("3) Exit\n");
        scanf("%d", &option);

    }

    // Free allocated memory and exit
    free(appointments);
    return 0;
}