//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display_menu() {
  printf("1. View current heart rate\n");
  printf("2. Record a new heart rate\n");
  printf("3. Set a goal\n");
  printf("4. View progress\n");
  printf("5. Exit\n");
}

int main() {
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);
  int hour = tm->tm_hour;
  int minute = tm->tm_min;

  char name[20];
  printf("Enter your name: ");
  scanf("%s", name);

  int heart_rate = 0;
  printf("Enter your current heart rate: ");
  scanf("%d", &heart_rate);

  int goal = 0;
  printf("Enter your goal heart rate: ");
  scanf("%d", &goal);

  int progress = 0;
  int progress_array[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  while (1) {
    display_menu();
    int choice = 0;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Your current heart rate is: %d\n", heart_rate);
        break;
      case 2:
        printf("Enter your current heart rate: ");
        scanf("%d", &heart_rate);
        progress_array[progress] = heart_rate;
        progress++;
        break;
      case 3:
        printf("Enter your goal heart rate: ");
        scanf("%d", &goal);
        break;
      case 4:
        printf("Your progress: \n");
        for (int i = 0; i < progress; i++) {
          printf("%d ", progress_array[i]);
        }
        printf("\n");
        break;
      case 5:
        printf("Thank you, %s, for using the C Fitness Tracker.\n", name);
        exit(0);
    }
  }
}