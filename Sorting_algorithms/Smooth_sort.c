#define LEFT_CHILD(i) (2 * (i) + 1)
#define RIGHT_CHILD(i) (2 * (i) + 2)

void sift_down(int arr[], int start, int end) {
    int root = start;
    while (LEFT_CHILD(root) <= end) {
        int child = LEFT_CHILD(root);
        int swap = root;

        if (arr[swap] < arr[child])
            swap = child;
        if (child + 1 <= end && arr[swap] < arr[child + 1])
            swap = child + 1;
        if (swap == root)
            return;
        else {
            int temp = arr[root];
            arr[root] = arr[swap];
            arr[swap] = temp;
            root = swap;
        }
    }
}

void smooth_sort(int arr[], int n) {
    int p = 1, r = 1, t = 1;
    while (t < n) {
        int p0 = p;
        if ((p & 3) == 1) {
            sift_down(arr, 0, r - 1);
            p += 1;
        } else {
            int z = 1;
            int tz = 1;
            if ((p & 3) == 3) {
                int lk = LEFT_CHILD(r - 1);
                int rk = RIGHT_CHILD(r - 1);
                if (arr[r - 1] < arr[lk] || arr[r - 1] < arr[rk]) {
                    z = 0;
                    tz = 0;
                }
            }
            if (tz) {
                int lv = LEFT_CHILD(p0) - 1;
                int rv = RIGHT_CHILD(p0) - 1;
                while (r <= n && arr[r - 1] <= arr[r - 2]) {
                    r += 1;
                    if (arr[r - 2] < arr[r - 1])
                        break;
                    int k = (r - p) / (p - p0);
                    int j = p - k * (p - p0);
                    sift_down(arr, lv + j, rv);
                    r -= k;
                    rv = lv + j;
                    lv = lv - k;
                }
            }
            if (z) {
                sift_down(arr, p0 - 1, r - 1);
            }
            p = p << 1;
        }
        t += 1;
    }
}
