//Falcon-180B DATASET v1.0 Category: Error handling ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Function to check if a string is a valid integer or not
bool is_valid_int(char *str) {
    for(int i=0;i<strlen(str);i++) {
        if(str[i]<'0' || str[i]>'9') {
            return false;
        }
    }
    return true;
}

//Function to perform basic arithmetic operations
int perform_operation(char *op,int num1,int num2) {
    int result=0;
    switch(op[0]) {
        case '+':
            result=num1+num2;
            break;
        case '-':
            result=num1-num2;
            break;
        case '*':
            result=num1*num2;
            break;
        case '/':
            if(num2==0) {
                printf("Error: Division by zero is not allowed.\n");
                exit(1);
            }
            result=num1/num2;
            break;
        default:
            printf("Error: Invalid operator.\n");
            exit(1);
    }
    return result;
}

int main() {
    char input[100];
    int num1,num2,result;
    printf("Enter an arithmetic expression in the format 'number operator number': ");
    scanf("%s",input);

    //Extracting numbers from the input string
    char *token=strtok(input," ");
    num1=atoi(token);

    token=strtok(NULL," ");
    if(token==NULL) {
        printf("Error: Invalid expression.\n");
        exit(1);
    }

    if(!is_valid_int(token)) {
        printf("Error: Invalid operator or number.\n");
        exit(1);
    }

    num2=atoi(token);

    //Performing the arithmetic operation
    result=perform_operation(token,num1,num2);

    //Printing the result
    printf("Result: %d\n",result);

    return 0;
}