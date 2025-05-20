//FormAI DATASET v1.0 Category: Digital Diary ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Entry {
  char date[20];
  char time[20];
  char title[50];
  char message[1000];
};

int main() {
  int option, num_entries = 0;
  struct Entry entries[100];
  
  printf("Welcome to the Cyberpunk Digital Diary!\n\n");
  
  while(1) {
    printf("Choose an option:\n");
    printf("1. Create a new entry\n");
    printf("2. View previous entries\n");
    printf("3. Exit program\n");
    
    scanf("%d", &option);
    getchar();
    
    if(option == 1) {
      printf("\nEnter the title of your entry: ");
      fgets(entries[num_entries].title, 50, stdin);
      entries[num_entries].title[strlen(entries[num_entries].title)-1] = '\0';
      
      time_t t = time(NULL);
      struct tm tm = *localtime(&t);
      sprintf(entries[num_entries].date, "%d-%02d-%02d", tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday);
      sprintf(entries[num_entries].time, "%02d:%02d:%02d", tm.tm_hour, tm.tm_min, tm.tm_sec);
      
      printf("\nEnter your message:\n");
      fgets(entries[num_entries].message, 1000, stdin);
      entries[num_entries].message[strlen(entries[num_entries].message)-1] = '\0';
      printf("\nEntry added successfully!\n\n");
      
      num_entries++;
    }
    
    else if(option == 2) {
      if(num_entries == 0) {
        printf("\nNo entries found.\n\n");
        continue;
      }
      
      printf("\n\n+------------------------------------------------------+\n");
      for(int i = 0; i < num_entries; i++) {
        printf("Date: %s\n", entries[i].date);
        printf("Time: %s\n", entries[i].time);
        printf("Title: %s\n", entries[i].title);
        printf("Message: %s\n", entries[i].message);
        printf("+------------------------------------------------------+\n\n");
      }
    }
    
    else if(option == 3) {
      printf("\nExiting Digital Diary...Goodbye!\n");
      exit(0);
    }
    
    else {
      printf("Invalid Input. Please choose a valid option.\n\n");
    }
  }
  
  return 0;
}