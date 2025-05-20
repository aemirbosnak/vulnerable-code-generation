//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure for periodic table element information
struct element_info
{
    char symbol[3];
    char name[30];
    int atomic_num;
    float atomic_mass;
    char state[10];
}; 

//Function to initialize periodic table elements
void initialize_elements(struct element_info *elements)
{
    strcpy(elements[0].symbol, "H");
    strcpy(elements[0].name, "Hydrogen");
    elements[0].atomic_num = 1;
    elements[0].atomic_mass = 1.008;
    strcpy(elements[0].state, "Gas");

    strcpy(elements[1].symbol, "He");
    strcpy(elements[1].name, "Helium");
    elements[1].atomic_num = 2;
    elements[1].atomic_mass = 4.003;
    strcpy(elements[1].state, "Gas");

    strcpy(elements[2].symbol, "Li");
    strcpy(elements[2].name, "Lithium");
    elements[2].atomic_num = 3;
    elements[2].atomic_mass = 6.941;
    strcpy(elements[2].state, "Solid");

    //Add more elements here...

}

//Quiz function, takes in an element and prompts user for information
void quiz(struct element_info *element)
{
    char guess[30];
    char answer[30];
    int correct = 0;

    printf("What is the symbol for %s?\n", element->name);
    scanf("%s", guess);

    if(strcmp(guess, element->symbol) == 0)
    {
        printf("Correct!\n");
        correct++;
    }
    else
    {
        printf("Incorrect. The correct answer is %s\n", element->symbol);
    }

    printf("What is the atomic number for %s?\n", element->name);
    scanf("%s", guess);

    sprintf(answer, "%d", element->atomic_num);

    if(strcmp(guess, answer) == 0)
    {
        printf("Correct!\n");
        correct++;
    }
    else
    {
        printf("Incorrect. The correct answer is %d\n", element->atomic_num);
    }

    printf("What is the atomic mass for %s?\n", element->name);
    scanf("%s", guess);

    sprintf(answer, "%.3f", element->atomic_mass);

    if(strcmp(guess, answer) == 0)
    {
        printf("Correct!\n");
        correct++;
    }
    else
    {
        printf("Incorrect. The correct answer is %.3f\n", element->atomic_mass);
    }

    printf("What is the state of matter for %s at room temperature?\n", element->name);
    scanf("%s", guess);

    if(strcmp(guess, element->state) == 0)
    {
        printf("Correct!\n");
        correct++;
    }
    else
    {
        printf("Incorrect. The correct answer is %s\n", element->state);
    }

    printf("You got %d out of 4 questions correct for %s\n", correct, element->name);
}

int main()
{
    struct element_info *elements = malloc(sizeof(struct element_info)*118);
    initialize_elements(elements);

    int choice = 0;

    while(choice != -1)
    {
        printf("Welcome to the Periodic Table Quiz\n");
        printf("Please select an element to quiz on (1-118) or enter -1 to exit:\n");

        scanf("%d", &choice);

        if(choice == -1)
        {
            break;
        }

        quiz(&elements[choice-1]);

        printf("\n");
    }

    return 0;
}