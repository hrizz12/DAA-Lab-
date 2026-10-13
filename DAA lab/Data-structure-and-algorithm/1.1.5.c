#include <stdio.h>
//25070521051
//Hrishikesh dapurkar
static void findSubsets(int arr[], int n, int start, int currentSum, int target, int chosen[], int chosenSize) {
    if (currentSum == target) {
        printf("Subset found: ");
        for (int i = 0; i < chosenSize; i++)
            printf("%d ", chosen[i]);
        printf("\n");
        return;
    }

    if (start >= n || currentSum > target)
        return;

    chosen[chosenSize] = arr[start];
    findSubsets(arr, n, start + 1, currentSum + arr[start], target, chosen, chosenSize + 1);
    findSubsets(arr, n, start + 1, currentSum, target, chosen, chosenSize);
}

int main(void) {
    int n, target;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter target sum: ");
    scanf("%d", &target);

    int arr[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int chosen[n];
    printf("Subsets with sum %d:\n", target);
    findSubsets(arr, n, 0, 0, target, chosen, 0);

    return 0;
}
