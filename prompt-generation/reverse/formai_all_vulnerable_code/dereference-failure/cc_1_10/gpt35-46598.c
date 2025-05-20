//FormAI DATASET v1.0 Category: Syntax parsing ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

void printResult(int result){
    printf("\nYour result is: %d", result);
}

int main(){
    printf("Welcome to C Syntax Parsing Program!\n");
    printf("Please input an equation using standard C syntax:\n");
    
    char* input = (char*)malloc(sizeof(char) * 100);
    scanf("%s", input);

    int answer = 0;

    for(int i = 0; input[i] != '\0'; i++){
        if(input[i] == ' '){
            continue;
        }
        else if(input[i] == '+'){
            int num1 = atoi(&input[i - 1]);
            int num2 = atoi(&input[i + 1]);
            answer += num1 + num2;
            i++; //skip the next number as it has been added above
        }
        else if(input[i] == '-'){
            int num1 = atoi(&input[i - 1]);
            int num2 = atoi(&input[i + 1]);
            answer += num1 - num2;
            i++; //skip the next number as it has been subtracted above
        }
        else if(input[i] == '*'){
            int num1 = atoi(&input[i - 1]);
            int num2 = atoi(&input[i + 1]);
            answer += num1 * num2;
            i++; //skip the next number as it has been multiplied above
        }
        else if(input[i] == '/'){
            int num1 = atoi(&input[i - 1]);
            int num2 = atoi(&input[i + 1]);
            answer += num1 / num2;
            i++; //skip the next number as it has been divided above
        }
        else{
            continue; //ignore any non-numeric characters
        }
    }

    free(input); //memory cleanup

    printResult(answer);

    return 0;
}