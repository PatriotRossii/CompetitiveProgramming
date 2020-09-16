#include <array>
#include <iostream>

const int n = 16;
int count = 0;

std::array<bool, n * n> col;
std::array<bool, n * n> diag1;
std::array<bool, n * n> diag2;

void search(int y) {
    if(y == n) {
        count++;
        return;
    }
    for(int x = 0; x < n; ++x) {
        if(col[x] || diag1[x + y] || diag2[x - y + n - 1]) continue;
        col[x] = diag1[x + y] = diag2[x - y + n - 1] = true;
        search(y + 1);
        col[x] = diag1[x + y] = diag2[x - y + n - 1] = false;
    }
}

int main() {
    search(0);
    std::cout << count;
}
