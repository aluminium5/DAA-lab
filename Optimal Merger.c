#include <stdio.h>
#include <stdlib.h>
void sort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
int optimalMerge(int files[], int n) {
	int cost = 0;
while (n > 1) {
		sort(files, n);
		int merged = files[0] + files[1];
		cost += merged;
		files[0] = merged;
		for (int i = 1; i < n - 1; i++) {
			files[i] = files[i + 1];
		}
		n--;
	}
	return cost;
}

int main() {
	int n;
	printf("Number of files: ");
	scanf("%d", &n);
	int *files = (int *)malloc(n * sizeof(int));
	printf("Enter the sizes of %d files: ", n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &files[i]);
	}
	int minCost = optimalMerge(files, n);
	printf("Minimum cost of merging is: %d\n", minCost);
	free(files);
	return 0;
}
