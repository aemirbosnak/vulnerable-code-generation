//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_FORTUNES 100

typedef struct Fortune {
    char description[100];
} Fortune;

typedef struct Error {
    char message[100];
} Error;

Error errors[10] = {{"Invalid option.", ""},
                    {"No fortune found.", ""},
                    {"Database error.", ""},
                    {"Memory allocation error.", ""},
                    {"Invalid input.", ""},
                    {"Out of range.", ""},
                    {"Unknown error.", ""},
                    {"Quitting program.", ""},
                    {"User input canceled.", ""},
                    {"Fortune already read.", ""}};

Fortune fortunes[MAX_FORTUNES] = {};
int fortuneCount = 0;

void loadFortunes(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: %s\n", errors[5].message);
        exit(1);
    }

    char line[100];
    int i = 0;
    while (fgets(line, sizeof(line), file)) {
        Fortune* fortune = &fortunes[i++];
        strcpy(fortune->description, line);
        fortune->description[strlen(line) - 1] = '\0';
        if (i == MAX_FORTUNES) {
            printf("Error: %s\n", errors[3].message);
            exit(1);
        }
    }

    fclose(file);
    fortuneCount = i;
}

int getFortuneIndex(int userInput) {
    if (userInput < 0 || userInput > fortuneCount) {
        printf("Error: %s\n", errors[6].message);
        return -1;
    }
    return userInput;
}

int main(int argc, char** argv) {
    srand(time(NULL));

    if (argc < 2) {
        printf("Usage: %s <fortune file>\n", argv[0]);
        printf("Error: %s\n", errors[0].message);
        return 1;
    }

    loadFortunes(argv[1]);

    while (1) {
        printf("\nWelcome to the Automated Fortune Teller!\n");
        printf("Please choose an option:\n");
        printf("1. Show a random fortune.\n");
        printf("2. Show a fortune by number.\n");
        printf("3. Quit.\n");

        char userInput[10];
        fgets(userInput, sizeof(userInput), stdin);
        userInput[strlen(userInput) - 1] = '\0';

        if (strcmp(userInput, "1") == 0) {
            int index = rand() % fortuneCount;
            printf("\nYour fortune: %s\n", fortunes[index].description);
        } else if (strcmp(userInput, "2") == 0) {
            char input[10];
            printf("Enter the number of the fortune: ");
            fgets(input, sizeof(input), stdin);
            input[strlen(input) - 1] = '\0';
            int userInputInt = atoi(input);
            int index = getFortuneIndex(userInputInt);
            if (index != -1) {
                printf("\nYour fortune: %s\n", fortunes[index].description);
            }
        } else if (strcmp(userInput, "3") == 0) {
            printf("Quitting program.\n");
            exit(0);
        } else {
            printf("Error: %s\n", errors[4].message);
        }
    }
}