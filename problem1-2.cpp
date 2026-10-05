#include <iostream>
#include <stack>

int ackermannNonRecursive(int m, int n) {
    std::stack<int> s;
    s.push(m);

    while (!s.empty()) {
        m = s.top();
        s.pop();

        if (m == 0) {
            n = n + 1;
        }
        else if (n == 0) {
            s.push(m - 1);
            n = 1;
        }
        else {
            s.push(m - 1);
            s.push(m);
            n = n - 1;
        }
    }
    return n;
}

int main() {
    int m, n;
    std::cout << "請輸入 m 和 n (以空格分隔): ";
    if (std::cin >> m >> n) {
        std::cout << "A(" << m << ", " << n << ") = "
            << ackermannNonRecursive(m, n) << std::endl;
    }
    return 0;
}