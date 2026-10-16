#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Graph represented using adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adjList[MAX_VERTICES];
int visited[MAX_VERTICES];

// Function to create a new adjacency list node
Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph
void addEdge(int u, int v) {
    Node* newNode = createNode(v);
    // Insert at the head of the list
    newNode->next = adjList[u];
    adjList[u] = newNode;
}

// Function to sort the adjacency list for each vertex
void sortAdjList(int V) {
    for (int i = 0; i < V; i++) {
        if (adjList[i] == NULL) continue;
        
        int swapped;
        Node* ptr1;
        Node* lptr = NULL;
        do {
            swapped = 0;
            ptr1 = adjList[i];
            
            while (ptr1->next != lptr) {
                if (ptr1->vertex > ptr1->next->vertex) {
                    int temp = ptr1->vertex;
                    ptr1->vertex = ptr1->next->vertex;
                    ptr1->next->vertex = temp;
                    swapped = 1;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
	}
}

// Depth-First Search (DFS) function
void DFS(int start) {
    printf("%d ", start);
    visited[start] = 1;
    
    Node* temp = adjList[start];
    while (temp != NULL) {
        int connectedVertex = temp->vertex;
        if (!visited[connectedVertex]) {
            DFS(connectedVertex);
        }
        temp = temp->next;
	}
}

int main() {
    int V, E;
    int u, v, start;

    // Read number of vertices and edges
    scanf("%d %d", &V, &E);

    // Initialize adjacency list
    for (int i = 0; i < V; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }

    // Read the edges
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    // Sort the adjacency list for each vertex
    sortAdjList(V);

    // Read the starting node
    scanf("%d", &start);

    // Perform DFS starting from the given node
    DFS(start);

    return 0;
}
