//FormAI DATASET v1.0 Category: Data mining ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1000
#define MAX_DATA 10000

struct Data {
    char name[20];
    int age;
    float height;
};

struct Data dataset[MAX_DATA]; // Declare a global dataset

int main() {
    FILE *fp;
    char line[MAX_LINE];
    int count = 0;

    // Open the data file and read the contents into the dataset
    fp = fopen("data.txt", "r");
    while (fgets(line, MAX_LINE, fp)) {
        sscanf(line, "%s %d %f", dataset[count].name, &dataset[count].age, &dataset[count].height);
        count++;
    }
    fclose(fp);

    // Print out the original dataset
    printf("Original dataset:\n");
    for (int i = 0; i < count; i++) {
        printf("%s %d %f\n", dataset[i].name, dataset[i].age, dataset[i].height);
    }

    // Sort the dataset by age in ascending order using a simple bubble sort algorithm
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (dataset[j].age > dataset[j+1].age) {
                // Swap the positions of the two elements
                struct Data temp = dataset[j];
                dataset[j] = dataset[j+1];
                dataset[j+1] = temp;
            }
        }
    }

    // Print out the sorted dataset
    printf("\nSorted dataset:\n");
    for (int i = 0; i < count; i++) {
        printf("%s %d %f\n", dataset[i].name, dataset[i].age, dataset[i].height);
    }

    return 0;
}