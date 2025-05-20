//FormAI DATASET v1.0 Category: Image Classification system ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define MAX_IMAGES 1000 //maximum number of images in dataset
#define IMAGE_SIZE 784  //size of each image as a 1D array
#define TRAIN_RATIO 0.8 //ratio of images used for training

typedef struct {
    int label; //label of the image
    float* pixels; //1D array of pixel values
} Image;

typedef struct {
    int num_images;
    Image* images;
} Dataset;

//function to load dataset from CSV file
Dataset loadDataset(char* filename) {
    FILE *fp = fopen(filename, "r");
    if(!fp) {
        printf("Error: Unable to open file %s\n", filename);
        exit(1);
    }

    Dataset dataset;
    dataset.num_images = 0;
    dataset.images = (Image*) malloc(MAX_IMAGES * sizeof(Image));

    char line[IMAGE_SIZE + 3]; //plus 3 for comma, newline and NULL character
    while(fgets(line, sizeof(line), fp)) {
        char* token = strtok(line, ","); //first token is label
        dataset.images[dataset.num_images].label = atoi(token);
        dataset.images[dataset.num_images].pixels = (float*) malloc(IMAGE_SIZE * sizeof(float));
        for(int i = 0; i < IMAGE_SIZE; i++) {
            token = strtok(NULL, ",");
            dataset.images[dataset.num_images].pixels[i] = atof(token);
        }
        dataset.num_images++;
    }

    fclose(fp);
    return dataset;
}

//function to shuffle images randomly
void shuffleImages(Image* images, int num_images) {
    for(int i = num_images - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Image temp = images[i];
        images[i] = images[j];
        images[j] = temp;
    }
}

//function to split dataset into training and testing sets
void splitDataset(Dataset dataset, int train_size, Dataset* train_set, Dataset* test_set) {
    //shuffle images randomly
    shuffleImages(dataset.images, dataset.num_images);

    //populate training set
    train_set->num_images = train_size;
    train_set->images = (Image*) malloc(train_size * sizeof(Image));
    for(int i = 0; i < train_size; i++) {
        train_set->images[i] = dataset.images[i];
    }

    //populate testing set
    test_set->num_images = dataset.num_images - train_size;
    test_set->images = (Image*) malloc(test_set->num_images * sizeof(Image));
    for(int i = train_size; i < dataset.num_images; i++) {
        test_set->images[i - train_size] = dataset.images[i];
    }
}

//function to compute dot product of two vectors
float dotProduct(float* v1, float* v2, int size) {
    float result = 0;
    for(int i = 0; i < size; i++) {
        result += v1[i] * v2[i];
    }
    return result;
}

//function to calculate sigmoid of a number
float sigmoid(float x) {
    return 1 / (1 + exp(-x));
}

//function to train logistic regression model
void trainLogisticRegression(Dataset train_set, int num_epochs, float learning_rate, float* weights) {
    //initialize weights with zeros
    for(int i = 0; i <= IMAGE_SIZE; i++) {
        weights[i] = 0;
    }

    //train model using gradient descent
    for(int epoch = 0; epoch < num_epochs; epoch++) {
        for(int i = 0; i < train_set.num_images; i++) {
            Image image = train_set.images[i];
            int label = image.label;
            float* pixels = image.pixels;

            //add bias term to pixels
            float x[IMAGE_SIZE + 1];
            x[0] = 1;
            for(int j = 1; j <= IMAGE_SIZE; j++) {
                x[j] = pixels[j - 1];
            }

            //compute predicted probability
            float z = dotProduct(x, weights, IMAGE_SIZE + 1);
            float y = sigmoid(z);

            //update weights using gradient descent
            weights[0] += learning_rate * (label - y) * y * (1 - y) * x[0];
            for(int j = 1; j <= IMAGE_SIZE; j++) {
                weights[j] += learning_rate * (label - y) * y * (1 - y) * x[j];
            }
        }
    }
}

//function to predict label of an image
int predictImageLabel(Image image, float* weights) {
    //add bias term to pixels
    float x[IMAGE_SIZE + 1];
    x[0] = 1;
    for(int j = 1; j <= IMAGE_SIZE; j++) {
        x[j] = image.pixels[j - 1];
    }

    //compute predicted probability
    float z = dotProduct(x, weights, IMAGE_SIZE + 1);
    float y = sigmoid(z);

    //classify based on threshold 0.5
    if(y >= 0.5) {
        return 1;
    }
    else {
        return 0;
    }
}

//function to test logistic regression model
void testLogisticRegression(Dataset test_set, float* weights, int* num_correct, int* num_total) {
    for(int i = 0; i < test_set.num_images; i++) {
        Image image = test_set.images[i];
        int label = image.label;
        int prediction = predictImageLabel(image, weights);

        if(prediction == label) {
            (*num_correct)++;
        }
        (*num_total)++;
    }
}

int main() {
    //load dataset
    char filename[] = "mnist.csv";
    Dataset dataset = loadDataset(filename);

    //split dataset into training and testing sets
    Dataset train_set, test_set;
    splitDataset(dataset, TRAIN_RATIO * dataset.num_images, &train_set, &test_set);

    //train logistic regression model
    int num_epochs = 10;
    float learning_rate = 0.1;
    float weights[IMAGE_SIZE + 1]; //plus 1 for bias term
    trainLogisticRegression(train_set, num_epochs, learning_rate, weights);

    //test logistic regression model
    int num_correct = 0, num_total = 0;
    testLogisticRegression(test_set, weights, &num_correct, &num_total);

    //print accuracy
    float accuracy = ((float) num_correct) / num_total;
    printf("Accuracy: %.2f%%\n", accuracy * 100);

    //free memory
    for(int i = 0; i < dataset.num_images; i++) {
        free(dataset.images[i].pixels);
    }
    free(dataset.images);
    free(train_set.images);
    free(test_set.images);

    return 0;
}