#include <iostream>
#include <vector>
#include <iomanip> // for std::setw
void printPolynomial(const std::vector<int>& coeffs, int degree)
{
    for (int i = degree; i >= 0; --i)
    {
        if (coeffs[i] != 0)
        {
            if (i < degree)
            {
                std::cout << " ";
                if (coeffs[i] > 0) std::cout << "+";
            }
            if (i == 0 || coeffs[i] != 1) std::cout << coeffs[i];
            if (i > 0) std::cout << "x";
            if (i > 1) std::cout << "^" << i;
        }
    }
    std::cout << std::endl;
}

// Function to compute the derivative of a polynomial
std::vector<int> computeDerivative(const std::vector<int>& coeffs, int degree)
{
    std::vector<int> derivative(degree, 0);
    for (int i = 1; i <= degree; ++i)
    {
        derivative[i - 1] = coeffs[i] * i;
    }
    return derivative;
}

int main()
{
    const int MAX_DEGREE = 5;
    std::vector<int> coeffs(MAX_DEGREE + 1, 0);

    int degree;
    std::cout << "Enter the degree of the polynomial (0-5): ";
    std::cin >> degree;

    if (degree < 0 || degree > MAX_DEGREE)
    {
        std::cerr << "Invalid degree! Degree should be between 0 and 5." << std::endl;
        return 1;
    }

    std::cout << "Enter the coefficients from highest degree to lowest (total " << (degree + 1) << " coefficients):" << std::endl;
    for (int i = degree; i >= 0; --i)
    {
        std::cout << "Coefficient of x^" << i << ": ";
        std::cin >> coeffs[i];
    }

    std::cout << "Polynomial: ";
    printPolynomial(coeffs, degree);

    if (degree > 0)
    {
        std::vector<int> derivative = computeDerivative(coeffs, degree);
        std::cout << "Derivative: ";
        printPolynomial(derivative, degree - 1);
    }
    else
    {
        std::cout << "Derivative: 0" << std::endl;
    }

    return 0;
}

