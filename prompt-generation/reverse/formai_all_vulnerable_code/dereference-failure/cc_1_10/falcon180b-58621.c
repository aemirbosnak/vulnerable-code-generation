//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    ((char*)userp)[strlen((char*)userp)] = 0;
    return size * nmemb;
}

int main(int argc, char *argv[]) {
    CURL *curl;
    CURLcode res;
    char *url = "https://www.speedtest.net/speedtest.php?test=1";
    char *useragent = "Mozilla/5.0 (Windows NT 6.1; WOW64; rv:17.0) Gecko/20100101 Firefox/17.0";
    char *referer = "https://www.speedtest.net/";
    char *data = malloc(1000000);
    char *download_speed = malloc(100);
    char *upload_speed = malloc(100);
    FILE *fp;
    int i;
    long file_size;
    double download_speed_num;
    double upload_speed_num;
    
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, useragent);
        curl_easy_setopt(curl, CURLOPT_REFERER, referer);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, data);
        res = curl_easy_perform(curl);
        if(res!= CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    
    fp = fopen("speedtest.html", "w");
    if(fp) {
        fwrite(data, strlen(data), 1, fp);
        fclose(fp);
    }
    
    fp = fopen("speedtest.html", "r");
    if(fp) {
        while((i = fgetc(fp))!= EOF) {
            if(i == '<') {
                if(fgets(referer, 100, fp)!= NULL) {
                    strcat(referer, ">");
                    strcat(referer, " ");
                }
            }
            else if(i == '"') {
                if(fgets(download_speed, 100, fp)!= NULL) {
                    strcat(download_speed, " ");
                }
            }
            else if(i == '\n') {
                download_speed_num = atof(download_speed);
                download_speed_num = download_speed_num / 8;
                upload_speed_num = download_speed_num * 0.8;
                sprintf(download_speed, "%.2f", download_speed_num);
                sprintf(upload_speed, "%.2f", upload_speed_num);
                printf("Download Speed: %s Mbps\n", download_speed);
                printf("Upload Speed: %s Mbps\n", upload_speed);
                break;
            }
        }
        fclose(fp);
    }
    
    free(data);
    free(download_speed);
    free(upload_speed);
    
    return 0;
}