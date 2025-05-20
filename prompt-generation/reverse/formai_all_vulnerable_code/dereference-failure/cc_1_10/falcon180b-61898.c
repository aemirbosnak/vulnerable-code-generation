//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((char*)userp)[size*nmemb] = '\0';
    return size*nmemb;
}

int main(int argc, char* argv[])
{
    CURL* curl;
    CURLcode res;
    char url[100];
    FILE* file;
    char buffer[4096];
    struct tm* tm;
    time_t now;
    int status_code;

    if(argc!= 3)
    {
        printf("Usage: %s <url> <logfile>\n", argv[0]);
        return 1;
    }

    strcpy(url, argv[1]);
    file = fopen(argv[2], "a");

    if(file == NULL)
    {
        printf("Error: Could not create log file.\n");
        return 1;
    }

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);

        res = curl_easy_perform(curl);

        if(res!= CURLE_OK)
        {
            printf("Error: %s\n", curl_easy_strerror(res));
        }
        else
        {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &status_code);

            time(&now);
            tm = localtime(&now);

            fprintf(file, "%d-%02d-%02d %02d:%02d:%02d %d\n", tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec, status_code);
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    fclose(file);

    return 0;
}