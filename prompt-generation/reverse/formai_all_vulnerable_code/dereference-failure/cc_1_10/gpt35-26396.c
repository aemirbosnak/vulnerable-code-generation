//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_URL_LENGTH 1024
#define MAX_THREADS 5

pthread_mutex_t lock;

void *sanitize_url(void *url)
{
    char *sanitized_url = (char *)malloc(MAX_URL_LENGTH * sizeof(char));
    strcpy(sanitized_url, url);
    int url_length = strlen(sanitized_url);
    
    for(int i=0; i<url_length; i++)
    {
        if(sanitized_url[i] == ' ')
        {
            sanitized_url[i] = '+';
        }
        else if(sanitized_url[i] == '&')
        {
            sanitized_url[i] = '_';
        }
        else if(sanitized_url[i] == '/')
        {
            sanitized_url[i] = '-';
        }
        else if(sanitized_url[i] == '/')
        {
            sanitized_url[i] = '-';
        }
        else if(sanitized_url[i] == ':')
        {
            sanitized_url[i] = '=';
        }
    }
    
    pthread_mutex_lock(&lock);
    printf("Original URL: %s\n", url);
    printf("Sanitized URL: %s\n", sanitized_url);
    printf("\n");
    pthread_mutex_unlock(&lock);
    
    free(sanitized_url);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[MAX_THREADS];
    char urls[MAX_THREADS][MAX_URL_LENGTH] = {"http://www.example.com", "http://localhost:8000/index.html", "https://www.google.com/search?q=url+sanitizer", "ftp://ftp.example.com/README", "https://www.yahoo.com/?p=1&abc=2"};
    
    if(pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("Mutex initialization failed.\n");
        return 1;
    }
    
    for(int i=0; i<MAX_THREADS; i++)
    {
        if(pthread_create(&threads[i], NULL, sanitize_url, &urls[i]) != 0)
        {
            printf("Thread creation failed.\n");
            return 1;
        }
    }
    
    for(int i=0; i<MAX_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }
    
    pthread_mutex_destroy(&lock);
    return 0;
}