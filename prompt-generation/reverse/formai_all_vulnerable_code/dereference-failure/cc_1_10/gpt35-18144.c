//FormAI DATASET v1.0 Category: Searching algorithm ; Style: distributed
// Assuming we have a dataset consisting of multiple key-value pairs
// where each key is a unique identifier and value is a text document
// and we want to search for a keyword in all documents

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define NUM_MAPPERS 4 // number of machines
#define NUM_REDUCERS 2 // number of machines
#define BUFFER_SIZE 1024 // buffer size for file input/output

pthread_t mappers[NUM_MAPPERS];
pthread_t reducers[NUM_REDUCERS];

// structure for key-value pair
typedef struct KeyValuePair {
    int key;
    char value[BUFFER_SIZE];
} KeyValuePair;

// structure for MapReduce task
typedef struct MapReduceTask {
    int id;
    int mapperID;
    int reducerID;
    int numMappers;
    int numReducers;
    KeyValuePair* inputData;
    KeyValuePair* outputData;
} MapReduceTask;

// function to set up a MapReduce task
void setupMapReduceTask(MapReduceTask* task, int id, int mapperID, int reducerID, int numMappers, int numReducers, KeyValuePair* inputData, KeyValuePair* outputData) {
    task->id = id;
    task->mapperID = mapperID;
    task->reducerID = reducerID;
    task->numMappers = numMappers;
    task->numReducers = numReducers;
    task->inputData = inputData;
    task->outputData = outputData;
}

// function to read the dataset from a file
KeyValuePair* readDataFromFile(char* filename, int* numItems) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    char buffer[BUFFER_SIZE];
    int itemCount = 0;
    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        itemCount++;
    }
    *numItems = itemCount;

    KeyValuePair* data = (KeyValuePair*) malloc(itemCount * sizeof(KeyValuePair));
    rewind(file);

    fgets(buffer, BUFFER_SIZE, file); // skip first line
    int i = 0;
    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        char* token = strtok(buffer, ",");
        data[i].key = atoi(token);

        token = strtok(NULL, ",");
        strcpy(data[i].value, token);

        i++;
    }

    fclose(file);
    return data;
}

// function to write the output to a file
void writeDataToFile(KeyValuePair* outputData, int numItems) {
    FILE* file = fopen("output.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    for (int i = 0; i < numItems; i++) {
        fprintf(file, "%d,%s", outputData[i].key, outputData[i].value);
    }
    fclose(file);
}

// Map function to search for a keyword in a text document
void* map(void* arg) {
    MapReduceTask* task = (MapReduceTask*) arg;

    int numItems = task->numMappers;
    int chunkSize = numItems / task->numMappers;
    int startIndex = task->mapperID * chunkSize;
    int endIndex = startIndex + chunkSize;

    for (int i = startIndex; i < endIndex; i++) {
        if (strstr(task->inputData[i].value, "keyword") != NULL) {
            // found keyword in text document
            task->outputData[i] = task->inputData[i];
        }
    }

    return NULL;
}

// Reduce function to merge map outputs
void* reduce(void* arg) {
    MapReduceTask* task = (MapReduceTask*) arg;

    int numItems = task->numReducers;
    int chunkSize = numItems / task->numReducers;
    int startIndex = task->reducerID * chunkSize;
    int endIndex = startIndex + chunkSize;

    for (int i = startIndex; i < endIndex; i++) {
        int mapperID = i % task->numMappers;

        for (int j = 0; j < task->numMappers; j++) {
            if (task->inputData[j].key == i) {
                task->outputData[i] = task->inputData[j];
                break;
            }
        }
    }

    return NULL;
}

int main() {
    int numItems;
    KeyValuePair* inputData = readDataFromFile("input.txt", &numItems);

    KeyValuePair* intermediateData = (KeyValuePair*) malloc(numItems * sizeof(KeyValuePair));

    MapReduceTask mapTasks[NUM_MAPPERS];
    MapReduceTask reduceTasks[NUM_REDUCERS];

    // Map phase
    for (int i = 0; i < NUM_MAPPERS; i++) {
        setupMapReduceTask(&mapTasks[i], i, i, i % NUM_REDUCERS, NUM_MAPPERS, NUM_REDUCERS, inputData, intermediateData);
        pthread_create(&mappers[i], NULL, map, &mapTasks[i]);
    }

    for (int i = 0; i < NUM_MAPPERS; i++) {
        pthread_join(mappers[i], NULL);
    }

    // Reduce phase
    KeyValuePair* outputData = (KeyValuePair*) malloc(numItems * sizeof(KeyValuePair));
    for (int i = 0; i < NUM_REDUCERS; i++) {
        setupMapReduceTask(&reduceTasks[i], i, -1, i, NUM_MAPPERS, NUM_REDUCERS, intermediateData, outputData);
        pthread_create(&reducers[i], NULL, reduce, &reduceTasks[i]);
    }

    for (int i = 0; i < NUM_REDUCERS; i++) {
        pthread_join(reducers[i], NULL);
    }

    writeDataToFile(outputData, numItems);

    free(inputData);
    free(intermediateData);
    free(outputData);

    return 0;
}