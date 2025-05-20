//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;
    FILE *file = (FILE *)userp;
    return fwrite(contents, realsize, 1, file);
}

static int ProgressCallback(void *clientp, curl_off_t dltotal, curl_off_t dlnow, curl_off_t ultotal, curl_off_t ulnow)
{
    int id = *(int *)clientp;
    printf("Thread %d: Download progress: %ld of %ld bytes\n", id, dlnow, dltotal);
    return 0;
}

void download_file(char *url, int thread_id)
{
    CURL *curl;
    FILE *fp;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        char filename[20];
        sprintf(filename, "thread%d.html", thread_id);
        fp = fopen(filename, "wb");

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);
        curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, ProgressCallback);
        curl_easy_setopt(curl, CURLOPT_PROGRESSDATA, &thread_id);

        res = curl_easy_perform(curl);

        if(res!= CURLE_OK)
            fprintf(stderr, "Thread %d: Download failed: %s\n", thread_id, curl_easy_strerror(res));

        else
            printf("Thread %d: Download completed\n", thread_id);

        fclose(fp);
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
}

int main()
{
    int num_threads = 5;
    pthread_t threads[num_threads];

    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, (void *)download_file, (void *)"https://example.com");
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}