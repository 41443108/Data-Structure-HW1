#include <iostream>
#include <vector>

void generatePowerset(const std::vector<char>& S, std::vector<char>& current, int index) {
    if (index == S.size()) {
        std::cout << "{ ";
        for (char c : current) {
            std::cout << c << " ";
        }
        std::cout << "}\n";
        return;
    }

    generatePowerset(S, current, index + 1);

    current.push_back(S[index]);
    generatePowerset(S, current, index + 1);

    current.pop_back();
}

int main() {
    int n;
    std::cout << "請輸入集合元素個數 n: ";
    if (std::cin >> n) {
        std::vector<char> S(n);
        std::cout << "請依次輸入 " << n << " 個字元元素 (以空格分隔): ";
        for (int i = 0; i < n; i++) {
            std::cin >> S[i];
        }

        std::vector<char> current;
        std::cout << "Powerset(S) 結果為:\n";
        generatePowerset(S, current, 0);
    }
    return 0;
}