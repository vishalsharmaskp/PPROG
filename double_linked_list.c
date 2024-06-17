#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the doubly linked list
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to append a node to the end of the list
void append(Node** head_ref, int data) {
    Node* newNode = createNode(data);
    Node* last = *head_ref;

    // If the linked list is empty
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }

    // Traverse to the last node
    while (last->next != NULL)
        last = last->next;

    // Change the next of the last node
    last->next = newNode;
    newNode->prev = last;
}


void deleteNode(Node** head_ref, int index) {
    if (*head_ref == NULL || index < 0) return;

    Node* temp = *head_ref;

    // Traverse to the node to be deleted
    for (int i = 0; temp != NULL && i < index; i++) {
        temp = temp->next;
    }

    // If the index is out of bounds
    if (temp == NULL) return;

    // If the node to be deleted is the head node
    if (*head_ref == temp) {
        *head_ref = temp->next;
    }

    // Change the next of the previous node, if it exists
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    // Change the prev of the next node, if it exists
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    // Free memory of the node to be deleted
    free(temp);
}

// Function to invert a doubly linked list
void invertList(Node** head_ref) {
    if (*head_ref == NULL) return;

    Node* current = *head_ref;
    Node* temp = NULL;

    // Traverse the list and swap the next and prev pointers of each node
    while (current != NULL) {
        // Swap the prev and next pointers
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to the previous node (since next and prev are swapped)
        current = current->prev;
    }

    // Adjust the head pointer to point to the new head
    if (temp != NULL) {
        *head_ref = temp->prev;
    }
}

// Function to print the linked list
void printList(Node* node) {
    Node* last;
    printf("Traversal in forward direction: \n");
    while (node != NULL) {
        printf("%d ", node->data);
        last = node;
        node = node->next;
    }
    printf("\nTraversal in reverse direction: \n");
    while (last != NULL) {
        printf("%d ", last->data);
        last = last->prev;
    }
    printf("\n");
}

Node* copyList(Node* head) {
    if (head == NULL) return NULL;

    // Create the head of the new list
    Node* newHead = createNode(head->data);
    Node* current = head->next;
    Node* newCurrent = newHead;

    // Traverse the original list and copy each node
    while (current != NULL) {
        // Create a new node
        Node* newNode = createNode(current->data);

        // Link the new node to the new list
        newCurrent->next = newNode;
        newNode->prev = newCurrent;

        // Move to the next node
        newCurrent = newNode;
        current = current->next;
    }
    return newHead;
}

// Main function to test the above functions
int main() {
    Node* head = NULL;

    append(&head, 6);
    append(&head, 7);
    append(&head, 1);
    append(&head, 4);

    printf("Original DLL is: \n");
    printList(head);

    printf("\nDeleting node at index 2\n");
    deleteNode(&head, 2);
    printf("DLL after deletion is: \n");
    printList(head);

    invertList(&head);
    printf("\nInverted DLL is: \n");
    printList(head);
    return 0;
}

