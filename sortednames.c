#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
    char name[50];
    struct node* next;
} Node;

Node* head = NULL;

Node* createNode() {
    Node* new = (Node*)malloc(sizeof(Node));
    return new;
}

void insert(char* Name) {
    Node* new = createNode();
    strcpy(new->name, Name);
    new->next = NULL;

    if (head == NULL || strcmp(Name, head->name) < 0) {
        new->next = head;
        head = new;
    }
    else {
        Node* current = head;
        while (current->next != NULL && strcmp(Name, current->next->name) > 0) {
            current = current->next;
        }
        new->next = current->next;
        current->next = new;
    }
}

void deletee() {
    printf("\nEnter the name to be deleted: ");
    char del[50];
    scanf("%s", del);
    
    Node* current = head;
    Node* prev = NULL;
    while (current != NULL && strcmp(del, current->name) != 0) {
        prev = current;
        current = current->next;
    }
    
    if (current == NULL) {
        printf("\nElement not found!");
    }
    else {
        if (prev == NULL) {
            head = current->next;
        }
        else {
            prev->next = current->next;
        }
        free(current);
        printf("\nName deleted successfully!");
    }
}

void display() {
    if (head == NULL) {
        printf("\nThe list is empty.\n");
    }
    else {
        printf("\nNames in sorted list are:\n");
        Node* ptr = head;
        while (ptr != NULL) {
            printf("%s\n", ptr->name);
            ptr = ptr->next;
        }
    }
}

int main() {
    int ch;
    char temp[50];
    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\nEnter name to add: ");
                scanf("%s", temp);
                insert(temp);
                break;
            case 2:
                deletee();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}
