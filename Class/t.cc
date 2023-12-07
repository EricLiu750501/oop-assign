#include <cstdio>
class Trace
{
public:
    Trace() { noisy = 0; }
    void print(const char *s)
    {
        if (noisy)
            printf("%s", s);
    }
    void on() { noisy = 1; }
    void off() { noisy = 0; }

private:
    int noisy;
};

class Po {
    private:
    int atk;

    public:
    Po(int a) {
        atk = a;
    }
    Po();
    void pr() {
        printf("%d", atk);
    }
    Po operator+(Po p) {
        Po t(0);
        t.atk = this->atk + p.atk;
        return t;
        
        
    }
};



int main() {

    Po pp(4);
    Po p2(5);
    pp.pr();
    printf("%d", pp+p2);

    Trace t;
    t.on();
    t.off();
    t.print("213");
}
