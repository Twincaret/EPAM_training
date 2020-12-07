#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using namespace sf;
 
class FigureShape
{
public:

    virtual double Area() const = 0;
    virtual double Perimetr() const = 0;
    virtual void Show() const = 0;
    virtual ~FigureShape() {}
};
 
class Circle : public FigureShape
{
    double r;
public:
	Circle (double _r) : r(_r) {}
    ~Circle () {}
    double Area() const {return 3.14*r*r;}
    double Perimetr() const {return 3.14*2*r;}
    void Show() const {cout<<"Circle"<<endl;}

};

class Square : public FigureShape
{
    double a;
public:
	Square(double _a) : a(_a) {}
    ~Square () {}
    double Area() const {return a * a;}
    double Perimetr() const {return 2*(a + a);}
    void Show() const {cout<<"Square"<<endl;}
};

class Rectangle : public FigureShape
{
    double a, b;
public:
	Rectangle(double _a, double _b) : a(_a), b(_b) {}
    ~Rectangle () {}
    double Area() const {return a * b;}
    double Perimetr() const {return 2 * (a + b);}
    void Show() const {cout<<"Rectangle"<<endl;}
};
 
class Octagon : public FigureShape
{
    double a;
public:
	Octagon(double _a) : a(_a){}
    ~Octagon () {}
    double Area() const {return a * a * (2 * (sqrt(2) + 1));}
    double Perimetr() const {return 8 * a;}
    void Show() const {cout<<"Octagon"<<endl;}
};
 
 
int main() 
{
	ContextSettings set;
	set.antialiasingLevel = 8;
	RenderWindow window(VideoMode(750, 200), "Solid Figure");
		
	vector<FigureShape*> v;
	FigureShape* ptr = nullptr;
    ptr = new Circle(65.f);    
    v.push_back(ptr);
    ptr = new Square(80.f);
    v.push_back(ptr);   
    ptr = new Rectangle(180.f, 115.f);
    v.push_back(ptr);   
    ptr = new Octagon(65.f);
    v.push_back(ptr);
    
    double sum_a = 0.f;
    double sum_p = 0.f;
    	
	for (auto i : v)
    {
		i->Show();
		sum_a += i->Area();
		sum_p += i->Perimetr() ;
        cout << "Area: " << i->Area() <<endl;
        cout << "Perimetr: " << i->Perimetr() <<endl;     
        cout <<endl;     
    }
	
	cout << "Total Area: " << sum_a <<endl;
	cout << "Total Perimetr: " << sum_p <<endl;
	
	/* Graphic display */
	while (window.isOpen()) 
	{
		// Event handler constructor
		Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == Event::Closed)
				window.close();
        }
        
		/* Circle */
		CircleShape c;
		c.setRadius(65.f);
		c.setPosition(35, 40);
		c.setFillColor(Color(255, 146, 0));
		c.setOutlineColor(Color(255, 255, 255));
		c.setOutlineThickness(2);
		
		/* Square */
		CircleShape s(80.f, 4);
		s.setPosition(260, -8); 
		s.setFillColor(Color(195, 0, 183));
		s.setOutlineColor(Color(255, 255, 255));
		s.setOutlineThickness(2);
		s.rotate(45);
		
		/* Rectangle */
		RectangleShape r;
		r.setSize(Vector2f(180, 115));
        r.setPosition(360, 48);
		r.setFillColor(Color(181, 0, 0));
		s.setOutlineColor(Color(255, 255, 255));
		r.setOutlineThickness(2);

		/* Octagon */
		CircleShape o(65.f, 8);
		o.setPosition(580, 42); 
		o.setFillColor(Color(0, 180, 144));
		o.setOutlineColor(Color(255, 255, 255));
		o.setOutlineThickness(2);

        window.clear();
        
        window.draw(c); 
		window.draw(s);  
		window.draw(r); 
        window.draw(o); 
        
        window.display();
    }
    
	for (auto i : v) {delete i;} // clear memory
    
    return 0;
}
