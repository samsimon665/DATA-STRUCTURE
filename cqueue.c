#include <stdio.h>
int queue[100];
int front = -1, rear = -1,choice,item,size;

int isFull() {
    if ((front == 0 && rear == size - 1) || (front == rear + 1))
        return 1;
    else
        return 0;
}

int isEmpty() {
    if (front == -1)
        return 1;
    else
        return 0;
}

void enqueue() {
    if (isFull())
        printf("Queue is full. Cannot enqueue.\n");
    else {
        printf("enter item : ");
        scanf("%d",&item);
        if (front == -1)
            front = 0;
        rear = (rear + 1) % size;
        queue[rear] = item;
        printf("Enqueued %d\n", item);
    }
}

void dequeue() {
    if (isEmpty())
        printf("Queue is empty. Cannot dequeue.\n");
    else {
        printf("Dequeued %d\n", queue[front]);
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % size;
    }
}

void display() {
    int i;
    if (isEmpty())
        printf("Queue is empty.\n");
    else {
        printf("Queue elements: ");
        for (i = front; i != rear; i = (i +1) % size)
            printf("%d, ", queue[i]);
        printf("%d\n", queue[i]);
    }
}

int main() {
    printf("\nenter the size of the array: ");
	scanf("%d",&size);
    do
	{
		printf("\n\nEnter the operation to perform:\n1.enqueue\n2.dequeue\n3.display\n4.exit\nyour choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				{
					enqueue();
					break;
				}
			case 2:
				{
					dequeue();
					break;
				}
			case 3:
				{	
					display();
					break;
				}
			case 4:
				{
					printf("exiting\n");
					break;
				}
			default:printf("\ninvalid input");
		};
	}while(choice!=4);
    return 0;
}


 





