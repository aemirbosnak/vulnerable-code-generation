//FormAI DATASET v1.0 Category: Smart home automation ; Style: Sherlock Holmes
/* 
   Sherlock Holmes' Smart Home Automation System
   
   By Sherlock Holmes, the world's greatest detective

   This program turns on/off lights and plays music according to the time of day and the user's preferences.

*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int hour, minute, music_preference;
    char light_preference;
    
    // Get user's music preference (1 = classical music, 2 = pop music, 3 = jazz music)
    printf("Good evening, dear guest! What type of music do you prefer tonight?\n");
    printf("1. Classical Music\n2. Pop Music\n3. Jazz Music\n");
    printf("Enter your choice: ");
    scanf("%d", &music_preference);
    
    // Get user's light preference (Y = on, N = off)
    printf("Do you want the lights on or off tonight? (Y/N)\n");
    scanf(" %c", &light_preference);
    
    // Get current hour and minute
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    hour = tm.tm_hour;
    minute = tm.tm_min;
    
    // Check if it's time to turn on the lights and play music
    if ((hour >= 18 && hour <= 23) && (minute >= 0 && minute <= 59)) {
        // Check user's light preference and turn on/off lights accordingly
        if (light_preference == 'Y') {
            printf("Turning on the lights...\n");
        } else {
            printf("Turning off the lights...\n");
        }
        
        // Play music according to user's preference
        if (music_preference == 1) {
            printf("Playing classical music...\n");
        } else if (music_preference == 2) {
            printf("Playing pop music...\n");
        } else if (music_preference == 3) {
            printf("Playing jazz music...\n");
        }
    } else {
        printf("It's not yet time to turn on the lights and play music.\n");
    }
    
    return 0;
}