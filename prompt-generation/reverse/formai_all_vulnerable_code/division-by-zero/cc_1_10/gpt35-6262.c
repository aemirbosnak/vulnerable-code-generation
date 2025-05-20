//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    char ch, input;
    int count=0, errors=0, wpm, accuracy;
    float time_taken;
    time_t start, end;

    printf("Welcome to the Typing Speed Test!\n\n");
    printf("Type the following passage as fast as you can:\n\n");
    printf("Gratitude unlocks the fullness of life. It turns what we have into enough, and more. It turns denial into acceptance, chaos to order, confusion to clarity. It can turn a meal into a feast, a house into a home, a stranger into a friend. Gratitude makes sense of our past, brings peace for today and creates a vision for tomorrow. So, for all of this, we say thank you.\n\n");

    printf("Press Enter to begin.\n\n");
    ch = getchar();

    time(&start);

    while(ch != '\n')
    {
        ch = getchar();
    }

    printf("\nType the passage exactly as it is, including capitalization and punctuation.\n\n");
    printf("Your time starts now - ");

    while(input != '\n')
    {
        input = getchar();
        if(input == EOF) 
        {
            break;
        }
        else if(input == ' ')
        {
            count++;
        }
        else if(input != ' ' && input != '\n')
        {
            if(ch != input)
            {
                errors++;
            }
            ch = getchar();
        }
    }

    time(&end);
    time_taken = difftime(end,start);
    wpm = (int)((count/time_taken)*60);
    accuracy = ((count-errors)*100)/count;

    printf("\n\nYou have typed %d words in %.2f seconds.\n", count+1, time_taken);
    printf("Your typing speed is %d words per minute with %d%% accuracy.\n\n", wpm, accuracy);

    return 0;
}