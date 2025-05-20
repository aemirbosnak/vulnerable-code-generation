//FormAI DATASET v1.0 Category: File handling ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

struct Person {
    char name[50];
    int age;
};

int main() {
    FILE *fp;
    char filename[50], *line;
    struct Person p1, p2;

    // Get the filename from user input
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file for writing
    fp = fopen(filename, "w");

    // Write to the file
    printf("\nEnter the name of person 1: ");
    scanf("%s", p1.name);
    printf("Enter the age of person 1: ");
    scanf("%d", &p1.age);
    fprintf(fp, "%s %d\n", p1.name, p1.age);

    printf("\nEnter the name of person 2: ");
    scanf("%s", p2.name);
    printf("Enter the age of person 2: ");
    scanf("%d", &p2.age);
    fprintf(fp, "%s %d", p2.name, p2.age);

    // Close the file
    fclose(fp);

    // Open the file for reading
    fp = fopen(filename, "r");

    // Read from the file and print to console
    line = malloc(sizeof(char) * 100);
    while (fgets(line, 100, fp)) {
        printf("\n%s", line);
    }

    // Close the file and free memory
    fclose(fp);
    free(line);

    return 0;
}