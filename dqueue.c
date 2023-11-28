#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int size;
    int front;
    int rear;
    int *arr;
} queue;

void enqueueFront(queue *q, int n) {
    if (q->front == -1 && q->rear == -1) {
        q->front = q->rear = 0;
    } 

    if (q->front == q->size) {
        printf("Queue is full\n");
        return;
    }

    q->arr[q->front] = n;
    q->front++;
}

void enqueueBack(queue *q, int n) {
    if (q->front == -1 && q->rear == -1) {
        q->front = q->rear = 0;
    } 

    if (q->rear == 0) {
        printf("Cant input at front.");
        return;
    }

    q->rear--;
    q->arr[q->rear] = n;
}

void dequeueBack(queue *q) {
    if (q->rear == q->front) {
        printf("Queue is empty.\n");
        return;
    }
    q->rear++;
}

void dequeueFront(queue *q) {
    if (q->rear == q->front) {
        printf("Queue is empty.\n");
        return;
    }
    q->front--;
}

void display(queue *q) {
    if (q->rear == q->front) {
        printf("Queue is empty.\n");
        return;
    }
    
    for (int i = q->rear; i < q->front; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n\n");
}

int main(void) {
    queue q;
    int opt, n, flag=0;
    q.front = q.rear = -1;

    printf("Enter the maximum size of the queue: ");
    scanf("%d", &q.size);

    q.arr = (int*)malloc(q.size*sizeof(int));
    
    while(1) {
        printf("1. Enqueue front\n2. Enqueue back\n3. Dequeue front\n4. Dequeue back\n5. Display\n6. Exit");
        printf("Enter your choice: ");
        scanf("%d", &opt);

        switch(opt) {
            case 1: 
                printf("Enter the number to be enqueued: ");
                scanf("%d", &n);
                enqueueFront(&q, n);
                display(&q);
                break;

            case 2: 
                printf("Enter the number to be enqueued: ");
                scanf("%d", &n);
                enqueueBack(&q, n);
                display(&q);
                break;

            case 3: 
                dequeueFront(&q);
                display(&q);
                break;

            case 4: 
                dequeueBack(&q);
                display(&q);
                break;

            case 5: 
                display(&q);
                break;

            case 6: 
                flag = 1;
                break;
        }

        if (flag) {
            break;
        }
    }

    return 0;
}