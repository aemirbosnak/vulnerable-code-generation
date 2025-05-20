//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num_questions, correct_answers = 0;
    char answer;
    int question_number = 0;
    int element_number = 0;
    int score = 0;
    int choice;
    int start_time, end_time;
    double elapsed_time;
    char play_again;

    srand(time(NULL));
    num_questions = rand() % 10 + 1;

    printf("Welcome to the C Periodic Table Quiz!\n");
    printf("How many questions would you like to answer? (1-10)\n");
    scanf("%d", &num_questions);

    do
    {
        printf("\nQuestion %d:\n", question_number + 1);
        element_number = rand() % 118;
        printf("What is the symbol for element %d?\n", element_number);
        printf("A) %c\n", 'A' + element_number);
        printf("B) %c\n", 'A' + (element_number + 1) % 118);
        printf("C) %c\n", 'A' + (element_number + 2) % 118);
        printf("D) %c\n", 'A' + (element_number + 3) % 118);
        scanf(" %c", &answer);

        if (answer == 'A' + element_number)
        {
            correct_answers++;
        }

        question_number++;
    } while (question_number < num_questions);

    end_time = clock();
    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\nYou answered %d out of %d questions correctly.\n", correct_answers, num_questions);
    printf("Your final score is %d%%\n", (int)(correct_answers / num_questions * 100));
    printf("Elapsed time: %.2f seconds\n", elapsed_time);

    printf("\nDo you want to play again? (y/n)\n");
    scanf(" %c", &play_again);

    if (play_again == 'y' || play_again == 'Y')
    {
        main();
    }

    return 0;
}