#include <iostream>
#include <cmath>

using namespace std;

struct dot {
	int x,y;
};

double dist(dot d);

int main()
{
	dot dots[100];
	int n,i;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>dots[i].x>>dots[i].y;
	}
    double m=-1;
    int o;
    for(i=0;i<n;i++){
		if(m<dist(dots[i])){
			m=dist(dots[i]);
			o=0;
		}
		if(m==dist(dots[i])){
			o++;
		}
    }
    cout<<m<<' '<<o;
	return 0;
}

double dist(dot d){
	return(sqrt(d.x*d.x+d.y*d.y));
}
