#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

/*Write the class AddElements here*/

// Class template AddElements
template <class T>
class AddElements {
public:
    T element;

    AddElements(T arg) {
        element = arg;
    }

    T add(T arg2) {
        return element + arg2;
    }
};

// Template specialization for string
template <>
class AddElements<string> {
public:
    string element;

    AddElements(string arg) {
        element = arg;
    }

    string concatenate(string arg2) {
        return element + arg2;
    }
};

int main() {
    int n, i;
    cin >> n;
    for (i = 0; i < n; i++) {
        string type;
        cin >> type;
        if (type == "float") {
            double element1, element2;
            cin >> element1 >> element2;
            AddElements<double> myfloat(element1);
            cout << myfloat.add(element2) << endl;
        } else if (type == "int") {
            int element1, element2;
            cin >> element1 >> element2;
            AddElements<int> myint(element1);
            cout << myint.add(element2) << endl;
        } else if (type == "string") {
            string element1, element2;
            cin >> element1 >> element2;
            AddElements<string> mystring(element1);
            cout << mystring.concatenate(element2) << endl;
        }
    }
    return 0;
}
