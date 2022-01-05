#include<iostream>
using namespace std;

typedef struct __Point
{
	int xpos;
	int ypos;
} Point;

Point& pntAdder(const Point &p1, const Point &p2)
{
	Point *res2 = new Point;
	res2 -> xpos = p1.xpos+p2.xpos;
	res2 -> ypos = p1.ypos+p2.ypos;
	
	return *res2;
}

int main(){
	Point *a = new Point;
	Point *b = new Point;
	
	a -> xpos=10;
	a -> ypos=30;
	b -> xpos=20;
	b -> ypos=20;
	
	Point &res = pntAdder(*a,*b);
	cout<<res.xpos<<res.ypos<<endl;
	
	delete a;
	delete b;
	delete &res;
	
}

