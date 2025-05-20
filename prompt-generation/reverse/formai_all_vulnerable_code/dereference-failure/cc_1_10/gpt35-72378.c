//FormAI DATASET v1.0 Category: Syntax parsing ; Style: mind-bending
/* 
This program is a mind-bending example of C syntax parsing. 
Although it may appear convoluted, it is a valid and functional program. 
Please bear with me as I take you on a tour of its inner workings. 
*/

#include<stdio.h>

int main(){

    char* message="Hello, World!";

    printf("The message is: %s\n", message);

    // Let's replace the letter "o" with "0"
    for(int i = 0; message[i]; i++){
        if(message[i] == 'o'){
            message[i] = '0';
            i++; // This line skips the next iteration of the loop
        }
    }

    printf("The modified message is: %s\n", message);

    // Now let's evaluate some intricate expressions
    int a=10, b=5;

    // Note: we are using a single equal sign here
    if(a=b){ // This sets "a" to the value of "b" and returns true
        printf("The value of a is now equal to b\n");
    }

    int result = a+++b; // This is equivalent to (a++) + b
    printf("The value of result is %d\n", result);

    // This is not a mistake, we are trying to syntax-parse a macro
    #define AUTHOR "John Doe"

    printf("The author of this program is %s\n", AUTHOR);

    // Finally, let's use some trigonometric functions
    double angle = 45; // In degrees

    double sine = sin(angle*0.0174533); // Convert to radians first
    printf("The sine of %lf degrees is %lf\n", angle, sine);

    double cosine = cos(angle*0.0174533);
    printf("The cosine of %lf degrees is %lf\n", angle, cosine);

    // We're done for now, let's exit the program
    return 0;
}

/*
Congratulations, you've made it to the end of this mind-bending program! 
I hope you enjoyed exploring its oddities and learning some new things about C syntax. 
If you have any questions or comments, feel free to leave them below. 
*/