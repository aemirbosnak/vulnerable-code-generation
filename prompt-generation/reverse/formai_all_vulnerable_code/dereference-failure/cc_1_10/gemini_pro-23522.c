//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char *question;
    char **options;
    int num_options;
    int correct_option;
} Question;

typedef struct {
    Question *questions;
    int num_questions;
} Exam;

Exam *create_exam(int num_questions) {
    Exam *exam = malloc(sizeof(Exam));
    exam->num_questions = num_questions;
    exam->questions = malloc(sizeof(Question) * num_questions);
    for (int i = 0; i < num_questions; i++) {
        exam->questions[i].question = malloc(100);
        exam->questions[i].options = malloc(sizeof(char *) * 4);
        for (int j = 0; j < 4; j++) {
            exam->questions[i].options[j] = malloc(100);
        }
    }
    return exam;
}

void free_exam(Exam *exam) {
    for (int i = 0; i < exam->num_questions; i++) {
        free(exam->questions[i].question);
        for (int j = 0; j < 4; j++) {
            free(exam->questions[i].options[j]);
        }
        free(exam->questions[i].options);
    }
    free(exam->questions);
    free(exam);
}

void print_question(Question *question) {
    printf("%s\n", question->question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, question->options[i]);
    }
}

int get_user_answer() {
    int answer;
    printf("Enter your answer (1-4): ");
    scanf("%d", &answer);
    return answer;
}

int grade_exam(Exam *exam) {
    int score = 0;
    for (int i = 0; i < exam->num_questions; i++) {
        int answer = get_user_answer();
        if (answer == exam->questions[i].correct_option) {
            score++;
        }
    }
    return score;
}

int main() {
    srand(time(NULL));

    Exam *exam = create_exam(10);

    // Set the questions and answers
    exam->questions[0].question = "What is the capital of France?";
    exam->questions[0].options[0] = "London";
    exam->questions[0].options[1] = "Paris";
    exam->questions[0].options[2] = "Rome";
    exam->questions[0].options[3] = "Madrid";
    exam->questions[0].correct_option = 1;

    exam->questions[1].question = "What is the largest ocean in the world?";
    exam->questions[1].options[0] = "Atlantic Ocean";
    exam->questions[1].options[1] = "Pacific Ocean";
    exam->questions[1].options[2] = "Indian Ocean";
    exam->questions[1].options[3] = "Arctic Ocean";
    exam->questions[1].correct_option = 1;

    exam->questions[2].question = "What is the chemical symbol for gold?";
    exam->questions[2].options[0] = "Ag";
    exam->questions[2].options[1] = "Au";
    exam->questions[2].options[2] = "Fe";
    exam->questions[2].options[3] = "Cu";
    exam->questions[2].correct_option = 1;

    exam->questions[3].question = "What is the name of the largest planet in our solar system?";
    exam->questions[3].options[0] = "Earth";
    exam->questions[3].options[1] = "Jupiter";
    exam->questions[3].options[2] = "Saturn";
    exam->questions[3].options[3] = "Uranus";
    exam->questions[3].correct_option = 1;

    exam->questions[4].question = "What is the name of the inventor of the telephone?";
    exam->questions[4].options[0] = "Thomas Edison";
    exam->questions[4].options[1] = "Alexander Graham Bell";
    exam->questions[4].options[2] = "Nikola Tesla";
    exam->questions[4].options[3] = "Albert Einstein";
    exam->questions[4].correct_option = 1;

    exam->questions[5].question = "What is the name of the first person to walk on the moon?";
    exam->questions[5].options[0] = "Yuri Gagarin";
    exam->questions[5].options[1] = "Neil Armstrong";
    exam->questions[5].options[2] = "Buzz Aldrin";
    exam->questions[5].options[3] = "Alan Shepard";
    exam->questions[5].correct_option = 1;

    exam->questions[6].question = "What is the name of the largest country in the world?";
    exam->questions[6].options[0] = "China";
    exam->questions[6].options[1] = "Russia";
    exam->questions[6].options[2] = "United States";
    exam->questions[6].options[3] = "Canada";
    exam->questions[6].correct_option = 0;

    exam->questions[7].question = "What is the name of the highest mountain in the world?";
    exam->questions[7].options[0] = "Mount Everest";
    exam->questions[7].options[1] = "K2";
    exam->questions[7].options[2] = "Kangchenjunga";
    exam->questions[7].options[3] = "Lhotse";
    exam->questions[7].correct_option = 0;

    exam->questions[8].question = "What is the name of the longest river in the world?";
    exam->questions[8].options[0] = "Nile River";
    exam->questions[8].options[1] = "Amazon River";
    exam->questions[8].options[2] = "Yangtze River";
    exam->questions[8].options[3] = "Mississippi River";
    exam->questions[8].correct_option = 0;

    exam->questions[9].question = "What is the name of the largest desert in the world?";
    exam->questions[9].options[0] = "Sahara Desert";
    exam->questions[9].options[1] = "Gobi Desert";
    exam->questions[9].options[2] = "Atacama Desert";
    exam->questions[9].options[3] = "Antarctic Polar Desert";
    exam->questions[9].correct_option = 0;

    // Print the questions and get the user's answers
    for (int i = 0; i < exam->num_questions; i++) {
        print_question(&exam->questions[i]);
    }

    // Grade the exam
    int score = grade_exam(exam);

    // Print the score
    printf("Your score is %d out of %d\n", score, exam->num_questions);

    // Free the exam
    free_exam(exam);

    return 0;
}