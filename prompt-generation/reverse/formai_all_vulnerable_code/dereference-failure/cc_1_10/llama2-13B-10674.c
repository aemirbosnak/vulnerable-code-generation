//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: surprised
// Oh my gosh, I can't believe I'm actually writing a phone book program!
// I mean, who even uses phone books anymore?! 😱
// Okay, okay, I'll stop complaining and just get on with it. 😅

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Gotta have a function to add a new phone number, right? 🤔
void addPhoneNumber(char **phoneBook, int *numEntries, const char *name, const char *phone) {
    // Oh wow, I'm actually writing code! 😲
    // I hope I don't mess this up... 😬

    // Check if the name is already in the phone book. 🤔
    int i;
    for (i = 0; i < *numEntries; i++) {
        if (strcmp(phoneBook[i], name) == 0) {
            // Oops, there's already an entry with that name! 😳
            // Better update the phone number for that entry. 💡
            phoneBook[i] = phone;
            break;
        }
    }

    // If we didn't find the name in the phone book, add a new entry. 🎉
    if (i == *numEntries) {
        // Increment the number of entries in the phone book. 📈
        (*numEntries)++;

        // Allocate memory for a new entry in the phone book. 🔀
        char *newEntry = (char *)malloc(sizeof(char) * (strlen(name) + 1));
        strcpy(newEntry, name);
        strcat(newEntry, " ");
        strcat(newEntry, phone);

        // Add the new entry to the phone book. 📝
        phoneBook[*numEntries - 1] = newEntry;
    }
}

int main() {
    // Create a phone book with some initial entries. 📝
    char **phoneBook = (char **)malloc(sizeof(char *) * 5);
    int numEntries = 0;

    // Add some phone numbers! 📞
    addPhoneNumber(phoneBook, &numEntries, "John Doe", "555-1234");
    addPhoneNumber(phoneBook, &numEntries, "Jane Doe", "555-5678");
    addPhoneNumber(phoneBook, &numEntries, "Bob Smith", "555-9012");

    // Print out the phone book. 📝
    for (int i = 0; i < numEntries; i++) {
        printf("%d. %s %s\n", i + 1, phoneBook[i], phoneBook[i + numEntries]);
    }

    return 0;
}