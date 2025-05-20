//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    char *subject;
    char *action;
    char *motive;
    char *culprit;
} ConspiracyTheory;

const char *subjects[] = {
    "aliens", "government", "big pharma", "illuminati",
    "celebrities", "scientists", "social media", "corporations"
};

const char *actions[] = {
    "control the population", "manipulate the weather",
    "experiment on humans", "hide technology", 
    "influence public opinion", "create false narratives",
    "steal our minds", "harvest our DNA"
};

const char *motives[] = {
    "to harness eternal power", "for profit", 
    "to enslave humanity", "to create chaos", 
    "to prevent world peace", "for world domination",
    "to hide the truth", "to monopolize resources"
};

const char *culprits[] = {
    "lizard people", "shadow government", "the elite", 
    "secret societies", "deep state", "ghosts from the future",
    "time travelers", "AI overlords"
};

void generateRandomTheory(ConspiracyTheory *theory) {
    theory->subject = (char *)subjects[rand() % (sizeof(subjects) / sizeof(subjects[0]))];
    theory->action = (char *)actions[rand() % (sizeof(actions) / sizeof(actions[0]))];
    theory->motive = (char *)motives[rand() % (sizeof(motives) / sizeof(motives[0]))];
    theory->culprit = (char *)culprits[rand() % (sizeof(culprits) / sizeof(culprits[0]))];
}

void displayTheory(ConspiracyTheory *theory) {
    printf("Conspiracy Theory:\n");
    printf("The %s are trying to %s %s %s.\n",
            theory->subject,
            theory->action,
            theory->motive,
            theory->culprit);
    printf("Stay alert! They could be watching you!\n\n");
}

int main() {
    srand(time(0));  // Seed for random number generator
    int theoriesCount;
    
    printf("Welcome to the C Random Conspiracy Theory Generator!\n");
    printf("How many theories would you like to generate? ");
    scanf("%d", &theoriesCount);
    
    ConspiracyTheory theories[theoriesCount];
    
    for(int i = 0; i < theoriesCount; i++) {
        generateRandomTheory(&theories[i]);
    }
    
    for(int i = 0; i < theoriesCount; i++) {
        displayTheory(&theories[i]);
    }
    
    printf("Remember: The truth is out there... or is it?\n");
    
    return 0;
}