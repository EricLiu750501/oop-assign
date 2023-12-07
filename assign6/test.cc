#include <iostream>
using namespace std;



class A {
    public:
        virtual void P()  {cout << "A";}
        void Q() {cout << "AA";}
        A* R(A*r) {return r;}
        void swapL(A*a, A*b) {
            cout << a << " " << b << "\n";

            A *temp = a;
            a = b;
            b = temp;
            
            cout << a << " " << b << "\n";
           

        }
};


class C : public A {
    public :
    void P() {cout << "C";}
    void l() {cout << "CCC";}
    
};



int main() {

    A *a[10][10];
    a[0][0] = new C();
    a[0][1] = new A();
    // a[0][0]->P();
    // swap(a[0][0], a[0][1]);
    cout << a[0][0] << "\n";
    a[0][0]->swapL(a[0][0], a[0][1]);
    a[0][1]->P();
    






    // B b;
    // // b.P();
    // A *t = new A();
    // cout << b.R(t) << " \n" << t;
    // b.R(t)->P();
    // // A().P();
    // // B().P();

    
    // // A *a;
    // // a = new B();
    // // // a = A();
    // // // a = (B)(B());
    // // a->P();
    // D *f = new D();
    // cout << endl;
    // cout << f << endl;

    // f->e();
    // cout << f;
    // f->PP();
    
}