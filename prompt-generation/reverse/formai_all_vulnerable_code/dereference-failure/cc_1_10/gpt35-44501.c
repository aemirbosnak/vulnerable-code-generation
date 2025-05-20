//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayMenu();
void startQuiz();
void addElement();
void searchElement();
void deleteElement();
void viewAllElements();

typedef struct{
    char symbol[3];
    char name[25];
    int atomicNumber;
    char state[10];
    float atomicMass;
}Element;

void main(){
    printf("Welcome to the Sherlock Holmes periodic table quiz program!\n\n");
    displayMenu();
}

void displayMenu(){
    int option;

    printf("\nPlease select an option:\n");
    printf("1. Start quiz\n");
    printf("2. Add an element to the periodic table\n");
    printf("3. Search for an element in the periodic table\n");
    printf("4. Delete an element from the periodic table\n");
    printf("5. View all elements in the periodic table\n");
    printf("6. Quit the program\n");

    scanf("%d", &option);

    switch(option){
        case 1: 
            startQuiz(); 
            break;
        case 2: 
            addElement(); 
            break;
        case 3: 
            searchElement(); 
            break;
        case 4: 
            deleteElement(); 
            break;
        case 5: 
            viewAllElements(); 
            break;
        case 6: 
            printf("Thank you for using the Sherlock Holmes periodic table quiz program!\n"); 
            exit(0);
        default: 
            printf("Invalid option, please try again.\n"); 
            displayMenu();
    }
}

void startQuiz(){
    Element elements[118];
    int score = 0;
    char answer[3];

    printf("\nWelcome to the Sherlock Holmes periodic table quiz!\n");
    printf("Answer the following questions to test your knowledge of the elements.\n\n");

    //populate the elements array with data from the periodic table
    FILE *fp;
    char buffer[100];

    fp = fopen("periodic_table.txt", "r");
    if(fp == NULL){
        printf("Error opening file.");
        exit(1);
    }

    int i = 0;
    while(fgets(buffer, 100, fp) != NULL){
        char *token = strtok(buffer, ",");
        strcpy(elements[i].symbol, token);
        token=strtok(NULL, ",");
        strcpy(elements[i].name, token);
        token=strtok(NULL, ",");
        elements[i].atomicNumber = atoi(token);
        token=strtok(NULL, ",");
        strcpy(elements[i].state, token);
        token=strtok(NULL, ",");
        elements[i].atomicMass = strtof(token, NULL);
        i++;
    }

    fclose(fp);

    //start the quiz
    int totalQuestions = 10;

    for(int i = 0; i < totalQuestions; i++){
        int elementIndex = rand() % 118;
        Element questionElement = elements[elementIndex];

        printf("Question %d: What is the symbol for %s?\n", i+1, questionElement.name);
        scanf("%s", answer);

        if(strcmp(answer, questionElement.symbol) == 0){
            printf("Correct! Well done, Sherlock!\n\n");
            score++;
        } else{
            printf("Incorrect! The correct answer is %s.\n\n", questionElement.symbol);
        }
    }

    printf("Quiz complete! You scored %d out of %d.\n\n", score, totalQuestions);

    displayMenu();
}

void addElement(){
    FILE *fp;
    fp = fopen("periodic_table.txt", "a");

    Element newElement;

    printf("\nEnter the symbol for the new element (max 2 characters):\n");
    scanf("%s", newElement.symbol);

    printf("Enter the name for the new element:\n");
    scanf("%s", newElement.name);

    printf("Enter the atomic number for the new element:\n");
    scanf("%d", &newElement.atomicNumber);

    printf("Enter the state for the new element (solid, liquid, or gas):\n");
    scanf("%s", newElement.state);

    printf("Enter the atomic mass for the new element:\n");
    scanf("%f", &newElement.atomicMass);

    fprintf(fp, "\n%s,%s,%d,%s,%.4f", newElement.symbol, newElement.name, newElement.atomicNumber, newElement.state, newElement.atomicMass);

    fclose(fp);

    printf("\nElement added to the periodic table! Well done, Sherlock!\n\n");

    displayMenu();
}

