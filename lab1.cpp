#include <cmath>
#include <iostream>

using namespace std;

class Informer
{
public:
    Informer() { cout << "Konstruktor Informera" << endl; }
    ~Informer() { cout << "Destrukcja Informera!" << endl; }
};

class Wektor2D
{
public:
    Wektor2D()
    {
        ++num_wek;
        cout << "Liczba wektorow: " << num_wek << endl;
        x = 0;
        y = 0;
    }

    ~Wektor2D()
    {
        cout << "Kasuje wektor o wspolrzednych x = " << x << " oraz y = " << y << endl;
        --num_wek;
        cout << "Liczba wektorow: " << num_wek << endl;
    }

    static Wektor2D kart(double kart_x, double kart_y)
    {
        Wektor2D wektor_kart{kart_x, kart_y};
        return wektor_kart;
    }

    static Wektor2D bieg(double bieg_r, double bieg_fi)
    {
        Wektor2D wektor_bieg{bieg_r * cos(bieg_fi), bieg_r * sin(bieg_fi)};
        return wektor_bieg;
    }

    // Informer informer;

    static int populacja() { return num_wek; }

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
    static int num_wek;
    double     x;
    double     y;

    friend ostream& operator<<(std::ostream& os, const Wektor2D& Vector);

    Wektor2D(double xx, double yy)
    {
        ++num_wek;
        cout << "Liczba wektorow: " << num_wek << endl;
        x = xx;
        y = yy;
        cout << "x = " << xx << " y = " << yy << endl;
    }
};

int Wektor2D::num_wek = 0;

Wektor2D operator+(Wektor2D wek1, Wektor2D wek2)
{
    double x = wek1.getX() + wek2.getX();
    double y = wek1.getY() + wek2.getY();
    return Wektor2D::kart(x, y);
}

double operator*(Wektor2D wek1, Wektor2D wek2)
{
    return wek1.getX() * wek2.getX() + wek1.getY() * wek2.getY();
}

ostream& operator<<(ostream& os, const Wektor2D& Vector)
{
    os << "[" << Vector.x << ", " << Vector.y << "] ";
    return os;
}

int main()
{
    Wektor2D wektor1 = Wektor2D::kart(1., 1.);
    Wektor2D wektor2 = Wektor2D::bieg(1., 1.);

    // Wektor2D suma = wektor + wektor2;
    // suma.print();

    // double iloczyn = wektor * wektor2;
    // cout << "iloczyn wektorow wynosi " << iloczyn << endl;

    // cout << wektor << wektor2 << "\n";

    cout << "Ostatnia linijka kodu\n" << endl;
}
