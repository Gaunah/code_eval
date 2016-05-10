#include <iostream>

int main()
{
    int i = 1, prime_count = 0, sum = 0;
    while (prime_count != 1000) {
        i++;
        int count = 0;
        for (int k = 2; k < i; k++) {
            if (i % k == 0) {
                count++;
            }
        }
        if (count == 0) {
            prime_count++;
            sum += i;
        }
    }
    std::cout << sum << std::endl;
    return 0;
}
