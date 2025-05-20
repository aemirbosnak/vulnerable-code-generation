//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// structure to store appointment details
typedef struct {
   int day;
   int month;
   int year;
   char name[50];
   char phone[20];
   char email[50];
   char notes[100];
} Appointment;

// function to display menu options
void displayMenu() {
   printf("\nAPPOINTMENT SCHEDULER\n");
   printf("---------------------\n");
   printf("1. Schedule an appointment\n");
   printf("2. View scheduled appointments\n");
   printf("3. Exit\n");
   printf("\nEnter your choice (1-3): ");
}

// function to get current date
void getCurrentDate(int *day, int *month, int *year) {
   time_t currentTime;
   struct tm *localTime;

   time(&currentTime);
   localTime = localtime(&currentTime);
   
   *day = localTime->tm_mday;
   *month = localTime->tm_mon + 1;
   *year = localTime->tm_year + 1900;
}

// function to add appointment to file
void scheduleAppointment() {
   Appointment appt;
   int day, month, year;

   // get current date
   getCurrentDate(&day, &month, &year);

   // get appointment details
   printf("\nEnter appointment details:\n");
   printf("Name: ");
   fflush(stdin);
   fgets(appt.name, 50, stdin);
   appt.name[strcspn(appt.name, "\n")] = 0; // remove newline character
   printf("Phone: ");
   fflush(stdin);
   fgets(appt.phone, 20, stdin);
   appt.phone[strcspn(appt.phone, "\n")] = 0; // remove newline character
   printf("Email: ");
   fflush(stdin);
   fgets(appt.email, 50, stdin);
   appt.email[strcspn(appt.email, "\n")] = 0; // remove newline character
   printf("Notes: ");
   fflush(stdin);
   fgets(appt.notes, 100, stdin);
   appt.notes[strcspn(appt.notes, "\n")] = 0; // remove newline character

   // validate date
   while (1) {
      printf("\nAppointment Date (dd/mm/yyyy): ");
      fflush(stdin);
      scanf("%d/%d/%d", &appt.day, &appt.month, &appt.year);
      if (appt.year < year) {
         printf("\nInvalid Year. Please re-enter\n");
         continue;
      } else if (appt.year == year && appt.month < month) {
         printf("\nInvalid Month. Please re-enter\n");
         continue;
      } else if (appt.year == year && appt.month == month && appt.day < day) {
         printf("\nInvalid Day. Please re-enter\n");
         continue;
      } else {
         break;
      }
   }

   // open file in append mode and write appointment details
   FILE *fp;
   fp = fopen("appointments.txt", "a");
   if (fp == NULL) {
      printf("\nError: Unable to open file for writing.\n");
      return;
   }
   fprintf(fp, "%d/%d/%d,%s,%s,%s,%s\n", appt.day, appt.month, appt.year, appt.name, appt.phone, appt.email, appt.notes);
   fclose(fp);

   printf("\nAppointment scheduled successfully!\n");
}

// function to display appointments from file
void viewAppointments() {
   FILE *fp;
   fp = fopen("appointments.txt", "r");
   if (fp == NULL) {
      printf("\nNo appointments scheduled yet!\n");
      return;
   }
   char line[200];
   int count = 0;
   printf("\nScheduled Appointments:\n");
   printf("------------------------\n");
   printf("S. No.\tDate\t\tName\t\tPhone\t\tEmail\t\tNotes\n");
   printf("-----\t----\t\t----\t\t-----\t\t-----\t\t-----\n");
   while (fgets(line, sizeof(line), fp)) {
      count++;
      char *token;
      token = strtok(line, ",");
      printf("%d.\t%s\t", count, token);
      token = strtok(NULL, ",");
      printf("%s\t", token);
      token = strtok(NULL, ",");
      printf("%s\t", token);
      token = strtok(NULL, ",");
      printf("%s\t", token);
      token = strtok(NULL, ",");
      printf("%s\n", token);
   }
   fclose(fp);
}

int main() {
   int choice;
   while (1) {
      displayMenu();
      scanf("%d", &choice);
      switch (choice) {
         case 1:
            scheduleAppointment();
            break;
         case 2:
            viewAppointments();
            break;
         case 3:
            printf("\nExiting program...\n");
            exit(0);
         default:
            printf("\nInvalid choice. Please try again.\n");
            break;
      }
   }
   return 0;
}