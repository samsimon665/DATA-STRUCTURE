#include <stdio.h>

void BFS(int);

int G[10][10],visited[10],n,v;


int main() {

    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &G[i][j]);
        }
    }
    
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Enter starting vertex: ");
    scanf("%d",&v);
    BFS(v);

    return 0;
}

void BFS(int u) {
    int queue[n], front = 0, rear = 0;

    queue[rear++] = u;
    visited[u] = 1;

    printf("Breadth First Search starting from vertex %d : \n",u);

    while (front < rear) {
        int i= queue[front++];
        printf("%d ", i);

        for (int j = 0; j < n; j++) {
            if (G[i][j] == 1 && visited[j]==0) {
                queue[rear++] = j;
                visited[j] = 1;
            }
        }
    }
}