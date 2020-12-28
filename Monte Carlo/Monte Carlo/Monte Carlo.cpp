// Monte Carlo.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <future>
using namespace std;
long int howManyGotIntoCircle(int n, int D) {
    srand(time(0));
    int res = 0;
    for (int i = 0; i < n; i++) {
        float a = rand() % D;  // a и b -пара рандомных координат
        float b = rand() % D;
        if (pow(float(a)-(float(D)/2), 2) + pow(float(b)-float(D)/2, 2) < pow(float(D)/2, 2)) { // сколько пар попало вкруг с центром в координатах (D/2, D/2) и диаметром D
            res += 1;
        }
    }
    return res;
}
void MonteCarlo(long int M, int D, int T) {
    auto start = chrono::steady_clock::now();
	vector<future<long int>> future_threads;
    long int part = M / T;
    int remainder = M % T;
    long long int res = 0;
    
    
    for (int i = 0; i < T; ++i) {
        future_threads.emplace_back(async(launch::async, howManyGotIntoCircle, part + (remainder ? 1 : 0), D));
        if (remainder) --remainder;
    }

    for (auto& t : future_threads) {
        res += t.get();
    }
    float pi = float(res)*4/M;
    auto end = chrono::steady_clock::now();
    chrono::duration<double> time = end - start;
    //setlocale(LC_ALL, "Russian");  // без этого может сбиваеться кодировка, возможно стоит раскомментить
    cout << "При " << M << " парах случайных чисел, используя квадрат со стороной " << D << " и " << T << " потоков, получаем число pi примерно равное " << pi << " за "<< time.count() << " секунд" << endl;
}
int main()
{
    MonteCarlo(1000, 10, 1);
    MonteCarlo(1000, 10, 2);
    MonteCarlo(1000, 10, 4);
    MonteCarlo(1000, 10, 7);
    MonteCarlo(1000, 10, 8);
    MonteCarlo(100000, 100, 2);
    MonteCarlo(100000, 100, 2);
    MonteCarlo(999999999, 10000, 4); 
    // Вывод: реальное значение значение pi не достигается, но достигается приближенное, при увеличении количества потоков до 4 скорость выполнения увеличивается, при дальнейшем увеличении зависимость непонятна
}

