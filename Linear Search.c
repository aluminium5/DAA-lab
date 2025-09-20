#include <stdio.h>

// Function to read elements into the array
void read1(int arr[], int n) {
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

// Recursive linear search function
int linearSearch(int arr[], int low, int high, int key) {
    if (low > high) {
        return -1;
    }
    if (arr[low] == key) {
        return low;
    }
    return linearSearch(arr, low + 1, high, key);
}

int main() {
    int a[20], n, pos, key;

    printf("Enter n value: ");
    scanf("%d", &n);

    read1(a, n);

    printf("Enter a key element: ");
    scanf("%d", &key);

    pos = linearSearch(a, 0, n - 1, key);

    if (pos == -1) {
        printf("The key element %d is not found\n", key);
    } else {
        printf("The key element %d is found at position: %d\n", key, pos);
    }

    return 0;
}
