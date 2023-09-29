/*BELLAM RAHUL*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAscending(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL || (*head)->data >= newNode->data) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL && current->next->data < newNode->data) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void display(struct Node* head) {
    struct Node* current = head;

    printf("Ascending Order: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    printf("Descending Order: ");
    while (head != NULL) {
        struct Node* max = head;
        current = head;

        while (current != NULL) {
            if (current->data > max->data) {
                max = current;
            }
            current = current->next;
        }

        printf("%d ", max->data);
        if (max == head) {
            head = head->next;
        } else {
            struct Node* prev = head;
            while (prev->next != max) {
                prev = prev->next;
            }
            prev->next = max->next;
        }
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        int data = rand() % 100; 
        insertAscending(&head, data);
    }
    display(head);

    return 0;
}

/// question 5.2
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void deleteEnd(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = *head;    
    
    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        
        *head = NULL;
    }

    free(temp);
    printf("Node deleted from the end successfully.\n");
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d <-> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
    
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    
    head->data = 1;
    head->prev = NULL;
    head->next = second;
    
    second->data = 2;
    second->prev = head;
    second->next = third;
    
    third->data = 3;
    third->prev = second;
    third->next = NULL;
    
    printf("Original Doubly Linked List: ");
    printList(head);
    

    deleteEnd(&head);
    
    printf("Doubly Linked List after deleting node from the end: ");
    printList(head);
    
    return 0;
}


// question 5.3

#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void deleteNode(struct Node** head, struct Node* nodeToDelete) {
    if (*head == NULL || nodeToDelete == NULL) {
        return;
    }

    if (*head == nodeToDelete) {
        *head = nodeToDelete->next;
    }

    if (nodeToDelete->next != NULL) {
        nodeToDelete->next->prev = nodeToDelete->prev;
    }

    if (nodeToDelete->prev != NULL) {
        nodeToDelete->prev->next = nodeToDelete->next;
    }

    // Free the memory occupied by the node
    free(nodeToDelete);
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d <-> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->prev = head;
    head->next->next = createNode(3);
    head->next->next->prev = head->next;
    head->next->next->next = createNode(4);
    head->next->next->next->prev = head->next->next;

    printf("Original Doubly Linked List: ");
    printList(head);

    struct Node* nodeToDelete = head->next->next; 
    deleteNode(&head, nodeToDelete);

    printf("Doubly Linked List after deleting node with value 3: ");
    printList(head);

    return 0;
}
