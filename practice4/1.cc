#include <iostream>

using namespace std;

class dorm {
    public:
        int id;
        string name;
        int posx;
        int posy;
        string descrpition;
        string forWho;

    private:   
};

int main() {
    dorm *D = new dorm[150];
    int n;
    cin >> n;

    for (int i=0;i<n;i++) {
        cin >> D[i].id >> D[i].name >> D[i].posx >> D[i].posy >> D[i].descrpition >> D[i].forWho;
    }

    char act[3] = {};
    cin >> act[0] >> act[1] >> act[2];

    int locx = 0, locy = 0; // where am i?
    int id_now = 0;
    int found = 0;




    for (int f=0;f<n;f++) {
            if (D[f].posx == locx && D[f].posy == locy) {
                id_now = f;
                found = 1;
                break;
            }
        }
    cout << "Room#" << D[id_now].id << endl;
    cout << D[id_now].name << endl;
    cout << "(" << D[id_now].posx << "," << D[id_now].posy << ")" << endl;
    cout << D[id_now].descrpition << endl;
    cout << D[id_now].forWho << endl;
    cout << "********************\n";



    for (int i=0;i<3;i++) {

         if (act[i] == 'n') {
        locy++;
        }
        else if (act[i] == 'e') {
            locx++;
        }
        else if (act[i] == 'w') {
            locx--;
        }
        else if (act[i] == 's') {
            locy--;
        }

        // find id;
        for (int f=0;f<n;f++) {
            if (D[f].posx == locx && D[f].posy == locy) {
                id_now = f;
                found = 1;
                break;
            }
        }

        if (!found) {
            locx = D[id_now].posx;
            locy = D[id_now].posy;
        }

        
        
        cout << "Room#" << D[id_now].id << endl;
        cout << D[id_now].name << endl;
        cout << "(" << D[id_now].posx << "," << D[id_now].posy << ")" << endl;
        cout << D[id_now].descrpition << endl;
        cout << D[id_now].forWho << endl;
        cout << "********************\n";

       
        
        
        found = 0; 
    }
    

}
