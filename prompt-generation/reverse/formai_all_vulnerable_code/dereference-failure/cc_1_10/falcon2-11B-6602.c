//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 1000
#define MAX_COL_LEN 1000

typedef struct {
    char* name;
    char* age;
    char* gender;
    char* occupation;
} Person;

void read_csv(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }
    
    char line[MAX_LINE_LEN];
    while (fgets(line, sizeof(line), file)!= NULL) {
        if (line[0] == '#') {
            continue;
        }
        
        char* tokens[MAX_COL_LEN];
        char* token = strtok(line, ",");
        int num_cols = 0;
        while (token!= NULL) {
            tokens[num_cols] = token;
            num_cols++;
            token = strtok(NULL, ",");
        }
        
        Person person;
        person.name = malloc(strlen(tokens[0]) + 1);
        strcpy(person.name, tokens[0]);
        person.age = malloc(strlen(tokens[1]) + 1);
        strcpy(person.age, tokens[1]);
        person.gender = malloc(strlen(tokens[2]) + 1);
        strcpy(person.gender, tokens[2]);
        person.occupation = malloc(strlen(tokens[3]) + 1);
        strcpy(person.occupation, tokens[3]);
        
        printf("%s, %s, %s, %s\n", person.name, person.age, person.gender, person.occupation);
        free(person.name);
        free(person.age);
        free(person.gender);
        free(person.occupation);
    }
    
    fclose(file);
}

int main() {
    read_csv("people.csv");
    return 0;
}