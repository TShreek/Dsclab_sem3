#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* lchild;
    struct node* rchild;
};
struct node* root = NULL;

struct node* create(int n) {
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = n;
    new->lchild = NULL;
    new->rchild = NULL;
    return new;
}

struct node* insert(struct node* ptr, int n) {
    if (ptr == NULL)
        return create(n);
    if (n > ptr->data)
        ptr->rchild = insert(ptr->rchild, n);
    else if (n < ptr->data)
        ptr->lchild = insert(ptr->lchild, n);
    else
        printf("\n Element already present!");
    return ptr;
}

void preorder(struct node* ptr) {
    if (ptr != NULL) {
        printf("\n %d", ptr->data);
        preorder(ptr->lchild);
        preorder(ptr->rchild);
    }
}

void inorder(struct node* ptr) {
    if (ptr != NULL) {
        inorder(ptr->lchild);
        printf("\n %d", ptr->data);
        inorder(ptr->rchild);
    }
}

void postorder(struct node* ptr) {
    if (ptr != NULL) {
        postorder(ptr->lchild);
        postorder(ptr->rchild);
        printf("\n %d", ptr->data);
    }
}

int main() {
    while (1) {
        printf("\n Enter valid choice: \n1.Insert\n2.Inorder\n3.Preorder\n");
        printf("4.Postorder\n5.Exit\n");
        int ch, n;
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            printf("\n Enter number to be inserted : ");
            scanf("%d", &n);
            root = insert(root, n);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            preorder(root);
            break;
        case 4:
            postorder(root);
            break;
        case 5:
            exit(0);
        default:
            printf("\n Enter a proper input!");
        }
    }
    return 0;
}
