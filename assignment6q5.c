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
