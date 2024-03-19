#include <limits.h>

void insertion_sort(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j <= right - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = temp;
    return i + 1;
}

void quick_sort(int arr[], int left, int right, int depth_limit) {
    while (right - left > 16) {
        if (depth_limit == 0) {
            heap_sort(arr, left, right);
            return;
        }
        depth_limit--;
        int pivot_index = partition(arr, left, right);
        quick_sort(arr, left, pivot_index - 1, depth_limit);
        left = pivot_index + 1;
    }
    insertion_sort(arr, left, right);
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int left, int right) {
    int n = right - left + 1;
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

void intro_sort(int arr[], int left, int right) {
    int depth_limit = (int)(sizeof(int) * CHAR_BIT);
    quick_sort(arr, left, right, depth_limit);
}
