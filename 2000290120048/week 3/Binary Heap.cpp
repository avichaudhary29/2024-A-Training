#include <iostream>
#include <vector>

class MinHeap {
private:
    std::vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    void heapifyUp(int i) {
        while (i > 0 && heap[i] < heap[parent(i)]) {
            std::swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int minIndex = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < heap.size() && heap[left] < heap[minIndex]) {
            minIndex = left;
        }

        if (right < heap.size() && heap[right] < heap[minIndex]) {
            minIndex = right;
        }

        if (minIndex != i) {
            std::swap(heap[i], heap[minIndex]);
            heapifyDown(minIndex);
        }
    }

public:
    bool empty() const { return heap.empty(); }

    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int extractMin() {
        if (empty()) {
            std::cout << "Heap is empty." << std::endl;
            return -1;
        }

        int minElement = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return minElement;
    }

    int getMin() const {
        if (empty()) {
            std::cout << "Heap is empty." << std::endl;
            return -1;
        }

        return heap[0];
    }
};

int main() {
    MinHeap minHeap;
    minHeap.insert(5);
    minHeap.insert(10);
    minHeap.insert(3);
    minHeap.insert(7);
    minHeap.insert(1);

    std::cout << "Min element: " << minHeap.getMin() << std::endl; // Should print 1

    while (!minHeap.empty()) {
        std::cout << "Extracted Min: " << minHeap.extractMin() << std::endl;
    }

    return 0;
}
