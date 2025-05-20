//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Appointment {
    char date[15];
    char time[10];
    char patientName[50];
    char doctorName[50];
};

void menu() {
    printf("1. Schedule an appointment\n");
    printf("2. View scheduled appointments\n");
    printf("3. Cancel an appointment\n");
    printf("4. Exit\n");
}

void scheduleAppointment(struct Appointment *appointments,int *count) {
    printf("Enter date (dd-mm-yyyy): ");
    scanf("%s",appointments[*count].date);
    printf("Enter time (24-hour format): ");
    scanf("%s",appointments[*count].time);
    printf("Enter patient's name: ");
    scanf("%s",appointments[*count].patientName);
    printf("Enter doctor's name: ");
    scanf("%s",appointments[*count].doctorName);
    printf("\nAppointment scheduled successfully!\n\n");
    (*count)++;
}

void viewAppointments(struct Appointment *appointments,int *count) {
    if(*count == 0) {
        printf("No appointments scheduled yet.\n\n");
        return;
    }
    printf("Scheduled Appointments:\n");
    printf("| %-15s | %-10s | %-50s | %-50s |\n","Date","Time","Patient Name","Doctor Name");
    for(int i=0;i<*count;i++) {
        printf("| %-15s | %-10s | %-50s | %-50s |\n",appointments[i].date,appointments[i].time,appointments[i].patientName,appointments[i].doctorName);
    }
    printf("\n");
}

void cancelAppointment(struct Appointment *appointments,int *count) {
    char date[10], time[10], patientName[50];
    printf("Enter date of appointment to cancel (dd-mm-yyyy): ");
    scanf("%s",date);
    printf("Enter time of appointment to cancel (24-hour format): ");
    scanf("%s",time);
    printf("Enter patient name: ");
    scanf("%s",patientName);
    for(int i=0;i<*count;i++) {
        if(strcmp(appointments[i].date,date) == 0 && strcmp(appointments[i].time,time) == 0 && strcmp(appointments[i].patientName,patientName) == 0) {
            for(int j=i;j<(*count)-1;j++) {
                appointments[j] = appointments[j+1];
            }
            (*count)--;
            printf("\nAppointment cancelled successfully!\n\n");
            return;
        }
    }   
    printf("\nNo appointment found with given details.\n\n");
}

int main() {
    struct Appointment *appointments = (struct Appointment *)malloc(sizeof(struct Appointment) * 100);
    int option,count=0;
    while(1) {
        menu();
        printf("Enter an option: ");
        scanf("%d",&option);
        printf("\n");
        switch(option) {
            case 1:
                scheduleAppointment(appointments,&count);
                break;
            case 2:
                viewAppointments(appointments,&count);
                break;
            case 3:
                cancelAppointment(appointments,&count);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid option.\n\n");
        }
    }
    return 0;
}