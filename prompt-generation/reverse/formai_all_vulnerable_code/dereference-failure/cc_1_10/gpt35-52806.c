//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118 //total number of elements in the periodic table

typedef struct Element //definition of the element structure
{
    char symbol[3];
    char name[20];
    int atomic_number;
    float atomic_mass;
} Element;

void display_menu(); //declaration of functions
void load_elements(Element elements[]);
void quiz(Element elements[]);

int main() 
{
    Element elements[MAX_ELEMENTS]; //declaration of array of elements

    load_elements(elements); //load the elements from file

    display_menu(); //display the menu for the user

    printf("\nEnter a choice: ");
    int choice;
    scanf("%d", &choice); //get user's choice
    while (choice != 3) //while user doesn't choose to exit
    {
        switch (choice) //perform the corresponding action based on user's choice
        {
            case 1:
                printf("\nStarting quiz...\n");
                quiz(elements);
                break;
            case 2:
                printf("\nThank you for using the C Periodic Table Quiz! Goodbye :)\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
        display_menu();
        printf("\nEnter a choice: ");
        scanf("%d", &choice);
    }

    return 0; //exit program
}

void load_elements(Element elements[])
{
    FILE* fp = fopen("elements.txt", "r"); //open file containing elements information

    if (fp == NULL) //if file cannot be opened
    {
        printf("Error opening file. Please make sure \'elements.txt\' exists in the same directory.\n");
        exit(1);
    }

    char line[100]; //declaration of temporary string to store a line of data from file

    for (int i = 0; i < MAX_ELEMENTS; i++) //loop through the lines in file to extract element information
    {
        fgets(line, 100, fp); //get the next line from file

        char* token = strtok(line, ","); //parse the line for each field of element structure
        strcpy(elements[i].symbol, token); //copy symbol to element

        token = strtok(NULL, ",");
        strcpy(elements[i].name, token); //copy name to element

        token = strtok(NULL, ",");
        elements[i].atomic_number = atoi(token); //convert atomic number from string to integer and copy to element

        token = strtok(NULL, ",");
        elements[i].atomic_mass = atof(token); //convert atomic mass from string to float and copy to element
    }

    fclose(fp); //close file
}

void quiz(Element elements[])
{
    int score = 0; //declaration of quiz score counter

    for (int i = 0; i < 10; i++) //10 questions in quiz
    {
        int index = rand() % MAX_ELEMENTS; //randomly select an element
        printf("\nWhat is the symbol for %s (atomic number %d)?\n", elements[index].name, elements[index].atomic_number);

        char answer[3];
        scanf("%s", &answer); //get user's answer

        if (strcmp(answer, elements[index].symbol) == 0) //if user answered correctly
        {
            score++;
            printf("Correct!\n");
        }
        else //if user answered incorrectly
        {
            printf("Incorrect. The correct answer is %s.\n", elements[index].symbol);
        }
    }

    printf("\nQuiz ended. Your score is %d/10.\n", score); //display user's score
}

void display_menu()
{
    printf("\nC Periodic Table Quiz Menu:\n");
    printf("1. Start quiz\n");
    printf("2. Exit program\n");
}