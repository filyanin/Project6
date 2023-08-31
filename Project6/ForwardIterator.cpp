// У меня не отурылось готовое решение, которое предлагают в качестве примера, поэтому убедиться в правильности не получилось.

// Требования к итератору: https://docs.w3cub.com/cpp/named_req/forwarditerator
// Итак, чтобы итератор удовлетворял все условия LegacyForwardIterator, он должен удовлетворять и условия более простых итераторов.

#include <vector>
#include <iostream>

template <typename T>
class ForwardIterator {
private:
    typename std::vector<T>::const_iterator current;
public:
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = const T*;
    using reference = const T&;
    using iterator_category = std::forward_iterator_tag;

    ForwardIterator(typename std::vector<T>::const_iterator iter) : current(iter) {}

    reference operator*() const {               // LegacyInputIterator выражение *i
        return *current;
    }

    ForwardIterator& operator++() {         // LegacyForwardIterator выражение *i++
        ++current;
        return *this;
    }

    ForwardIterator operator++(int) {       // LegacyForwardIterator выражение i++
        ForwardIterator tmp = *this;
        ++current;
        return tmp;
    }

    bool operator!=(const ForwardIterator& other) const {   // LegacyInputIterator выражение i != j
        return current != other.current;
    }

    bool operator==(const ForwardIterator& other) const {   // EqualityComparable выражение i == j
        return current == other.current;
    }
};

int main() {
    std::vector<int> numbers = { 1, 2, 3, 4, 5 };

    ForwardIterator<int> it = numbers.begin();

    it++;

    while (it != numbers.end()) {
        std::cout << *it << " ";
        ++it;
    }

    std::cout << std::endl;

    

    std::cout << std::endl;

    return 0;
}