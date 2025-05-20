//Falcon2-11B DATASET v1.0 Category: Spell checking ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a word is present in a dictionary
int isWordPresent(char *word, char **dictionary) {
    char *temp = strdup(word);
    int i;
    for (i = 0; dictionary[i]!= NULL; i++) {
        if (strcmp(temp, dictionary[i]) == 0) {
            free(temp);
            return 1;
        }
    }
    free(temp);
    return 0;
}

// Function to check spelling of a word
int checkSpelling(char *word) {
    char *dictionary[100];
    int i;
    for (i = 0; i < 100; i++) {
        dictionary[i] = strdup(NULL);
    }
    dictionary[0] = "apple";
    dictionary[1] = "banana";
    dictionary[2] = "cherry";
    dictionary[3] = "date";
    dictionary[4] = "elderberry";
    dictionary[5] = "fig";
    dictionary[6] = "grape";
    dictionary[7] = "honeydew";
    dictionary[8] = "jackfruit";
    dictionary[9] = "kiwi";
    dictionary[10] = "lemon";
    dictionary[11] = "mango";
    dictionary[12] = "nectarine";
    dictionary[13] = "orange";
    dictionary[14] = "peach";
    dictionary[15] = "pineapple";
    dictionary[16] = "plum";
    dictionary[17] = "quince";
    dictionary[18] = "raspberry";
    dictionary[19] = "strawberry";
    dictionary[20] = "tamarind";
    dictionary[21] = "watermelon";
    dictionary[22] = "xigua";
    dictionary[23] = "yuzu";
    dictionary[24] = "zucchini";

    if (isWordPresent(word, dictionary) == 1) {
        printf("%s is a valid word\n", word);
    } else {
        printf("%s is an invalid word\n", word);
    }
}

int main() {
    char word[100];
    printf("Enter a word: ");
    fgets(word, sizeof(word), stdin);
    word[strcspn(word, "\n")] = '\0'; // Remove the newline character from the input string
    checkSpelling(word);
    return 0;
}