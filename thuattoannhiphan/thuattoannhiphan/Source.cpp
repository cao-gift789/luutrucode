#include <iostream>
#include <vector>

int gcd(int a, int b) {
    while (b) {
        a = a % b;
        std::swap(a, b);
    }
    return a;
}

std::vector<int> largestDivisors(const std::vector<int>& arr) {
    std::vector<int> result;
    for (int num : arr) {
        int largestDivisor = 1;
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                largestDivisor = std::max(largestDivisor, std::max(i, num / i));
            }
        }
        result.push_back(largestDivisor);
    }
    return result;
}

int main() {
    std::vector<int> arr = { 3, 20, 9 };
    std::vector<int> result = largestDivisors(arr);

    std::cout << "Output: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
