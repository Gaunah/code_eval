#include <iomanip>
#include <iostream>

int main()
{
    using namespace std;
    for (int i = 1; i <= 12; i++) {
        for (int k = 1; k <= 12; k++) {
            cout << setw(4) << right << i *k;
        }
        cout << endl;
    }
    return 0;
}
