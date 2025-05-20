//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main()
{
    int day, month, year, leap = 0, valid_date = 0, current_year;
    char time_travel[50], time_zone[10], date[20], month_name[20], day_name[20];

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    current_year = tm.tm_year + 1900;

    printf("Welcome to the Time Travel Simulator!\n\n");

    printf("You are standing in front of a time machine. To travel through time, please enter the date and time in the following format: DD/MM/YYYY HH:MM AM/PM Timezone\n\n");
    printf("Example: 14/12/1891 10:30 AM GMT\n\n");
    printf("Enter the date and time: ");

    fgets(time_travel, sizeof(time_travel), stdin);
    sscanf(time_travel, "%d/%d/%d %s %s %s", &day, &month, &year, &date, &time_zone, &month_name);

    if(year%4 == 0 && year%100!=0 || year%400 == 0)
    {
        leap = 1;
    }

    if(year <= current_year && month >=1 && month <=12 && day >=1 && day <= 31)
    {
        if(month == 2)
        {
            if(leap == 1 && day <= 29)
            {
                valid_date = 1;
            }
            else if(leap == 0 && day <= 28)
            {
                valid_date = 1;
            }
            else
            {
                printf("Invalid date\n");
                exit(0);
            }
        }
        else if(month == 4 || month == 6 || month == 9 || month == 11)
        {
            if(day <= 30)
            {
                valid_date = 1;
            }
            else
            {
                printf("Invalid date\n");
                exit(0);
            }
        }
        else
        {
            valid_date = 1;
        }
    }
    else
    {
        printf("Invalid date\n");
        exit(0);
    }

    printf("\n\nYou have successfully traveled through time to %s, %s %d, %d %s.\n\n", month_name, date, day, year, time_zone);

    switch(tm.tm_wday)
    {
        case 0:
            strcpy(day_name,"Sunday");
            break;
        case 1:
            strcpy(day_name,"Monday");
            break;
        case 2:
            strcpy(day_name,"Tuesday");
            break;
        case 3:
            strcpy(day_name,"Wednesday");
            break;
        case 4:
            strcpy(day_name,"Thursday");
            break;
        case 5:
            strcpy(day_name,"Friday");
            break;
        case 6:
            strcpy(day_name,"Saturday");
            break;
    }

    printf("Today is %s, %s %d, %d. You have traveled from the year %d to %d.\n\n", day_name, month_name, tm.tm_mday, tm.tm_year+1900, year, current_year);

    return(0);
}