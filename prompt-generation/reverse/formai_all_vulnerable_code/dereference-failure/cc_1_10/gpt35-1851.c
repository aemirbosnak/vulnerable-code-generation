//FormAI DATASET v1.0 Category: Database simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
    int id;
    char name[20];
    char date_of_birth[11];
    char city[20];
    char favorite_color[15];
};

int main() {
    int option = 0;
    int count = 0;
    struct person* people = malloc(sizeof(struct person));
    
    printf("Welcome to Our Database Simulation Program!\n\n");
    
    do {
        printf("Please choose an option:\n");
        printf("1. Add Person\n");
        printf("2. View People\n");
        printf("3. Exit\n");
        
        scanf("%d", &option);
        getchar(); //clear input buffer
        
        if (option == 1) {
            printf("\nPlease enter the following information:\n");
            printf("ID: ");
            scanf("%d", &people[count].id);
            getchar(); //clear input buffer
            
            printf("Name: ");
            fgets(people[count].name, 20, stdin);
            people[count].name[strlen(people[count].name) - 1] = '\0';
            
            printf("Date of Birth (MM/DD/YYYY): ");
            fgets(people[count].date_of_birth, 11, stdin);
            people[count].date_of_birth[strlen(people[count].date_of_birth) - 1] = '\0';
            
            printf("City: ");
            fgets(people[count].city, 20, stdin);
            people[count].city[strlen(people[count].city) - 1] = '\0';
            
            printf("Favorite Color: ");
            fgets(people[count].favorite_color, 15, stdin);
            people[count].favorite_color[strlen(people[count].favorite_color) - 1] = '\0';
            
            count++;
            people = realloc(people, sizeof(struct person) * (count + 1));
            
            printf("\nPerson added successfully!\n\n");
        } else if (option == 2) {
            if (count == 0) {
                printf("There are no people in the database yet.\n\n");
            } else {
                printf("\nPeople in the database:\n");
                for (int i = 0; i < count; i++) {
                    printf("\nID: %d\nName: %s\nDate of Birth: %s\nCity: %s\nFavorite Color: %s\n\n", people[i].id, people[i].name, people[i].date_of_birth, people[i].city, people[i].favorite_color);
                }
            }
        } else if (option != 3) {
            printf("Invalid option chosen. Please try again.\n\n");
        }
        
    } while (option != 3);
    
    printf("Thank you for using our Database Simulation Program!\n");
    free(people);
    return 0;
}