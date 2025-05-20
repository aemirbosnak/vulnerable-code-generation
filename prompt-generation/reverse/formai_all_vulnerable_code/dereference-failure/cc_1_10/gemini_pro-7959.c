//GEMINI-pro DATASET v1.0 Category: String manipulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom string manipulation functions
char* my_strrev(char* str) {
    int len = strlen(str);
    char* reversed = malloc(len + 1);
    for (int i = 0, j = len - 1; i < len; i++, j--) {
        reversed[i] = str[j];
    }
    reversed[len] = '\0';
    return reversed;
}

char* my_strtoupper(char* str) {
    int len = strlen(str);
    char* uppercased = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        uppercased[i] = toupper(str[i]);
    }
    uppercased[len] = '\0';
    return uppercased;
}

char* my_strlowercase(char* str) {
    int len = strlen(str);
    char* lowercased = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        lowercased[i] = tolower(str[i]);
    }
    lowercased[len] = '\0';
    return lowercased;
}

int main() {
    // Immersive C String Manipulation Adventure

    // Introduction
    printf("Welcome to the immersive C String Manipulation Adventure!\n");
    printf("Get ready to embark on a journey where you'll master the art of string manipulation.\n\n");

    // Level 1: The Enchanted Forest of Strings
    printf("**Level 1: The Enchanted Forest of Strings**\n");
    printf("You enter a lush forest filled with towering trees of strings.\n");
    printf("Your mission is to traverse this forest, manipulating strings along the way.\n\n");

    // Task 1: Reverse the Enchanting Strings
    printf("**Task 1: Reverse the Enchanting Strings**\n");
    printf("You encounter enchanted strings that have been scrambled.\n");
    printf("Use your string manipulation skills to reverse these strings and restore their true form.\n");

    char* enchantedString1 = "olleh";
    char* enchantedString2 = "dlroW";
    char* enchantedString3 = "siht";

    printf("Enchanted String 1: %s\n", enchantedString1);
    printf("Reversed String: %s\n", my_strrev(enchantedString1));

    printf("Enchanted String 2: %s\n", enchantedString2);
    printf("Reversed String: %s\n", my_strrev(enchantedString2));

    printf("Enchanted String 3: %s\n", enchantedString3);
    printf("Reversed String: %s\n", my_strrev(enchantedString3));

    // Task 2: Ascend the Majestic Mountain of Capitalization
    printf("**Task 2: Ascend the Majestic Mountain of Capitalization**\n");
    printf("As you climb higher into the forest, you encounter strings that have lost their capitalization.\n");
    printf("Use your string manipulation skills to capitalize these strings and bring them to their fullest potential.\n");

    char* lowercaseString1 = "the quick brown fox";
    char* lowercaseString2 = "once upon a time";
    char* lowercaseString3 = "hello world";

    printf("Lowercase String 1: %s\n", lowercaseString1);
    printf("Capitalized String: %s\n", my_strtoupper(lowercaseString1));

    printf("Lowercase String 2: %s\n", lowercaseString2);
    printf("Capitalized String: %s\n", my_strtoupper(lowercaseString2));

    printf("Lowercase String 3: %s\n", lowercaseString3);
    printf("Capitalized String: %s\n", my_strtoupper(lowercaseString3));

    // Task 3: Descend into the Mysterious Cave of Lowercase
    printf("**Task 3: Descend into the Mysterious Cave of Lowercase**\n");
    printf("As you journey deeper into the forest, you stumble upon a cave shrouded in darkness.\n");
    printf("Inside, you find strings that have been transformed into all uppercase.\n");
    printf("Use your string manipulation skills to lowercase these strings and restore their humility.\n");

    char* uppercaseString1 = "THE QUICK BROWN FOX";
    char* uppercaseString2 = "ONCE UPON A TIME";
    char* uppercaseString3 = "HELLO WORLD";

    printf("Uppercase String 1: %s\n", uppercaseString1);
    printf("Lowercase String: %s\n", my_strlowercase(uppercaseString1));

    printf("Uppercase String 2: %s\n", uppercaseString2);
    printf("Lowercase String: %s\n", my_strlowercase(uppercaseString2));

    printf("Uppercase String 3: %s\n", uppercaseString3);
    printf("Lowercase String: %s\n", my_strlowercase(uppercaseString3));

    // Conclusion
    printf("\nCongratulations! You have successfully completed the immersive C String Manipulation Adventure.\n");
    printf("You have mastered the art of string manipulation and emerged as a true string manipulator.\n");
    printf("May your strings always be well-crafted and your adventures continue to be filled with creativity and innovation.\n");

    return 0;
}