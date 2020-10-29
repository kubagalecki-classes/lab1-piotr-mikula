class Wektor2D
{
  public:
    Wektor2D(){x = 0; y = 0;}
    Wektor2D(double nowe_X, dobule nowe_Y)
    {
      x = nowe_X;
      y = nowe_Y;
    }

  ~Wektor2D(){std::cout << "Goodbye, " << "..."<<std::endl;}

  void setX(double X_in){x = X_in;}
  void setY(double Y_in){y = Y_in;}

  double getX(){return x;}
  double getY(){return y;}

  void   print() { std::cout << x << " " << y << std::endl; }

  private:
  double x;
  double y;

};

Wektor2D operator+(Wektor2D w1, Wektor2D w2)
{
  double x = w1.getX() + w2.getX();
  double y = w1.getY() + w2.getY();
  return Wektor2D{x, y};
}

double operator*(Wektor2D w1, Wektor2D w2)
{
  return w1.getX()*w2.getX()+w1.getY()*w2.getY();
}