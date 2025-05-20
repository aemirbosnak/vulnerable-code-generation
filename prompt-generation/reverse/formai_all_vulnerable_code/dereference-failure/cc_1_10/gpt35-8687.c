//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: decentralized
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<curl/curl.h>
#include<unistd.h>

// Define a structure to hold the data to be passed into the curl callback function
struct WebData {
  char* url;
  long http_code;
};
 
// Define the curl callback function to handle the response from the server
size_t handle_response(void *ptr, size_t size, size_t nmemb, void *data)
{
    struct WebData *webdata = (struct WebData *)data;
    webdata->http_code = 0;

    // Parse the response to get the HTTP status code
    sscanf(ptr, "HTTP/1.%*d %ld", &webdata->http_code);

    return size * nmemb;
}
 
// Define the main function
int main(int argc, char *argv[])
{
    CURL *curl;
    CURLcode response;
    struct WebData webdata;
    time_t now;
    struct tm *local_time;

    // Check the command line arguments
    if (argc < 2)
    {
        printf("Usage: %s <URL> [interval]\n", argv[0]);
        printf("Example: %s https://www.google.com 10\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Set the URL to be monitored
    webdata.url = argv[1];

    // Set up the CURL library
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, webdata.url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, handle_response);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&webdata);

    while (1)
    {
        printf("\n------------------\n");

        // Get the local time and print it to stdout
        now = time(NULL);
        local_time = localtime(&now);
        printf("%04d-%02d-%02d %02d:%02d:%02d\n", local_time->tm_year + 1900, local_time->tm_mon + 1,
            local_time->tm_mday, local_time->tm_hour, local_time->tm_min, local_time->tm_sec);

        // Perform the HTTP request
        response = curl_easy_perform(curl);

        // Check for errors
        if (response != CURLE_OK)
        {
            printf("cURL error: %s\n", curl_easy_strerror(response));
        }
        else
        {
            // Check the HTTP status code
            if (webdata.http_code == 200)
            {
                printf("%s is up\n", webdata.url);
            }
            else
            {
                printf("%s is down\n", webdata.url);
            }
        }

        // Sleep for the specified interval
        if (argc >= 3)
        {
            sleep(atoi(argv[2]));
        }
        else
        {
            sleep(60);
        }
    }

    // Clean up the CURL library
    curl_easy_cleanup(curl);
    curl_global_cleanup();

    return 0;
}