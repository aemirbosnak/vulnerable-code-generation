//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Let's define some romantic constants to set the mood.
#define PASSIONATE_LOVE "I can't resist your allure, my dear."
#define ADORING_AFFECTION "Your words are like sweet music to my ears."
#define HEARTFELT_DEVOTION "My heart beats only for you, my soulmate."
#define INTIMATE_EMBRACE "Let me hold you close, forever in my arms."

// Our spam detection system will need a way to analyze messages.
typedef struct {
    char *message;
    size_t length;
} Message;

// We'll create a function to check for words that indicate spam.
bool containsSpammyWords(Message message) {
    const char *spammyWords[] = {"FREE", "WIN", "URGENT", "GUARANTEED"};
    size_t numSpammyWords = sizeof(spammyWords) / sizeof(char *);

    for (size_t i = 0; i < numSpammyWords; i++) {
        if (strstr(message.message, spammyWords[i]) != NULL) {
            return true;
        }
    }

    return false;
}

// Now, let's create a function to craft a captivating response.
char *generateResponse(Message message) {
    char *response;

    if (containsSpammyWords(message)) {
        response = "My heart aches to be rid of your spammy advances.";
    } else if (strstr(message.message, "I love you") != NULL) {
        response = HEARTFELT_DEVOTION;
    } else if (strstr(message.message, "I adore you") != NULL) {
        response = ADORING_AFFECTION;
    } else {
        response = PASSIONATE_LOVE;
    }

    return strdup(response);
}

// Finally, let's write a main function to put it all together.
int main() {
    // Imagine you've received a romantic message from a potential suitor.
    Message message = {"My dearest, your presence fills my heart with joy.", 43};

    // Analyze the message for any signs of spam.
    bool isSpam = containsSpammyWords(message);

    if (isSpam) {
        printf("Alas, your words reek of deceit. Farewell, spammer!\n");
    } else {
        // If it's not spam, generate a charming response.
        char *response = generateResponse(message);

        // Send your heart's message to your suitor.
        printf("My heart flutters with every word you grace me with, %s\n", response);
    }

    return 0;
}