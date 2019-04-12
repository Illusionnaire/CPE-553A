Vector:
- A dynamically growing array (list)
- vector<int> a;
- a.push_back(3);
- a.size() tells you how big it is
- a[i] -> overloading of operator[] to make it look like an array.

```
for(int i = 0; i < a.size(); i++) // O(N^2)
    cout << a[i] << ' ';
cout << "\n";
```
```
for(vector<int>::iterator i = a.begin(); i != a.end(); ++i)
    cout << *i << ' ';
cout << "\n";
```
- specific iterator === const_iterator is read only to allow it to be passed as a const value into a function.
- 4 different types of iterators. There is also a reverse iterator.
```
for (auto x : a){ //Under the hood, this uses the iterator object
    cout << x << ' ';
}
cout << "\n";
```
- If you call auto& x, you can change x because you are the referenced numbers. (i.e. append a number or do operations on list items)
- If you call auto x, you are using a copy, so it cannot change.

### When to use List/Vectors
1. in LinkedLists, items within the list are not next to each other in memory. You always needs to start with the head and increment into it.
2. Vector -> Better when things are built in order. (Always add to end, like Queue)
3. LinkedList -> Better if you need to insert into the middle of array of stuff.

### Auto Keyword
1. in old C code, auto was a qualifier that defined a variable, on the stack.
2. -> Now, auto is used to automatically define a type based on what it needs. 

### Ordered Map:
* A quick way to map a value to a keyword, but not the other way around.
* This is a TreeMap
```
#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, double> stockPrice;

stockPrice["AAPL"] = 205;
stockPrice["IBM] = 132;
stockPrice["MSFT] = 73.5;
stockPrice["TSLA"] = 290;

cout << stockPrice["APPL"] << "\n";
cout << stockPrice["XXY"] << "\n";  //Would crash because it doesn't exist (It does not let you ask if something exists first before getting it, they are two different things)

if (stockPrice.contains("XXY")) { //contains keyword is only a C++20 standard.
    cout << stockPrice["XXY"];
}
```

* Each list of things should have an iterator created by the maker of the class

```
for(map<string,double>::iterator i = stockPrice.begin(); i != stockPrice.end(); ++i){
    cout << i->first << " ==> " << i->second << endl;
}

for(auto x : stockPrice){
    cout << x.first << " ==> " << x.second << endl;
}
```

### Unordered Map:
```
#include<string>
#include <unordered_map>

unordered_map<string, double> stockPrice;

stockPrice["AAPL"] = 205;
stockPrice["IBM] = 132;
stockPrice["MSFT] = 73.5;
stockPrice["TSLA"] = 290;

cout << stockPrice["APPL"] << "\n";
cout << stockPrice["XXY"] << "\n";  //Would crash because it doesn't exist (It does not let you ask if something exists first before getting it, they are two different things)
```

```
for(unordered_map<string,double>::iterator i = stockPrice.begin(); i != stockPrice.end(); ++i){
    cout << i->first << " ==> " << i->second << endl;
}

for(auto x : stockPrice){
    cout << x.first << " ==> " << x.second << endl;
}
```