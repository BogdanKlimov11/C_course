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

void merge(int arr[], int l, int m, int r) {
    int len1 = m - l + 1, len2 = r - m;
    int Left[len1], Right[len2];
    for (int i = 0; i < len1; ++i)
        Left[i] = arr[l + i];
    for (int j = 0; j < len2; ++j)
        Right[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < len1 && j < len2) {
        if (Left[i] <= Right[j])
            arr[k++] = Left[i++];
        else
            arr[k++] = Right[j++];
    }
    while (i < len1)
        arr[k++] = Left[i++];
    while (j < len2)
        arr[k++] = Right[j++];
}

int calculate_min_run(int n) {
    int r = 0;
    while (n >= 62) {
        r |= (n & 1);
        n >>= 1;
    }
    return n + r;
}

void timsort(int arr[], int n) {
    int min_run = calculate_min_run(n);
    for (int i = 0; i < n; i += min_run)
        insertion_sort(arr, i, (i + min_run - 1 < n - 1) ? (i + min_run - 1) : (n - 1));
    for (int size = min_run; size < n; size <<= 1) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = (left + 2 * size - 1 < n - 1) ? (left + 2 * size - 1) : (n - 1);
            merge(arr, left, mid, right);
        }
    }
}
