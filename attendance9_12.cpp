#include <iostream>
#include <cmath>
#include <vector>

void rotateLeft(std::vector<char>& v, int k);

int main(void) {
    std::vector<char> attend {'1', 'u', '3', '4', 'g', '6', 'r', 'j', 'y', 'j',
    'd', 'd', 'f', 'h', 's', 'd', 'f', '5', 'a', 'd', 'h', '6', 'j', 's', 'd', 'f',
    'j', '1', 's', 'v', 'a', '8', 'q', 'n', 'a', 'o', '9', 's', 'j', 'd', 'f'};

    int n_rotations = pow((50 * 2 - 75 / 3 + 20 % 7 + 20 + 12 / 4), 3);
    rotateLeft(attend, n_rotations);
    for(int i = 0; i < 5; i++) {
        std::cout << attend.at(i);
    }
    std::cout << '\n';
    return 0;
}

void rotateLeft(std::vector<char>& v, int k) {
    k %= v.size();
    while (k) {
        //get the first and insert at the end
        v.insert(v.end() - 1, v.front());

        //remove the first element
        v.erase(v.begin());
        k--;
    }
}