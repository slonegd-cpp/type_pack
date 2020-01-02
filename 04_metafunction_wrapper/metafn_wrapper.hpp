// value based обёртка над метафункциями
#pragma once

#include <type_traits>
#include "type_identity.hpp"

struct value_first {};
constexpr auto value_first_v = value_first{};

template <template <class...> class F, class...Ts>
struct value_fn {
    template <class...Us>
    constexpr auto operator()(type_identity<Us>...) {
        return F<Ts...,Us...>::value;
    }
};

// когда в метафункцию необходимо сначала передать аргументы, по которым итерируемся
template <template <class...> class F, class...Ts>
struct value_first_fn {
    template <class...Us>
    constexpr auto operator()(type_identity<Us>...) {
        return F<Us...,Ts...>::value;
    }
};

template <template <class...> class F, class...Ts>
struct type_fn {
    template <class...Us>
    constexpr auto operator()(type_identity<Us>...) {
        return type_identity<typename F<Ts...,Us...>::type>{};
    }
};


