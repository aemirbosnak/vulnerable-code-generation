//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

void reverse(char *str, int start, int end) {
    char temp;
    for (; start < end; start++, end--) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
    }
}

int main() {
    char name[MAX_NAME_LENGTH];
    char queenName[MAX_NAME_LENGTH] = "Lorelei Bavarian, the Queen";
    char *nameParts[3];

    printf("Enter the name of the scoundrel: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // remove newline character

    // Split the name into parts
    int i = 0;
    nameParts[i] = strtok(name, " ");
    while (nameParts[i] != NULL) {
        i++;
        nameParts[i] = strtok(NULL, " ");
    }

    // Check if the name matches the scandalous one
    if (strcmp(nameParts[0], "Sherlock") && strcmp(nameParts[1], "Holmes")) {
        printf("Sorry, I cannot help you with that name.\n");
        return 1;
    }

    // Reverse the scandalous queen's name
    int queenNameLength = strlen(queenName);
    reverse(queenName, 0, queenNameLength / 2);

    // Compare the reversed queen's name with the given name
    int nameLength = strlen(name);
    if (nameLength != queenNameLength) {
        printf("Names are not the same length.\n");
        return 1;
    }

    int j = 0;
    for (; j < nameLength; j++) {
        if (name[j] != queenName[queenNameLength - j - 1]) {
            printf("Names do not match.\n");
            return 1;
        }
    }

    printf("The scoundrel, %s, knows the secret!\n", name);

    return 0;
}