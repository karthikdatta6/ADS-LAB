#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *create(int data) {
    struct node *nn = (struct node *)malloc(sizeof(struct node));
    nn->data = data;
    nn->next = NULL;
    return nn;
}

struct node *initialise(struct node *head) {
    int n, data;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        struct node *new = create(data);

        if (head == NULL) {
            head = new;
        } else {
            struct node *temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = new;
        }
    }
    return head;
}

void display(struct node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int countn(struct node *head) {
    int count = 0;

    while (head != NULL) {
        count++;
        head = head->next;
    }

    return count;
}

struct node *insertAtBeginning(struct node *head) {
    int val;

    printf("Enter value: ");
    scanf("%d", &val);

    struct node *new = create(val);

    new->next = head;
    head = new;

    return head;
}

struct node *insertAtEnd(struct node *head) {
    int val;

    printf("Enter value: ");
    scanf("%d", &val);

    struct node *new = create(val);

    if (head == NULL)
        return new;

    struct node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = new;

    return head;
}

struct node *insertAtPos(struct node *head) {
    int pos, val;

    printf("Enter position: ");
    scanf("%d", &pos);

    printf("Enter value: ");
    scanf("%d", &val);

    int n = countn(head);

    if (pos < 0 || pos > n) {
        printf("Invalid position!\n");
        return head;
    }

    struct node *new = create(val);

    if (pos == 0) {
        new->next = head;
        return new;
    }

    struct node *temp = head;

    for (int i = 0; i < pos - 1; i++)
        temp = temp->next;

    new->next = temp->next;
    temp->next = new;

    return head;
}

struct node *deleteAtBegin(struct node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }

    struct node *temp = head;
    head = head->next;
    free(temp);

    return head;
}

struct node *deleteAtEnd(struct node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct node *temp = head;

    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;

    return head;
}

struct node *deleteAtPos(struct node *head) {
    int pos;

    if (head == NULL) {
        printf("List is empty.\n");
        return head;
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    int n = countn(head);

    if (pos < 0 || pos >= n) {
        printf("Invalid position!\n");
        return head;
    }

    if (pos == 0)
        return deleteAtBegin(head);

    struct node *temp = head;

    for (int i = 0; i < pos - 1; i++)
        temp = temp->next;

    struct node *del = temp->next;
    temp->next = del->next;
    free(del);

    return head;
}

void search(struct node *head) {
    int key, pos = 0;

    printf("Enter key: ");
    scanf("%d", &key);

    struct node *temp = head;

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Key found at position %d\n", pos);
            return;
        }

        temp = temp->next;
        pos++;
    }

    printf("Key not found.\n");
}

int main() {
    struct node *head = NULL;
    int choice;

    while (1) {
        printf("\n1.Initialise\n");
        printf("2.Display\n");
        printf("3.Insert at Beginning\n");
        printf("4.Insert at End\n");
        printf("5.Insert at Position\n");
        printf("6.Delete at Beginning\n");
        printf("7.Delete at End\n");
        printf("8.Delete at Position\n");
        printf("9.Search\n");
        printf("10.Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = initialise(head);
                break;
            case 2:
                display(head);
                break;
            case 3:
                head = insertAtBeginning(head);
                break;
            case 4:
                head = insertAtEnd(head);
                break;
            case 5:
                head = insertAtPos(head);
                break;
            case 6:
                head = deleteAtBegin(head);
                break;
            case 7:
                head = deleteAtEnd(head);
                break;
            case 8:
                head = deleteAtPos(head);
                break;
            case 9:
                search(head);
                break;
            case 10:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
