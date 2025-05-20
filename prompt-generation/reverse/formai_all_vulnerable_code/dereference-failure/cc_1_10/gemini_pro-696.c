//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The enigmatic contents of our spam detection system
typedef struct spam_detective {
    char *magic_incantation; // A mystical phrase to ward off spam
    int secret_number;       // The key to unlock the spam-free realm
    float spam_o_meter;       // A gauge measuring the likelihood of spam
} spam_detective_t;

// Our trusty spam detector, ready to vanquish unwanted messages
spam_detective_t detector = {
    .magic_incantation = "Spam begone, with a sprinkle of rain!",
    .secret_number = 42,
    .spam_o_meter = 0.0f
};

// The inbox, a treacherous place where spam lurks
char **inbox = NULL;
int inbox_size = 0;

// A riddle-wrapped function to load the inbox
void load_inbox() {
    inbox = malloc(sizeof(char *) * 10); // A mysterious number of slots to hold messages
    inbox_size = 3;
    inbox[0] = "Hello, I am a legitimate email.";
    inbox[1] = "Your account has been compromised! Click here to fix it!"; // A dubious claim
    inbox[2] = "Congratulations! You have won a million dollars!"; // Too good to be true?
}

// The crux of our system, a perplexing spam detection algorithm
void detect_spam() {
    for (int i = 0; i < inbox_size; i++) {
        char *message = inbox[i];

        // A peculiar check for the forbidden phrase "free"
        if (strstr(message, "free") != NULL) {
            detector.spam_o_meter += 0.2f;
        }

        // A riddle: How many exclamation marks make a message suspicious?
        int exclamation_count = 0;
        for (int j = 0; message[j] != '\0'; j++) {
            if (message[j] == '!') {
                exclamation_count++;
            }
        }
        if (exclamation_count > 3) {
            detector.spam_o_meter += 0.1f;
        }

        // A mystical formula to calculate spam likelihood
        if (detector.spam_o_meter > 0.5f) {
            printf("Message %d: Beware, this one smells like spam, my friend!\n", i);
        } else {
            printf("Message %d: Seems legit, you can trust it.\n", i);
        }

        // Return to the ethereal realm, where spam has no power
        detector.spam_o_meter = 0.0f;
    }
}

int main() {
    load_inbox();
    detect_spam();

    // Vanquish the forces of spam, one email at a time
    free(inbox);
    return 0;
}