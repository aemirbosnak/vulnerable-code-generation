//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

// defining structure for appointment
struct appointment {
    char name[50];
    int day;
    int month;
    int year;
    int hour;
    int minute;
};

// function to create new appointment
struct appointment* createAppointment(char n[], int d, int m, int y, int h, int min){
    struct appointment* appt = (struct appointment*)malloc(sizeof(struct appointment));
    
    // assigning values to appointment fields
    for(int i=0; i<50; i++){
        appt->name[i] = n[i];
    }
    appt->day = d;
    appt->month = m;
    appt->year = y;
    appt->hour = h;
    appt->minute = min;
    
    return appt;
}

// function to print appointment details
void displayAppointment(struct appointment* appt){
    printf("Appointment Details:\n");
    printf("Name: %s\n", appt->name);
    printf("Date: %d-%d-%d\n", appt->day, appt->month, appt->year);
    printf("Time: %d:%d\n", appt->hour, appt->minute);
}

// function to compare dates for sorting appointments
int compareDate(struct appointment* appt1, struct appointment* appt2){
    // comparing years
    if(appt1->year > appt2->year){
        return 1;
    }
    else if(appt1->year < appt2->year){
        return -1;
    }
    else{
        // comparing months
        if(appt1->month > appt2->month){
            return 1;
        }
        else if(appt1->month < appt2->month){
            return -1;
        }
        else{
            // comparing days
            if(appt1->day > appt2->day){
                return 1;
            }
            else if(appt1->day < appt2->day){
                return -1;
            }
            else{
                // comparing hours
                if(appt1->hour > appt2->hour){
                    return 1;
                }
                else if(appt1->hour < appt2->hour){
                    return -1;
                }
                else{
                    // comparing minutes
                    if(appt1->minute > appt2->minute){
                        return 1;
                    }
                    else if(appt1->minute < appt2->minute){
                        return -1;
                    }
                    else{
                        return 0;
                    }
                }
            }
        }
    }
}

int main(){
    // creating appointments
    struct appointment* appt1 = createAppointment("Meeting 1", 15, 6, 2022, 10, 30);
    struct appointment* appt2 = createAppointment("Meeting 2", 17, 6, 2022, 12, 0);
    struct appointment* appt3 = createAppointment("Meeting 3", 15, 6, 2022, 14, 15);
    
    // sorting appointments
    struct appointment* appts[3] = {appt1, appt2, appt3};
    for(int i=0; i<3; i++){
        for(int j=i+1; j<3; j++){
            if(compareDate(appts[i], appts[j]) > 0){
                struct appointment* temp = appts[i];
                appts[i] = appts[j];
                appts[j] = temp;
            }
        }
    }
    
    // displaying sorted appointments
    for(int i=0; i<3; i++){
        displayAppointment(appts[i]);
        printf("\n");
    }
    
    return 0;
}