//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: standalone
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
    FILE *fp;
    char url[50];
    double speed;

    if(argc!= 2)
    {
        printf("Usage: %s <server_url>\n", argv[0]);
        exit(1);
    }

    strcpy(url, argv[1]);

    // Initialize curl
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl)
    {
        // Set the URL to download
        curl_easy_setopt(curl, CURLOPT_URL, url);

        // Set the write callback function
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

        // Set the write data pointer
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);

        // Perform the download
        res = curl_easy_perform(curl);

        // Close the curl session
        curl_easy_cleanup(curl);

        // Calculate the download speed
        speed = (double)curl_easy_getinfo(curl, CURLINFO_SPEED_DOWNLOAD, NULL) / 1024;

        // Open the log file
        fp = fopen("speed_test_log.txt", "a");

        // Write the speed to the log file
        fprintf(fp, "Download speed: %.2lf KB/s\n", speed);

        // Close the log file
        fclose(fp);

        // Print the download speed
        printf("Download speed: %.2lf KB/s\n", speed);
    }

    curl_global_cleanup();

    return 0;
}