template <class T>
struct type_identity { using type = T; };

template <class T>
using type_identity_t = typename type_identity<T>::type;

template<class T>
void foo(T, T) {}
 
template<class T>
void bar(T, type_identity_t<T>) {}

int main() {
    // foo(4.2, 0); // error, deduced conflicting types for parameter ‘T’ (‘double’ and ‘int’)
    bar(4.2, 0); // OK, calls bar<double>
}