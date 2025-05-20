//FormAI DATASET v1.0 Category: Image Classification system ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define IMAGE_SIZE 784   // 28 x 28 pixels
#define NUM_CLASSES 10   // 0 to 9 digits
#define NUM_HIDDEN_UNITS 128
#define LEARNING_RATE 0.1
#define NUM_EPOCHS 50

// Define a structure for a single layer in our neural network
typedef struct {
  float *weights;
  float *biases;
  float *outputs;
} Layer;

// Allocate memory for a layer
void layer_alloc(Layer *layer, int num_inputs, int num_outputs) {
  layer->weights = calloc(num_inputs * num_outputs, sizeof(float));
  layer->biases = calloc(num_outputs, sizeof(float));
  layer->outputs = calloc(num_outputs, sizeof(float));
}

// Free memory for a layer
void layer_free(Layer *layer) {
  free(layer->weights);
  free(layer->biases);
  free(layer->outputs);
}

// Initialize the weights and biases of a layer with random values
void layer_init(Layer *layer, int num_inputs, int num_outputs) {
  for (int i = 0; i < num_inputs * num_outputs; i++) {
    layer->weights[i] = ((float) rand() / RAND_MAX) - 0.5f;
  }
  for (int i = 0; i < num_outputs; i++) {
    layer->biases[i] = ((float) rand() / RAND_MAX) - 0.5f;
  }
}

// Compute the dot product of the inputs and weights of a layer, add the biases, and apply the activation function
void layer_forward(Layer *layer, float *inputs) {
  for (int j = 0; j < NUM_HIDDEN_UNITS; j++) {
    float dot_product = 0.0f;
    for (int i = 0; i < IMAGE_SIZE; i++) {
      dot_product += inputs[i] * layer->weights[i * NUM_HIDDEN_UNITS + j];
    }
    dot_product += layer->biases[j];
    layer->outputs[j] = 1.0f / (1.0f + expf(-dot_product));
  }
}

// Train a neural network on a dataset of images and labels
void train_network(float **images, int *labels, int num_images) {
  // Allocate memory for our layers
  Layer input_layer, hidden_layer, output_layer;
  layer_alloc(&input_layer, IMAGE_SIZE, NUM_HIDDEN_UNITS);
  layer_alloc(&hidden_layer, NUM_HIDDEN_UNITS, NUM_HIDDEN_UNITS);
  layer_alloc(&output_layer, NUM_HIDDEN_UNITS, NUM_CLASSES);

  // Initialize the weights and biases of our layers
  layer_init(&input_layer, IMAGE_SIZE, NUM_HIDDEN_UNITS);
  layer_init(&hidden_layer, NUM_HIDDEN_UNITS, NUM_HIDDEN_UNITS);
  layer_init(&output_layer, NUM_HIDDEN_UNITS, NUM_CLASSES);

  // Train the network for a number of epochs
  for (int epoch = 0; epoch < NUM_EPOCHS; epoch++) {
    float total_loss = 0.0f;
    for (int image_index = 0; image_index < num_images; image_index++) {
      // Forward pass through the network
      layer_forward(&input_layer, images[image_index]);
      layer_forward(&hidden_layer, input_layer.outputs);
      layer_forward(&output_layer, hidden_layer.outputs);

      // Compute the loss and gradients of the output layer
      float output_loss[NUM_CLASSES];
      float output_gradients[NUM_CLASSES];
      for (int k = 0; k < NUM_CLASSES; k++) {
        output_loss[k] = (labels[image_index] == k) ? 1.0f - output_layer.outputs[k] : 0.0f - output_layer.outputs[k];
        output_gradients[k] = output_loss[k] * output_layer.outputs[k] * (1.0f - output_layer.outputs[k]);
      }
      total_loss += output_loss[labels[image_index]];

      // Compute the gradients of the hidden layer
      float hidden_gradients[NUM_HIDDEN_UNITS];
      for (int j = 0; j < NUM_HIDDEN_UNITS; j++) {
        float dot_product = 0.0f;
        for (int k = 0; k < NUM_CLASSES; k++) {
          dot_product += output_gradients[k] * output_layer.weights[j * NUM_CLASSES + k];
        }
        hidden_gradients[j] = hidden_layer.outputs[j] * (1.0f - hidden_layer.outputs[j]) * dot_product;
      }

      // Update the weights and biases of the output layer
      for (int j = 0; j < NUM_HIDDEN_UNITS; j++) {
        for (int k = 0; k < NUM_CLASSES; k++) {
          output_layer.weights[j * NUM_CLASSES + k] -= LEARNING_RATE * output_gradients[k] * hidden_layer.outputs[j];
        }
        output_layer.biases[j] -= LEARNING_RATE * output_gradients[j];
      }

      // Update the weights and biases of the hidden layer
      for (int i = 0; i < IMAGE_SIZE; i++) {
        for (int j = 0; j < NUM_HIDDEN_UNITS; j++) {
          hidden_layer.weights[i * NUM_HIDDEN_UNITS + j] -= LEARNING_RATE * hidden_gradients[j] * input_layer.outputs[i];
        }
      }
      for (int j = 0; j < NUM_HIDDEN_UNITS; j++) {
        hidden_layer.biases[j] -= LEARNING_RATE * hidden_gradients[j];
      }
    }
    printf("Epoch %d: Loss = %f\n", epoch + 1, total_loss / num_images);
  }

  // Free memory for our layers
  layer_free(&input_layer);
  layer_free(&hidden_layer);
  layer_free(&output_layer);
}

int main() {
  // Load the MNIST dataset of handwritten digit images and labels
  float **images = calloc(60000, sizeof(float *));
  int *labels = calloc(60000, sizeof(int));
  for (int i = 0; i < 60000; i++) {
    images[i] = calloc(IMAGE_SIZE, sizeof(float));
  }
  FILE *fp_images = fopen("train-images.idx3-ubyte", "rb");
  FILE *fp_labels = fopen("train-labels.idx1-ubyte", "rb");
  unsigned char buffer[16];
  fread(buffer, sizeof(unsigned char), 16, fp_images);
  fread(buffer, sizeof(unsigned char), 8, fp_labels);
  for (int i = 0; i < 60000; i++) {
    fread(images[i], sizeof(unsigned char), IMAGE_SIZE, fp_images);
    fread(buffer, sizeof(unsigned char), 1, fp_labels);
    labels[i] = buffer[0];
  }
  fclose(fp_images);
  fclose(fp_labels);

  // Train a neural network on the MNIST dataset
  train_network(images, labels, 60000);

  // Free memory for the MNIST dataset
  for (int i = 0; i < 60000; i++) {
    free(images[i]);
  }
  free(images);
  free(labels);

  return 0;
}