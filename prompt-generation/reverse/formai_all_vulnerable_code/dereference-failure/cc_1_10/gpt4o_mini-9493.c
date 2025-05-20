//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT_LENGTH 100

// A function to get the current date as a string
const char* get_current_date() {
    static char buffer[11]; // Format YYYY-MM-DD
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    snprintf(buffer, sizeof(buffer), "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    return buffer;
}

// Romantic date converter function
void romantic_date_converter(const char* natural_date) {
    struct tm tm;
    char output[100];
    
    // Attempt to parse the natural date
    if (strptime(natural_date, "%B %d, %Y", &tm) == NULL) {
        printf("Oh darling, it seems that your date is not in the format I understand.\n");
        printf("Please let me know the date in 'Month Day, Year' format.\n");
        return;
    }

    // Convert it to a romantic string
    snprintf(output, sizeof(output), "Ah, my sweet! The date you've shared, %s, is only a whisper away from %s.\n",
             natural_date, get_current_date());
    
    printf("%s", output);
}

// Main function to greet and convert the date
int main() {
    char user_input[MAX_INPUT_LENGTH];
    
    printf("Welcome, my beloved! Together we shall embrace the beauty of time.\n");
    printf("Please share with me a date in 'Month Day, Year' format: ");
    fgets(user_input, sizeof(user_input), stdin);
    
    // Remove the newline character from the input
    user_input[strcspn(user_input, "\n")] = 0;
    
    // Convert the date
    romantic_date_converter(user_input);
    
    printf("May our memories blossom like flowers in the spring. Until we meet again...\n");
    
    return 0;
}