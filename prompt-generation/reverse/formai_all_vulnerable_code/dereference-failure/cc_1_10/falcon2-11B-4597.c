//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to add an appointment to the schedule
void addAppointment(char **schedule, int size, int start_time, int duration, char *title, char *description) {
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (strcmp(schedule[i], "") == 0) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        index = size;
        strcpy(schedule[index], "");
    }
    
    char *start_string = (char *)malloc((strlen(start_time) + 1) * sizeof(char));
    strcpy(start_string, start_time);
    
    char *duration_string = (char *)malloc((strlen(duration) + 1) * sizeof(char));
    strcpy(duration_string, duration);
    
    strcpy(schedule[index + 1], start_string);
    strcpy(schedule[index + 2], duration_string);
    strcpy(schedule[index + 3], title);
    strcpy(schedule[index + 4], description);
}

// Function to display the schedule
void displaySchedule(char **schedule, int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(schedule[i], "") == 0) {
            printf(" ");
        } else {
            printf("%s\n", schedule[i]);
        }
    }
}

int main() {
    int size = 0;
    char **schedule = (char **)malloc(size * sizeof(char *));
    
    // Prompt user to enter the size of the schedule
    printf("Enter the size of the schedule: ");
    scanf("%d", &size);
    
    // Prompt user to add appointments to the schedule
    int start_time, duration, i;
    char title[50], description[100];
    for (i = 0; i < size; i++) {
        printf("Enter the start time of appointment %d: ", i + 1);
        scanf("%d", &start_time);
        
        printf("Enter the duration of appointment %d: ", i + 1);
        scanf("%d", &duration);
        
        printf("Enter the title of appointment %d: ", i + 1);
        scanf("%s", title);
        
        printf("Enter the description of appointment %d: ", i + 1);
        scanf("%s", description);
        
        addAppointment(schedule, size, start_time, duration, title, description);
    }
    
    // Display the schedule
    displaySchedule(schedule, size);
    
    return 0;
}