#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[50];
    struct Student* next;
} Student;

typedef struct Queue {
    Student* front;
    Student* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, char* name) {
    Student* temp = (Student*)malloc(sizeof(Student));
    strcpy(temp->name, name);
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

void dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    Student* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    printf("Student %s has taken the exam\n", temp->name);
    free(temp);
}

int main() {
    Queue* q = createQueue();
    int choice;
    char name[50];

    while (1) {
        printf("1. Add student to queue\n");
        printf("2. Call next student for exam\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter student name: ");
                scanf("%s", name);
                enqueue(q, name);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}