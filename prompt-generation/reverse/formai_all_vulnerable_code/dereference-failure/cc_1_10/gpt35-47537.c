//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

// Morse Code Lookup Table
char *morse_code[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
                      "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

// ASCII Lookup Table
char ascii[256][8];

// Signal Handler
void SIG_HANDLER(int signo) {
    printf("\n");
    exit(1);
}

// Function to initialize the ASCII Lookup Table with Morse Code
void init_lookup_table() {
    memset(ascii, 0, sizeof(ascii));
    for (int i = 0; i < 26; i++) {
        ascii['a' + i][0] = morse_code[i][0];
        ascii['a' + i][1] = morse_code[i][1];
        ascii['a' + i][2] = morse_code[i][2];
        ascii['a' + i][3] = '\0';
    }
}

// Function to convert message to Morse Code
void convert_to_morse(const char *message) {
    int len = strlen(message);
    for (int i = 0; i < len; i++) {
        if (message[i] == ' ') {
            printf("   ");
            continue;
        }
        printf("%s ", ascii[message[i]]);
        fflush(stdout);
        usleep(350000);
    }
    printf("\n");
}

int main() {

    // Initialize Signal Handler
    signal(SIGINT, SIG_HANDLER);

    // Initialize Lookup Table
    init_lookup_table();

    // User Input
    char message[100];
    printf("Enter Message: ");
    fflush(stdout);
    fgets(message, 100, stdin);

    // Convert to Morse Code
    convert_to_morse(message);

    return 0;
}