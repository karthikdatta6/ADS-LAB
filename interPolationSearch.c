#include <stdio.h>

int InterPolationSearch(int a[], int target, int low, int high) {

    int pos;

    while (low <= high && target >= a[low] && target <= a[high]) {

        if (a[high] == a[low]) {
            if (a[low] == target)
                return low;
            return -1;
        }

        pos = low + (target - a[low]) * (high - low)
                    / (a[high] - a[low]);

        if (target == a[pos]) {
            return pos;
        }
        else if (target < a[pos]) {
            high = pos - 1;
        }
        else {
            low = pos + 1;
        }
    }

    return -1;
}

int main() {

    int n;

    printf("Enter no of elements: ");
    scanf("%d", &n);

    int a[10];

    printf("Enter elements in sorted order: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    int low, high;
    int target;

    printf("\nEnter low and high: ");
    scanf("%d %d", &low, &high);

    printf("Enter target element: ");
    scanf("%d", &target);

    int p = InterPolationSearch(a, target, low, high);

    if (p != -1){
	
        printf("Element found at index: %d\n", p);
    }
    else{
	    printf("Element not found\n");	
	}

    return 0;
}
