//Falcon2-11B DATASET v1.0 Category: Product Inventory System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    int id;
    char* name;
    int quantity;
} Product;

Product* products = NULL;
int productCount = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* addProduct(void* pParam) {
    Product* product = (Product*)pParam;
    int result = pthread_mutex_lock(&mutex);
    if (result) {
        printf("Failed to lock mutex\n");
        return NULL;
    }
    product->id = productCount;
    productCount++;
    products = realloc(products, sizeof(Product) * productCount);
    memcpy(&(products[productCount - 1]), product, sizeof(Product));
    result = pthread_mutex_unlock(&mutex);
    if (result) {
        printf("Failed to unlock mutex\n");
        return NULL;
    }
    return NULL;
}

void* removeProduct(void* pParam) {
    int result = pthread_mutex_lock(&mutex);
    if (result) {
        printf("Failed to lock mutex\n");
        return NULL;
    }
    int index = -1;
    for (int i = 0; i < productCount; i++) {
        if (products[i].id == pParam) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Product not found\n");
        return NULL;
    }
    for (int i = index; i < productCount - 1; i++) {
        products[i] = products[i + 1];
    }
    productCount--;
    result = pthread_mutex_unlock(&mutex);
    if (result) {
        printf("Failed to unlock mutex\n");
        return NULL;
    }
    return NULL;
}

void* updateQuantity(void* pParam) {
    int result = pthread_mutex_lock(&mutex);
    if (result) {
        printf("Failed to lock mutex\n");
        return NULL;
    }
    int index = -1;
    for (int i = 0; i < productCount; i++) {
        if (products[i].id == pParam) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Product not found\n");
        return NULL;
    }
    products[index].quantity = (int)pParam;
    result = pthread_mutex_unlock(&mutex);
    if (result) {
        printf("Failed to unlock mutex\n");
        return NULL;
    }
    return NULL;
}

void* updateName(void* pParam) {
    int result = pthread_mutex_lock(&mutex);
    if (result) {
        printf("Failed to lock mutex\n");
        return NULL;
    }
    int index = -1;
    for (int i = 0; i < productCount; i++) {
        if (products[i].id == pParam) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Product not found\n");
        return NULL;
    }
    strcpy(products[index].name, (char*)pParam);
    result = pthread_mutex_unlock(&mutex);
    if (result) {
        printf("Failed to unlock mutex\n");
        return NULL;
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2, thread3;

    Product product1 = {1, "Product 1", 10};
    Product product2 = {2, "Product 2", 20};
    Product product3 = {3, "Product 3", 30};

    pthread_create(&thread1, NULL, addProduct, &product1);
    pthread_create(&thread2, NULL, removeProduct, &product2);
    pthread_create(&thread3, NULL, updateQuantity, &product3);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    return 0;
}