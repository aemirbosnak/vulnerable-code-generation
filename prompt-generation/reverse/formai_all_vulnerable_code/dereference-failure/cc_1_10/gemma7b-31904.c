//Gemma-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    srand(time(NULL));

    // Create a list of suspects
    char **suspect_list = malloc(10 * sizeof(char *));
    for (int i = 0; i < 10; i++)
    {
        suspect_list[i] = malloc(20 * sizeof(char));
    }

    // Generate fake names for each suspect
    for (int i = 0; i < 10; i++)
    {
        sprintf(suspect_list[i], "Suspect %d", i + 1);
    }

    // Assign each suspect a random occupation
    for (int i = 0; i < 10; i++)
    {
        suspect_list[i][0] = rand() % 5 + 1;
    }

    // Create a list of suspicious activities
    char **suspicious_activities = malloc(20 * sizeof(char *));
    for (int i = 0; i < 20; i++)
    {
        suspicious_activities[i] = malloc(50 * sizeof(char));
    }

    // Generate fake suspicious activities for each suspect
    for (int i = 0; i < 20; i++)
    {
        sprintf(suspicious_activities[i], "Suspicious Activity %d", i + 1);
    }

    // Print the suspect list and activities
    printf("Suspect List:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%s - Occupation: %d\n", suspect_list[i], suspect_list[i][0]);
    }

    printf("\nSuspicious Activities:**\n");
    for (int i = 0; i < 20; i++)
    {
        printf("%s\n", suspicious_activities[i]);
    }

    return 0;
}