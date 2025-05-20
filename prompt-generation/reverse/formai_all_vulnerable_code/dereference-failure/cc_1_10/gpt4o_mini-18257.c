//GPT-4o-mini DATASET v1.0 Category: Natural Language Date Converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to display the date
void displayDate(struct tm *date) {
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", date);
    printf("🎉 Here you go! The formatted date is: %s 🎉\n", buffer);
}

// Function to parse a natural language date
void parseDate(char *input, struct tm *date) {
    if (strcmp(input, "today") == 0) {
        time_t t = time(NULL);
        *date = *localtime(&t);
    } else if (strcmp(input, "tomorrow") == 0) {
        time_t t = time(NULL) + 86400;  // 86400 seconds in a day
        *date = *localtime(&t);
    } else if (strcmp(input, "yesterday") == 0) {
        time_t t = time(NULL) - 86400;
        *date = *localtime(&t);
    } else {
        printf("🤔 Hmm, I didn't quite understand that! Let's try again.\n");
    }
}

int main() {
    char input[100];
    struct tm date;

    printf("👋 Welcome to the Cheerful Date Converter! 🎊\n");
    printf("You can type in 'today', 'tomorrow', or 'yesterday' to get a quick date conversion.\n");
    
    while (1) {
        printf("🌟 Please enter a date (type 'exit' to quit): ");
        fgets(input, sizeof(input), stdin);
        
        // Remove trailing newline character from the input
        input[strcspn(input, "\n")] = 0; 
        
        if (strcmp(input, "exit") == 0) {
            printf("👋 Thank you for using the Cheerful Date Converter! Have a great day! 🌈\n");
            break;
        }

        parseDate(input, &date);
        displayDate(&date);
    }
    
    return 0;
}