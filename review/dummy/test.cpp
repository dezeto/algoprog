#include <stdio.h>
#include <string.h>
#define FILE_NAME "students.txt"

typedef struct Address
{
    char city[30];
    char road_name[30];
    char country[30];
} Add;

typedef struct Student
{
    char name[255];
    int age;
    // struct Address address;
} Stu;

void merge(Stu arr[], int left, int middle, int right)
{
    Stu tempArray[right - left + 1];
    int leftIndex = left, rightIndex = middle + 1, tempIndex = 0;
    int leftLimit = middle, rightLimit = right;

    // sorting
    while (leftIndex <= leftLimit && rightIndex <= rightLimit)
    {
        // if (strcmp(arr[leftIndex].name, arr[rightIndex].name) < 0)
        if (arr[leftIndex].age < arr[rightIndex].age)
        {
            tempArray[tempIndex].age = arr[leftIndex].age;
            strcpy(tempArray[tempIndex].name, arr[leftIndex].name);
            // tempArray[tempIndex] = arr[leftIndex];
            ++leftIndex;
            ++tempIndex;
        }
        else
        {
            // tempArray[tempIndex] = arr[rightIndex];
            tempArray[tempIndex].age = arr[rightIndex].age;
            strcpy(tempArray[tempIndex].name, arr[rightIndex].name);
            ++rightIndex;
            ++tempIndex;
        }
    }

    // ambil sisa
    while (leftIndex <= leftLimit)
    {
        // tempArray[tempIndex] = arr[leftIndex];
        tempArray[tempIndex].age = arr[leftIndex].age;
        strcpy(tempArray[tempIndex].name, arr[leftIndex].name);
        ++leftIndex;
        ++tempIndex;
    }

    while (rightIndex <= rightLimit)
    {
        // tempArray[tempIndex] = arr[rightIndex];
        tempArray[tempIndex].age = arr[rightIndex].age;
        strcpy(tempArray[tempIndex].name, arr[rightIndex].name);
        ++rightIndex;
        ++tempIndex;
    }

    // gabung temp_array ke array utama
    tempIndex = 0;
    for (int i = left; i <= right; ++i)
    {
        // arr[i] = tempArray[tempIndex];
        arr[i].age = tempArray[tempIndex].age;
        strcpy(arr[i].name, tempArray[tempIndex].name);
        ++tempIndex;
    }
}

void merge_sort(Stu arr[], int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;
        merge_sort(arr, left, middle);
        merge_sort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

void write(Stu data[], int size)
{
    // open
    FILE *f = fopen(FILE_NAME, "w");

    // logic
    for (int i = 0; i < size; ++i)
    {
        // fprintf(f, "%s#%d#%s-%s-%s\n", data[i].name, data[i].age, data[i].address.city, data[i].address.road_name, data[i].address.country);
        // fprintf(f, "%s#%d#%s-%s-%s\n", data[i].name, data[i].age, data[i].address.city, data[i].address.road_name, data[i].address.country);
    }

    // close
    fclose(f);
}

int read(Student students[101])
{
    // open
    FILE *f = fopen(FILE_NAME, "r");

    if (f == NULL)
    {
        printf("file not found !\n");
        return 0;
    }

    int idx = 0;
    while (!feof(f))
    {
        fscanf(f, "%[^#]#%d\n", students[idx].name, &students[idx].age);
        // fscanf(f, "%[^#]#%d\n", students[idx].name, &students[idx].age);
        ++idx;
    }

    // close
    fclose(f);
    return idx;
}

void print_students(Student students[101], int size)
{
    // int size = sizeof(students) / sizeof(students[0]);
    for (int i = 0; i < size; ++i)
    {
        printf("Students #%d\n", i + 1);
        printf("------------\n");
        printf("Name : %s\n", students[i].name);
        printf("Age : %d\n", students[i].age);
        // printf("Address : %s, %s, %s\n", students[i].address.road_name, students[i].address.city, students[i].address.country);
        printf("\n");
    }
}

int main()
{
    // Stu students_temp[] = {
    //     {
    //         "adrian",
    //         20,
    //         {
    //             "Jakarta",
    //             "Jl. Melati No.1",
    //             "Indonesia",
    //         },
    //     },
    //     {
    //         "somi",
    //         21,
    //         {
    //             "Medan",
    //             "Jl. Anggrek No.123",
    //             "Indonesia",
    //         },
    //     },
    //     {
    //         "vercherla",
    //         21,
    //         {
    //             "Kuala Lumpur",
    //             "Jl. Pisang No.12",
    //             "Malaysia",
    //         },
    //     },
    // };
    // char nama[][101] = {"Pisang Goreng", "Mie Goreng", "Lumpia"};
    // int price[] = {10000, 20000, 30000};

    // write(students_temp, 3);
    Stu students[101] = {};
    int size = read(students);
    // print_students(students, size);
    merge_sort(students, 0, size - 1);
    print_students(students, size);
    // append(nama, price, size);

    return 0;
}