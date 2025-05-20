//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STRING_LENGTH 100
#define TEST_DURATION 60 //in seconds

//function to generate a random string for typing test
char* generate_random_string(int length) {
    char* str = (char*) malloc((length+1) * sizeof(char));
    for(int i=0; i<length; i++) {
        str[i] = 'a' + rand() % 26;
    }
    str[length] = '\0';
    return str;
}

int main() {
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given random strings to type.\n");
    printf("Type each string as fast as possible and hit enter to move to the next one.\n");
    printf("Your typing speed will be calculated at the end.\n\n");

    printf("Press enter to start the test...");
    getchar();

    char* str;
    clock_t start_time = clock();
    int num_correct = 0;
    int num_total = 0;
    double elapsed_time = 0.0;

    while(elapsed_time < TEST_DURATION) {
        //generate a random string and print it
        str = generate_random_string(MAX_STRING_LENGTH);
        printf("%s\n", str);

        //get user input and calculate typing speed
        char input[MAX_STRING_LENGTH];
        fgets(input, MAX_STRING_LENGTH, stdin);
        num_total++;
        if(strcmp(input, str) == 0) {
            num_correct++;
        }
        elapsed_time = (double) (clock() - start_time) / CLOCKS_PER_SEC;
    }

    //calculate typing speed and accuracy and print results
    double typing_speed = (double) num_total / elapsed_time * 60.0;
    double accuracy = (double) num_correct / num_total * 100.0;

    printf("\n\nTest complete!\n");
    printf("Your typing speed is %.2f words per minute.\n", typing_speed);
    printf("Your accuracy is %.2f%%.\n", accuracy);

    free(str);
    return 0;
}