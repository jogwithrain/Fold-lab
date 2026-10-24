#include <iostream>
#include <vector>
#include <functional>
#include <cassert>


using namespace std;


template<typename T, typename UnaryFunc>
T fold(const vector<T>& v, UnaryFunc f, int i = 0) {
    if (v.size() - 1 == i) {
        return v[i];
    }
    return f(v[i], fold(v, f, i + 1));
}


template<typename T>
T add(T x, T y) {
    return x + y;
}
template<typename T>
T mult(T x, T y) {
    return x * y;
}


int main() {
    { //adding
        vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
        function<int(int, int)> a = add<int>;
        int x = fold(v, a);
        assert(x == 55);
        cout << x << endl;


        vector<double> y = { 2.2,2.3,2.4,2.5 };
        function<double(double, double)> b = add<double>;
        double z = fold(y, b);
        assert(z == 9.4);
        cout << z << endl;


        vector<char> c = { 'a','b','c' };
        function<char(char, char)> d = add<char>;
        char e = fold(c, d);
        assert(e == '&');
        cout << e << endl;
    }
    {//scope of multiplication
        vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
        function<int(int, int)> a = mult<int>;
        int x = fold(v, a);
        assert(x == 3628800);
        cout << x << endl;


        vector<double> y = { 2.2,2.3,2.4,2.5 };
        function<double(double, double)> b = mult<double>;
        double z = fold(y, b);
        assert(z == 30.36);
        cout << z << endl;


        vector<char> c = { 'a','b','c' };
        function<char(char, char)> d = mult<char>;
        char e = fold(c, d);
        assert(e == '&');
        cout << e << endl;
    }


}


