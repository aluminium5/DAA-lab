#include <stdio.h>


void printArray(int arr[], int start, int end) {
    for (int i = start; i <= end; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];


    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }


    printf("Pass: ");
    printArray(arr, left, right);
}

void mergeSort(int arr[], int temp[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, temp, left, mid);
        mergeSort(arr, temp, mid + 1, right);
        merge(arr, temp, left, mid, right);
    }
}

int main() {
    int n, i;
    printf("no of elements: ");
    scanf("%d", &n);

    int arr[n], temp[n];
    printf("elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Given array:\n");
    printArray(arr, 0, n - 1);

    mergeSort(arr, temp, 0, n - 1);

    printf("Sorted array:\n");
    printArray(arr, 0, n - 1);

    return 0;
}