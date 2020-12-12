/*#include<set>
#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include <queue>
#include <unordered_set>
#include<math.h>
#include<complex>
using namespace std; 
#define PI 3.14159265
#define ll long long
typedef complex<double> point;
point rotate(point P, point Q, double theta)
{
	return (P - Q) * polar(1.0, theta) + Q;
}
int main()
{
	double shipx = 0;
	double shipy = 0;
	string temp;
	point waypoint(10, 1);
	point origin(0, 0);
	while (getline(cin, temp))
	{
		if (temp.size() == 0)
			break;
		char instruction = temp[0];
		temp.erase(0, 1);
		int magnitude = stoi(temp);
		switch (instruction)
		{
		case 'N':
			waypoint += point(0, magnitude);
			break;
		case 'S':
			waypoint += point(0, -magnitude);
			break;
		case 'E':
			waypoint += point(magnitude, 0);
			break;
		case 'W':
			waypoint += point(-magnitude, 0);
			break;
		case 'L':
			waypoint = rotate(waypoint, origin, magnitude * PI / 180);
			break;
		case 'R':
			waypoint = rotate(waypoint, origin, -magnitude * PI / 180);
			break;
		case 'F':
			{
			shipx += magnitude*real(waypoint);
			shipy += magnitude*imag(waypoint);
			}
		}
	}
	cout << abs(shipx)+abs(shipy) << endl;
	return 0;
}*/