//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: scientific
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

// Define struct for appointments
struct Appointment {
   int day;
   int hour;
   char* name;
};

// Define function to create new appointment
struct Appointment* createAppointment(int day, int hour, char* name) {
   struct Appointment* appointment = malloc(sizeof(struct Appointment)); 
   appointment->day = day;
   appointment->hour = hour;
   appointment->name = malloc(strlen(name)+1);
   strcpy(appointment->name, name);
   return appointment;
}

// Define function to print appointment details
void printAppointment(struct Appointment* appointment) {
   printf("Day: %d\n", appointment->day); 
   printf("Time: %d:00\n", appointment->hour);
   printf("Name: %s\n", appointment->name);
}

// Define function to check for scheduling conflicts
int checkConflict(struct Appointment* appointment1, struct Appointment* appointment2) {
   if (appointment1->day == appointment2->day && appointment1->hour == appointment2->hour) {
      return 1;
   } else {
      return 0;
   }
}

int main() {

   // Define array to store appointments
   struct Appointment* appointments[10];

   // Get appointment details and add to array
   appointments[0] = createAppointment(1, 8, "John");
   appointments[1] = createAppointment(2, 10, "Mary");
   appointments[2] = createAppointment(3, 14, "Bob");

   // Check for conflicts with existing appointments
   struct Appointment* newAppointment = createAppointment(2, 11, "Jane");
   int conflict = 0;
   for (int i = 0; i < 3; i++) {
      conflict = checkConflict(appointments[i], newAppointment);
      if (conflict == 1) {
         printf("Scheduling conflict! Cannot add appointment.\n");
         break;
      }
   }
   if (conflict == 0) {
      appointments[3] = newAppointment;
      printf("Appointment added successfully!\n");
   }

   // Print all appointments
   for (int i = 0; i < 4; i++) {
      printAppointment(appointments[i]);
   }

   return 0;
}