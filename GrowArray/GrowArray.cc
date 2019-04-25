#include <string>
#include <memory.h>
#include <iostream>
using namespace std;

template<typename T>
class GrowArray{
private:
    T* data;
    int len;
public:
    GrowArray() : data(nullptr), len(0) {}
    ~GrowArray() { delete[] data; }
    GrowArray(const GrowArray& orig) : data(new T[orig.len]), len(orig.len) {
        for(int i = 0; i < len; i++){
            data[i] = orig.data[i];
        }
    }
    GrowArray& operator =(const GrowArray& orig) {
        GrowArray copy(orig);
        this->len = copy.len;
        swap(this->data,copy.data); //swap so the temporary copy dies and deletes the old memory
        return *this;
    }
    GrowArray(GrowArray&& orig) : len(orig.len), data(orig.data) {
        orig.data = nullptr;
    }


    void add(const T& v) {
        T* old = data; //Temp pointer to old data
        data = new T[len+1]; //Allocate 1 more array size
        for (int i = 0; i < len; i++){
            data[i] = old[i];
        }
        data[len] = v;
        delete [] old;
        len++;
    }

    friend ostream& operator <<(ostream& s, const GrowArray& a){
        for (int i = 0; i < a.len; i++){
            s << a.data[i] << " ";
        }
        return s;
    }
    //Note: Stupid C++ Rule, some operators cannot be made friends, must be members.
    //Operator =, [], ()

    T operator [] const(int i){
        if (i >= len){
            throw "Index out of Bounds";
        }
        return data[i];
    }

    T& operator [](int i){
        if (i >= len){
            throw "Index out of Bounds";
        }
        return data[i];
    }

    

};

class Elephant {
    friend ostream& operator << (ostream& s, const Elephant& e){
        return s << "Yo, I'm an elephant.";
    }
};

int main() {
    GrowArray<int> a;
    a.add(5);
    a.add(6);
    for( int i = 0; i < 10; i++){
        a.add(i);
    }
    cout << a;
    GrowArray<string> b;
    b.add("hello");
    b.add("bye");
    cout << b << '\n';
    GrowArray<int> c;
    GrowArray<int> d;
    c.add(2);
    c = d = a;
    


    GrowArray<Elephant> elephants;
    elephants.add(Elephant());
    elephants.add(Elephant());
}