#include <stdio.h>
#include <math.h>

/**
 * @brief ������� ��� ���������� �������� a.
 * @param x �������� ���������� x.
 * @param y �������� ���������� y.
 * @param z �������� ���������� z.
 * @return ��������� ���������� a.
*/
double get_a(double x, double y, double z);

/**
 * @brief ������� ��� ���������� �������� b.
 * @param x �������� ���������� x.
 * @param y �������� ���������� y.
 * @param z �������� ���������� z.
 * @return ��������� ���������� b.
*/
double get_b(double x, double y, double z);

/**
 * @brief ����� ����� � ���������.
 * @return ���������� � ������ ������.
*/
int main() {
	const double x = 0.61;
	const double y = 0.9;
	const double z = 0.3;

	double a = get_a(x, y, z);
	double b = get_b(x, y, z);

	printf("a = %f\nb = %f", a, b);

	return 0;
}
double get_a(double x, double y, double z) {
	return (pow(z, 2 * x) + pow(y, -x) * cos(z+y)*x) / (x + 1);
}
double get_b(double x, double y, double z) {
	return sqrt(x * x + y) - y * y * pow(sin((x + z) / x), 3);
}