//
// Created by geek on 2019/12/12.
//

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;

    struct node *leftChild;
    struct node *rightChild;
};

struct node *root = NULL;

void insert(int data) {
    struct node *tempNode = (struct node *) malloc(sizeof(struct node));
    struct node *current;
    struct node *parent;

    tempNode->data = data;
    tempNode->leftChild = NULL;
    tempNode->rightChild = NULL;

    //if tree is empty
    if (root == NULL) {
        root = tempNode;
    } else {
        current = root;
        parent = NULL;

        while (1) {
            parent = current;

            //go to left of the tree
            if (data < parent->data) {
                current = current->leftChild;
            }

            //insert to the left
            if (current == NULL) {
                parent->leftChild = tempNode;
                return;
            }// go to right of the tree
            else {
                current = current->rightChild;

                if (current == NULL) {
                    parent->rightChild = tempNode;
                    return;
                }
            }
        }
    }
}


struct node *search(int data) {
    struct node *current = root;
    printf("Visiting elements: ");

    while (current->data != data) {
        if (current != NULL)
            printf("%d", current->data);

        //go to left tree
        if (current->data > data) {
            current = current->leftChild;
        }
            //else go to right tree
        else {
            current = current->rightChild;
        }

        //not found
        if (current == NULL) {
            return NULL;
        }
    }
    return current;
}

void pre_order_traversal(struct node *root) {
    if (root != NULL) {
        printf("%d", root->data);
        pre_order_traversal(root->leftChild);
        pre_order_traversal(root->rightChild);
    }
}

void inorder_traversal(struct node *root) {
    if (root != NULL) {
        inorder_traversal(root->leftChild);
        printf("%d", root->data);
        inorder_traversal(root->rightChild);
    }
}

void post_order_traversal(struct node *root) {
    if (root != NULL) {
        post_order_traversal(root->leftChild);
        post_order_traversal(root->rightChild);
        printf("%d ", root->data);
    }
}

int GetDepth(struct node *root)
{
    if (root == NULL)
        return 0;
    int left_depth = GetDepth(root->leftChild) + 1;
    int right_depth = GetDepth(root->rightChild) + 1;
    return left_depth > right_depth ? left_depth : right_depth;
}


int GetKLevel(struct node *root, int k)
{
    if (root == NULL || k < 1)
        return 0;
    if (k == 1)
        return 1;
    return GetKLevel(root->leftChild, k - 1) + GetKLevel(root->rightChild, k - 1);
}



int main() {
    int i;
    int array[7] = {27, 233, 2323, 323, 121, 1212, 23};
    for (i = 0; i < 7; i++) {
        insert(array[i]);
    }

    i = 31;
    struct node *temp = search(i);

    if (temp != NULL) {
        printf("[%d] element found", temp->data);
        printf("\n");
    } else {
        printf("[x] Element not found (%d).\n", i);
    }

    i = 15;
    temp = search(i);

    if (temp != NULL) {
        printf("[%d] Element Found ", temp->data);
        printf("\n");

    } else {
        printf("[ x ] Element not found (%d).\n", i);
    }

    printf("\nPreorder traversal: ");
    pre_order_traversal(root);

    printf("\nInorder traversal: ");
    inorder_traversal(root);

    printf("\nPost order traversal: ");
    post_order_traversal(root);

    printf("\nDepth of Tree: %d", GetDepth(root));


    printf("\nKLevel of Tree: %d",GetKLevel(root, 2));


    return 0;
}