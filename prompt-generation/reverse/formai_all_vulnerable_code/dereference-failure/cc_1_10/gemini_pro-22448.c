//GEMINI-pro DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the conspiracy theories
const char *conspiracyTheories[] = {
    "The moon landing was faked.",
    "The Earth is flat.",
    "Aliens are living among us.",
    "The government is hiding the truth about UFOs.",
    "The Illuminati is controlling the world.",
    "The CIA killed JFK.",
    "9/11 was an inside job.",
    "The Bilderberg Group is a secret society of world leaders.",
    "The Rothschilds control the world's finances.",
    "The New World Order is a plan to create a one-world government."
};

// Define the evidence
const char *evidence[] = {
    "There are no stars in the moon landing photos.",
    "The Earth's shadow on the moon is the wrong shape.",
    "The American flag is waving in the wind on the moon.",
    "The Van Allen radiation belts would have killed the astronauts.",
    "The lunar lander was too small to carry all of the equipment.",
    "The Soviet Union never saw the moon landing.",
    "The Earth is not a perfect sphere.",
    "There are no pictures of the Earth from space that show the entire planet.",
    "The stars in the night sky move in a circular pattern.",
    "The government has covered up evidence of UFOs.",
    "There are alien implants in human bodies.",
    "The Illuminati has a secret headquarters in Switzerland.",
    "The CIA has a secret program to assassinate world leaders.",
    "The 9/11 attacks were carried out by the US government.",
    "The Bilderberg Group meets in secret to discuss world events.",
    "The Rothschilds own a majority of the world's banks.",
    "The New World Order is a plan to create a one-world government."
};

// Define the people
const char *people[] = {
    "Neil Armstrong",
    "Buzz Aldrin",
    "Michael Collins",
    "Alan Shepard",
    "John Glenn",
    "Yuri Gagarin",
    "Laika",
    "Elon Musk",
    "Jeff Bezos",
    "Bill Gates",
    "Mark Zuckerberg",
    "David Rockefeller",
    "George Soros",
    "Vladimir Putin",
    "Xi Jinping",
    "Donald Trump",
    "Joe Biden",
    "Barack Obama",
    "George W. Bush"
};

// Define the locations
const char *locations[] = {
    "Area 51",
    "Roswell",
    "Dulce Base",
    "Denver International Airport",
    "The Vatican",
    "The White House",
    "The Pentagon",
    "The Bilderberg Hotel",
    "The Bohemian Grove",
    "The World Economic Forum",
    "The United Nations",
    "The International Monetary Fund",
    "The World Bank",
    "The Bank of England",
    "The Federal Reserve",
    "The European Central Bank",
    "The Bank of Japan",
    "The People's Bank of China",
    "The Russian Central Bank"
};

// Define the events
const char *events[] = {
    "The moon landing",
    "The assassination of JFK",
    "The 9/11 attacks",
    "The Iraq War",
    "The War on Terror",
    "The global financial crisis",
    "The COVID-19 pandemic",
    "The rise of China",
    "The decline of the United States",
    "The New World Order",
    "The coming of the Antichrist",
    "The end of the world"
};

// Generate a random conspiracy theory
void generateConspiracyTheory() {
    // Select a random conspiracy theory
    int conspiracyTheoryIndex = rand() % (sizeof(conspiracyTheories) / sizeof(char *));
    char *conspiracyTheory = conspiracyTheories[conspiracyTheoryIndex];

    // Select a random piece of evidence
    int evidenceIndex = rand() % (sizeof(evidence) / sizeof(char *));
    char *evidence = evidence[evidenceIndex];

    // Select a random person
    int personIndex = rand() % (sizeof(people) / sizeof(char *));
    char *person = people[personIndex];

    // Select a random location
    int locationIndex = rand() % (sizeof(locations) / sizeof(char *));
    char *location = locations[locationIndex];

    // Select a random event
    int eventIndex = rand() % (sizeof(events) / sizeof(char *));
    char *event = events[eventIndex];

    // Combine the conspiracy theory, evidence, person, location, and event into a sentence
    char sentence[256];
    sprintf(sentence, "%s. The evidence is %s. %s is involved. The location is %s. The event is %s.",
        conspiracyTheory, evidence, person, location, event);

    // Print the sentence
    printf("%s\n", sentence);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate 100 random conspiracy theories
    for (int i = 0; i < 100; i++) {
        generateConspiracyTheory();
    }

    return 0;
}