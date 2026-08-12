#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int medianOfThree(int arr[], int low, int high)
{
    int mid = low + (high - low) / 2;

    if (arr[low] > arr[mid]) {
        swap(&arr[low], &arr[mid]);
    }

    if (arr[low] > arr[high]) {
        swap(&arr[low], &arr[high]);
    }

    if (arr[mid] > arr[high]) {
        swap(&arr[mid], &arr[high]);
    }

    swap(&arr[mid], &arr[high - 1]);

    return arr[high - 1];
}

int partition(int arr[], int low, int high)
{
    int pivot = medianOfThree(arr, low, high);

    int i = low;
    int j = high - 1;

    while (1) {

        while (arr[++i] < pivot);

        while (arr[--j] > pivot);

        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
        else {
            break;
        }
    }

    swap(&arr[i], &arr[high - 1]);

    return i;
}

void quickSort(int arr[], int low, int high)
{
    if (low + 1 >= high) {

        if (low < high && arr[low] > arr[high]) {
            swap(&arr[low], &arr[high]);
        }

        return;
    }

    int pivotIdx = partition(arr, low, high);

    quickSort(arr, low, pivotIdx - 1);
    quickSort(arr, pivotIdx + 1, high);
}

int main()
{
    int n;

    printf("Enter no of elements: ");
    scanf("%d", &n);

    int a[10];

    printf("Enter elements: ");

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Array: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    quickSort(a, 0, n - 1);

    printf("\nSorted array:\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
