//
// Created by AisingioroHao on 2022/10/29.
//

#ifndef BUAA_PROGRAMMINGANDALGORITHMS_TERMPROJECT_SORT_H
#define BUAA_PROGRAMMINGANDALGORITHMS_TERMPROJECT_SORT_H

#include <vector>
#include <functional>
#include <thread>

template<typename T>
class Sort {
public:
    static void SelectionSort(std::vector<T> &data);

    static std::vector<T> MergeSortBuffer;

    static void MergeSort(std::vector<T> &data);

    static void QuickSort(std::vector<T> &data);

    static void ShellSort(std::vector<T> &data);

    static void RadixSort(std::vector<T> &data);

    static void MultiThreadRadixSort(std::vector<T> &data, int threadNums = std::thread::hardware_concurrency());

};

template<typename T>
/**
 * 选择排序
 * @tparam T 传入数据类型
 * @param data 传入的数据集合
 */
void Sort<T>::SelectionSort(std::vector<T> &data) {
    int n = data.size();
    for (int i = 0; i < n - 1; i++) {
        //当前趟最小元素下标
        int min = i;
        //寻找当前趟的最小元素，并将最小元素的下标赋值给min
        for (int j = i + 1; j < n; j++) {
            if (data[j] < data[min]) {
                min = j;
            }
        }
        //交换本趟排序的开始元素的下标和当前趟最小元素的下标的值
        std::swap(data[i], data[min]);
    }
}

template<typename T>
std::vector<T> Sort<T>::MergeSortBuffer;

template<typename T>
void Sort<T>::MergeSort(std::vector<T> &data) {
    static std::function<void(int l, int r)> merge_sort = [&data](int l, int r) {
        if (l >= r)return;
        int mid = (l + r) / 2;
        merge_sort(l, mid);
        merge_sort(mid + 1, r);
        int i = l, j = mid + 1, p = l;
        while (i <= mid && j <= r) {
            if (data[i] <= data[j]) {
                MergeSortBuffer[p++] = data[i++];
            } else {
                MergeSortBuffer[p++] = data[j++];
            }
        }
        while (i <= mid) {
            MergeSortBuffer[p++] = data[i++];
        }
        while (j <= r) {
            MergeSortBuffer[p++] = data[j++];
        }
        for (i = l; i <= r; i++) {
            data[i] = MergeSortBuffer[i];
        }
    };
    if (MergeSortBuffer.size() < data.size()) {
        MergeSortBuffer.resize(data.size());
    }
    merge_sort(0, data.size() - 1);
}

template<typename T>
void Sort<T>::QuickSort(std::vector<T> &data) {

}

template<typename T>
void Sort<T>::RadixSort(std::vector<T> &data) {
    std::vector<int> tmp[10];
    int k = 0;
    T max_element = data[0];
    for (int i = 1; i < data.size(); i++) {
        max_element = std::max(max_element, data[i]);
    }
    if (max_element) {
        while (max_element) {
            max_element /= 10;
            k++;
        }
    } else {
        k = 1;
    }
    for (int i = 1, x = 1; i <= k; i++, x *= 10) {
        for (int j = 0; j < data.size(); j++) {
            int v = (data[j] / x) % 10;
            tmp[v].push_back(data[j]);
        }
        for (int j = 0, p = 0; j <= 9; j++) {
            for (int l = 0; l < tmp[j].size(); l++) {
                data[p++] = tmp[j][l];
            }
            tmp[j].clear();
        }
    }
}

template<typename T>
/**
 * 希尔排序
 * @tparam T 输入数据类型
 * @param data 输入数据集合
 */
void Sort<T>::ShellSort(std::vector<T> &data) {
    int n = data.size();
    int inc;//希尔增量 步长
    //这里采用朴素希尔增量，就是每次增量都是原来的一半，直到增量为1为止
    for (inc = n / 2; inc >= 1; inc = inc / 2) {
        //插入排序
        for (int i = inc; i < n; i++) {
            int temp = data[i];//temp存储要插入的值
            int j;
            //j从i-inc开始往前遍历，每一步的距离是inc
            for (j = i - inc; j >= 0 && data[j] > temp; j = j - inc) {
                data[j + inc] = data[j];
            }
            data[j + inc] = temp;
        }
    }
}

template<typename T>
void Sort<T>::MultiThreadRadixSort(std::vector<T> &data, int threadNums) {

}


#endif //BUAA_PROGRAMMINGANDALGORITHMS_TERMPROJECT_SORT_H