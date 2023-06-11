// linkedlist.h

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// LinkedList structure
typedef struct LinkedList {
    Node* head; // head of the LinkedList
    int size;   // size of the LinkedList (number of nodes)
} LinkedList;

// Function that creates a new empty LinkedList
LinkedList* create();

// Function to insert a new node in the LinkedList at the tail, append
void insert(LinkedList* list, void* data);

// Function to insert a new node in the LinkedList at an index assigned data
void insertAt(LinkedList* list, int index, void* data);

// Function to delete a node in the LinkedList at the tail, pop
void delete(LinkedList* list);

// Function to delete a node in the LinkedList at an index
void deleteAt(LinkedList* list, int index);

// Function to update the value at a given index node
void update(LinkedList* list, int index, void* data);

// Function to search for a value in the LinkedList
Node* search(LinkedList* list, void* value);

// Function to retrieve data at a certain index in the LinkedList
void* getValue(LinkedList* list, int index);

// Function that will traverse the LinkedList at an index and return the Node associated
Node* getNode(LinkedList* list, int index);

// Function that returns the length of the LinkedList
int getSize(LinkedList* list);

// Function to check if the LinkedList is empty or not
_Bool isEmpty(LinkedList* list);

// Function to clear the entire LinkedList, deallocating memory and resetting list to empty state
void clear(LinkedList* list);

// Function to print the LinkedList in the format 1 -> 2 -> 3 -> etc...
// NOTE: this is a testing function and only supports integer data types
void printLinkedList(LinkedList* list);

#endif // LINKEDLIST_H
