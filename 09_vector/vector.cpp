#include <iostream>
#include <vector>

void print(const std::vector<int>& v);
void rotateRight(std::vector<int>& v, int k);
void rotateLeft(std::vector<int>& v, int k);

int main(void) {
    //Create a vector (Intialization list)
    std::vector<int> v {1, 2, 3, 4, 5, 6};
    print(v);

    //Create with size and default value
    std::vector<int> v2(5, 10); //5 elements, each set to 10
    print(v2);

    //Create a copy from another vector
    std::vector<int> v3(v);
    print(v3);

    //Print the current number of elements
    std::cout << v3.size() << std::endl;

    //Front and back
    std::cout << "Front " << v3.front() << std::endl;
    std::cout << "Back " << v3.back() << std::endl;

    // Ad to the end
    v3.push_back(8);
    v3.push_back(9);

    //Remove the last element
    v3.pop_back();
    std::cout << "After addition and removal\n";
    print(v3);

    //Iterators - is an object that enables traversal over elements
    /*
        Begin(): point to the first element
        end(): points to one past the last one
    */

    //Insert an element (iterator, value)
    v3.insert(v3.begin(), 100);
    print (v3);

    //Insert 999 in the middle
    int middle =v3.size() / 2;
    v3.insert(v3.begin() + middle, 999);
    print (v3);

    //Erase (iterator)
    v3.erase(v3.begin() + 1); // remove the second element
    print(v3);

    rotateRight(v3);
    print(v3);
    rotateLeft(v3);
    print(v3);

    return 0;
}

void print(const std::vector<int>& v) {
    for (int el : v) {
        std::cout << el << ' ';
    }
    std::cout << std::endl;
}

void rotateRight(std::vector<int>& v, int k) {
    k %= v.size();
    while (k) {
        //get the last and insert at the beginning
        v.insert(v.front(), v.end() - 1);

        //remove the last element
        v.erase(v.back());
        k--;
    }
}

void rotateLeft(std::vector<int>& v, int k) {
    k %= v.size();
    while (k) {
        //get the first and insert at the end
        v.insert(v.end() - 1, v.front());

        //remove the first element
        v.erase(v.front());
        k--;
    }
}