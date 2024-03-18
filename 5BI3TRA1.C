#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define p printf
#define s scanf

int i;
struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(char value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, char value) {
    if (root == NULL) {
	return createNode(value);
    }

    if (value < root->data) {
	root->left = insert(root->left, value);
    } else if (value > root->data) {
	root->right = insert(root->right, value);
    }

    return root;
}

void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
	inOrderTraversal(root->left);
	p("%c ", root->data);
	inOrderTraversal(root->right);
    }
}

void preOrderTraversal(struct Node* root) {
    if (root != NULL) {
	p("%c ", root->data);
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
    }
}

void postOrderTraversal(struct Node* root) {
    if (root != NULL) {
	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	p("%c ", root->data);
    }
}

void displayTree(struct Node* root, const char* traversalType) {
    p("\n%s of the binary tree: ", traversalType);
    if (strcmp(traversalType, "Inorder LTR") == 0) {
	inOrderTraversal(root);
    } else if (strcmp(traversalType, "Preorder TLR") == 0) {
	preOrderTraversal(root);
    } else if (strcmp(traversalType, "Postorder LRT") == 0) {
	postOrderTraversal(root);
    }
    p("\n");
}

void displayTreeStructure(struct Node* root, int space) {
    if (root == NULL)
	return;

    space += 5;

    displayTreeStructure(root->right, space);

    p("\n");
    for (i = 5; i < space; i++)
	p(" ");
    p("%c\n", root->data);

    displayTreeStructure(root->left, space);
}

int main() {
    struct Node* root = NULL;

    clrscr();

    // Insert some letters into the binary tree
    root = insert(root, 'E');
    insert(root, 'C');  //left child of e
    insert(root, 'G');  //right child of e
    insert(root, 'B');  //left child of c
    insert(root, 'D');  //right child of c
    insert(root, 'F');  //left child of g
    insert(root, 'H');  //right child of g

    // Display the binary tree structure
    p("Binary Tree Structure:\n");
    displayTreeStructure(root, 0);

    // Display the binary tree using different traversals
    displayTree(root, "Inorder LTR");
    displayTree(root, "Preorder TLR");
    displayTree(root, "Postorder LRT");

    getch();
    return 0;
}