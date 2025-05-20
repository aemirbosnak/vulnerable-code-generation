//FormAI DATASET v1.0 Category: Sorting ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(char **strings, int numStrings) {
    int i, j;
    char* tempString;

    //bubble sort algorithm to sort the strings in alphabetical order
    for (i = 0; i < numStrings - 1; i++) {
        for (j = 0; j < numStrings - i - 1; j++) {
            if (strcmp(strings[j], strings[j + 1]) > 0) {
                tempString = strings[j];
                strings[j] = strings[j + 1];
                strings[j + 1] = tempString;
            }
        }
    }
}

int main() {
    int numStrings, i;
    char **strings;

    printf("Enter the number of strings: ");
    scanf("%d", &numStrings);

    strings = malloc(numStrings * sizeof(char *));

    for (i = 0; i < numStrings; i++) {
        printf("Enter string #%d: ", i + 1);

        //allocate enough memory for each string in memory
        strings[i] = malloc(100 * sizeof(char));
        scanf("%s", strings[i]);
    }

    //call sort function to sort the strings
    sort(strings, numStrings);

    //print sorted list of strings
    printf("\nSorted strings:\n");
    for (i = 0; i < numStrings; i++) {
        printf("%s\n", strings[i]);
    }

    //free the allocated memory for strings
    for (i = 0; i < numStrings; i++) {
        free(strings[i]);
    }
    free(strings);

    return 0;
}