//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int num_elements,num_questions;
    char symbol[3];
    char name[20];
    int atomic_number,atomic_weight;
    int correct_answers = 0;
    int wrong_answers = 0;
    float percentage;

    printf("Welcome to the Periodic Table Quiz!\n");

    srand(time(NULL));
    num_elements = rand()%118+1;
    num_questions = num_elements;

    printf("You will be asked %d questions about the periodic table.\n",num_questions);

    for(int i=1;i<=num_elements;i++)
    {
        atomic_number = rand()%118+1;
        atomic_weight = rand()%200;

        sprintf(symbol,"%c%c",atomic_number+64,atomic_number+64);
        strcpy(name,"Element ");
        strcat(name,symbol);

        printf("\n%d. What is the symbol for the element with atomic number %d?\n",i,atomic_number);
        scanf("%s",symbol);

        if(strcmp(symbol,name)==0)
        {
            correct_answers++;
        }
        else
        {
            wrong_answers++;
        }
    }

    percentage = (float)correct_answers/num_questions*100;

    printf("\n\nYou got %d out of %d questions correct, which is %.2f%%.",correct_answers,num_questions,percentage);

    return 0;
}