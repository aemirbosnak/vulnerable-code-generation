//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ELEMENTS 118

//Struct defining each element
typedef struct element{
    char symbol[3];
    char name[20];
    int atomicNumber;
    float atomicMass;
    char electronConfig[20];
} Element;

//Populate the periodic table with data
void populateTable(Element *table){
    FILE *input = fopen("elements.txt","r");
    char name[20],symbol[3],electrons[20];
    int number = 0;
    float mass = 0.0;

    //Read data from the file
    while(fscanf(input,"%s %s %d %f %s",symbol,name,&number,&mass,electrons) != EOF){
        strcpy(table[number-1].name,name);
        strcpy(table[number-1].symbol,symbol);
        table[number-1].atomicNumber = number;
        table[number-1].atomicMass = mass;
        strcpy(table[number-1].electronConfig,electrons);
    }
    fclose(input);
}

int main(){
    Element periodicTable[MAX_ELEMENTS];
    populateTable(periodicTable);

    int i, choice, correct=0, wrong=0;
    char response[3], answer[3];

    printf("~~~Welcome to the Periodic Table quiz!~~~\n\n");
    printf("The quiz will test your knowledge of the elements on the periodic table. Good luck!\n\n");

    do{
        //Choose a random element from the table
        i = rand() % MAX_ELEMENTS;

        //Ask the user for the symbol of the element
        printf("What is the symbol for %s? ", periodicTable[i].name);
        scanf("%s", response);

        //Check if the user answered correctly
        if(strcmp(response, periodicTable[i].symbol) == 0){
            printf("Correct!\n");
            correct++;
        }
        else{
            printf("Incorrect. The correct symbol is %s.\n", periodicTable[i].symbol);
            wrong++;
        }

        printf("Do you want to continue? (y/n) ");
        scanf("%s", answer);
        printf("\n");

    } while(strcmp(answer, "y") == 0);

    printf("Quiz results:\n");
    printf("Correct answers: %d\n", correct);
    printf("Incorrect answers: %d\n", wrong);

    return 0;
}