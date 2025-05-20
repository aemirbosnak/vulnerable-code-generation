//FormAI DATASET v1.0 Category: Spam Detection System ; Style: ultraprecise
#include <stdio.h>
#include <string.h>

/* Global variables */
int count = 0;

/* Function Prototypes */
void check_for_spam(char line[]);
void display_results();

/* Main function */
int main()
{
    char line[100];

    printf("Welcome to the Spam Detection System!\n");
    printf("Enter 'exit' to quit.\n\n");

    while (1) {
        printf("Enter message: ");
        scanf("%[^\n]%*c", line);

        if (strcmp(line, "exit") == 0) {
            printf("\n");
            display_results();
            break;
        }

        check_for_spam(line);
    }

    return 0;
}

/* Check for spam function */
void check_for_spam(char line[])
{
    char words[][10] = {"buy", "click", "free", "money", "offer", "win"};
    int i;

    for (i = 0; i < 6; i++) {
        if (strstr(line, words[i]) != NULL) {
            printf("SPAM DETECTED!\n");
            count++;
            return;
        }
    }

    printf("Message is clean.\n");
}

/* Display results function */
void display_results()
{
    printf("SPAM DETECTION SYSTEM RESULTS\n");
    printf("Total messages checked: %d\n", count);
    printf("Number of spam messages detected: %d\n", count);
    printf("Percentage of spam messages: %d%%\n", (count * 100) / count);
}