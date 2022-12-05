
#include <iostream>
template<typename T>
T sort(T* arr, int first, int sec) {
    
    //создаём копию массива
    T arr2[8];
    for (int i = 0; i < 10; i++) {
        arr2[i] = arr[i];
    }
    //меняем местами значения, если первое число больше
    if (arr[first] > arr[sec]) {
        arr[sec] = arr[first];
        arr[first] = arr2[sec];
    }

    return *arr;
}
template<typename T>
T sort2(T* arr, int first, int sec) {
    T arr2[10];
    //создаём копию массива
    for (int i = 0; i < 8; i++) {
        arr2[i] = arr[i];
    }
    //счётчики k и j показывает, сколько элементов берём из первой корзины и из второй
    int k = 0;
    int j = 0;
    int razn = sec - first;
    //цикл, который работает пока одна из корзин не опустеет
    while ((k < (razn)) && (j < (razn))) {
     //минимальный из первых элементов из двух корзин добавляется в массив в начало, "начало" сдвигается в одной из корзин
    if (arr2[first + k] < arr2[sec + j]) {
        arr[first + j + k] = arr2[first + k];
        k++;   
    } else {
        arr[first + k + j] = arr2[sec + j];
          j++;
    }
    
}//добавляем остатки корзины, которая не опустела
    if (k == (razn)) {
        while (j < (razn)) {
            arr[first + k + j] = arr2[sec + j];
            j++;

       }
    }
    if (j == (razn)) {
      while (k < (razn)) {
            arr[first + k + j] = arr2[first + k];
           k++;

        }
   }
    return *arr;
}

template<typename T>
void Merge(T arr[]) {
    //сортировка по 2 элемента
    for (int i = 0; i < 8; i = i + 2) {
        int k = i + 1;
        sort(arr, i, k);
    }

   //слияния двоек, а потом четвёрок
    sort2(arr, 0, 2);
    sort2(arr, 4, 6);
    sort2(arr, 0, 4);



}
int main()
{
    //проверка работы алгоритмов на массивах из 8 элементов типа int float
    int  arr[8] = { 14,1,3,13,24,0,8,7 };
    for (int i = 0; i < 8; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << " " << std::endl;
    Merge(arr);
    for (int i = 0; i < 8; ++i) {
     std::cout << arr[i] << " ";}
    std::cout << " " << std::endl;
    float  arr2[8] = { 14.3 ,1.0,3.5,13.4,24.4,0.0,8.5,-7.4 };
    for (int i = 0; i < 8; ++i) {
        std::cout << arr2[i] << " ";
    }
    std::cout << " " << std::endl;
    Merge(arr2);
    for (int i = 0; i < 8; ++i) {
        std::cout << arr2[i] << " ";
    }
    return 0;
}

