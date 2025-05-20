//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define NUM_THREADS 4  // number of threads to be used

pthread_mutex_t lock;  // mutex lock to protect shared variable
int sentiment_score = 0;  // shared variable to store overall sentiment score

void *calc_sentiment(void *arg);

int main()
{
    pthread_t threads[NUM_THREADS];  // array to store thread IDs
    char text_input[1000];  // variable to store user input

    printf("Enter some text to analyze sentiment: ");
    fgets(text_input, 1000, stdin);  // get user input from keyboard
    
    char *token = strtok(text_input, " ");  // split text_input into tokens using space delimiter

    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_create(&threads[i], NULL, &calc_sentiment, (void *) token);  // create threads and pass token as argument
        token = strtok(NULL, " ");  // get next token
    }

    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);  // wait for threads to finish executing
    }

    printf("Overall sentiment score: %d\n", sentiment_score);  // print overall sentiment score

    pthread_mutex_destroy(&lock);  // destroy mutex lock

    return 0;
}

void *calc_sentiment(void *arg)
{
    char *token = (char *) arg;  // cast argument back to string pointer
    int local_score = 0;  // local score for each thread
    int len = strlen(token);

    for (int i = 0; i < len; i++)
    {
        if (token[i] == 'g')
        {
            local_score += 2;  // add 2 to score for 'g' character
        }
        else if (token[i] == 'b')
        {
            local_score -= 1;  // subtract 1 from score for 'b' character
        }
    }

    pthread_mutex_lock(&lock);  // acquire lock before accessing shared variable
    sentiment_score += local_score;  // update overall sentiment score
    pthread_mutex_unlock(&lock);  // release lock

    pthread_exit(NULL);  // exit thread
}