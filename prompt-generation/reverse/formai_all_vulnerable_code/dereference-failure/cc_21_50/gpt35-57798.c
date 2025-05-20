//FormAI DATASET v1.0 Category: Date and time ; Style: funny
#include <stdio.h>
#include <time.h>

int main()
{
    printf("Hello there! I am a program that prints the current date and time.\n");

    // Let's get the current time
    time_t t = time(NULL);
    struct tm *local_time = localtime(&t);

    // Let's print the current date and time in a funny way
    printf("It's ");
    if(local_time->tm_hour >= 12 && local_time->tm_hour < 18)
    {
        printf("%d:%02d in the afternoon", local_time->tm_hour % 12, local_time->tm_min);
    }
    else if(local_time->tm_hour >= 18 && local_time->tm_hour < 24)
    {
        printf("%d:%02d in the evening", local_time->tm_hour % 12, local_time->tm_min);
    }
    else if(local_time->tm_hour >= 0 && local_time->tm_hour < 6)
    {
        printf("%d:%02d in the middle of the night", local_time->tm_hour % 12, local_time->tm_min);
    }
    else if(local_time->tm_hour >= 6 && local_time->tm_hour < 12)
    {
        printf("%d:%02d in the morning", local_time->tm_hour % 12, local_time->tm_min);
    }
    printf(" on ");
    switch(local_time->tm_wday)
    {
        case 0:
            printf("Sunday");
            break;
        case 1:
            printf("Monday");
            break;
        case 2:
            printf("Tuesday");
            break;
        case 3:
            printf("Wednesday");
            break;
        case 4:
            printf("Thursday");
            break;
        case 5:
            printf("Friday");
            break;
        case 6:
            printf("Saturday");
            break;
    }
    printf(", the ");
    switch(local_time->tm_mday)
    {
        case 1:
        case 21:
        case 31:
            printf("%dst", local_time->tm_mday);
            break;
        case 2:
        case 22:
            printf("%dnd", local_time->tm_mday);
            break;
        case 3:
        case 23:
            printf("%drd", local_time->tm_mday);
            break;
        default:
            printf("%dth", local_time->tm_mday);
            break;
    }
    switch(local_time->tm_mon)
    {
        case 0:
            printf(" of January");
            break;
        case 1:
            printf(" of February");
            break;
        case 2:
            printf(" of March");
            break;
        case 3:
            printf(" of April");
            break;
        case 4:
            printf(" of May");
            break;
        case 5:
            printf(" of June");
            break;
        case 6:
            printf(" of July");
            break;
        case 7:
            printf(" of August");
            break;
        case 8:
            printf(" of September");
            break;
        case 9:
            printf(" of October");
            break;
        case 10:
            printf(" of November");
            break;
        case 11:
            printf(" of December");
            break;
    }
    printf(".");

    return 0;
}