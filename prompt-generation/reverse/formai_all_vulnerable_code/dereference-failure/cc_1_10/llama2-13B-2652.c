//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NAME_LENGTH 25
#define MAX_PHONE_NUMBER_LENGTH 10

// Function to calculate the number of digits in a number
int numDigits(int n) {
    int count = 0;
    while (n > 0) {
        count++;
        n /= 10;
    }
    return count;
}

// Function to format a phone number with parentheses and commas
char *formatPhoneNumber(int phoneNumber) {
    char *number = malloc(numDigits(phoneNumber) + 1);
    int i = 0;
    while (phoneNumber > 0) {
        number[i++] = phoneNumber % 10 + '0';
        phoneNumber /= 10;
    }
    number[i] = '\0';
    return number;
}

// Function to create a phone book entry
struct phoneBookEntry {
    char name[MAX_NAME_LENGTH];
    char phoneNumber[MAX_PHONE_NUMBER_LENGTH];
};

struct phoneBookEntry createPhoneBookEntry(char *name, int phoneNumber) {
    struct phoneBookEntry entry;
    strcpy(entry.name, name);
    strcpy(entry.phoneNumber, formatPhoneNumber(phoneNumber));
    return entry;
}

int main() {
    // Create a phone book with 10 entries
    struct phoneBookEntry phoneBook[10];
    for (int i = 0; i < 10; i++) {
        char name[MAX_NAME_LENGTH];
        int phoneNumber;
        printf("Enter name and phone number for entry %d: ", i + 1);
        fgets(name, MAX_NAME_LENGTH, stdin);
        sscanf(name, "%d", &phoneNumber);
        phoneBook[i] = createPhoneBookEntry(name, phoneNumber);
    }

    // Print the phone book
    for (int i = 0; i < 10; i++) {
        printf("%d: %s %s\n", i + 1, phoneBook[i].name, phoneBook[i].phoneNumber);
    }

    return 0;
}