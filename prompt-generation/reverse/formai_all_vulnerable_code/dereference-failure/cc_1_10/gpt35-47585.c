//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_ELEMS 118

// Struct to hold information about an element
typedef struct Element{
    char name[20];
    char symbol[3];
    int atomic_number;
    float atomic_mass;
    char electron_config[30];
} Element;

// Function to print the quiz instructions
void print_quiz_instructions(){
    printf("\nWelcome to the Periodic Table Quiz!\n");
    printf("Please enter the correct atomic symbol for the given element name.\n");
    printf("You will be scored out of a total of 10 marks.\n");
}

// Function to load the elements from a file
void load_elements(Element* elements){
    FILE* fp = fopen("elements.txt", "r");
    
    if(fp == NULL){
        printf("Error loading data!");
        exit(1);
    }
    
    char line[50];
    char* token;
    int i = 0;
    while(fgets(line, sizeof(line), fp)){
        // Extract information from each line of the file and store it in a struct array
        token = strtok(line, ",");
        strcpy(elements[i].name, token);
        
        token = strtok(NULL, ",");
        strcpy(elements[i].symbol, token);
        
        token = strtok(NULL, ",");
        elements[i].atomic_number = atoi(token);
        
        token = strtok(NULL, ",");
        elements[i].atomic_mass = atof(token);
        
        token = strtok(NULL, ",");
        strcpy(elements[i].electron_config, token);
        
        i++;
    }
    
    fclose(fp);
}

// Function to randomly pick 10 elements from the array
int* generate_random_indices(){
    int* indices = calloc(10, sizeof(int));
    
    int i, j, found;
    srand(time(NULL));
    
    for(i=0; i<10; i++){
        found = 0;
        while(!found){
            indices[i] = rand()%MAX_ELEMS;
            found = 1;
            for(j=0; j<i; j++){
                if(indices[j] == indices[i]){
                    found = 0;
                    break;
                }
            }
        }
    }
    
    return indices;
}

// Function to prompt the user for a guess
void take_guess(Element element){
    char guess[3];
    printf("\nWhat is the atomic symbol for %s?  ", element.name);
    scanf("%s", guess);
    if(strcmp(guess, element.symbol) == 0){
        printf("Correct!");
    }else{
        printf("Incorrect. The correct answer is %s.", element.symbol);
    }
}

// Main function to run the quiz
int main(){
    Element elements[MAX_ELEMS];
    load_elements(elements);
    print_quiz_instructions();
    int* indices = generate_random_indices();
    int i, score = 0;
    
    for(i=0; i<10; i++){
        printf("\n%d. ", i+1);
        take_guess(elements[indices[i]]);
        score++;
    }
    
    printf("\n\nYou scored %d out of 10.\n", score);
    return 0;
}