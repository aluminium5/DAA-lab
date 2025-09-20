#include <stdio.h>
void printSubarray(int arr[], int low, int high) {
    for (int i = low; i <= high; i++) {
        printf("%d", arr[i]);
        if (i < high) printf(" ");
    }
    printf(" \n");
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
	}
    int tmp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = tmp;
    return i + 1;
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        printf("Pass: ");
        printSubarray(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main() {
    int n;
    printf("number of elements: ");
    if (scanf("%d", &n) != 1) return 0;
    int arr[n];
    printf("elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
	}
    printf("Original array: ");
    printSubarray(arr, 0, n - 1);
    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    printSubarray(arr, 0, n - 1);

    return 0;
}