void searchElement(){
    Element elements[118];

    //populate the elements array with data from the periodic table
    FILE *fp;
    char buffer[100];

    fp = fopen("periodic_table.txt", "r");
    if(fp == NULL){
        printf("Error opening file.");
        exit(1);
    }

    int i = 0;
    while(fgets(buffer, 100, fp) != NULL){
        char *token = strtok(buffer, ",");
        strcpy(elements[i].symbol, token);
        token=strtok(NULL, ",");
        strcpy(elements[i].name, token);
        token=strtok(NULL, ",");
        elements[i].atomicNumber = atoi(token);
        token=strtok(NULL, ",");
        strcpy(elements[i].state, token);
        token=strtok(NULL, ",");
        elements[i].atomicMass = strtof(token, NULL);
        i++;
    }

    fclose(fp);

    char searchName[25];
    printf("\nEnter the name of the element you want to search for:\n");
    scanf("%s", searchName);

    int found = 0;

    for(int i = 0; i < 118; i++){
        if(strcmp(searchName, elements[i].name) == 0){
            printf("Symbol: %s\n", elements[i].symbol);
            printf("Name: %s\n", elements[i].name);
            printf("Atomic Number: %d\n", elements[i].atomicNumber);
            printf("State: %s\n", elements[i].state);
            printf("Atomic Mass: %.4f\n\n", elements[i].atomicMass);
            found = 1;
            break;
        }
    }

    if(!found){
        printf("Element not found in the periodic table. Better luck next time, Sherlock!\n\n");
    } else{
        printf("Well done, Sherlock! Another case solved!\n\n");
    }

    displayMenu();
}

void deleteElement(){
    FILE *fp;
    char buffer[1000], deleteName[25], temp[] = "temp.txt";

    fp = fopen("periodic_table.txt", "r");
    if(fp == NULL){
        printf("Error opening file.");
        exit(1);
    }
    FILE *tempFile = fopen(temp, "w");   

    printf("\nEnter the name of the element you want to delete:\n");
    scanf("%s", deleteName);

    int found = 0;

    while(fgets(buffer, 1000, fp) != NULL){
        char *token = strtok(buffer, ",");
        if(strcmp(deleteName, token) != 0){
            fputs(buffer, tempFile);
        } else{
            found = 1;
        }
    }

    fclose(fp);
    fclose(tempFile);

    if(found){
        printf("\n%s has been deleted from the periodic table. Another case solved, Sherlock!\n\n", deleteName);
        remove("periodic_table.txt");
        rename("temp.txt", "periodic_table.txt");
    } else{
        printf("\nElement not found in the periodic table. Better luck next time, Sherlock!\n\n");
        remove("temp.txt");
    }

    displayMenu();
}

void viewAllElements(){
    Element elements[118];

    //populate the elements array with data from the periodic table
    FILE *fp;
    char buffer[100];

    fp = fopen("periodic_table.txt", "r");
    if(fp == NULL){
        printf("Error opening file.");
        exit(1);
    }

    int i = 0;
    while(fgets(buffer, 100, fp) != NULL){
        char *token = strtok(buffer, ",");
        strcpy(elements[i].symbol, token);
        token=strtok(NULL, ",");
        strcpy(elements[i].name, token);
        token=strtok(NULL, ",");
        elements[i].atomicNumber = atoi(token);
        token=strtok(NULL, ",");
        strcpy(elements[i].state, token);
        token=strtok(NULL, ",");
        elements[i].atomicMass = strtof(token, NULL);
        i++;
    }

    fclose(fp);

    printf("\nHere is the full periodic table:\n\n");

    for(int i = 0; i < 118; i++){
        printf("Symbol: %s\n", elements[i].symbol);
        printf("Name: %s\n", elements[i].name);
        printf("Atomic Number: %d\n", elements[i].atomicNumber);
        printf("State: %s\n", elements[i].state);
        printf("Atomic Mass: %.4f\n\n", elements[i].atomicMass);
    }

    printf("Great job, Sherlock! You've uncovered all the elements in the periodic table!\n\n");

    displayMenu();
}