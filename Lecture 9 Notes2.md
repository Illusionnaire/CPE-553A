### Templates
``` 
#include <iostream>
using namespace std;

template<typename T>
void print(const int a[], size_t size){
    for (uint32_t i = 0; i < size; i++)
        cout << a[i] << ' ';
    cout << '\n';
}


int main() {
    int x[] = {5,4, 1};
    int y[] = {5, 4, 1, 1, 9, 8, 8, 16 ,423, 5};
    print(x, sizeof(x) / sizeof(int));
}
```


### Swapping two spots without the need of a temp
* Using overflow
```
x[i] = x[i] + x[i+1];
x[i+1] = x[i] - x[i+1];
x[i] = x[i] - x[i+1];

x[i] = x[i] ^ x[i+1];
x[i+1] = x[i] ^ x[i+1];
x[i] = x[i] ^ x[i+1];
```

##Template Functions
```
template<typename T, typename Key>
void sort(T x[], int n, Key T::*key)

    // x[i].*key > x[i+1].*key
    // T temp = x[i]
```

##Template Classes
```
template<typename Precision>
class Complex {
private:
    Precision r, i;
public:


};

int main(){
    Complex<double> a(1.5,2.3);
}