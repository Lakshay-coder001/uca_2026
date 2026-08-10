#include<stdio.h>
#include<stdlib.h>
typedef struct {
    int population;
    int clinics;
    double load;
} Node;

void swap(Node *a, Node *b)
{
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyDown(Node heap[], int n, int i)
{
    int largest = i;
    int left = 2*i +1;
    int right = 2*i +2;

    if(left < n && heap[left].load > heap[largest].load){
        largest = left;
    }
    if(right < n && heap[right].load > heap[largest].load){
        largest = right;
    }
    if(largest != i)
    {
        swap(&heap[i], &heap[largest]);
        heapifyDown(heap, n, largest);
    }
}

void buildHeap(Node heap[], int n)
{
    for(int i = n / 2 - 1; i >= 0; i--){
        heapifyDown(heap, n, i);
    }
}


double solve(int population[], int n, int k)
{
    Node *heap = malloc(n * sizeof(Node));
    for(int i = 0; i < n; i++)
    {
        heap[i].population = population[i];
        heap[i].clinics = 1;
        heap[i].load = population[i];
        k--;
    }
    buildHeap(heap, n);
    while(k > 0)
    {

        heap[0].clinics++;
        heap[0].load = (double)heap[0].population / heap[0].clinics;
        heapifyDown(heap, n, 0);
        k--;
    }
    double res = heap[0].load;
    free(heap);
    return res;
}

int main(){
    int n;

    printf("Enter number of villages: ");
    scanf("%d", &n);

    int *popu = malloc(n * sizeof(int));
    printf("Enter population of villages:");
    for(int i = 0; i < n; i++){
        scanf("%d", &popu[i]);
    }
    int k;
    printf("Enter number of clinics: ");
    scanf("%d", &k);
    double answer = solve(popu, n, k);
    printf("Minimum max load = %.2f", answer);
    free(popu);
}