#include<stdio.h>
#include<stdlib.h>

int binarySearch(int a[], int low, int high, int key)
{
    if (low <= high) {
        int mid = (low + high) / 2;
        if (a[mid] == key)
            return mid;
        if (a[mid] > key)
            return binarySearch(a, low, mid - 1, key);
        if (a[mid] < key)
            return binarySearch(a, mid + 1, high, key);
    }
    return -1;
}

int main()
{
    int array[6];
    printf("Enter elements of array: ");
    for (int i = 0; i < 6; i++)
        scanf("%d", &array[i]);
    printf("\nEnter the element to be searched: ");
    int k;
    scanf("%d", &k);
    int low = 0, high = 5;
    int result = binarySearch(array, low, high, k);
    if (result != -1)
        printf("\nElement found at index: %d", result);
    else
        printf("\nElement not found");
    return 0;
}
