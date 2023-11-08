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
    int op, n, flag = 0;
    queue q;
    q.size = -1;
    while (1) {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Enter number: ");
            scanf("%d", &n);
            enqueue(&q, n);
            display(&q);
            break;

        case 2: 
            dequeue(&q);
            display(&q);
            break;

        case 3: 
            display(&q);
            break;
        
        case 4: 
            flag = 1;
        default:
            break;
        }

        if (flag) break;
    }
    return 0;
}