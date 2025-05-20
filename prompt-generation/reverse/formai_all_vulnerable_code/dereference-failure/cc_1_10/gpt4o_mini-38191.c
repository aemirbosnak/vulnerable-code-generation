//GPT-4o-mini DATASET v1.0 Category: Data mining ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_OCCUPATIONS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char occupation[MAX_NAME_LENGTH];
} User;

void parseLine(char *line, User *user) {
    char *token = strtok(line, ",");
    strcpy(user->name, token);

    token = strtok(NULL, ",");
    user->age = atoi(token);

    token = strtok(NULL, ",");
    strcpy(user->occupation, token);
}

void analyzeData(const char *filename) {
    FILE *file = fopen(filename, "r");
    if(!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return;
    }

    User users[100];
    int userCount = 0;
    int ageSum = 0;
    int ageCount = 0;
    int occupationCount[MAX_OCCUPATIONS] = {0};
    char occupations[MAX_OCCUPATIONS][MAX_NAME_LENGTH];
    int uniqueOccupationCount = 0;

    char line[MAX_LINE_LENGTH];

    while(fgets(line, sizeof(line), file)) {
        User user;
        parseLine(line, &user);

        // Collect age details
        ageSum += user.age;
        ageCount++;

        // Collect occupation details
        int found = 0;
        for(int i = 0; i < uniqueOccupationCount; i++) {
            if(strcmp(occupations[i], user.occupation) == 0) {
                occupationCount[i]++;
                found = 1;
                break;
            }
        }
        if(!found && uniqueOccupationCount < MAX_OCCUPATIONS) {
            strcpy(occupations[uniqueOccupationCount], user.occupation);
            occupationCount[uniqueOccupationCount] = 1;
            uniqueOccupationCount++;
        }

        users[userCount] = user;
        userCount++;
    }

    fclose(file);

    // Calculate average age
    double averageAge = (double)ageSum / ageCount;

    // Find the most common occupation
    int maxCount = 0;
    char mostFrequentOccupation[MAX_NAME_LENGTH];
    for(int i = 0; i < uniqueOccupationCount; i++) {
        if(occupationCount[i] > maxCount) {
            maxCount = occupationCount[i];
            strcpy(mostFrequentOccupation, occupations[i]);
        }
    }

    // Display the analysis results
    printf("Number of users: %d\n", userCount);
    printf("Average Age: %.2f\n", averageAge);
    printf("Most Frequent Occupation: %s (count: %d)\n", mostFrequentOccupation, maxCount);
}

int main(int argc, char **argv) {
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <data_file.csv>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    analyzeData(filename);

    return EXIT_SUCCESS;
}