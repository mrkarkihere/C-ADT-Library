// queue.h

#ifndef QUEUE_H
#define QUEUE_H

// Queue structure
typedef struct Queue {
    Node* front; // front of the queue
    Node* rear; // end of the queue
    int size;   // size of the Queue (number of nodes)
} Queue;

// Function that creates a new empty Queue
Queue* create();

// Function to enqueue an element into the Queue; basically adding a new node; return true if successful, otherwise false
_Bool enqueue(Queue* queue, void* data);

// Function to dequeue an element from the Queue; essentially remove the front and return its value
void* dequeue(Queue* queue);

// Function to return the data stored at the front node
void* peek(Node* front);

// Function to check if the Queue is empty or not
_Bool isEmpty(Queue* queue);

// Function to clear the entire Queue, deallocating memory and resetting queue to empty state
void clear(Queue* queue);

// Function that returns the length of the Queue
int getSize(Queue* queue);

#endif // QUEUE_H