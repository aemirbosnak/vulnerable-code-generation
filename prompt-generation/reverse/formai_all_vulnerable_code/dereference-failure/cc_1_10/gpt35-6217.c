//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct appointment{
    char name[20];
    int age;
    char date[10];
    char time[6];
}Appointment;
void display_appointment(Appointment appointment){
    printf("Name: %s\n",appointment.name);
    printf("Age: %d\n",appointment.age);
    printf("Date: %s\n",appointment.date);
    printf("Time: %s\n",appointment.time);
}
int check_date(char date[]){
    char month[3],day[3],year[5];
    sscanf(date,"%[^/]/%[^/]/%s",day,month,year);
    int d = atoi(day), m = atoi(month), y = atoi(year);
    if(m<1 || m>12 || d<1 || d>31) return 0; // check month and date
    if(m==4 || m==6 || m==9 || m==11) return (d<=30); // check 30 day month
    if(m==2){
        if((y%4==0 && y%100!=0) || y%400==0) return (d<=29); // Leap year
        return (d<=28);
    }
    return 1;
}
void clear_input(){
    char c;
    while((c=getchar()) != '\n' && c!= EOF);
}
int main(){
    int choice,n = 0,max_appointment=10;
    Appointment *appointments = (Appointment*) calloc(max_appointment,sizeof(Appointment));
    while(1){
        printf("\n-----------------\n");
        printf("Appointment Scheduler\n");
        printf("-----------------\n");
        printf("1. Book an appointment\n");
        printf("2. View All Appointments\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        clear_input();
        switch(choice){
            case 1:{
                if(n>=max_appointment){
                    printf("Cannot add more appointments\n");
                    break;
                }
                printf("Enter name: ");
                fgets(appointments[n].name,20,stdin);
                appointments[n].name[strcspn(appointments[n].name,"\n")]='\0';
                printf("Enter age: ");
                scanf("%d",&(appointments[n].age));
                printf("Enter date (dd/mm/yyyy): ");
                fgets(appointments[n].date,10,stdin);
                appointments[n].date[strcspn(appointments[n].date,"\n")]='\0';
                if(!check_date(appointments[n].date)){
                    printf("Invalid date. Appointments are booked for the next 31 days from today\n");
                    break;
                }
                printf("Enter time (hh:mm): ");
                fgets(appointments[n].time,6,stdin);
                appointments[n].time[strcspn(appointments[n].time,"\n")]='\0';
                display_appointment(appointments[n]);
                n++;
                break;
            }
            case 2:{
                printf("\nAll Appointments:\n");
                printf("----------------------------\n");
                for(int i=0;i<n;i++){
                    display_appointment(appointments[i]);
                    printf("----------------------------\n");
                }
                break;
            }
            case 3:{
                printf("Exiting...\n");
                free(appointments);
                exit(0);
            }
            default:{
                printf("Invalid choice\n");
            }
        }
    }
    return 0;
}