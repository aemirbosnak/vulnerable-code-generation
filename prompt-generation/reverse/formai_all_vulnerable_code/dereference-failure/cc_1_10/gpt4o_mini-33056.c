//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define ERROR_CHECK(expr, msg) \
    do { \
        if ((expr) != 0) { \
            fprintf(stderr, "%s: %s\n", msg, strerror(errno)); \
            exit(EXIT_FAILURE); \
        } \
    } while (0)

typedef struct {
    char name[50];
    int age;
    float height;
} Person;

void prompt_person_details(Person *p) {
    printf("Enter name: ");
    fgets(p->name, sizeof(p->name), stdin);
    p->name[strcspn(p->name, "\n")] = 0;  // Removing newline character

    printf("Enter age: ");
    ERROR_CHECK(scanf("%d", &p->age) == 0, "Invalid age input");
    getchar();  // Clear the newline character from buffer

    printf("Enter height in meters: ");
    ERROR_CHECK(scanf("%f", &p->height) == 0, "Invalid height input");
    getchar();  // Clear the newline character from buffer
}

void display_person_details(const Person *p) {
    printf("Person Details:\n");
    printf("Name: %s\n", p->name);
    printf("Age: %d\n", p->age);
    printf("Height: %.2f meters\n", p->height);
}

void save_person_to_file(const Person *p, const char *filename) {
    FILE *file = fopen(filename, "a");
    ERROR_CHECK(file == NULL, "Failed to open file");

    fprintf(file, "%s,%d,%.2f\n", p->name, p->age, p->height);
    
    ERROR_CHECK(fclose(file), "Failed to close file");
}

void read_people_from_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    ERROR_CHECK(file == NULL, "Failed to open file");

    Person p;
    printf("People in file:\n");
    while (fgets(p.name, sizeof(p.name), file)) {
        char *token = strtok(p.name, ",");
        strcpy(p.name, token);
        token = strtok(NULL, ",");
        p.age = atoi(token);
        token = strtok(NULL, ",");
        p.height = atof(token);
        
        display_person_details(&p);
    }
    
    ERROR_CHECK(fclose(file), "Failed to close file");
}

int main() {
    Person p;
    char filename[100];

    printf("Enter the filename for saving person details: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0;  // Removing newline character

    while (1) {
        prompt_person_details(&p);
        save_person_to_file(&p, filename);

        char choice;
        printf("Do you want to enter another person? (y/n): ");
        scanf(" %c", &choice);
        getchar();  // Clear the newline character from buffer
        if (choice != 'y') break;
    }

    read_people_from_file(filename);

    return 0;
}