//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: medieval
#include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <curl/curl.h>
    #include <time.h>
    #include <math.h>

    size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
    {
        size_t realsize = size * nmemb;
        char* data = (char*)malloc(realsize + 1);
        memcpy(data, contents, realsize);
        data[realsize] = '\0';

        printf("%s", data);

        free(data);
        return realsize;
    }

    int main(int argc, char** argv)
    {
        if(argc < 2)
        {
            printf("Usage: %s <server_url>\n", argv[0]);
            return 1;
        }

        CURL* curl;
        CURLcode res;

        curl_global_init(CURL_GLOBAL_DEFAULT);
        curl = curl_easy_init();

        if(curl)
        {
            char url[100];
            strcpy(url, argv[1]);

            curl_easy_setopt(curl, CURLOPT_URL, url);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

            res = curl_easy_perform(curl);

            if(res!= CURLE_OK)
            {
                printf("Error: %s\n", curl_easy_strerror(res));
            }

            curl_easy_cleanup(curl);
        }

        curl_global_cleanup();

        return 0;
    }