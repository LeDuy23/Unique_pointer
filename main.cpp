#include<my_unique_ptr.hpp>
#include<iostream>

int main() {
    try {
        // For a single object
        my_unique_ptr<int> ptr(new int(42));
        std::cout << "Value of ptr: " << *ptr << std::endl;

        // For an array
        my_unique_ptr<int[]> arr(new int[5]{1, 2, 3, 4, 5});
        std::cout << "Array elements: ";
        for (int i = 0; i < 5; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;

    } catch (const std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}