//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: creative
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    char input[100];                                    // to store input from user
    char para[200] = "The quick brown fox jumps over the lazy dog. This sentence is being used for typing practice.";  //text for practice
    int count = 0, i = 0, j = 0, errors = 0, cpm = 0, wpm = 0, time_taken = 0;
    time_t start_time, end_time;                        // to calculate time taken to type
    double accuracy = 0;

    printf("\nWelcome to Typing Speed Test!");
    printf("\nYou will be given a paragraph to type, let's get started!\n");

    printf("\nType the following paragraph: \n\n%s", para);

    time(&start_time);                                 //start time of typing

    while(para[i]!='\0')
    {
        input[i] = getchar();                          //getting input from user 

        if(input[i]=='\n')                             //if user presses enter, terminate
            break;

        if(para[i] != input[i])                        //checking for errors
            errors++;

        count++;

        i++;

    }
    input[i]='\0';                                     

    time(&end_time);                                   //end time of typing
    time_taken = difftime(end_time, start_time);        //calculating time taken
    cpm = (count/5) / (time_taken/60);                 //characters per minute
    wpm = (count/5 - errors) / (time_taken/60);        //words per minute
    accuracy = ((double)count - errors)/count * 100;    //accuracy in percentage

    printf("\n\n");
    printf("Typing Speed Test Result:\n");
    printf("----------------------------\n");
    printf("Total Characters Typed: %d\n", count);
    printf("Total Errors: %d\n", errors);
    printf("Accuracy: %.2lf%%\n", accuracy);
    printf("Typing Speed in CPM: %d\n", cpm);
    printf("Typing Speed in WPM: %d\n", wpm);

    return 0;
}