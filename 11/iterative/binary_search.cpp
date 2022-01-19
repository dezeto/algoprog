#include <stdio.h>

int binary_search(int arr[], int search_value, int left, int right)
{
    while (left <= right)
    {
        // mencegah overflow dari integer
        int mid = left + ((right - left) / 2);

        if (search_value == arr[mid])
            return mid;
        else if (search_value < arr[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return 0;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 12};

    int size = (sizeof(arr) / sizeof(arr[0])) - 1;
    printf("%d\n", binary_search(arr, 12, 0, size));
    return 0;
}