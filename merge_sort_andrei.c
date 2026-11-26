// Radulescu Andrei

#include <stdio.h>

#define MAX_LEN 100

static void merge(int array[], int left, int mid, int right)
{
    int temp[MAX_LEN];
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (array[i] <= array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }

    while (i <= mid)
        temp[k++] = array[i++];

    while (j <= right)
        temp[k++] = array[j++];

    for (i = 0; i < k; i++)
        array[left + i] = temp[i];
}

static void merge_sort(int array[], int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    merge_sort(array, left, mid);
    merge_sort(array, mid + 1, right);
    merge(array, left, mid, right);
}

static void print_array(int array[], int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main(void)
{
    int array[MAX_LEN], len;

    printf("Lungimea vectorului (maxim %d): ", MAX_LEN);
    if (scanf("%d", &len) != 1 || len < 1 || len > MAX_LEN) {
        printf("Lungime invalida\n");
        return 1;
    }

    printf("Introdu cele %d elemente:\n", len);
    for (int i = 0; i < len; i++)
        scanf("%d", &array[i]);

    printf("Vector nesortat: ");
    print_array(array, len);

    merge_sort(array, 0, len - 1);

    printf("Vector sortat: ");
    print_array(array, len);

    return 0;
}
