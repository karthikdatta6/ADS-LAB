#include <stdio.h>

void init(int a[], int n)
{
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void print(int a[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int insert(int a[], int n, int pos, int ele)
{
    for(int i = n; i > pos; i--)
        a[i] = a[i - 1];

    a[pos] = ele;
    n++;

    print(a, n);
    return n;
}

int delete(int a[], int n, int pos)
{
    for(int i = pos; i < n - 1; i++)
        a[i] = a[i + 1];

    n--;

    print(a, n);
    return n;
}

int lsearch(int a[], int n, int key)
{
    for(int i = 0; i < n; i++)
    {
        if(a[i] == key)
            return i;
    }
    return -1;
}

int main()
{
    int a[10], n = 0;

    while(1)
    {
        printf("\n1.Array Initialization\n");
        printf("2.Print Elements\n");
        printf("3.Insert Element\n");
        printf("4.Delete Element\n");
        printf("5.Linear Search\n");
        printf("6.Exit\n");

        int ch;
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("Enter n: ");
                scanf("%d", &n);

                printf("Enter elements:\n");
                init(a, n);
                break;

            case 2:
                print(a, n);
                break;

            case 3:
            {
                int pos, ele;
                printf("Enter position: ");
                scanf("%d", &pos);

                printf("Enter element: ");
                scanf("%d", &ele);

                n = insert(a, n, pos, ele);
                break;
            }

            case 4:
            {
                int pos;
                printf("Enter position: ");
                scanf("%d", &pos);

                n = delete(a, n, pos);
                break;
            }

            case 5:
            {
                int key;
                printf("Enter element to search: ");
                scanf("%d", &key);

                int p = lsearch(a, n, key);

                if(p == -1)
                    printf("Element not found\n");
                else
                    printf("Element found at index %d\n", p);

                break;
            }

            case 6:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
