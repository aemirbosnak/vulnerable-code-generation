//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 118 //maximum number of elements in the periodic table

typedef struct Element{
    char symbol[3];
    char name[25];
    int atomicNum;
    double atomicMass;
    char electronConfig[50];
}element;

//function prototypes
void loadElements(element *arr[]);
void intro();
void quiz(element *arr[]);
void printElement(element *elem);

int main(){
    element *elements[MAX]; //array of element pointers
    loadElements(elements); //load data into elements array
    
    intro(); //display intro message and instructions
    quiz(elements); //run the quiz
    
    return 0;
}

//load data from elements.txt into elements array
void loadElements(element *arr[]){

    FILE *file = fopen("elements.txt", "r"); //open file

    if(file == NULL){ //check if file was successfully opened
        printf("Error opening file.");
        exit(1);
    }

    char line[150];
    int num = 0;

    while(fgets(line, 150, file) != NULL){ //read each line in the file
        element *elem = (element *)malloc(sizeof(element)); //allocate memory for new element
        
        strcpy(elem->symbol, strtok(line, ",")); //tokenize and copy data into element
        strcpy(elem->name, strtok(NULL, ","));
        elem->atomicNum = atoi(strtok(NULL, ","));
        elem->atomicMass = atof(strtok(NULL, ","));
        strcpy(elem->electronConfig, strtok(NULL, "\n"));

        arr[num] = elem; //add element pointer to array
        num++;
    }

    fclose(file); //close file
}

//display intro message and instructions
void intro(){
    printf("Welcome to the Periodic Table Quiz!\n\n");
    printf("You will be presented with the symbol of an element and you must guess its name.\n");
    printf("Enter 'quit' at any time to exit the quiz.\n");
    printf("Good luck!\n\n");
}

//run the quiz
void quiz(element *arr[]){
    int score = 0;
    char guess[25];

    //generate random order of elements
    int order[MAX];
    for(int i = 0; i < MAX; i++){
        order[i] = i;
    }
    srand(time(NULL)); //seed RNG
    for(int i = 0; i < MAX; i++){
        int j = rand() % (i+1);
        int temp = order[i];
        order[i] = order[j];
        order[j] = temp;
    }

    //display elements randomly and check user guess
    for(int i = 0; i < MAX; i++){
        element *elem = arr[order[i]];
        printf("What is the name of the element with the symbol %s?\n", elem->symbol);
        scanf("%s", guess);

        if(strcmp(guess, "quit") == 0){ //check if user wants to quit
            break;
        }

        if(strcmp(guess, elem->name) == 0){ //check if answer is correct
            printf("Correct!\n");
            score++;
        }
        else{
            printf("Incorrect. The correct answer is %s.\n", elem->name);
        }

        printElement(elem); //display element information
        printf("Score: %d/%d\n\n", score, i+1);
    }

    printf("Final Score: %d/%d", score, MAX);
}

//display element information
void printElement(element *elem){
    printf("%s - %s\n", elem->symbol, elem->name);
    printf("Atomic Number: %d\n", elem->atomicNum);
    printf("Atomic Mass: %.4f\n", elem->atomicMass);
    printf("Electron Configuration: %s\n", elem->electronConfig);
}