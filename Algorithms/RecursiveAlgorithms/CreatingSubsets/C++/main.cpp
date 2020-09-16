#include <vector>
#include <iostream>

void search(int k, int n, std::vector<int>& subset, std::vector<std::vector<int>>& result) {
    if(k == n + 1) {
        result.push_back(subset);
    } else {
        subset.push_back(k);
        search(k + 1, n, subset, result);
        subset.pop_back();
        search(k + 1, n, subset, result);
    }
}

int main() {
    int n = 0;
    std::cin >> n;
    
    std::vector<int> subset;
    std::vector<std::vector<int>> result;
    
    search(1, n, subset, result);
    for(std::vector<int> x: result) {
        for(int y: x) {
            std::cout << y << " ";
        }
        std::cout << '\n';
    }
}
