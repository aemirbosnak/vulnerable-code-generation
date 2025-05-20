//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    return size * nmemb;
}

int main(int argc, char **argv)
{
    CURL *curl;
    CURLcode res;
    double download_speed, upload_speed;
    struct curl_slist *slist = NULL;
    char *url = "https://speedtest.net/speedtest.php";
    FILE *fp;
    char readBuffer[1024];

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl)
    {
        slist = curl_slist_append(slist, "Expect:");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &fp);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, slist);

        res = curl_easy_perform(curl);
        if(res!= CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        }
        else
        {
            fseek(fp, 0, SEEK_SET);
            while(fgets(readBuffer, sizeof(readBuffer), fp)!= NULL)
            {
                if(strstr(readBuffer, "Download Speed:")!= NULL)
                {
                    sscanf(readBuffer, "Download Speed: %lf", &download_speed);
                }
                else if(strstr(readBuffer, "Upload Speed:")!= NULL)
                {
                    sscanf(readBuffer, "Upload Speed: %lf", &upload_speed);
                }
            }
            fclose(fp);

            printf("Download Speed: %.2lf Mbps\n", download_speed);
            printf("Upload Speed: %.2lf Mbps\n", upload_speed);
        }

        curl_easy_cleanup(curl);
        curl_slist_free_all(slist);
    }

    curl_global_cleanup();
    return 0;
}