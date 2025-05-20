//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>

// Function to convert characters to Morse code
char* charToMorse(char c) {
    static char result[6];  // Morse code can have up to 5 characters (+ null terminator)
    if (c == 'a' || c == 'A') strcpy(result, ".-");
    else if (c == 'b' || c == 'B') strcpy(result, "-...");
    else if (c == 'c' || c == 'C') strcpy(result, "-.-.");
    else if (c == 'd' || c == 'D') strcpy(result, "-..");
    else if (c == 'e' || c == 'E') strcpy(result, ".");
    else if (c == 'f' || c == 'F') strcpy(result, "..-.");
    else if (c == 'g' || c == 'G') strcpy(result, "--.");
    else if (c == 'h' || c == 'H') strcpy(result, "....");
    else if (c == 'i' || c == 'I') strcpy(result, "..");
    else if (c == 'j' || c == 'J') strcpy(result, ".---");
    else if (c == 'k' || c == 'K') strcpy(result, "-.-");
    else if (c == 'l' || c == 'L') strcpy(result, ".-..");
    else if (c == 'm' || c == 'M') strcpy(result, "--");
    else if (c == 'n' || c == 'N') strcpy(result, "-.");
    else if (c == 'o' || c == 'O') strcpy(result, "---");
    else if (c == 'p' || c == 'P') strcpy(result, ".--.");
    else if (c == 'q' || c == 'Q') strcpy(result, "--.-");
    else if (c == 'r' || c == 'R') strcpy(result, ".-.");
    else if (c == 's' || c == 'S') strcpy(result, "...");
    else if (c == 't' || c == 'T') strcpy(result, "-");
    else if (c == 'u' || c == 'U') strcpy(result, "..-");
    else if (c == 'v' || c == 'V') strcpy(result, "...-");
    else if (c == 'w' || c == 'W') strcpy(result, ".--");
    else if (c == 'x' || c == 'X') strcpy(result, "-..-");
    else if (c == 'y' || c == 'Y') strcpy(result, "-.--");
    else if (c == 'z' || c == 'Z') strcpy(result, "--..");
    else if (c == '0') strcpy(result, "-----");
    else if (c == '1') strcpy(result, ".----");
    else if (c == '2') strcpy(result, "..---");
    else if (c == '3') strcpy(result, "...--");
    else if (c == '4') strcpy(result, "....-");
    else if (c == '5') strcpy(result, ".....");
    else if (c == '6') strcpy(result, "-....");
    else if (c == '7') strcpy(result, "--...");
    else if (c == '8') strcpy(result, "---..");
    else if (c == '9') strcpy(result, "----.");
    else if (c == '.') strcpy(result, ".-.-.-");
    else if (c == ',') strcpy(result, "--..--");
    else if (c == '?') strcpy(result, "..--..");
    else if (c == '\'') strcpy(result, ".----.");
    else if (c == '!') strcpy(result, "-.-.--");
    else if (c == '/') strcpy(result, "-..-.");
    else if (c == '(' || c == ')') strcpy(result, "-.--.-");
    else if (c == '&') strcpy(result, ".-...");
    else if (c == ':') strcpy(result, "---...");
    else if (c == ';') strcpy(result, "-.-.-.");
    else if (c == '=') strcpy(result, "-...-");
    else if (c == '+') strcpy(result, ".-.-.");
    else if (c == '-') strcpy(result, "-....-");
    else if (c == '_') strcpy(result, "..--.-");
    else if (c == '\"') strcpy(result, ".-..-.");
    else if (c == '$') strcpy(result, "...-..-");
    else if (c == '@') strcpy(result, ".--.-.");
    else strcpy(result, "");  // Invalid character returns an empty string
    return result;
}

// Function to convert a string to Morse code
void stringToMorse(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        char c = str[i];
        char* morse = charToMorse(c);
        printf("%s ", morse);
    }
    printf("\n");
}

int main() {
    char* message = "Hello, world!";
    stringToMorse(message);
    return 0;
}