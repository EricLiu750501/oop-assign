#include <iostream>
using namespace std;

namespace rect {
    float len;
    float wid;
    float area() {
        return len*wid;
    }
}
using namespace rect;
int main() {
    cin >> len >> wid;
    cout << rect::area() << endl;
    string a[2] = {"123", "456"};
    cout << a[1];
}
