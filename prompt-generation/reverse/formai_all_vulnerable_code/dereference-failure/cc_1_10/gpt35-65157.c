//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    // Let's set the time machine to the year 1970
    struct tm *timeinfo;
    time_t current_time, travel_time;
    time(&current_time);
    timeinfo = localtime(&current_time);
    timeinfo->tm_year = 70;
    travel_time = mktime(timeinfo);
    printf("Welcome to the C Time Travel Simulator!\n");
    printf("We are currently in the year %d.\n\n", 1900 + timeinfo->tm_year);
    printf("Preparing to time travel to the year 2022...\n\n");
    printf("3...\n");
    sleep(1);
    printf("2...\n");
    sleep(1);
    printf("1...\n");
    sleep(1);
    printf("Buckle up and hold on tight!\n\n");
    sleep(1);
    
    // Let's travel to the year 2022
    time(&current_time);
    timeinfo = localtime(&current_time);
    timeinfo->tm_year = 122;
    travel_time = mktime(timeinfo);
    printf("We have arrived in the year %d!\n", 1900 + timeinfo->tm_year);
    printf("Wow, look at all the new technology!\n\n");
    printf("But wait... something seems off...\n");
    printf("There are robots walking dogs and self-driving cars everywhere!\n");
    printf("And why are people wearing silver suits and helmets?\n");
    printf("Oh no... we must have overshot and traveled to the year 2122!\n\n");
    
    // Let's travel back to the year 2022
    time(&current_time);
    timeinfo = localtime(&current_time);
    timeinfo->tm_year = 122;
    travel_time = mktime(timeinfo);
    printf("Quick, let's set the time machine back to the year 2022!\n");
    printf("3...\n");
    sleep(1);
    printf("2...\n");
    sleep(1);
    printf("1...\n");
    sleep(1);
    printf("Phew, we made it back to the right year!\n\n");
    printf("Let's take a look around...\n");
    printf("Aha, things are back to normal.\n");
    printf("People are still driving their own cars and walking their own dogs.\n");
    printf("And no one is wearing a silver suit!\n");
    printf("Looks like our time machine is working perfectly.\n\n");
    
    // Let's travel to the year 1900
    time(&current_time);
    timeinfo = localtime(&current_time);
    timeinfo->tm_year = 0;
    travel_time = mktime(timeinfo);
    printf("Okay, let's try traveling back to the year 1900.\n");
    printf("This should be interesting!\n\n");
    printf("3...\n");
    sleep(1);
    printf("2...\n");
    sleep(1);
    printf("1...\n");
    sleep(1);
    printf("Hold on tight!\n\n");
    
    // Let's travel to the year 1900
    printf("We have arrived in the year %d!\n\n", 1900 + timeinfo->tm_year);
    printf("This is amazing!\n");
    printf("Look at the old-fashioned cars and the horse-drawn carriages!\n");
    printf("And the women in long dresses and big hats!\n");
    printf("Let's explore and see what else we can find.\n\n");
    
    // Let's travel back to the present day
    time(&current_time);
    timeinfo = localtime(&current_time);
    printf("Well, it's been fun time traveling, but it's time to go back to the present day.\n");
    printf("3...\n");
    sleep(1);
    printf("2...\n");
    sleep(1);
    printf("1...\n");
    sleep(1);
    printf("Here we go!\n\n");
    
    // Let's travel back to the present day
    printf("We have arrived back in the present day!\n");
    printf("Thanks for using the C Time Travel Simulator!\n");
    printf("We hope you had a blast!\n");
    
    return 0;
}