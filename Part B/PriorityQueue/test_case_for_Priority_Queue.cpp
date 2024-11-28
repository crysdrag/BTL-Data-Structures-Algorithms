#include "_PRIORITY_QUEUE.hpp"
#include "_COMPARE.hpp"

int main() {
    Priority_Queue<int, Greater<int>> pq;

    pq.push(10);
    pq.push(5);
    pq.push(20);
    pq.push(15);

    std::cout << "Size: " << pq.size() << "\n";

    std::cout << "Min: " << pq.top() << "\n";
    std::cout << "Max: " << pq.back() << "\n";
    
    int i = 2;
    std::cout << "The third elem: " << pq[i] << "\n";

	std::cout << "Start pop:\n";
    while (!pq.empty()) {
        std::cout << "First elem: " << pq.top() << "\n";
        pq.pop();
    }

    if (pq.empty()) {
        std::cout << "Priority queue is null.\n";
    }

    return 0;
}

