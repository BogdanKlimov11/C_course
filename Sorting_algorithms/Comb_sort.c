void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int get_next_gap(int gap) {
    gap = (gap * 10) / 13;
    if (gap < 1)
        return 1;
    return gap;
}

void comb_sort(int arr[], int n) {
    int gap = n;
    bool swapped = true;
    while (gap != 1 || swapped) {
        gap = get_next_gap(gap);
        swapped = false;
        for (int i = 0; i < n - gap; ++i) {
            if (arr[i] > arr[i + gap]) {
                swap(&arr[i], &arr[i + gap]);
                swapped = true;
            }
        }
    }
}
