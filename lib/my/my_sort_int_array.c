/*
** EPITECH PROJECT, 2024
** my_sort_int_array.c
** File description:
** my_sort_int_array.c
*/

static void aux_function_sort_int_array(int *array, int *min, int j)
{
    if (array[*min] > array[j]) {
        *min = j;
    }
}

void my_sort_int_array(int *array, int size)
{
    int min;
    int temp;

    for (int i = 0; i < size; i++) {
        min = i;
        for (int j = i; j < size; j++) {
            aux_function_sort_int_array(array, &min, j);
        }
        temp = array[min];
        array[min] = array[i];
        array[i] = temp;
    }
}
