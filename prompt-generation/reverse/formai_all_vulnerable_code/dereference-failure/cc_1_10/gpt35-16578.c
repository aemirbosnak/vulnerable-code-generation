//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct representing a Toy */
typedef struct Toy {
    char *name;
    char *type;
    int age;
} Toy;

/* Function to parse the XML file */
void parseXML(char *filename, Toy **toys, int *numToys) {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int i = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Unable to open file.\n");
        exit(EXIT_FAILURE);
    }

    // Count the number of toys in the XML file
    while ((read = getline(&line, &len, fp)) != -1) {
        if (strstr(line, "<Toy>") != NULL) {
            (*numToys)++;
        }
    }

    // Allocate memory for the toys array
    *toys = (Toy*)malloc((*numToys) * sizeof(Toy));

    // Reset file pointer
    fseek(fp, 0, SEEK_SET);

    // Parse through the XML file and populate the toys array
    while ((read = getline(&line, &len, fp)) != -1) {
        if (strstr(line, "<Toy>") != NULL) {
            (*toys)[i].name = (char*)malloc(100 * sizeof(char));
            (*toys)[i].type = (char*)malloc(100 * sizeof(char));
            i++;
        }
        else if (strstr(line, "<Name>") != NULL) {
            char *start = strchr(line, '>') + 1;
            char *end = strchr(line, '<');
            strncpy((*toys)[i-1].name, start, end-start);
        }
        else if (strstr(line, "<Type>") != NULL) {
            char *start = strchr(line, '>') + 1;
            char *end = strchr(line, '<');
            strncpy((*toys)[i-1].type, start, end-start);
        }
        else if (strstr(line, "<Age>") != NULL) {
            char *start = strchr(line, '>') + 1;
            char *end = strchr(line, '<');
            (*toys)[i-1].age = atoi(start);
        }
    }

    // Close the file and free the line memory
    fclose(fp);
    if (line) {
        free(line);
    }
}

/* Main function */
int main(void) {
    Toy *toys;
    int numToys = 0;

    // Parse the XML file
    parseXML("toys.xml", &toys, &numToys);

    // Print the toy details
    for (int i = 0; i < numToys; i++) {
        printf("Toy %d:\n", i+1);
        printf("Name: %s\n", toys[i].name);
        printf("Type: %s\n", toys[i].type);
        printf("Age: %d\n", toys[i].age);
        printf("\n");
    }

    // Free the memory allocated for toys array
    for (int i = 0; i < numToys; i++) {
        free(toys[i].name);
        free(toys[i].type);
    }
    free(toys);

    return 0;
}