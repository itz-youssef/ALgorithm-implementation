#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class Heap {
private:
    vector<int> heap;

    int parent(int i) { return i / 2; }
    int left(int i) { return 2 * i; }
    int right(int i) { return 2 * i + 1; }

    
    void heapifyDown(int i) {
        int l = left(i);
        int r = right(i);
        int largest = i;

        if (l < heap.size() && heap[l] > heap[largest])
            largest = l;
        if (r < heap.size() && heap[r] > heap[largest])
            largest = r;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

    
    void heapifyUp(int i) {
        while (i > 1 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

public:
    Heap() {
        heap.push_back(-1); 
    }

    void insert(int key) {
        heap.push_back(key);
        heapifyUp(heap.size() - 1);
    }


    int extractMax() {
        if (heap.size() <= 1)
            throw runtime_error("Heap is empty!");

        int maxVal = heap[1];
        heap[1] = heap.back();
        heap.pop_back();
        if (heap.size() > 1)
            heapifyDown(1);
        return maxVal;
    }

    

    int getMin() {
        if (heap.size() <= 1)
            throw runtime_error("Heap is empty!");

        int minVal = heap[1];
        for (int i = 2; i < heap.size(); i++)
            if (heap[i] < minVal)
                minVal = heap[i];
        return minVal;
    }

    bool empty() const {
        return heap.size() <= 1;
    }

    void display() {
        for (int i = 1; i < heap.size(); i++)
            cout << heap[i] << " ";
        cout << endl;
    }

    vector<int> getHeap() { return heap; }
};



class PriorityQueue {
private:
    Heap heap;

public:
    void insert(int element, int priority) {
        
        heap.insert(priority);
        cout << "Inserted element " << element << " with priority " << priority << endl;
    }

    int extractHighestPriority() {
        if (heap.empty())
            throw runtime_error("Priority Queue is empty!");
        return heap.extractMax();
    }

    void display() {
        cout << "Priority Queue contents: ";
        heap.display();
    }
};


void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);


    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}



int main() {
    cout << " Heap Implementation " ;
    Heap heap;
    heap.insert(10);
    heap.insert(40);
    heap.insert(30);
    heap.insert(5);
    heap.insert(12);

    cout << "Heap elements: ";
    heap.display();
    cout << "Extracted Max: " << heap.extractMax() ;
    cout << "Minimum in heap: " << heap.getMin()  ;

    cout << "\n Priority Queue "  ;
    PriorityQueue pq;
    pq.insert(1, 20);
    pq.insert(2, 50);
    pq.insert(3, 15);
    pq.display();
    cout << "Highest Priority Extracted: " << pq.extractHighestPriority()  ;
    pq.display();

    cout << "\n Heap Sort " ;
    vector<int> arr = { 12, 11, 13, 5, 6, 7 };
    cout << "Original array: ";
    for (int v : arr) cout << v << " ";
    cout ;

    heapSort(arr);

    cout << "Sorted array: ";
    for (int v : arr) cout << v << " ";
    cout ;

    return 0;
}
