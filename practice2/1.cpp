#include <iostream>
using namespace std;

void ne(int score[500][500], int numa, int numb) {
    score[numa][numb] += 5;
    score[numb][numa] += 5; 
}

void fg(int score[500][500], int numa, int numb) {
    score[numa][numb] += 3;
    score[numb][numa] += 3; 
}

void chat(int score[500][500], int numa, int numb) {
    score[numa][numb] += 2;
    score[numb][numa] += 2;
}

void cj(int jokes[500][500], int score[500][500], int numa, int numb) {
    score[numa][numb] += 2;
    jokes[numa][numb] += 1;
    if ( jokes[numa][numb] == 3) {
        score[numb][numa] = 0;
        jokes[numa][numb] = 0; 
    }
}

int main() {
    int n;
    cin >> n;
    string names[500]; 

    // int **score = (int **)calloc(n, sizeof(int) * n);
    // for (int i = 0; i < n; i++) {
    //     score[i] = (int *)calloc(n, sizeof(int));
    // }

    // int **jokes = (int **)calloc(n, sizeof(int) * n);
    // for (int i = 0; i < n; i++) {
    //     jokes[i] = (int *)calloc(n, sizeof(int));
    // }
    int score[500][500] = {};
    int jokes[500][500] = {}; 

    for (int i=0;i<n;i++)  {
        cin >> names[i];
    }  


    string act, aman, bman;
    while (cin >> act >> aman >> bman) {
        int anum, bnum;
        for (int i=0;i<n;i++) {
            if (names[i] == aman) {
                anum = i;
            }
            if (names[i] == bman) {
                bnum = i;
            } 
        }
        if (act == "Chatting") {
           chat(score, anum, bnum);
        }
        else if (act == "Field_Game") {
            fg(score, anum, bnum);
 
        }
        else if (act == "Night_Education") {
           ne(score, anum, bnum);
        }  
        else if (act == "Cheesy_Joke") {
            cj(jokes, score, anum, bnum);
        }

        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                if (score[i][j] >= 10 && score[j][i] >= 10) {
                    if (names[i] > names[j]) {
                        cout << names[j] << " " << names[i];
                    }
                    else {
                         cout << names[i] << " " << names[j];
                    }
                    return 0;
                }
            }
        }
    }
}