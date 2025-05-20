//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: Alan Turing
// A delightful voyage into the realm of Alan Turing's greedy algorithms

// Preamble: Let us embark on a quest to decipher the cryptic Enigma machine

#include <stdio.h>  // A hearty handshake with the world of input and output streams
#include <stdlib.h> // A trusted companion for dynamic memory allocation and more

// Constants: Unwavering truths that guide our journey
#define MAX_ROTORS 5 // The Enigma machine's maximum rotor capacity
#define MIN_ROTORS 1 // Its irreducible minimum for any meaningful encryption

// Types: A tapestry of abstractions

// An Enigma rotor, the heart of the encryption mechanism
typedef struct rotor {
    int position;       // Its current rotational position
    int ring_setting;   // Its offset from the absolute position
    char wiring[26];   // A permutation of the alphabet, defining its encryption behaviour
} Rotor;

// The Enigma machine, a symphony of interconnected rotors
typedef struct enigma {
    Rotor rotors[MAX_ROTORS];   // An array of rotors, the core of the encryption process
    int num_rotors;             // The current number of rotors in use
} Enigma;

// Functions: Our trusty tools for manipulating the Enigma machine

// Creates a new Enigma machine
Enigma* create_enigma() {
    Enigma* enigma = malloc(sizeof(Enigma));  // Allocate memory for the machine
    enigma->num_rotors = 0;                  // Initialize with no rotors
    return enigma;
}

// Adds a rotor to the Enigma machine
void add_rotor(Enigma* enigma, Rotor rotor) {
    if (enigma->num_rotors >= MAX_ROTORS) {  // Respect the machine's rotor capacity
        printf("Enigma: I can't accommodate any more rotors!\n");
        return;
    }
    enigma->rotors[enigma->num_rotors++] = rotor;  // Add the rotor to the array
}

// Encrypts a character using the Enigma machine
char encrypt_char(Enigma* enigma, char c) {
    // Iterate through the rotors, applying their encryption logic
    for (int i = 0; i < enigma->num_rotors; i++) {
        int index = c - 'A';                                  // Convert character to index
        index += enigma->rotors[i].ring_setting;                  // Apply ring setting
        index -= enigma->rotors[i].position;                     // Apply rotor position
        index %= 26;                                           // Wrap around alphabet
        index += 'A';                                          // Convert index to character
        c = enigma->rotors[i].wiring[index - 'A'];                // Apply rotor wiring
    }
    return c;
}

// Rotates the Enigma machine's rotors
void rotate_rotors(Enigma* enigma) {
    // Rotate the first rotor and propagate the rotation to subsequent rotors
    for (int i = 0; i < enigma->num_rotors; i++) {
        enigma->rotors[i].position = (enigma->rotors[i].position + 1) % 26;  // Rotate rotor position
        if (i < enigma->num_rotors - 1 && enigma->rotors[i].position == 0) {  // If first rotor at 0, rotate next
            enigma->rotors[i + 1].position = (enigma->rotors[i + 1].position + 1) % 26;
        }
    }
}

// A sample Enigma rotor with its wiring and settings
Rotor sample_rotor = {
    .position = 0,
    .ring_setting = 0,
    .wiring = "EKMFLGDQVZNTOWYHXUSPAIBRCJ"
};

// Let us now, through the lens of a curious observer, witness the Enigma machine in action
int main() {
    Enigma* enigma = create_enigma();  // Our trusty Enigma machine
    add_rotor(enigma, sample_rotor);  // Let's add a single rotor for simplicity

    printf("Original message: ATTACK\n");

    // Encrypt the message character by character
    char encrypted_message[7];
    for (int i = 0; i < 6; i++) {
        encrypted_message[i] = encrypt_char(enigma, "ATTACK"[i]);
        rotate_rotors(enigma);  // Rotate the rotors after each encryption
    }
    encrypted_message[6] = '\0';  // Terminate the string

    printf("Encrypted message: %s\n", encrypted_message);

    return 0;  // Mission accomplished!
}