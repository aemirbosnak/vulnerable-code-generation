//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Create a structure to hold test data
    struct test_data {
        char* name;
        int num_questions;
        int* question_numbers;
        int* correct_answers;
        char** question_text;
        char** answer_options;
    };

    // Create an array to hold test data
    struct test_data tests[5];

    // Initialize the tests
    tests[0].name = "Test 1";
    tests[0].num_questions = 10;
    tests[0].question_numbers = (int*)malloc(10 * sizeof(int));
    tests[0].correct_answers = (int*)malloc(10 * sizeof(int));
    tests[0].question_text = (char**)malloc(10 * sizeof(char*));
    tests[0].answer_options = (char**)malloc(10 * sizeof(char*));

    tests[1].name = "Test 2";
    tests[1].num_questions = 20;
    tests[1].question_numbers = (int*)malloc(20 * sizeof(int));
    tests[1].correct_answers = (int*)malloc(20 * sizeof(int));
    tests[1].question_text = (char**)malloc(20 * sizeof(char*));
    tests[1].answer_options = (char**)malloc(20 * sizeof(char*));

    // Initialize the question numbers, correct answers, and question text
    int i;
    for (i = 0; i < tests[0].num_questions; i++) {
        tests[0].question_numbers[i] = i + 1;
        tests[0].correct_answers[i] = i % 2 == 0? 1 : 0;
        tests[0].question_text[i] = (char*)malloc(50 * sizeof(char));
        sprintf(tests[0].question_text[i], "Question %d", i + 1);
        tests[0].answer_options[i] = (char*)malloc(50 * sizeof(char));
        sprintf(tests[0].answer_options[i], "Answer 1");
        tests[1].question_numbers[i] = i + 1;
        tests[1].correct_answers[i] = i % 2 == 0? 1 : 0;
        tests[1].question_text[i] = (char*)malloc(50 * sizeof(char));
        sprintf(tests[1].question_text[i], "Question %d", i + 1);
        tests[1].answer_options[i] = (char*)malloc(50 * sizeof(char));
        sprintf(tests[1].answer_options[i], "Answer 1");
    }

    // Display the test data
    printf("Test Data:\n");
    printf("Name: %s\n", tests[0].name);
    printf("Number of Questions: %d\n", tests[0].num_questions);
    printf("Question Numbers:\n");
    for (i = 0; i < tests[0].num_questions; i++) {
        printf("%d: %s\n", tests[0].question_numbers[i], tests[0].question_text[i]);
    }
    printf("Correct Answers:\n");
    for (i = 0; i < tests[0].num_questions; i++) {
        printf("%d: %s\n", tests[0].correct_answers[i], tests[0].answer_options[i]);
    }
    printf("Name: %s\n", tests[1].name);
    printf("Number of Questions: %d\n", tests[1].num_questions);
    printf("Question Numbers:\n");
    for (i = 0; i < tests[1].num_questions; i++) {
        printf("%d: %s\n", tests[1].question_numbers[i], tests[1].question_text[i]);
    }
    printf("Correct Answers:\n");
    for (i = 0; i < tests[1].num_questions; i++) {
        printf("%d: %s\n", tests[1].correct_answers[i], tests[1].answer_options[i]);
    }

    // Free allocated memory
    for (i = 0; i < tests[0].num_questions; i++) {
        free(tests[0].question_text[i]);
        free(tests[0].answer_options[i]);
    }
    free(tests[0].question_text);
    free(tests[0].answer_options);
    free(tests[0].question_numbers);
    free(tests[0].correct_answers);

    for (i = 0; i < tests[1].num_questions; i++) {
        free(tests[1].question_text[i]);
        free(tests[1].answer_options[i]);
    }
    free(tests[1].question_text);
    free(tests[1].answer_options);
    free(tests[1].question_numbers);
    free(tests[1].correct_answers);

    return 0;
}