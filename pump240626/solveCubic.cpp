
#include "solveCubic.h"

using namespace std;


double solveCubic(double a, double b, double c, double d)
{
    if (a == 0) {
        return 2*b ;
    }
    // Normalize the coefficients
    b /= a;
    c /= a;
    d /= a;
    // Convert to depressed cubic t^3 + pt + q = 0
    double p = c - b * b / 3.0;
    double q = 2.0 * b * b * b / 27.0 - b * c / 3.0 + d;
    // Calculate the discriminant
    double discriminant = q * q / 4.0 + p * p * p / 27.0;
    if (discriminant > 0) {
        // One real root and two complex conjugate roots
        complex<double> sqrt_discriminant = sqrt(complex<double>(discriminant, 0));
        complex<double> u1 = cbrt(-q / 2.0 + sqrt_discriminant.real());
        complex<double> u2 = cbrt(-q / 2.0 - sqrt_discriminant.real());
        complex<double> root1 = u1 + u2;
        return root1.real() - b / 3.0;
    }
    else if (discriminant == 0) {
        // All roots are real and at least two are equal
        complex<double> u1 = cbrt(-q / 2.0);
        complex<double> root1 = 2.0 * u1;
        complex<double> root2 = -u1;
        if (root1.real() - b / 3.0 >= 0)
            return root1.real() - b / 3.0;
        else if (root2.real() - b / 3.0 >= 0)
            return root2.real() - b / 3.0;
        else return -1;
    }
    else {
        // All roots are real and unequal (discriminant < 0)
        double phi = acos(-q / 2.0 / sqrt(-p * p * p / 27.0));
        double r = 2 * sqrt(-p / 3.0);
        double root1 = r * cos(phi / 3.0) - b / 3.0;
        double root2 = r * cos((phi + 2.0 * M_PI) / 3.0) - b / 3.0;
        double root3 = r * cos((phi + 4.0 * M_PI) / 3.0) - b / 3.0;
        if (root1 >= 0 || abs(root1) < 1e-7)
            return root1;
        else if (root2 >= 0 || abs(root1) < 1e-7)
            return root2;
        else if (root3 >= 0 || abs(root1) < 1e-7)
            return root3;
        else return -1;
    }
}






