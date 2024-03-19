void counting_sort(int arr[], int n, int max_value) {
    int output[n];
    int count[max_value + 1];
    
    for (int i = 0; i <= max_value; ++i) {
        count[i] = 0;
    }

    for (int i = 0; i < n; ++i) {
        ++count[arr[i]];
    }

    for (int i = 1; i <= max_value; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; --i) {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }

    for (int i = 0; i < n; ++i) {
        arr[i] = output[i];
    }
}
