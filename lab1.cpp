#include <cmath>
#include <iostream>

using namespace std;

class Informer
{
public:
    Informer() { cout << "Konstruuje konstruktor" << endl; }

    ~Informer() { cout << "Destrukcja!" << endl; }
};

class Wektor2D
{
public:
    static int num_wek;
    Wektor2D()
    {
        ++num_wek;
        cout << "Liczba wektorow: " << num_wek << endl;
        x = 0;
        y = 0;
        // Informer no_name;
    }

    Wektor2D(double xx, double yy)
    {
        ++num_wek;
        cout << "Liczba wektorow: " << num_wek << endl;
        x = xx;
        y = yy;
        cout << "x = " << xx << " y = " << yy << endl;
        // Informer no_name;
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

Wektor2D operator+(Wektor2D wek1, Wektor2D wek2)
{
    double x = wek1.getX() + wek2.getX();
    double y = wek1.getY() + wek2.getY();
    return Wektor2D{x, y};
}

double operator*(Wektor2D wek1, Wektor2D wek2)
{
    return wek1.getX() * wek2.getX() + wek1.getY() * wek2.getY();
}

int main()
{
    // Wektor2D wektor, wektor2(6, 8), wektor3(0, 3);
    // wektor.y = 4;
    // wektor.x = 3;

    Wektor2D wektor{3, 4}, wektor2{6, 8};
    // wektor.setX(3);
    // wektor.setY(4);

    // wektor2.setX(6);
    // wektor2.setY(8);

    Wektor2D suma = wektor + wektor2;
    suma.print();

    double iloczyn = wektor * wektor2;
    cout << "iloczyn wektorow wynosi " << iloczyn << endl;
    // wektor.print();
    // wektor2.print();

    // puts("Hello, World!");
}
