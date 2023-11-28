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
        q->arr[q->front] = n;
    } 

    else if ((q->front+1)%q->size == q->rear) {
        printf("Queue is full\n");
        return;
    }

    else {
        q->front = (q->front+1)%q->size;
        q->arr[q->front] = n;
    }
}

void dequeueBack(queue *q) {
    if (q->front == -1 && q->rear == -1) {
        printf("Queue is empty\n");
    }
    else if (q->rear == q->front) {
        q->rear = q->front = -1;
        return;
    }
    else {
        q->rear = (q->rear+1)%q->size;
    }
}

void display(queue *q) {
    int i = q->rear;
    if (q->rear == -1 && q->front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    
    while (i != q->front) {
        printf("%d " , q->arr[i]);
        i = (i+1)%(q->size);
    }
    printf("%d ", q->arr[q->front]);
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
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
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
                dequeueBack(&q);
                display(&q);
                break;

            case 3: 
                display(&q);
                break;

            case 4: 
                flag = 1;
                break;
        }

        if (flag) {
            break;
        }
    }

    return 0;
}