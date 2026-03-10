#include <iostream>

using namespace std;

//1.找最大值的函數
int findMax(int A[], int n) {
    int max_val = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > max_val) {
            max_val = A[i];
        }
    }
    return max_val;
}

//2.輔助函數：交換兩個數字
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

//3. Partition (分割) 函數
int partition(int A[], int left, int right) {
    int pivot = A[right]; //選擇最右邊的數作為基準
    int i = left;         //i 紀錄小於等於 pivot 的邊界
    
    for (int j = left; j < right; j++) {
        if (A[j] <= pivot) {
            swap(A[i], A[j]);
            i++;
        }
    }
    swap(A[i], A[right]); //最後把 pivot 放回中間
    return i;             //回傳 pivot 的正確位置
}

//4. QuickSelect 函數
int quickSelect(int A[], int left, int right, int k) {
    if (left == right) return A[left];

    int p = partition(A, left, right);
    int rank = p - left + 1; //計算pivot是這一段範圍內的第幾小

    if (k == rank) {
        return A[p];
    } else if (k < rank) {
        return quickSelect(A, left, p - 1, k);
    } else {
        //在右半邊找，k扣掉左半邊的個數
        return quickSelect(A, p + 1, right, k - rank);
    }
}

int main() {
    //定義基礎陣列
    int data[] = {12, 3, 5, 7, 4, 19, 26};
    int n = sizeof(data) / sizeof(data[0]); //計算陣列長度

    //1: 找最大值
    cout << "陣列內容: ";
    for (int i = 0; i < n; i++) cout << data[i] << " ";
    cout << endl;
    
    cout << "最大值是: " << findMax(data, n) << endl;

    //2: 找第k小(假設找第2小，答案是4)
    int k = 2;
    //注意：QuickSelect會移動陣列元素的順序
    cout << "第 " << k << " 小的數字是: " << quickSelect(data, 0, n - 1, k) << endl;

    return 0;
}