//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    return size * nmemb;
}

int main(int argc, char *argv[])
{
    CURL *curl;
    CURLcode res;
    char *download_url = "https://speedtest.net/speedtest-config.php?os=desktop&browser=chrome&browserversion=88.0.4324.190&conn=cable&download=5000&upload=1000&ping=10&serverid=2131&isp=Comcast&ip=24.0.0.1&testid=20220402_220000_000_24.0.0.1";
    FILE *fp;
    long response_code;

    /* Initialize curl */
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        /* Set URL to download */
        curl_easy_setopt(curl, CURLOPT_URL, download_url);

        /* Set callback function to handle downloaded data */
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

        /* Set user data for callback function */
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);

        /* Perform the download */
        res = curl_easy_perform(curl);

        /* Check for errors */
        if(res!= CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

        /* Close the curl session */
        curl_easy_cleanup(curl);
    }

    /* Close the file */
    fclose(stdout);

    /* Exit the program */
    return 0;
}