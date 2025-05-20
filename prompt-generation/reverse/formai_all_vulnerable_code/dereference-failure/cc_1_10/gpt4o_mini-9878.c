//GPT-4o-mini DATASET v1.0 Category: Automated Fortune Teller ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void displayWelcomeMessage() {
    printf("-------------------------------------------------\n");
    printf("Welcome to the Sherlock Holmes Fortune Teller!\n");
    printf("Where Mystery Meets Your Future...\n");
    printf("-------------------------------------------------\n\n");
    printf("Answer the following questions to unveil your fortune.\n\n");
}

void askQuestions(char *answers[], int numQuestions) {
    const char *questions[] = {
        "What is your favorite color? (Red, Blue, Green, Yellow)",
        "Which animal do you like the most? (Cat, Dog, Bird, Fish)",
        "Preferred detective method? (Observation, Deduction, Intuition, Elimination)",
        "If you could solve one crime, which would it be? (Theft, Murder, Fraud, Kidnapping)"
    };
    
    for (int i = 0; i < numQuestions; i++) {
        printf("%s\n", questions[i]);
        printf("Your answer: ");
        fgets(answers[i], 50, stdin);
        // Remove the newline character at the end of the answer
        answers[i][strcspn(answers[i], "\n")] = 0;
    }
}

void generateFortune(char *answers[], int numQuestions) {
    srand(time(0));
    int fortuneIndex = rand() % 5;  // Generate a random fortune index
    
    const char *fortunes[] = {
        "Your keen eyesight will unveil truths that others overlook.",
        "A curious encounter will lead you down an unexpected path.",
        "Beware of the shadows; they may hold secrets yet to be discovered.",
        "Your instincts are sharp; trust them in times of doubt.",
        "A thrilling mystery is on the horizon, ready for you to solve."
    };

    printf("\n-------------------------------------------------\n");
    printf("Your Fortune:\n");
    printf("%s\n", fortunes[fortuneIndex]);
    printf("-------------------------------------------------\n");
    
    printf("Thank you for participating in this detective journey!\n");
}

int main() {
    const int numQuestions = 4;
    char *answers[numQuestions];
    
    // Initialize answer storage
    for (int i = 0; i < numQuestions; i++) {
        answers[i] = (char *)malloc(50 * sizeof(char));
    }

    displayWelcomeMessage();
    askQuestions(answers, numQuestions);
    generateFortune(answers, numQuestions);
    
    // Free allocated memory
    for (int i = 0; i < numQuestions; i++) {
        free(answers[i]);
    }

    return 0;
}