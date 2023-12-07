#include <iostream>
using namespace std;


int cal(int **arr) {
    int temp = 0;
    int count = 0;
    for (int i=0;i<5;i++) {
        for (int j=0;j<5;j++) {
            scanf("%d", &temp);
            if (temp == 1 && arr[i][j] == 1) {
                count += 1;
            }
            else if (temp == 1 && arr[i][j] == 8) {
                count += 2;
            }
            else if (temp == 8 && arr[i][j] == 1) {
                count += 7;
            }
            else if (temp == 8 && arr[i][j] == 8) {
                count += 5;
            }
            arr[i][j] = temp;
        }
    }
    return count;
}

int main() {
    int P;
    cin >> P;
    int **arr = new int*[5];
    for (int i=0;i<5;i++) {
        arr[i] = new int[5]{0};
    }

    for (int i=0;i<5;i++) {
        for (int j=0;j<5;j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    while (--P) {
       cout << cal(arr) << endl;
    }

}

