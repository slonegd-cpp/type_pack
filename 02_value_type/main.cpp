#include <type_traits>

template <class T>
struct type_identity { using type = T; };

template <class T>
using type_identity_t = typename type_identity<T>::type;

// получить значение типа
constexpr auto int_type = type_identity<int>{};

// достать тип из значения типа
using int_type_t = decltype(int_type)::type;

int main() {
    static_assert(std::is_same_v<int_type_t, int>);
}