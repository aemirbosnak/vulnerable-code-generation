//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: romantic
#include <stdio.h>
#include <time.h>
#include <curl/curl.h>

#define WEBSITE_URL "https://www.example.com"

int main(void)
{
    CURL *curl_handle;
    CURLcode result;
    struct tm *local_time;
    struct timeval start_time, end_time;
    double elapsed_time;

    curl_global_init(CURL_GLOBAL_ALL);
    curl_handle = curl_easy_init();
    if(curl_handle)
    {
        curl_easy_setopt(curl_handle, CURLOPT_URL, WEBSITE_URL);

        gettimeofday(&start_time, NULL);

        /* Perform the request */
        result = curl_easy_perform(curl_handle);

        gettimeofday(&end_time, NULL);

        /* Calculate elapsed time */
        elapsed_time = (end_time.tv_sec - start_time.tv_sec) 
                       + ((end_time.tv_usec - start_time.tv_usec)/1e6);

        /* Get local time and print status */
        local_time = localtime(&end_time.tv_sec);
        printf("Timestamp: %d-%02d-%02d %02d:%02d:%02d\n", 
               local_time->tm_year + 1900, local_time->tm_mon + 1, 
               local_time->tm_mday, local_time->tm_hour, 
               local_time->tm_min, local_time->tm_sec);
        if(result == CURLE_OK)
            printf("Website is online!\n");
        else
            printf("Website is offline!\n");

        printf("Elapsed time: %.3f seconds\n", elapsed_time);

        /* Clean up */
        curl_easy_cleanup(curl_handle);
    }
    else
    {
        fprintf(stderr, "Couldn't initialize curl!\n");
        return 1;
    }

    curl_global_cleanup();
    return 0;
}