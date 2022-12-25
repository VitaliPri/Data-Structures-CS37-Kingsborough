
//Vitaliy Prymak, Shaya Ahmed

#include <iostream>
#include <iomanip> // working with design (set width)
#include <fstream> //working with files
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>

using namespace std;


//Bubble sort is simple concept of comparing 2 elements and if first number is larger then second swap it and repeated till the end, it is where name comes bubble up. It is unefficient algorithm because in worst case scenario is O(n^2)
void bubbleSort(vector<int>, int);

// Quick sort based on principle you chose pivot in the middle, then put it at the end, next step is take largest element from the left and smallest from the right and swap it, reapeted untill index of left element is larger then right one. Worst case scenario is O(n^2), which is unefficient
void quickSort(vector<int>, int);
void q_sort(vector<int>, int, int);


int main() {
    srand(time(0));
    clock_t start, end;
    vector<int> data(10000);
    int Size = data.size();
    double duration;
// Best Case
    ofstream bestCaseFile("best.txt");
    // output file (we write into file) and bestCaseFile is name of object
    for(int i = 1; i <= Size; i++){
        //wtite data into file
        bestCaseFile << i << endl;
        bestCaseFile.close(); //   allocated memory from operating system is released
// Worst Case
        ofstream worstCaseFile("worst.txt");
        for(int i = Size; i >= 1; i--){
            worstCaseFile << i << endl;
            worstCaseFile.close();
// Avg Case
            ofstream avgCaseFile("avg.txt");
            for(int i = 1; i <= Size; i++) {
                avgCaseFile << (rand() % Size + 1) << endl;}
            avgCaseFile.close();
                // read from bestCase File to vector
                ifstream myFile1("best.txt");
                if(!myFile1.is_open()){
                    cout << "File does not exist!...\n";}
                    else{
                        while(!myFile1.eof()){
                            // while we did not reach end of file
                            for (int i = 0; i < Size; i++){
                                myFile1 >> data[i];
                            }
                        }
                        start = clock();
                        bubbleSort(data, Size);
                        end = clock();
                        duration = ((double)(end-start))/CLOCKS_PER_SEC;
                        cout << "\nBubble Sort Best Case took " << setprecision(3) << fixed << duration << endl;
                        start = clock();
                        quickSort(data, Size);
                        end = clock();
                        duration = ((double)(end-start))/CLOCKS_PER_SEC;
                        cout << "Quick Sort Best Case took " << setprecision(3) << fixed << duration << endl;
                    }
                    myFile1.close();
                    // read from worstCase File to vector
                    ifstream myFile2("worst.txt");
                    if(!myFile2.is_open()){
                        cout << "File does not exist!...";
                    }


        else{
            while(!myFile2.eof()){
                for(int i = 0; i < Size; i++){

        myFile2 >> data[i];

    }

 }

                        start = clock();
                        bubbleSort(data, Size);
                        end = clock();
                        duration = ((double)(end-start))/CLOCKS_PER_SEC;
                        cout << "\nBubble Sort Worst Case took " << setprecision(3) << fixed << duration << endl;
                        start = clock();
                        quickSort(data, Size);
                        end = clock();
                        duration = ((double)(end-start))/CLOCKS_PER_SEC;
                        cout << "Quick Sort Worst Case took " << setprecision(3) << fixed << duration << endl;
                    }



myFile2.close();
// read from avgCase File to vector
ifstream myFile3("avg.txt");
if(!myFile3.is_open()){
cout << "File does not exist!...";}
else{
while(!myFile3.eof()){
for(int i = 0; i < Size; i++){
myFile3 >> data[i];
} }
start = clock();
bubbleSort(data, Size);
end = clock();
duration = ((double)(end-start))/CLOCKS_PER_SEC;
cout << "\nBubble Sort Average Case took " << setprecision(3) << fixed << duration << endl;
start = clock();
quickSort(data, Size);
end = clock();
duration = ((double)(end-start))/CLOCKS_PER_SEC;
cout << "Quick Sort Average Case took " << setprecision(3) << fixed << duration << endl;
}
myFile3.close();
cout << "\n\n";
return 0;
}


//Bubble sort is simple concept of comparing 2 elements and if first number is larger then second swap it and repeated till the end, it is where name comes bubble up. It is unefficient algorithm because in worst case scenario is O(n^2)
void bubbleSort(vector<int> num, int size) {
    int temp; // need for swapping
    for (int i = 1; i < size; i++) {
        for (int j = 1; j < size; j++) {
            // when previous number is larger then next one, then swap it
            if (num[j - 1] > num[j]) {
                temp = num[j - 1];
                num[j - 1] = num[j];
                num[j] = temp;
            }
        }
    }
}

// Quick sort based on principle you chose pivot in the middle, then put it at the end, next step is take largest element from the left and smallest from the right and swap it, reapeted untill index of left element is larger then right one. Worst case scenario is O(n^2), which is unefficient

        void quickSort(vector<int> num, int size)
        {
            q_sort(num, 0, size-1);
        }
        void q_sort(vector<int> num, int l, int h)
        {
            int pivot = num[l],
                    i = l, j = h;
            do {
                while ((num[h] >= pivot) && (l < h)h--;)
                if (l != h) {
                    num[l] = num[h];
                    l++;
                }


while ((num[l] <= pivot) && (l < h))
if (l != h) {
num[h] = num[l];
h--; }
}while (l < h);
num[l] = pivot;
pivot = l;
l = i;
h = j;
if (l < pivot)
q_sort(num, l, pivot-1);
if (h > pivot)
q_sort(num, pivot+1, h);}