//FormAI DATASET v1.0 Category: Image Classification system ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CLASSES 3
#define IMAGE_SIZE 28
#define INPUT_SIZE (IMAGE_SIZE * IMAGE_SIZE)
#define HIDDEN_SIZE 16
#define LEARNING_RATE 0.1
#define BATCH_SIZE 10

typedef struct {
    double *data;
    int label;
} Example;

typedef struct {
    double *input_weights;
    double *hidden_weights;
    double *input_bias;
    double *hidden_bias;
} Model;

void seed_random() {
    srand(42);
}

double random_double() {
    return (double)rand() / RAND_MAX;
}

Model *create_model() {
    Model *model = malloc(sizeof(Model));

    model->input_weights = malloc(sizeof(double) * INPUT_SIZE * HIDDEN_SIZE);
    model->hidden_weights = malloc(sizeof(double) * HIDDEN_SIZE * NUM_CLASSES);
    model->input_bias = malloc(sizeof(double) * HIDDEN_SIZE);
    model->hidden_bias = malloc(sizeof(double) * NUM_CLASSES);

    for (int i = 0; i < INPUT_SIZE * HIDDEN_SIZE; i++) {
        model->input_weights[i] = random_double() - 0.5;
    }

    for (int i = 0; i < HIDDEN_SIZE * NUM_CLASSES; i++) {
        model->hidden_weights[i] = random_double() - 0.5;
    }

    for (int i = 0; i < HIDDEN_SIZE; i++) {
        model->input_bias[i] = random_double() - 0.5;
    }

    for (int i = 0; i < NUM_CLASSES; i++) {
        model->hidden_bias[i] = random_double() - 0.5;
    }

    return model;
}

void destroy_model(Model *model) {
    free(model->input_weights);
    free(model->hidden_weights);
    free(model->input_bias);
    free(model->hidden_bias);
    free(model);
}

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double *sigmoid_array(double *input, int size) {
    double *output = malloc(sizeof(double) * size);

    for (int i = 0; i < size; i++) {
        output[i] = sigmoid(input[i]);
    }

    return output;
}

double *vector_add(double *a, double *b, int size) {
    double *output = malloc(sizeof(double) * size);

    for (int i = 0; i < size; i++) {
        output[i] = a[i] + b[i];
    }

    return output;
}

void vector_mutate(double *v, int size, double scale) {
    for (int i = 0; i < size; i++) {
        v[i] += (random_double() - 0.5) * scale;
    }
}

Example *create_example(double *data, int label) {
    Example *example = malloc(sizeof(Example));
    example->data = data;
    example->label = label;
    return example;
}

void destroy_example(Example *example) {
    free(example->data);
    free(example);
}

double *image_to_vector(char *filename) {
    double *vector = malloc(sizeof(double) * INPUT_SIZE);

    FILE *file = fopen(filename, "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int i = 0;

    while ((read = getline(&line, &len, file)) != -1 && i < IMAGE_SIZE) {
        for (int j = 0; j < IMAGE_SIZE; j++) {
            vector[i * IMAGE_SIZE + j] = (double)(line[j] - '0') / 255.0;
        }

        i++;
    }

    fclose(file);

    if (line) {
        free(line);
    }

    return vector;
}

double *image_batch_to_input(Example **examples, int size) {
    double *input = malloc(sizeof(double) * size * INPUT_SIZE);

    for (int i = 0; i < size; i++) {
        memcpy(input + i * INPUT_SIZE, examples[i]->data, sizeof(double) * INPUT_SIZE);
    }

    return input;
}

int *label_batch_to_output(Example **examples, int size) {
    int *output = malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++) {
        output[i] = examples[i]->label;
    }

    return output;
}

int predict(Model *model, double *input) {
    double *hidden_input = vector_add(model->input_weights, model->input_bias, HIDDEN_SIZE);
    double *hidden_output = sigmoid_array(hidden_input, HIDDEN_SIZE);

    double *output_input = vector_add(model->hidden_weights, model->hidden_bias, NUM_CLASSES);

    for (int i = 0; i < HIDDEN_SIZE; i++) {
        for (int j = 0; j < NUM_CLASSES; j++) {
            output_input[j] += hidden_output[i] * model->hidden_weights[i * NUM_CLASSES + j];
        }
    }

    free(hidden_input);
    free(hidden_output);

    double max_value = output_input[0];
    int max_index = 0;

    for (int i = 1; i < NUM_CLASSES; i++) {
        if (output_input[i] > max_value) {
            max_value = output_input[i];
            max_index = i;
        }
    }

    free(output_input);

    return max_index;
}

