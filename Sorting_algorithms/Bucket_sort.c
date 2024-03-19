#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* create_node(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void free_nodes(Node** bucket, int n) {
    for (int i = 0; i < n; ++i) {
        Node* current = bucket[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
}

void insertion_sort(Node** bucket, int n) {
    for (int i = 0; i < n; ++i) {
        Node* head = bucket[i];
        Node* sorted = NULL;
        while (head != NULL) {
            Node* current = head;
            head = head->next;
            if (sorted == NULL || current->value < sorted->value) {
                current->next = sorted;
                sorted = current;
            } else {
                Node* search = sorted;
                while (search->next != NULL && search->next->value < current->value) {
                    search = search->next;
                }
                current->next = search->next;
                search->next = current;
            }
        }
        bucket[i] = sorted;
    }
}

void bucket_sort(int arr[], int n) {
    const int numBuckets = 10;
    Node* buckets[numBuckets];

    for (int i = 0; i < numBuckets; ++i) {
        buckets[i] = NULL;
    }

    for (int i = 0; i < n; ++i) {
        int bucketIndex = arr[i] / numBuckets;
        Node* newNode = create_node(arr[i]);
        newNode->next = buckets[bucketIndex];
        buckets[bucketIndex] = newNode;
    }

    insertion_sort(buckets, numBuckets);

    int index = 0;
    for (int i = 0; i < numBuckets; ++i) {
        Node* current = buckets[i];
        while (current != NULL) {
            arr[index++] = current->value;
            current = current->next;
        }
    }

    free_nodes(buckets, numBuckets);
}
