#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* create(int val) {
    struct node* nn = (struct node*)malloc(sizeof(struct node));

    nn->data = val;
    nn->left = NULL;
    nn->right = NULL;

    return nn;
}

struct node* insert(struct node* root, int val) {

    if (root == NULL) {
        return create(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    }

    else if (val > root->data) {
        root->right = insert(root->right, val);
    }

    return root;
}

struct node* minnode(struct node* root) {

    while (root->left != NULL) {
        root = root->left;
    }

    return root;
}

struct node* del(struct node* root, int val) {

    if (root == NULL) {
        return NULL;
    }

    if (val < root->data) {
        root->left = del(root->left, val);
    }

    else if (val > root->data) {
        root->right = del(root->right, val);
    }

    else {

        if (root->left == NULL) {
            struct node* t = root->right;
            free(root);
            return t;
        }

        if (root->right == NULL) {
            struct node* t = root->left;
            free(root);
            return t;
        }

        struct node* t = minnode(root->right);

        root->data = t->data;

        root->right = del(root->right, t->data);
    }

    return root;
}

struct node* search(struct node* root, int val) {

    if (root == NULL || root->data == val) {
        return root;
    }

    if (val > root->data) {
        return search(root->right, val);
    }

    return search(root->left, val);
}




void inorder(struct node* root) {

    if (root != NULL) {

        inorder(root->left);

        printf("%d ", root->data);

        inorder(root->right);
    }
}




void preorder(struct node* root) {

    if (root != NULL) {

        printf("%d ", root->data);

        preorder(root->left);

        preorder(root->right);
    }
}



void postorder(struct node* root) {

    if (root != NULL) {

        postorder(root->left);

        postorder(root->right);

        printf("%d ", root->data);
    }
}


int main() {

    struct node* root = NULL;

    int choice;
    int val;

    while (1) {

        

        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Inorder\n");
        printf("5. Preorder\n");
        printf("6. Postorder\n");
        printf("7. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:

                printf("Enter value: ");
                scanf("%d", &val);

                root = insert(root, val);

                break;


            case 2:

                printf("Enter value to delete: ");
                scanf("%d", &val);

                root = del(root, val);

                break;


            case 3:

                printf("Enter value to search: ");
                scanf("%d", &val);

                if (search(root, val) != NULL)
                    printf("Element found");
                else
                    printf("Element not found");

                break;


            case 4:

                printf("Inorder: ");

                inorder(root);

                break;


            case 5:

                printf("Preorder: ");

                preorder(root);

                break;


            case 6:

                printf("Postorder: ");

                postorder(root);

                break;


            case 7:

                exit(0);


            default:

                printf("Invalid choice");
        }
    }

    return 0;
	
}
