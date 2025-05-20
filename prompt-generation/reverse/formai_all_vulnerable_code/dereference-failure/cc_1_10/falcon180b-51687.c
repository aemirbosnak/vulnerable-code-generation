//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <sys/time.h>

// Function to perform HTTP GET request
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((char*)userp)[(size_t)0] = '\0';
    return size * nmemb;
}

// Function to check if the website is up or down
int CheckWebsite(char* website)
{
    CURL* curl = curl_easy_init();
    CURLcode res;

    if (curl)
    {
        char* buffer = malloc(10000);
        curl_easy_setopt(curl, CURLOPT_URL, website);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, buffer);
        res = curl_easy_perform(curl);
        if (res!= CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        }
        else
        {
            if (strstr(buffer, "200 OK"))
            {
                printf("Website is up\n");
                return 1;
            }
            else
            {
                printf("Website is down\n");
                return 0;
            }
        }
        curl_easy_cleanup(curl);
    }
    return 0;
}

// Function to continuously check the website status
void MonitorWebsite(char* website)
{
    while (1)
    {
        int status = CheckWebsite(website);
        if (status == 0)
        {
            printf("Website is down\n");
            system("say Website is down");
        }
        else if (status == 1)
        {
            printf("Website is up\n");
            system("say Website is up");
        }
        sleep(60);
    }
}

// Main function
int main(int argc, char** argv)
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <website>\n", argv[0]);
        exit(1);
    }
    MonitorWebsite(argv[1]);
    return 0;
}