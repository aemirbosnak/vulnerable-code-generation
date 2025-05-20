//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define BLOCK_SIZE 1024

typedef struct {
    char *file_path;
    unsigned char *image_data;
    size_t image_size;
} image_data_t;

typedef struct {
    image_data_t *image_data;
    unsigned char *watermark_data;
    size_t watermark_size;
} watermark_data_t;

sem_t image_count_sem;
sem_t watermark_count_sem;
pthread_mutex_t image_mutex;
pthread_mutex_t watermark_mutex;

void *watermark_thread(void *args) {
    watermark_data_t *data = (watermark_data_t *)args;
    unsigned char *image_data = data->image_data->image_data;
    size_t image_size = data->image_data->image_size;
    unsigned char *watermark_data = data->watermark_data;
    size_t watermark_size = data->watermark_size;
    
    for (size_t i = 0; i < image_size; i++) {
        image_data[i] = (image_data[i] & 0xF0) | (watermark_data[i] & 0x0F);
    }
    
    pthread_mutex_lock(&watermark_mutex);
    sem_post(&watermark_count_sem);
    pthread_mutex_unlock(&watermark_mutex);
    
    return NULL;
}

void *embed_watermark(void *args) {
    image_data_t *image_data = (image_data_t *)args;
    char *file_path = image_data->file_path;
    
    FILE *file = fopen(file_path, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }
    
    struct stat file_stat;
    if (fstat(fileno(file), &file_stat) != 0) {
        perror("Error getting file size");
        fclose(file);
        return NULL;
    }
    
    image_data->image_size = file_stat.st_size;
    image_data->image_data = (unsigned char *)malloc(image_data->image_size);
    if (image_data->image_data == NULL) {
        perror("Error allocating memory for image data");
        fclose(file);
        return NULL;
    }
    
    if (fread(image_data->image_data, 1, image_data->image_size, file) != image_data->image_size) {
        perror("Error reading file");
        free(image_data->image_data);
        fclose(file);
        return NULL;
    }
    
    fclose(file);
    
    pthread_mutex_lock(&image_mutex);
    sem_post(&image_count_sem);
    pthread_mutex_unlock(&image_mutex);
    
    return NULL;
}

int main() {
    sem_init(&image_count_sem, 0, 0);
    sem_init(&watermark_count_sem, 0, 0);
    pthread_mutex_init(&image_mutex, NULL);
    pthread_mutex_init(&watermark_mutex, NULL);
    
    DIR *dir = opendir(".");
    if (dir == NULL) {
        perror("Error opening directory");
        return 1;
    }
    
    pthread_t watermark_thread_id;
    pthread_t embed_watermark_thread_id;
    
    while (1) {
        struct dirent *dirent = readdir(dir);
        if (dirent == NULL) {
            break;
        }
        
        if (dirent->d_type != DT_REG) {
            continue;
        }
        
        char *file_path = malloc(strlen(dirent->d_name) + 1);
        if (file_path == NULL) {
            perror("Error allocating memory for file path");
            closedir(dir);
            return 1;
        }
        
        strcpy(file_path, dirent->d_name);
        
        image_data_t *image_data = malloc(sizeof(image_data_t));
        if (image_data == NULL) {
            perror("Error allocating memory for image data");
            closedir(dir);
            return 1;
        }
        
        image_data->file_path = file_path;
        image_data->image_data = NULL;
        image_data->image_size = 0;
        
        watermark_data_t *watermark_data = malloc(sizeof(watermark_data_t));
        if (watermark_data == NULL) {
            perror("Error allocating memory for watermark data");
            closedir(dir);
            return 1;
        }
        
        watermark_data->image_data = image_data;
        watermark_data->watermark_data = NULL;
        watermark_data->watermark_size = 0;
        
        pthread_create(&embed_watermark_thread_id, NULL, embed_watermark, image_data);
        pthread_create(&watermark_thread_id, NULL, watermark_thread, watermark_data);
        
        sem_wait(&image_count_sem);
        sem_wait(&watermark_count_sem);
        
        pthread_join(embed_watermark_thread_id, NULL);
        pthread_join(watermark_thread_id, NULL);
        
        free(image_data->image_data);
        free(image_data);
        free(watermark_data);
    }
    
    closedir(dir);
    
    sem_destroy(&image_count_sem);
    sem_destroy(&watermark_count_sem);
    pthread_mutex_destroy(&image_mutex);
    pthread_mutex_destroy(&watermark_mutex);
    
    return 0;
}