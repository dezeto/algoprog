#include <stdio.h>

bool binary_search(int arr[], int searchValue, int left, int right)
{
    if (left > right)
        return false;

    int middle = left + (right - left) / 2;
    if (arr[middle] == searchValue)
        return true;
    else if (arr[middle] < searchValue)
        return binary_search(arr, searchValue, middle + 1, right);
    else
        return binary_search(arr, searchValue, left, middle - 1);
}

int main()
{
    int arr[] = {1, 2, 4, 5, 6, 7, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", binary_search(arr, 12, 0, size - 1));
    return 0;
}