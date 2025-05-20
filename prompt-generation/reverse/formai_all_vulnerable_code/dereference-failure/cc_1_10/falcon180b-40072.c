//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define SERVER_URL "http://speedtest.net"
#define UPLOAD_FILE "upload.txt"
#define DOWNLOAD_FILE "download.txt"

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    FILE* file = (FILE*)userp;
    size_t written = fwrite(contents, size, nmemb, file);
    return written;
}

int main(int argc, char* argv[])
{
    CURL* curl;
    FILE* uploadFile;
    FILE* downloadFile;
    struct curl_slist* headers = NULL;
    char readBuffer[CURL_MAX_WRITE_SIZE];
    long responseCode;
    CURLcode res;

    curl = curl_easy_init();
    if(curl)
    {
        uploadFile = fopen(UPLOAD_FILE, "wb");
        downloadFile = fopen(DOWNLOAD_FILE, "wb");

        if(uploadFile && downloadFile)
        {
            headers = curl_slist_append(headers, "Expect:");
            curl_easy_setopt(curl, CURLOPT_URL, SERVER_URL);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, uploadFile);
            curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);
            curl_easy_setopt(curl, CURLOPT_READDATA, NULL);
            curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);
            curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, NULL);
            curl_easy_setopt(curl, CURLOPT_PROGRESSDATA, NULL);
            curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "");
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

            res = curl_easy_perform(curl);

            if(res == CURLE_OK)
            {
                curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &responseCode);
                printf("Upload Speed: %ld\n", responseCode);
            }
            else
            {
                printf("Error: %s\n", curl_easy_strerror(res));
            }

            curl_easy_cleanup(curl);
            fclose(uploadFile);
            fclose(downloadFile);
        }
        else
        {
            printf("Error: could not open files.\n");
        }
    }
    else
    {
        printf("Error: could not initialize curl.\n");
    }

    return 0;
}