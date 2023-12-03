#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 100; // Максимальний розмір масиву

// Функція для обчислення добутку додатних елементів масиву
double dob_positive_elements(double arr[], int size) {
    double product = 1.0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0) {
            product *= arr[i];
        }
    }
    return product;
}

// Функція для знаходження суми елементів до мінімального елемента
double sum_elements_before_min(double arr[], int size) {
    if (size == 0) {
        return 0.0;
    }

    double min_element = arr[0];
    int min_index = 0;

    for (int i = 1; i < size; ++i) {
        if (arr[i] < min_element) {
            min_element = arr[i];
            min_index = i;
        }
    }

    double sum = 0.0;
    for (int i = 0; i < min_index; ++i) {
        sum += arr[i];
    }
    return sum;
}

// Функція для сортування елементів за позиціями (парні/непарні)
void sort_elements_by_position(double arr[], int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if ((i % 2 == 0 && arr[i] > arr[j]) || (i % 2 != 0 && arr[i] < arr[j])) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

int main() {
    int size;
    double arr[MAX_SIZE];

    cout << "Enter the size of the array (max " << MAX_SIZE << "): ";
    cin >> size;

    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < size; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "Product of positive elements: " << dob_positive_elements(arr, size) << endl;
    cout << "The sum of elements to the minimum: " << sum_elements_before_min(arr, size) << endl;

    sort_elements_by_position(arr, size);

    cout << "Even numbers: ";
    for (int i = 0; i < size; ++i) {
        if (static_cast<int>(arr[i]) % 2 == 0) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;

    cout << "Odd numbers: ";
    for (int i = 0; i < size; ++i) {
        if (static_cast<int>(arr[i]) % 2 != 0) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
