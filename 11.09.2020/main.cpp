#include<random>
#include<iostream>
#include<time.h>
#define CONST 1000000
int RandomClass1() {
	srand(time(nullptr));
	return rand();
}
int RandomClass2() {
	std::random_device device;
	return device();
}
int RandomClass3() {
	std::mt19937 rnd;
	std::random_device device;
	rnd.seed(device());
	return rnd();
}
int RandomClass4() {
	std::uniform_int_distribution<int> gen(0, CONST);
	std::mt19937 rnd;
	rnd.seed(time(nullptr));
	return gen(rnd);
}
int main() {
	int Arr1[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int Arr2[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int Arr3[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int Arr4[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	for (int i = 0; i < CONST; i++) {
		int One = RandomClass1();
		int Two = RandomClass2();
		int Three = RandomClass3();
		int Four = RandomClass4();
		for (int j = 2; j < 10; j++) {
			if (One % j == 0) {
				Arr1[j]++;
			}
			if (Two % j == 0) {
				Arr2[j]++;
			}
			if (Three % j == 0) {
				Arr3[j]++;
			}
			if (Four % j == 0) {
				Arr4[j]++;
			}
		}
	}
	for (int i = 2; i < 10; i++) {
		std::cout << i << ": " << Arr1[i] << "\n";
	}
	std::cout << "\n";
	for (int i = 2; i < 10; i++) {
		std::cout << i << ": " << Arr2[i] << "\n";
	}
	std::cout << "\n";
	for (int i = 2; i < 10; i++) {
		std::cout << i << ": " << Arr3[i] << "\n";
	}
	std::cout << "\n";
	for (int i = 2; i < 10; i++) {
		std::cout << i << ": " << Arr4[i] << "\n";
	}
	return 0;
}