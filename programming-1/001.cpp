#include <iostream>
#include <iomanip>

using namespace std;

/*
	001
	----------------------------------------
	Napisati program koji izračunava ukupan
	zbir faktorijela od svih prostih brojeva
	koji su članovi prvih 100 elemenata
	Fibonacci niza (tzv. fibonacci prime).

	Napomena: Pazljivo pročitajte zadatak.
	Obavezno voditi računa da se uradit
	tačno ono što je trazeno u zadataku i
	da zadatak bude logicki ispravan.
	Obavezno koristiti bar jednu funkciju
	kojoj ćete prosljediti parametar po
	referenci.

*/
void goThruFibonacci(int&);
bool isPrime(int);
double getFactorial(double);

int main() {
	int fibonacciMax = 100;

	goThruFibonacci(fibonacciMax);

	system("pause");
	return 0;
}

void goThruFibonacci(int& max) {
	long double temp1 = 0;
	long double temp2 = 1;
	long double next = 0;

	long double sum = 0;

	for (int i = 0; i < max; i++) {
		next = temp1 + temp2;

		bool prime = isPrime(next);

		cout << setw(3) << i << " - Number: " << setw(12) << next << " (Prime: " << (prime ? "Yes": "No") << ")" << endl;

		sum += (prime ? getFactorial(next) : 0);

		temp1 = temp2;
		temp2 = next;
	}

	cout << endl << "Total factorial of prime numbers: " << sum << endl;
}

bool isPrime(int number) {
	if (number == 0 || number == 1) {
		return false;
	}

	for (int i = 2; i <= number / 2; i++) {
		if (number % i == 0) {
			return false;
		}
	}

}

double getFactorial(double number) {
	if (number == 0 || number == 1) {
		return 0;
	}

	int factorial = 1;
	for (int i = 2; i <= number; i++) {
		factorial *= i;
	}

	return factorial;
}
