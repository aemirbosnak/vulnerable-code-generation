//MISTRAL-7B DATASET v1.0 Category: Fitness Tracker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

typedef struct {
  char name[50];
  int steps;
  int calories;
} Person;

int main(int argc, char *argv[]) {
  Person p;
  int fd;
  char filename[50];
  time_t rawtime;
  struct tm * timeinfo;
  int choice, steps_input;

  if(argc != 2) {
    printf("Usage: %s <Your Name>\n", argv[0]);
    exit(1);
  }

  strcpy(p.name, argv[1]);
  printf("\n**********************************\n");
  printf("* Welcome, %s, to your C Fitness *\n", argv[1]);
  printf("* Tracker! Let's get moving!     *\n");
  printf("**********************************\n");

  while(1) {
    printf("\n1. Log Steps\n");
    printf("2. View Stats\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("Enter steps taken today: ");
        scanf("%d", &steps_input);
        p.steps += steps_input;
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        sprintf(filename, "%s_steps.txt", p.name);
        fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        write(fd, &p.steps, sizeof(int));
        close(fd);
        printf("Steps logged.\n");
        break;

      case 2:
        printf("Name: %s\n", p.name);
        printf("Total Steps: %d\n", p.steps);
        printf("Calories Burned: %d\n", p.calories);
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        printf("Last updated: %s %s %d %d:%d:%d\n",
            asctime(timeinfo) + 8,
            timeinfo->tm_mon + 1,
            timeinfo->tm_mday,
            timeinfo->tm_hour,
            timeinfo->tm_min,
            timeinfo->tm_sec);
        printf("\nPress any key to go back to main menu.\n");
        getchar();
        break;

      case 3:
        printf("Goodbye, %s! Have a great day!\n", argv[1]);
        exit(0);

      default:
        printf("Invalid option. Try again.\n");
        break;
    }
  }

  return 0;
}