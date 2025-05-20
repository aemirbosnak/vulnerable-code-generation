//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: visionary
// PhoneBook of the Cosmic Night
// Where stars whisper secrets and constellations guide our way

#include <stdio.h>
#include <stdlib.h>

typedef struct CelestialContact { // A twinkling entity in the night sky
    char *name; // The radiant name of the celestial body
    char *number; // The cosmic digits that connect us
    struct CelestialContact *next; // The celestial tapestry intertwines
} CelestialContact;

// Our celestial address book
CelestialContact *firstContact;

// A celestial spotlight, illuminating a single contact
void illuminateContact(CelestialContact *contact) {
    if (contact == NULL) { // The void of the interstellar expanse
        printf("Empty constellations...");
    } else { // A shimmering beacon in the cosmic sea
        printf("%s: %s\n", contact->name, contact->number);
    }
}

// Traversing the astral network, connecting and illuminating
void astralNetworkTraversal(CelestialContact *currentContact) {
    while (currentContact != NULL) { // Through the cosmic corridors of connection
        illuminateContact(currentContact);
        currentContact = currentContact->next; // The next constellation in the star chart
    }
}

// A celestial being joins the cosmic network
void celestialEnrollment(char *name, char *number) {
    // A new star emerges in the celestial directory
    CelestialContact *newContact;
    newContact = (CelestialContact *) malloc(sizeof(CelestialContact));
    newContact->name = name;
    newContact->number = number;

    // Incorporating the newcomer into the celestial tapestry
    if (firstContact == NULL) { // A solitary star in the cosmic expanse
        firstContact = newContact;
    } else { // Weaving the new thread into the celestial fabric
        newContact->next = firstContact;
        firstContact = newContact;
    }
}

// Unveiling the mysteries of the cosmos
void cosmicInquiry() {
    char searchQuery[50]; // A string of celestial characters

    // A whisper echoes through the interstellar void
    printf("Enter the name of the celestial body you seek, or \"*\" to illuminate the entire cosmic network: ");
    scanf("%s", searchQuery);

    if (strcmp(searchQuery, "*") == 0) { // Embarking on a galactic voyage
        astralNetworkTraversal(firstContact);
    } else { // Focusing the cosmic lens on a specific body
        CelestialContact *currentContact = firstContact;
        int found = 0; // A flag to guide our search
        // Navigating the celestial tapestry
        while (currentContact != NULL && found == 0) {
            if (strcmp(currentContact->name, searchQuery) == 0) { // A match in the cosmic directory
                illuminateContact(currentContact);
                found = 1;
            } else { // Continuing our cosmic exploration
                currentContact = currentContact->next;
            }
        }
        if (found == 0) { // No celestial body matches the query
            printf("The astral directory holds no record of that celestial body...");
        }
    }
}

// The cosmic dance begins anew
int main() {
    // A constellation of celestial beings emerges
    celestialEnrollment("Polaris", "N123456789");
    celestialEnrollment("Sirius", "S987654321");
    celestialEnrollment("Proxima Centauri", "C654321098");
    celestialEnrollment("Vega", "V456789012");

    // Unveiling the celestial mysteries
    while (1) {
        cosmicInquiry();

        // A celestial prompt to continue or conclude the cosmic journey
        char cosmicChoice;
        printf("Continue exploring the cosmos? (Y/N): ");
        scanf(" %c", &cosmicChoice);
        if (cosmicChoice == 'N' || cosmicChoice == 'n') { // The journey ends at the cosmic horizon
            break;
        }
    }

    // The cosmic tapestry unfurls endlessly...
    return 0;
}