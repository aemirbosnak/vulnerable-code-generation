//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    char* love_life[6]= {"Great things are in store for your love life", 
                          "Love is in the air", 
                          "Your love life will take an unexpected turn", 
                          "Focus on yourself for now, love will come later", 
                          "Be patient, true love is on its way", 
                          "Your love life will face challenges but it will only make you stronger"};
    char* career[6] = {"You will receive a job offer soon", 
                        "Don't give up, the right career path is coming", 
                        "Hard work will pay off in your career", 
                        "Be open to new opportunities in your career", 
                        "Success in your career is on its way", 
                        "Your unique skills will lead you to success in your career"};
    char* finances[6] = {"Your financial situation will greatly improve", 
                          "Unexpected expenses are coming, be prepared", 
                          "Your financial choices will lead to long-term stability", 
                          "Invest in your future now, it will pay off later",
                          "Be cautious with your spending, it will pay off in the long run",
                          "Your financial situation may face challenges, stay calm and focused"};
    char* health[6] = {"Your physical and mental health are at their peak", 
                       "Make sure to take care of your physical health in the upcoming weeks", 
                       "Mental health should be your top priority right now", 
                       "Your health may face minor challenges, but nothing serious",
                       "Your health needs more attention, don't ignore any warning signs",
                       "Try new healthy habits or physical activities to improve your health"};
    
    char* user_input;
    time_t t;
    srand((unsigned) time(&t));
    printf("Welcome to the Automated Fortune Teller! Ask any question and I will give you an answer!\n");
    printf("What would you like to know?\n");
    getline(&user_input, &(size_t) { 0 }, stdin);
    
    while(user_input) {
        int num = (rand() % 6);
        printf("The fortune teller says...\n");
        if(strstr(user_input, "love") != NULL) {
            printf("%s\n", love_life[num]);
        }
        else if(strstr(user_input, "career") != NULL) {
            printf("%s\n", career[num]);
        }
        else if(strstr(user_input, "finances") != NULL) {
            printf("%s\n", finances[num]);
        }
        else if(strstr(user_input, "health") != NULL) {
            printf("%s\n", health[num]);
        }
        else {
            printf("I'm sorry, I do not have an answer for that question\n");
        }
        printf("What else would you like to know?\n");
        getline(&user_input, &(size_t) { 0 }, stdin);
    }
    
    return 0;
}