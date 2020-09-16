#include <vector>
#include <iostream>
#include <array>

const int n = 5;

std::vector<int> permutation;
std::array<int, n + 1> chosen;

std::vector<std::vector<int>> result;

void search() {
    if(permutation.size() == n) {
        std::cout << "Generated permutation: ";
        for(int x: permutation) {
            std::cout << x << ' ';
        }
        std::cout << '\n';
        
        result.push_back(permutation);
    } else {
        for(int i = 1; i <= n; ++i) {
            if(chosen[i]) continue;
            chosen[i] = true;
            
            std::cout << "Pushed back: " << i << '\n';
            
            permutation.push_back(i);
            search();
            chosen[i] = false;
            
            std::cout << "Popped back: " << permutation.back() << '\n';
            permutation.pop_back();
        }
    }
}

int main() {
    search();
}
