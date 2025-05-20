//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_SIZE 100

struct appointment {
  char name[MAX_SIZE];
  char date[MAX_SIZE];
  char time[MAX_SIZE];
  int duration;
};

int compare_dates(const void* a, const void* b) {
  struct appointment* app1 = (struct appointment*)a;
  struct appointment* app2 = (struct appointment*)b;

  int year1, month1, day1, hour1, min1;
  int year2, month2, day2, hour2, min2;

  if(sscanf(app1->date, "%d-%d-%d %d:%d", &year1, &month1, &day1, &hour1, &min1)!= 5 ||
     sscanf(app2->date, "%d-%d-%d %d:%d", &year2, &month2, &day2, &hour2, &min2)!= 5) {
    return 0;
  }

  if(year1 > year2) {
    return 1;
  } else if(year1 < year2) {
    return -1;
  } else {
    if(month1 > month2) {
      return 1;
    } else if(month1 < month2) {
      return -1;
    } else {
      if(day1 > day2) {
        return 1;
      } else if(day1 < day2) {
        return -1;
      } else {
        if(hour1 > hour2) {
          return 1;
        } else if(hour1 < hour2) {
          return -1;
        } else {
          if(min1 > min2) {
            return 1;
          } else if(min1 < min2) {
            return -1;
          } else {
            return 0;
          }
        }
      }
    }
  }
}

int main() {
  int num_appointments, i;
  struct appointment* appointments;

  printf("Enter number of appointments: ");
  scanf("%d", &num_appointments);

  appointments = (struct appointment*)malloc(num_appointments * sizeof(struct appointment));
  for(i = 0; i < num_appointments; i++) {
    printf("Enter name for appointment %d: ", i+1);
    scanf("%s", appointments[i].name);

    printf("Enter date and time for appointment %d (YYYY-MM-DD HH:MM): ", i+1);
    scanf("%s", appointments[i].date);

    printf("Enter duration of appointment %d (in minutes): ", i+1);
    scanf("%d", &appointments[i].duration);
  }

  qsort(appointments, num_appointments, sizeof(struct appointment), compare_dates);

  printf("\nAppointments:\n");
  for(i = 0; i < num_appointments; i++) {
    printf("%s - %s (%d minutes)\n", appointments[i].name, appointments[i].date, appointments[i].duration);
  }

  return 0;
}