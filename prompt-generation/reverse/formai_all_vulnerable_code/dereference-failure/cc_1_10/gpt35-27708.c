//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

struct appointment {
  int day;
  int month;
  int year;
  int hour;
  int minute;
  char name[50];
  char description[100];
};

int main() {
  // allocate memory for max 100 appointments
  struct appointment *appointments = malloc(100 * sizeof(struct appointment));
  int count = 0;

  // loop to add appointments
  while(1) {
    printf("Enter appointment details:\n");

    // get date and time
    printf("Date (DD MM YYYY): ");
    scanf("%d %d %d", &appointments[count].day, &appointments[count].month, &appointments[count].year);
    printf("Time (HH MM): ");
    scanf("%d %d", &appointments[count].hour, &appointments[count].minute);

    getchar(); // to clear input buffer

    // get name and description
    printf("Name: ");
    fgets(appointments[count].name, 50, stdin);
    printf("Description: ");
    fgets(appointments[count].description, 100, stdin);

    // increment appointment count
    count++;

    // ask if user wants to add another appointment
    printf("Do you want to add another appointment? (Y/N): ");
    char choice;
    scanf("%c", &choice);

    // if choice is 'N', break out of loop
    if (choice == 'N') {
      break;
    } else {
      getchar(); // to clear input buffer
    }
  }

  // loop to display appointments
  printf("\nAppointments:\n");
  for (int i=0; i<count; i++) {
    printf("%d/%d/%d ", appointments[i].day, appointments[i].month, appointments[i].year);
    printf("%02d:%02d %s - %s\n", appointments[i].hour, appointments[i].minute, appointments[i].name, appointments[i].description);
  }

  // free memory
  free(appointments);

  return 0;
}