// queue.c
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"

// node structure; static
typedef struct Node {
    void* data;
    struct Node* next;
} Node;

// Function that creates a new empty Queue
Queue* create(){
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    // make sure the memory is properly allocated and set the default structure.
    assert(queue != NULL); 

    // error
    if(queue == NULL){
        printf("Error: Failed to allocate memory for Queue");
        exit(EXIT_FAILURE);
    }
    // create and set front and rear pointer nodes; make sure properly allocated
    Node* front = (Node*) malloc(sizeof(Node));
    assert(front != NULL);

    // error
    if(front == NULL){
        printf("Error: Failed to allocate memory for Node");
        exit(EXIT_FAILURE);
    }

    queue->front = front;
    queue->rear = front;
    queue->size = 0;
    
    return queue;
}

// Function to enqueue an element into the Queue; return true if successful, otherwise false
_Bool enqueue(Queue* queue, void* data) {
    assert(queue != NULL);

    // allocate memory for the new node
    Node* node = (Node*)malloc(sizeof(Node));
    assert(node != NULL);

    // error
    if(node == NULL){
        printf("Error: Failed to allocate memory for Node");
        return 0;
    }

    node->data = data;
    node->next = NULL;

    // if the queue is empty
    if(isEmpty(queue)){
        queue->front = node;
        queue->rear = node;
    }
    // queue is populated
    else{
        // make the current front point to the new node rather than NULL
        queue->front->next = node;
        // update the Queue's new front pointer
        queue->front = node;
    }
    queue->size++;

    return 1; // successfully inserted the new element
}


// Function to dequeue an element from the Queue; essentially remove the front and return its value
void* dequeue(Queue* queue) {
    // make sure the queue exists
    assert(queue != NULL && queue->front != NULL);

    // error
    if(isEmpty(queue)){
        printf("Error: Queue is empty\n");
        return NULL;
    }

    // deallocate front node and return the data associated with the node
    Node* front = queue->front;
    void* data = front->data;
    queue->size--;

    queue->front = front->next;
    free(front);

    // if queue is empty, update rear to NULL as well
    if (isEmpty(queue)) {
        queue->rear = NULL;
    }

    return data;
}

// Function to clear the entire Queue, deallocating memory and resetting queue to empty state
void clear(Queue* queue){
    // make sure queue exists
    assert(queue != NULL && queue->front != NULL);

    // error
    if(isEmpty(queue) == 1){
        printf("Error: Queue is empty\n");
    }

    Node* curr = queue->front;
    // traverse each node and free the memory
    while(curr != NULL){
        Node* next = curr->next;
        free(curr);
        curr = next;
    }
    // reset size and free Queue structure
    queue->rear = NULL;
    queue->size = 0;
    free(queue);
}

// Function to return the data stored at the front node
void* peek(Node* front){
    assert(front != NULL);
    // error
    if(front == NULL){
        printf("Error: Queue is empty\n");
        return NULL;
    }
    return front->data;
}

// Function to check if the Queue is empty or not
_Bool isEmpty(Queue* queue){
    // make sure queue is allocated and check front node
    assert(queue != NULL);
    if(queue->front != NULL){
        return 0; // queue is NOT empty
    }
    return 1; // queue is empty
}

// Function that returns the length of the Queue
int getSize(Queue* queue){
    return queue->size;
}