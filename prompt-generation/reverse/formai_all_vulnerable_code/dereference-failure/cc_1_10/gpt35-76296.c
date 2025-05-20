//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_BUF_SIZE 1024
#define TEST_FILE_URL "http://speedtest.tele2.net/100MB.zip"

struct SpeedTestResults {
    double download_speed;
    double upload_speed;
};

struct MemoryStruct {
    char *memory;
    size_t size;
};

static size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *) userp;
    mem->memory = realloc(mem->memory, mem->size + realsize + 1);
    if (mem->memory == NULL) {
        /* out of memory! */
        printf("Failed to allocate memory for download.\n");
        return 0;
    }
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;
    return realsize;
}

static double perform_download(FILE *devnull, CURL *curl) {
    struct MemoryStruct chunk;
    chunk.memory = malloc(1);
    chunk.size = 0;
    curl_easy_setopt(curl, CURLOPT_URL, TEST_FILE_URL);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *) &chunk);
    curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
    curl_easy_perform(curl);
    double metaspeed = (100.0 * chunk.size) / (1024 * 1024);
    if (metaspeed > 0) {
        time_t start_time = time(NULL);
        fseek(devnull, 0, SEEK_SET);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, devnull);
        curl_easy_perform(curl);
        double elapsed = difftime(time(NULL), start_time);
        return metaspeed / elapsed;
    }
    return 0.0;
}

static struct SpeedTestResults perform_speedtest() {
    struct SpeedTestResults results;
    FILE *devnull = fopen("/dev/null", "w");
    CURL *curl = curl_easy_init();
    if (curl) {
        results.download_speed = perform_download(devnull, curl);
        fseek(devnull, 0, SEEK_SET);
        curl_easy_setopt(curl, CURLOPT_URL, "http://ipv4.ikoula.testdebit.info/");
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, devnull);
        curl_easy_perform(curl);
        curl_easy_getinfo(curl, CURLINFO_SPEED_UPLOAD, &results.upload_speed);
        curl_easy_cleanup(curl);
    } else {
        printf("Failed to initialize curl.\n");
        results.download_speed = 0;
        results.upload_speed = 0;
    }
    fclose(devnull);
    return results;
}

char *format_speed(double speed) {
    if (speed < 1024) {
        return "B/s";
    } else if (speed < 1024 * 1024) {
        return "KB/s";
    } else {
        return "MB/s";
    }
}

double normalize_speed(double speed) {
    if (speed < 1024) {
        return speed;
    } else if (speed < 1024 * 1024) {
        return speed / 1024;
    } else {
        return speed / (1024 * 1024);
    }
}

int main() {
    struct SpeedTestResults results = perform_speedtest();
    printf("Download speed: %.2f %s\nUpload speed: %.2f %s\n",
           normalize_speed(results.download_speed), format_speed(results.download_speed),
           normalize_speed(results.upload_speed), format_speed(results.upload_speed));
    return EXIT_SUCCESS;
}