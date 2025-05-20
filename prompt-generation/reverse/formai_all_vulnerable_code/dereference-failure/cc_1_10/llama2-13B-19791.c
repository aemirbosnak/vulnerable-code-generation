//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 20

struct phone_book {
    char name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_NUMBER_LENGTH];
};

int main() {
    struct phone_book *phone_book = calloc(1, sizeof(struct phone_book));

    // Brave adventurer, prepare to embark on a quest for knowledge!
    printf("Welcome, brave adventurer, to the land of Phone Book!\n");

    // The Phone Book is a mystical tome filled with the knowledge of the ages.
    printf("Would you like to add a new entry to the Phone Book? (y/n): ");
    char input = getchar();
    if (input == 'y') {
        // The Phone Book is guarded by a fierce dragon, but fear not!
        printf("Enter the name of the person you wish to contact: ");
        fgets(phone_book->name, MAX_NAME_LENGTH, stdin);
        printf("Enter the person's phone number: ");
        fgets(phone_book->phone_number, MAX_PHONE_NUMBER_LENGTH, stdin);
        printf("You have added %s to the Phone Book!\n", phone_book->name);
    } else {
        // The Phone Book is a dangerous place, but with courage and cunning,
        // you can find the knowledge you seek.
        printf("You have chosen not to add an entry to the Phone Book. "
               "Pity, for the knowledge within is vast and true.\n");
    }

    // The Phone Book is a powerful tool, but beware the consequences of its use.
    printf("Would you like to look up a phone number? (y/n): ");
    input = getchar();
    if (input == 'y') {
        // The Phone Book is a mysterious tome, its secrets hidden in plain sight.
        printf("Enter the name of the person you wish to look up: ");
        fgets(phone_book->name, MAX_NAME_LENGTH, stdin);
        printf("The phone number for %s is %s.\n", phone_book->name,
               phone_book->phone_number);
    } else {
        // The Phone Book is a dangerous place, and those who seek its knowledge
        // too eagerly may be consumed by its power.
        printf("You have chosen not to look up a phone number. "
               "The Phone Book remains a mystery, for now.\n");
    }

    // The Phone Book is a weapon of great power, but use it wisely.
    printf("Would you like to delete an entry from the Phone Book? (y/n): ");
    input = getchar();
    if (input == 'y') {
        // The Phone Book is a sacred text, and its knowledge must be respected.
        printf("Enter the name of the person you wish to delete: ");
        fgets(phone_book->name, MAX_NAME_LENGTH, stdin);
        printf("You have deleted %s from the Phone Book.\n", phone_book->name);
    } else {
        // The Phone Book is a dangerous place, and those who seek its knowledge
        // too eagerly may be consumed by its power.
        printf("You have chosen not to delete an entry from the Phone Book. "
               "The knowledge within remains unchanged.\n");
    }

    // The Phone Book is a journey, and those who embark on it must be prepared
    // for the challenges that lie ahead.
    printf("Your journey through the Phone Book has come to an end. "
           "May the knowledge you have gained serve you well in your future endeavors.\n");

    return 0;
}