void train(Example **examples, int num_examples, Model *model) {
    double *input = image_batch_to_input(examples, BATCH_SIZE);
    int *output = label_batch_to_output(examples, BATCH_SIZE);

    double *hidden_input = vector_add(model->input_weights, model->input_bias, HIDDEN_SIZE);
    double *hidden_output = sigmoid_array(hidden_input, HIDDEN_SIZE);

    double *output_input = vector_add(model->hidden_weights, model->hidden_bias, NUM_CLASSES);

    for (int i = 0; i < HIDDEN_SIZE; i++) {
        for (int j = 0; j < NUM_CLASSES; j++) {
            output_input[j] += hidden_output[i] * model->hidden_weights[i * NUM_CLASSES + j];
        }
    }

    double *output_error = malloc(sizeof(double) * NUM_CLASSES);

    for (int i = 0; i < NUM_CLASSES; i++) {
        output_input[i] = sigmoid(output_input[i]);
        output_error[i] = output[i] - output_input[i];
    }

    double *hidden_error = malloc(sizeof(double) * HIDDEN_SIZE);

    for (int i = 0; i < HIDDEN_SIZE; i++) {
        double error = 0.0;

        for (int j = 0; j < NUM_CLASSES; j++) {
            error += output_error[j] * model->hidden_weights[i * NUM_CLASSES + j];
        }

        hidden_error[i] = hidden_output[i] * (1.0 - hidden_output[i]) * error;
    }

    for (int i = 0; i < HIDDEN_SIZE; i++) {
        for (int j = 0; j < NUM_CLASSES; j++) {
            model->hidden_weights[i * NUM_CLASSES + j] += LEARNING_RATE * hidden_output[i] * output_error[j];
        }
    }

    for (int i = 0; i < NUM_CLASSES; i++) {
        model->hidden_bias[i] += LEARNING_RATE * output_error[i];
    }

    for (int i = 0; i < INPUT_SIZE; i++) {
        for (int j = 0; j < HIDDEN_SIZE; j++) {
            model->input_weights[i * HIDDEN_SIZE + j] += LEARNING_RATE * hidden_error[j] * input[i];
        }
    }

    for (int i = 0; i < HIDDEN_SIZE; i++) {
        model->input_bias[i] += LEARNING_RATE * hidden_error[i];
    }

    free(input);
    free(output);
    free(hidden_input);
    free(hidden_output);
    free(output_input);
    free(output_error);
    free(hidden_error);
}

void shuffle_examples(Example **examples, int num_examples) {
    for (int i = 0; i < num_examples; i++) {
        int j = rand() % num_examples;
        Example *temp = examples[i];
        examples[i] = examples[j];
        examples[j] = temp;
    }
}

void train_model(char **filenames, int num_examples, Model *model) {
    Example **examples = malloc(sizeof(Example*) * num_examples);

    for (int i = 0; i < num_examples; i++) {
        double *input = image_to_vector(filenames[i]);
        int label = filenames[i][strlen(filenames[i]) - 5] - '0';
        examples[i] = create_example(input, label);
    }

    seed_random();

    for (int epoch = 0; epoch < 10; epoch++) {
        shuffle_examples(examples, num_examples);

        for (int i = 0; i < num_examples; i += BATCH_SIZE) {
            int batch_size = BATCH_SIZE;

            if (i + batch_size > num_examples) {
                batch_size = num_examples - i;
            }

            train(examples + i, batch_size, model);
        }
    }

    for (int i = 0; i < num_examples; i++) {
        destroy_example(examples[i]);
    }

    free(examples);
}

int main() {
    char *filenames[] = {
        "image0.txt",
        "image1.txt",
        "image2.txt",
        "image3.txt",
        "image4.txt",
        "image5.txt",
        "image6.txt",
        "image7.txt",
        "image8.txt",
        "image9.txt",
        "image10.txt",
        "image11.txt",
        "image12.txt",
        "image13.txt",
        "image14.txt",
        "image15.txt",
        "image16.txt",
        "image17.txt",
        "image18.txt",
        "image19.txt",
        "image20.txt",
        "image21.txt",
        "image22.txt",
        "image23.txt",
        "image24.txt",
        "image25.txt",
        "image26.txt",
        "image27.txt",
        "image28.txt",
        "image29.txt"
    };

    Model *model = create_model();

    train_model(filenames, 30, model);

    printf("Prediction for image0.txt: %d\n", predict(model, image_to_vector("image0.txt")));
    printf("Prediction for image8.txt: %d\n", predict(model, image_to_vector("image8.txt")));
    printf("Prediction for image17.txt: %d\n", predict(model, image_to_vector("image17.txt")));

    destroy_model(model);

    return 0;
}