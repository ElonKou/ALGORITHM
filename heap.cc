/*================================================================
*  Copyright (C)2020 All rights reserved.
*  FileName : heap.cc
*  Author   : elonkou
*  Email    : elonkou@ktime.cc
*  Date     : Wed 03 Mar 2021 08:57:15 PM CST
================================================================*/

#include <iostream>
#include <vector>

using namespace std;

class Heap {
  public:
    vector<int> data;

    Heap() {}

    ~Heap() {}

    void adjustBigRootHeap() {
        for (size_t i = data.size() / 2; i > 0; i--) {
            if (data.size() == 2 * i + 1) {
                if (data[i] < data[2 * i]) {
                    int temp    = data[2 * i];
                    data[2 * i] = data[i];
                    data[i]     = temp;
                }
            } else {
                if (data[i] < data[2 * i] && data[i] < data[2 * i + 1]) {
                    if (data[2 * i] > data[2 * i + 1]) {
                        int temp    = data[2 * i];
                        data[2 * i] = data[i];
                        data[i]     = temp;
                    } else {
                        int temp        = data[2 * i + 1];
                        data[2 * i + 1] = data[i];
                        data[i]         = temp;
                    }
                } else if (data[i] < data[2 * i]) {
                    int temp    = data[2 * i];
                    data[2 * i] = data[i];
                    data[i]     = temp;
                } else if (data[i] < data[2 * i + 1]) {
                    int temp        = data[2 * i + 1];
                    data[2 * i + 1] = data[i];
                    data[i]         = temp;
                }
            }
        }
    }

    void adjustSmallRootHeap() {
        for (size_t i = data.size() / 2; i > 0; i--) {
            if (data.size() == 2 * i + 1) {
                if (data[i] > data[2 * i]) {
                    int temp    = data[2 * i];
                    data[2 * i] = data[i];
                    data[i]     = temp;
                }
            } else {
                if (data[i] > data[2 * i] && data[i] > data[2 * i + 1]) {
                    if (data[2 * i] < data[2 * i + 1]) {
                        int temp    = data[2 * i];
                        data[2 * i] = data[i];
                        data[i]     = temp;
                    } else {
                        int temp        = data[2 * i + 1];
                        data[2 * i + 1] = data[i];
                        data[i]         = temp;
                    }
                } else if (data[i] > data[2 * i]) {
                    int temp    = data[2 * i];
                    data[2 * i] = data[i];
                    data[i]     = temp;
                } else if (data[i] > data[2 * i + 1]) {
                    int temp        = data[2 * i + 1];
                    data[2 * i + 1] = data[i];
                    data[i]         = temp;
                }
            }
        }
    }

    void biuldMaxHeap() {
        for (size_t i = 0; i < (data.size() - 1) / 2; i++) {
            adjustBigRootHeap();
        }
    }

    void biuldSmallHeap() {
        for (size_t i = 0; i < (data.size() - 1) / 2; i++) {
            adjustSmallRootHeap();
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Heap& heap) {
        for (size_t i = 0; i < heap.data.size() - 1; i++) {
            os << heap.data[i + 1] << " ";
        }
        return os;
    }
};

int main(int argc, char* argv[]) {
    Heap        heap;
    vector<int> data = {-1, 53, 17, 78, 9, 45, 65, 87, 32};
    heap.data        = data;

    cout << heap << endl;
    // heap.biuldMaxHeap();
    heap.biuldSmallHeap();
    cout << heap << endl;

    return 0;
}
