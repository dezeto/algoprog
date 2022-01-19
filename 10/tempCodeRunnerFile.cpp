50, 70, 40, 80, 60};
    int size = sizeof(arr) / sizeof(arr[0]);

    quick_sort(arr, 0, size - 1);
    printArray(arr, size);