//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: calm
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <curl/curl.h>
 
//Struct to store the returned data
struct MemoryStruct {
  char *memory;
  size_t size;
};
 
//Function callback to write data into MemoryStruct object
static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *)userp;
    mem->memory = realloc(mem->memory, mem->size + realsize + 1);
    if (mem->memory == NULL) {
        printf("Unable to allocate memory for writing data.\n");
        exit(EXIT_FAILURE);
    }
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;
    return realsize;
}
 
int main() {
    CURL *curl;
    CURLcode res;
    struct MemoryStruct chunk;
    chunk.memory = malloc(1);
    chunk.size = 0;
    char *url = "http://speedtest.net/speedtest-servers.php";
 
    //Initialize the curl object and set options
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
 
        //Perform the request
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            printf("Unable to retrieve data from the server. Error: %s\n", curl_easy_strerror(res));
            exit(EXIT_FAILURE);
        }
        else {
            //Data retrieval successful. Now parse the data and extract the server URL.
            char *p = strstr(chunk.memory, "<server url=\"");
            char *start = p + 13; //Start of server URL
            char *end = strstr(start, "\""); //End of server URL
            char server_url[100];
            strncpy(server_url, start, end-start); //Copy Server URL into a char array
            server_url[end-start] = '\0'; //Make it a valid string
            printf("Server URL: %s\n", server_url);
            curl_easy_cleanup(curl);
 
            //Now test the internet speed using the selected server
            struct MemoryStruct down_chunk;
            down_chunk.memory = malloc(1);
            down_chunk.size = 0;
            struct MemoryStruct up_chunk;
            up_chunk.memory = malloc(1);
            up_chunk.size = 0;
            char *down_url = "http://c.speedtest.net/speedtest/random250x250.jpg";
            char *up_url = "http://c.speedtest.net/speedtest/upload.php";
            curl = curl_easy_init();
            if(curl) {
                /* Download Speed Test */
                curl_easy_setopt(curl, CURLOPT_URL, down_url);
                curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&down_chunk);
                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
                clock_t tStart = clock();
                res = curl_easy_perform(curl);
                if(res != CURLE_OK) {
                    printf("Download speed test failed. Error: %s\n", curl_easy_strerror(res));
                    exit(EXIT_FAILURE);
                }
                float time_elapsed = (float)(clock() - tStart)/CLOCKS_PER_SEC;
                float download_speed = ((float)down_chunk.size/time_elapsed)/1024; //Speed in KB/s
                printf("Download Speed: %.1f KB/s\n", download_speed);
 
                /* Upload Speed Test */
                char *postdata = "content1=1234567890123456789012345678901234567890&content2=0987654321";
                struct curl_httppost *formpost=NULL;
                struct curl_httppost *lastptr=NULL;
                curl_formadd(&formpost, &lastptr, CURLFORM_PTRNAME, "Dummy Data", CURLFORM_PTRCONTENTS, postdata, CURLFORM_CONTENTSLENGTH, 62, CURLFORM_END);
                curl_easy_setopt(curl, CURLOPT_URL, up_url);
                curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&up_chunk);
                tStart = clock();
                res = curl_easy_perform(curl);
                if(res != CURLE_OK) {
                    printf("Upload speed test failed. Error: %s\n", curl_easy_strerror(res));
                    exit(EXIT_FAILURE);
                }
                time_elapsed = (float)(clock() - tStart)/CLOCKS_PER_SEC;
                float upload_speed = ((float)126/time_elapsed)/1024; //Speed in KB/s
                printf("Upload Speed: %.1f KB/s\n", upload_speed);
                curl_easy_cleanup(curl);
                curl_formfree(formpost);
            }
            free(down_chunk.memory);
            free(up_chunk.memory);
        }
    }
    free(chunk.memory);
    return 0;
}