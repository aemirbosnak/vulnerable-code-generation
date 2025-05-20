//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Structure to store client information
typedef struct Client
{
    char name[50];
    char phone[15];
    char email[50];
    char appointment_time[20];
} client;

//Function to check if input time is valid
int check_valid_time(char *time_str)
{
    int hour, min;
    char temp[3];

    //Check if time string is valid
    if (strlen(time_str) != 5)
        return 0;
    if (time_str[2] != ':')
        return 0;

    //Extract hour and minute
    strncpy(temp, time_str, 2);
    temp[2] = '\0';
    hour = atoi(temp);
    strncpy(temp, time_str + 3, 2);
    temp[2] = '\0';
    min = atoi(temp);

    //Check if hour and minute are valid
    if (hour < 0 || hour > 23)
        return 0;
    if (min < 0 || min > 59)
        return 0;

    return 1;
}

//Function to check if appointment time is valid
int check_time(client c)
{
    //Check if appointment time is valid
    if (!check_valid_time(c.appointment_time))
    {
        printf("Invalid appointment time entered. Please enter appointment time in HH:MM format.\n");
        return 0;
    }

    //Check if appointment time is at least an hour from current time
    time_t current_time = time(NULL);
    struct tm *local_time = localtime(&current_time);
    int current_hour = local_time->tm_hour;
    int current_min = local_time->tm_min;

    int hour, min;
    char temp[3];
    strncpy(temp, c.appointment_time, 2);
    temp[2] = '\0';
    hour = atoi(temp);
    strncpy(temp, c.appointment_time + 3, 2);
    temp[2] = '\0';
    min = atoi(temp);

    if (hour < current_hour || (hour == current_hour && min <= current_min + 59))
    {
        printf("Appointment time must be at least an hour from current time.\n");
        return 0;
    }

    return 1;
}

//Function to display all clients with appointments
void display_appointments(client *clients, int count)
{
    printf("Clients with appointments:\n");
    printf("Name\tPhone\tEmail\tAppointment Time\n");
    for (int i = 0; i < count; i++)
    {
        printf("%s\t%s\t%s\t%s\n", clients[i].name, clients[i].phone, clients[i].email, clients[i].appointment_time);
    }
}

int main()
{
    int option, count = 0, num_clients;
    client *clients = NULL;

    //Main menu
    while (1)
    {
        printf("\nAppointment Scheduler\n");
        printf("1. Schedule Appointment\n");
        printf("2. Display Appointments\n");
        printf("3. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            //Schedule appointment
            printf("\nEnter number of clients: ");
            scanf("%d", &num_clients);
            clients = (client *)realloc(clients, (count + num_clients) * sizeof(client));
            for (int i = 0; i < num_clients; i++)
            {
                printf("\nClient %d\n", i + 1);
                printf("Name: ");
                scanf("%s", clients[count + i].name);
                printf("Phone: ");
                scanf("%s", clients[count + i].phone);
                printf("Email: ");
                scanf("%s", clients[count + i].email);
                printf("Appointment Time (HH:MM): ");
                scanf("%s", clients[count + i].appointment_time);

                //Check if appointment time is valid
                int valid_time = check_time(clients[count + i]);
                if (!valid_time)
                {
                    i--;
                    num_clients--;
                }
            }
            count += num_clients;
            printf("%d appointments scheduled.\n", num_clients);
            break;

        case 2:
            //Display appointments
            if (count > 0)
                display_appointments(clients, count);
            else
                printf("No appointments scheduled.\n");
            break;

        case 3:
            //Exit
            printf("Goodbye!\n");
            return 0;

        default:
            printf("Invalid option. Please enter a number between 1 and 3.\n");
            break;
        }
    }

    return 0;
}