#include <stdio.h>

typedef struct queue {
    int arr[100];
    int size;
} queue;

void enqueue(queue *q, int n) {
    if (q->size == 99) {
        printf("Queue is full.\n");
        return;
    }

    int l = -1, r = q->size + 1;
    while(r - l > 1) {
        int m = l + (r-l)/2;
        if (q->arr[m] <= n) {
            l = m;
        }
        else {
            r = m;
        }
    }

    for (int i = q->size; i >= r; i--) {
        q->arr[i+1] = q->arr[i];
    }
    q->arr[r] = n;
    q->size++;
    return;
}

void dequeue(queue *q) {
    if (q->size == -1) {
        printf("Queue is empty.\n");
        return;
    }

    int index = 0, max = q->arr[0];
    for (int i = 0; i < q->size; i++) {
        if (max < q->arr[i]) {
            max = q->arr[i];
            index = i;
        }
    }

    for (int i = q->size; i >= index; i--) {
        q->arr[i+1] = q->arr[i];
    }
    q->size--;
}

void display(queue *q) {
    if (q->size == -1) {
        printf("Queue is empty.\n");
        return;
    }

    for (int i = 0; i <= q->size; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
    return;
}

int main(void) {
    queue q;
    q.size = -1;
    enqueue(&q, 5);
    enqueue(&q, 7);
    enqueue(&q, 8);
    enqueue(&q, 6);
    display(&q);
    dequeue(&q);
    display(&q);
    return 0;
}