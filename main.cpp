#include <iostream>
#include <gmp.h>
#include <gmpxx.h>
#include <chrono>

int main() {

    auto started = std::chrono::high_resolution_clock::now();

    mpz_t a,b,c;

    mpz_init(a);
    mpz_init(b);
    mpz_init(c);

    mpz_set_str(a, "1", 10);
    mpz_set_str(b, "2", 10);
    mpz_set_str(b, "0", 10);

    int interation = 99999;

    for(int i = 0; i < interation; i++){
        mpz_add(c, a, b);
        mpz_set(a, b);
        mpz_set(b, c);
    }
    auto done = std::chrono::high_resolution_clock::now();

    std::cout << "SUM \na " << a << " \nb " << b << " \nc " << c;

    std::cout << "\n" << std::chrono::duration_cast<std::chrono::milliseconds>(done-started).count();
    return 0;
}
