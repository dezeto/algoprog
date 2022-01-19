#include <stdio.h>

void merge(int arr[], int left, int middle, int right)
{
    int tempArray[right - left];

    int leftIndex = left, rightIndex = middle + 1, tempIndex = 0;
    int leftLimit = middle;
    int rightLimit = right;

    // sorting
    while (leftIndex <= leftLimit && rightIndex <= rightLimit)
    {
        if (arr[leftIndex] < arr[rightIndex])
        {
            tempArray[tempIndex] = arr[leftIndex];
            ++leftIndex;
            ++tempIndex;
        }
        else
        {
            tempArray[tempIndex] = arr[rightIndex];
            ++rightIndex;
            ++tempIndex;
        }
    }

    // copy sisa dari kiri dan kanan
    while (leftIndex <= leftLimit)
    {
        tempArray[tempIndex] = arr[leftIndex];
        ++leftIndex;
        ++tempIndex;
    }

    while (rightIndex <= rightLimit)
    {
        tempArray[tempIndex] = arr[rightIndex];
        ++rightIndex;
        ++tempIndex;
    }

    // pindahkan tempArray ke dalam arrayUtama
    tempIndex = 0;
    for (int i = left; i <= right; ++i)
    {
        arr[i] = tempArray[tempIndex];
        ++tempIndex;
    }
}

void merge_sort(int arr[], int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;

        // divide
        merge_sort(arr, left, middle);
        merge_sort(arr, middle + 1, right);

        // conquer
        merge(arr, left, middle, right);
    }
}

void print_array(int arr[], int size)
{
    int i = 0;
    for (i = 0; i < size; ++i)
    {
        if (i != size - 1)
            printf("%d ", arr[i]);
        else
            printf("%d\n", arr[i]);
    }
}

int main()
{
    int arr[] = {2, 8, 5, 3, 9, 4, 1, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    merge_sort(arr, 0, size - 1);
    print_array(arr, size);
    return 0;
}