#include <stdio.h>
#include <cstdlib>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot -> value terakhir
    int i = low - 1;
    int j;

    for (j = low; j < high; ++j)
    {
        if (arr[j] < pivot)
        {
            ++i;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

int partition_random(int arr[], int low, int high)
{
    srand(time(NULL));
    int random = low + rand() % (high - low);

    swap(&arr[random], &arr[high]);

    return partition(arr, low, high);
}

void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition_random(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
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
    int arr[] = {30, 90, 20, 10, 50, 70, 40, 80, 60};
    int size = sizeof(arr) / sizeof(arr[0]);

    quick_sort(arr, 0, size - 1);
    print_array(arr, size);

    return 0;
}