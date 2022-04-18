// muravei.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()
{
    cout << "Hello World!\n";
    int r, n;
    cin >> n >> r;
    int* vse_puti = new int[n];//массив, где для каждого индекса будет количество путей в эту клетку, в первые 2 клетки всегда 1 путь
    vse_puti[0] = 1;
    vse_puti[1] = 1;

    for (int i = 2; i < r; i++) {
        int sum = 0;
        for (int j = 0; j < i; j++) {
            sum += vse_puti[j];
        }
        vse_puti[i] = sum;
    }//заполнили первые r индексов, которые будут использоваться в дальнейшей формуле
    if (r > 1) {
        vse_puti[r] = vse_puti[r - 1] * 2;
    }//заполняем индекс r
    for (int i = r+1; i < n; i++) {
        vse_puti[i] = vse_puti[i-1]*2-vse_puti[i-r-1];
    }//цикл который найдет количество путей для оставшихся индексов
    cout << vse_puti[n-1];
}
