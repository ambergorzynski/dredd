#include <cstdint>

// Number wraps integer, enforcing explicit casting
struct Number {
    
    uint32_t value = {};
    
    // Constructors
    Number() = default;
    explicit Number(unsigned long long int v) : value(static_cast<uint32_t>(v)) {}

    operator uint32_t() const { return value; }

};

using u32 = Number;

inline u32 operator""_u(unsigned long long int value) {
    return u32(static_cast<uint32_t>(value));
}

int main() {
    
    u32 foo = 1_u;

    return 0;
}
