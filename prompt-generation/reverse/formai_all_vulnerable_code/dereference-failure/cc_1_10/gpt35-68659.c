//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    // Initialize the quiz score and set the quiz questions
    int score = 0;
    char questions[5][50] = {"What is the symbol of Carbon?", "What is the atomic number of Oxygen?", "What is the most electronegative element?", "What is the symbol of Sodium?", "What is the atomic number of Helium?"};
    char answers[5][3] = {"C", "8", "Fluorine", "Na", "2"};

    // Set up a random seed for shuffling the questions
    srand(time(NULL));

    // Shuffle the questions using Fisher-Yates algorithm 
    for(int i = 4;i >= 1;i--){
        int j = rand()% (i + 1);
        if(i != j){
            char tempq[50];
            char tempa[3];
            strcpy(tempq, questions[i]);
            strcpy(tempa, answers[i]);
            strcpy(questions[i], questions[j]);
            strcpy(answers[i], answers[j]);
            strcpy(questions[j], tempq);
            strcpy(answers[j], tempa);
        }
    }

    // Display the shuffled quiz questions and ask the user to input their answer
    printf("Welcome to the Periodic Table quiz!\n");
    for(int i = 0;i < 5;i++){
        printf("\nQuestion %d: %s\n", i+1, questions[i]);
        char user_answer[3];
        printf("Your answer: ");
        scanf("%s", user_answer);

        // Check if the user's answer is correct and update the score accordingly
        if(strcmp(user_answer, answers[i]) == 0){
            printf("Correct!\n");
            score++;
        }
        else{
            printf("Wrong. The correct answer is %s.\n", answers[i]);
        }
    }

    // Display the final score
    printf("\nThanks for playing! Your final score is %d out of 5.\n", score);

    return 0;
}