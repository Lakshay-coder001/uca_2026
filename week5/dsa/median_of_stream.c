#include <stdio.h>
#define MAX 1000

typedef struct {
    int arr[MAX];
    int size;
} pq;

typedef struct {
    pq maxpq;
    pq minpq;
} median;

void insert(median *mf, int num)
{
    pq *maxH = &mf->maxpq;
    pq *minH = &mf->minpq;
    if (maxH->size == 0 || num <= maxH->arr[0]) {
        int i = maxH->size;
        maxH->arr[i] = num;
        maxH->size++;

        while (i > 0) {
            int parent = (i - 1) / 2;
            if (maxH->arr[parent] >= maxH->arr[i])
                break;
            int temp = maxH->arr[parent];
            maxH->arr[parent] = maxH->arr[i];
            maxH->arr[i] = temp;
            i = parent;
        }
    }
    else {

        int i = minH->size;
        minH->arr[i] = num;
        minH->size++;

        while (i > 0) {
            int parent = (i - 1) / 2;

            if (minH->arr[parent] <= minH->arr[i])
                break;

            int temp = minH->arr[parent];
            minH->arr[parent] = minH->arr[i];
            minH->arr[i] = temp;

            i = parent;
        }
    }
    if (maxH->size > minH->size + 1) {
        int x = maxH->arr[0];
        maxH->size--;
        maxH->arr[0] = maxH->arr[maxH->size];
        int i = 0;

        while (1) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if (left < maxH->size &&
                maxH->arr[left] > maxH->arr[largest])
                largest = left;

            if (right < maxH->size &&
                maxH->arr[right] > maxH->arr[largest])
                largest = right;

            if (largest == i)
                break;

            int temp = maxH->arr[i];
            maxH->arr[i] = maxH->arr[largest];
            maxH->arr[largest] = temp;

            i = largest;
        }
        i = minH->size;
        minH->arr[i] = x;
        minH->size++;

        while (i > 0) {
            int parent = (i - 1) / 2;

            if (minH->arr[parent] <= minH->arr[i])
                break;
            int temp = minH->arr[parent];
            minH->arr[parent] = minH->arr[i];
            minH->arr[i] = temp;

            i = parent;
        }
    }
    else if (minH->size > maxH->size) {

        int x = minH->arr[0];

        minH->size--;
        minH->arr[0] = minH->arr[minH->size];

        int i = 0;

        while (1) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int smallest = i;

            if (left < minH->size &&
                minH->arr[left] < minH->arr[smallest])
                smallest = left;

            if (right < minH->size &&
                minH->arr[right] < minH->arr[smallest])
                smallest = right;

            if (smallest == i)
                break;

            int temp = minH->arr[i];
            minH->arr[i] = minH->arr[smallest];
            minH->arr[smallest] = temp;

            i = smallest;
        }
        i = maxH->size;
        maxH->arr[i] = x;
        maxH->size++;

        while (i > 0) {
            int parent = (i - 1) / 2;
            if (maxH->arr[parent] >= maxH->arr[i])
                break;
            int temp = maxH->arr[parent];
            maxH->arr[parent] = maxH->arr[i];
            maxH->arr[i] = temp;
            i = parent;
        }
    }
}


double getMedian(median *mf)
{
    if (mf->maxpq.size == mf->minpq.size) {

        return (mf->maxpq.arr[0] +
                mf->minpq.arr[0]) / 2.0;
    }
    return mf->maxpq.arr[0];
}

int main(){

    return 0;
}