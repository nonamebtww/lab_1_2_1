#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void fix1() {
    int n;
    cout << "--- Задача 1: Делители числа n ---" << endl;
    cout << "Введите натуральное число n: ";
    cin >> n;

    cout << "Делители числа " << n << ": ";
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            cout << i << " ";
        }
    }

    cout << endl << endl;
}

void fix2() {
    int n;
    cout << "--- Задача 2: Двойной факториал (n!!) ---" << endl;
    cout << "Введите натуральное число n: ";
    cin >> n;

    double y = 1.0;
    for (int i = n; i > 0; i -= 2) {
        y *= i;
    }

    cout << "y = " << y << endl << endl;
}

void fix3() {
    int n;
    cout << "--- Задача 3: Произведение ряда ---" << endl;
    cout << "Введите n: ";
    cin >> n;

    double p = 1.0;
    for (int i = 1; i <= n; ++i) {
        if (i % 2 != 0) {
            p *= (double)(i + 1) / i;
        }
        else {
            p *= (double)i / (i + 1);
        }
    }

    cout << "Произведение p = " << p << endl << endl;
}

void fix4() {
    int n;
    double x;
    cout << "--- Задача 4: Двойная сумма ((x+k)/m) ---" << endl;
    cout << "Введите n: ";
    cin >> n;
    cout << "Введите x: ";
    cin >> x;

    double total = 0.0;

    for (int k = 1; k <= n; ++k) {
        double inner = 0.0;
        for (int m = k; m <= n; ++m) {
            inner += (x + k) / m;
        }

        total += inner;
    }

    cout << "Результат = " << total << endl << endl;
}

void fix5() {
    int n;
    cout << "--- Задача 5: Двойная сумма (1/(i+2j)) ---" << endl;
    cout << "Введите n: ";
    cin >> n;

    double total = 0.0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            total += 1.0 / (i + 2 * j);
        }
    }

    cout << "Результат = " << total << endl << endl;
}

void fix6() {
    srand(static_cast<unsigned int>(time(0)));

    const int N = 200;
    vector<double> arr(N);

    cout << "--- Задача 6: Локальные максимумы ---" << endl;
    cout << "Генерация массива из " << N << " случайных чисел..." << endl;

    for (int i = 0; i < N; ++i) {
        arr[i] = static_cast<double>(rand()) / RAND_MAX * 100.0;
    }

    cout << "Первые 10 чисел: ";
    for (int i = 0; i < 10; ++i) cout << arr[i] << " ";
    cout << "..." << endl;

    int count = 0;

    for (int i = 1; i < N - 1; ++i) {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
            count++;
        }
    }

    cout << "Количество чисел, больших своих соседей: " << count << endl << endl;
}

void fix7() {
    cout << "--- Задача 7: Произведение П(1/(i + j^2)) ---" << endl;

    double p = 1.0;
    int limit = 20;

    for (int i = 1; i <= limit; ++i) {
        for (int j = 1; j <= limit; ++j) {
            p *= 1.0 / (i + pow(j, 2));
        }
    }

    cout << "Результат произведения: " << p << endl << endl;
}