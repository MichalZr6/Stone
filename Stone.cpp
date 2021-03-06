// https://www.spoj.com/problems/STONE/

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

struct Point
{
	double x = 0.0;
	double y = 0.0;
	Point() {};
	Point(int x, int y) : x(x), y(y) {};
};

int main()
{
	int i, ntests, npoints;
	double A = 0.0, cen_x = 0.0, cen_y = 0.0;
	std::vector<Point> points;

	//std::cout << "tests number: ";
	std::cin >> ntests;
	//ntests = 1;

	for (int n = 0; n < ntests; n++)
	{
		A = cen_x = cen_y = 0.0;
		//std::cout << "number of points: ";
		std::cin >> npoints;
		//npoints = 4;
		if (npoints < 3 || npoints > 1000000)
			break;

		points.resize(npoints + 1);

		for (i = 0; i < npoints; i++)
		{
			std::cin >> points[i].x >> points[i].y;
			if (abs(points[i].x) > 20000 || abs(points[i].y) > 20000)
				break;
		}

		for (i = 0; i < npoints; i++)
		{
			if (i == npoints - 1)
				A += points[i].x * points[0].y - points[0].x * points[i].y;
			else
				A += points[i].x * points[i + 1].y - points[i + 1].x * points[i].y;
		}
		A *= 0.5;
		//std::cout << "area: " << A << std::endl;

		for (i = 0; i < npoints; i++)
		{
			if (i == npoints - 1)
			{
				cen_x += (points[i].x + points[0].x) * (points[i].x * points[0].y - points[0].x * points[i].y);
				cen_y += (points[i].y + points[0].y) * (points[i].x * points[0].y - points[0].x * points[i].y);
			}
			else
			{
				cen_x += (points[i].x + points[i + 1].x) * (points[i].x * points[i + 1].y - points[i + 1].x * points[i].y);
				cen_y += (points[i].y + points[i + 1].y) * (points[i].x * points[i + 1].y - points[i + 1].x * points[i].y);
			}
		}
		cen_x *= 1.0 / (6.0 * A);
		cen_y *= 1.0 / (6.0 * A);

		if (std::fabs(cen_x) < 0.005) cen_x = 0.0;
		if (std::fabs(cen_y) < 0.005) cen_y = 0.0;

		std::cout << std::fixed;
		std::cout << std::setprecision(2);
		std::cout << cen_x << " " << cen_y << std::endl;

	}

	return 0;
}