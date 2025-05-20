//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

#define MAX_TIME_LIMIT 10
#define TEST_LENGTH 50

void printRandomString(char string[], int len){
    int i;
    
    for(i=0;i<len;i++){
        string[i] = 'a' + rand()%26;
        printf("%c", string[i]);
    }
    
    printf("\n");
}

int calculateTypingSpeed(int timeTaken){
    int speed = (TEST_LENGTH*60)/timeTaken;
    return speed;
}

int main(){
    char inputString[TEST_LENGTH+1];
    char randomString[TEST_LENGTH+1];
    int i, mistakes=0, j, speed, timeTaken;
    clock_t start, end;
    double timeElapsed;
    
    printf("Welcome to the Shape Shifting Typing Speed Test Program\n");
    printf("You will be given a random string of length %d to type as fast as you can.\n", TEST_LENGTH);
    printf("Your typing speed will be calculated in terms of words per minute.\n");
    printf("You will have 10 seconds to complete the test.\n");
    printf("Press Enter to Start the Test\n");
    getchar(); //wait for user to press enter
    
    printRandomString(randomString, TEST_LENGTH);
    
    start = clock();
    
    scanf("%50[^\n]", inputString); //read input string, limited to 50 characters
    
    end = clock();
    
    timeElapsed = (double)(end-start)/CLOCKS_PER_SEC;
    
    printf("Time Taken: %.2lf seconds\n", timeElapsed);
    
    if(timeElapsed > MAX_TIME_LIMIT){ //if time taken > 10 seconds
        printf("Time Out! You have exceeded the time limit of %d seconds.\n", MAX_TIME_LIMIT);
    }
    else{ //if time taken <= 10 seconds
        printf("Input String: %s\n", inputString);
        for(i=0;i<TEST_LENGTH;i++){
            if(inputString[i] != randomString[i]){
                mistakes++;
            }
        }
        
        printf("Mistakes: %d\n", mistakes);
        
        speed = calculateTypingSpeed((int)timeElapsed);
        
        printf("Typing Speed: %d words per minute\n", speed);
    }
    
    return 0;
}