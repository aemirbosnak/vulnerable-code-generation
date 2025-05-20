//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Appointment {
    char name[20];
    int day;
    int month;
    int year;
};

int main()
{
    int num_of_appts, i;
    printf("How many appointments would you like to schedule? ");
    scanf("%d", &num_of_appts);
    struct Appointment appts[num_of_appts];
    for (i = 0; i < num_of_appts; i++) {
        printf("Name: ");
        scanf("%s", appts[i].name);
        printf("Date (dd/mm/yyyy): ");
        scanf("%d/%d/%d", &appts[i].day, &appts[i].month, &appts[i].year);
    }

    // Sorting appointments by date
    for (i = 0; i < num_of_appts - 1; i++) {
        int j;
        for (j = i+1; j < num_of_appts; j++) {
            if (appts[i].year > appts[j].year) {
                struct Appointment temp = appts[i];
                appts[i] = appts[j];
                appts[j] = temp;
            }
            else if (appts[i].year == appts[j].year && appts[i].month > appts[j].month) {
                struct Appointment temp = appts[i];
                appts[i] = appts[j];
                appts[j] = temp;
            }
            else if (appts[i].year == appts[j].year && appts[i].month == appts[j].month && appts[i].day > appts[j].day) {
                struct Appointment temp = appts[i];
                appts[i] = appts[j];
                appts[j] = temp;
            }
        }
    }

    // Displaying appointments
    printf("\nAppointments:\n");
    for (i = 0; i < num_of_appts; i++) {
        printf("%s: %d/%d/%d\n", appts[i].name, appts[i].day, appts[i].month, appts[i].year);
    }

    return 0;
}