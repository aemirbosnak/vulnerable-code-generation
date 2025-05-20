//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function declarations
int random_number(int min, int max);
int random_bool();

int main() {
    // seed random number generator
    srand(time(NULL));

    // conspiracy theory statement templates
    char templates[][100] = {
        "Did you know that %s is actually controlled by a hidden organization?",
        "The government is hiding the truth about %s to maintain control.",
        "%s is a cover-up for the real conspiracy happening behind the scenes.",
        "Wake up, people! The secret society behind %s is manipulating everything.",
        "The mainstream media won't tell you this, but %s is all part of a larger plan.",
        "Believe it or not, %s is just a pawn in a bigger conspiracy.",
        "Don't be fooled by %s, it's just a distraction from the real issues.",
        "The truth about %s is being suppressed by those in power.",
        "You think %s is bad? You should see what's really going on.",
        "You won't hear this on the news, but %s is just a small piece of the puzzle."
    };

    // conspiracy theories
    char theories[][100] = {
        "climate change",
        "flat earth theory",
        "9/11",
        "the moon landing",
        "vaccines",
        "chemtrails",
        "the Illuminati",
        "the New World Order",
        "the Rothschilds",
        "alien cover-up"
    };

    // generate random conspiracy theory
    int index = random_number(0, 9);
    char theory[100];
    sprintf(theory, theories[index]);

    // substitute theory into statement template
    index = random_number(0, 9);
    char statement[100];
    sprintf(statement, templates[index], theory);

    // add a twist to the conspiracy theory
    if (random_bool()) {
        index = random_number(0, 9);
        char twist[100];
        sprintf(twist, " and %s is behind it all!", theories[index]);
        strcat(statement, twist);
    }

    // print conspiracy theory
    printf("%s\n", statement);

    return 0;
}

// generates a random number between min and max (inclusive)
int random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// generates a random boolean value (0 or 1)
int random_bool() {
    return rand() % 2;
}