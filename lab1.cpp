#include <cmath>
#include <iostream>

using namespace std;

class Wektor2D
{
public:
    static int num_wek;
    Wektor2D()
    {
        ++num_wek;
        cout << "Liczba wektorow: " << num_wek << endl;
    }

    Wektor2D(double xx, double yy)
    {
        ++num_wek;
        cout << "Liczba wektorow: " << num_wek << endl;
        x = xx;
        y = yy;
        cout << "x = " << xx << " y = " << yy << endl;
    }

    ~Wektor2D()
    {
        cout << "Kasuje wektor o wspolrzednych x = " << x << " oraz y = " << y << endl;
        --num_wek;
        cout << "Liczba wektorow: " << num_wek << endl;
    }

    double norm() { return sqrt(x * x + y * y); }

    void print()
    {
        double suma = norm();
        cout << "Norma wektora o wspolrzednych x = " << x << " oraz y = " << y << " rowna jest "
             << suma << endl;
    }

    void setX(double X) { x = X; };
    void setY(double Y) { y = Y; };

    double getX() { return x; };
    double getY() { return y; };

private:
    double x;
    double y;
};

int Wektor2D::num_wek = 0;

class Informer
{
public:
    Informer() { cout << "Konstruuje konstruktor domyslny" << endl; }

    ~Informer() { cout << "Destrukcja!" << endl; }
};

class Algebra
{
public:
    Algebra(){};
    Algebra(Wektor2D w1, Wektor2D w2)
    {
        wektor1 = w1;
        wektor2 = w2;
    }
    Wektor2D wektor1;
    Wektor2D wektor2;
};

Algebra operator+(Wektor2D wek1, Wektor2D wek2)
{
    double sumX = wek1.getX() + wek2.getX();
    double sumY = wek1.getY() + wek2.getY();
    cout << "Suma dwoch wektorow to [" << sumX << ", " << sumY << "]" << endl;
    return Algebra{wek1, wek2};
}

Algebra operator*(Wektor2D wek1, Wektor2D wek2)
{
    double mnozenie = wek1.getX() * wek1.getY() + wek2.getX() * wek2.getY();
    cout << "Iloczyn dwoch wektorow to " << mnozenie << endl;
    return Algebra{wek1, wek2};
}

int main()
{
    // Wektor2D wektor, wektor2(6, 8), wektor3(0, 3);
    // wektor.y = 4;
    // wektor.x = 3;

    Wektor2D wektor, wektor2;
    wektor.setX(3);
    wektor.setY(4);

    wektor2.setX(6);
    wektor2.setY(8);

    // wektor.print();
    // wektor2.print();

    Algebra suma;
    suma = wektor + wektor2;

    Algebra iloczyn;
    iloczyn = wektor * wektor2;

    // puts("Hello, World!");
}
