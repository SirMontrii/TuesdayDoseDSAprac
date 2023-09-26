#include <iostream>
using namespace std;
class Array_op{
    int *arr;
    int size;
    public:
    //cons
    Array_op(int n){
        arr = new int[n];
        size=n;
        for (int i = 0; i < n; i++)
        {
            arr[i]=0;
        }
    }
    void getarr(){
        cout<<"enter the elements of the array:"<<endl;
        for (int i = 0; i < size; i++)
        {
            cin>>arr[i];
        }
    }
    void display(){
        cout<<"First array:";
        for (int i = 0; i < size; i++)
        {
            cout<<arr[i]<<",";
        }
        cout<<endl;
        
    }
    int sumOfArray(){
        int sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum +=arr[i];
        }
        return sum;
    }
    int avgArr(){
        int avg=sumOfArray()/size;
        return avg;
    }
    void minMax(){
        int minimum = INT8_MAX;
        int maximum = INT8_MIN;
        for (int i = 0; i < size; i++)
        {
            if (arr[i]<minimum){
                minimum = arr[i];
            }
            if(arr[i]>maximum){
                maximum = arr[i];
            }
        }
        cout<<"Minimum element:"<<minimum<<endl<<"Maximum element:"<<maximum<<endl;
    }
    void concat(Array_op arr1){
        int concat_arr[size+arr1.size];
        for (int i = 0; i < size+arr1.size; i++)
        {
            concat_arr[i]=arr[i];
        }
        for (int i = 0; i < arr1.size; i++)
        {
            concat_arr[i+size]= arr1.arr[i];
        }
        
        cout<<"concated array: "<<endl;
        for (int i = 0; i < size+arr1.size; i++)
        {
            cout<<concat_arr[i]<<",";
        }
        cout<<endl; 
    }
    void bub_sort(){
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size-i; j++)
            {
                if (arr[j]>arr[j+1])
                {
                    int temp = 0;
                    //swapping
                    temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
        }
    }
    void inst_sort(){
        for (int i =1; i < size; i++)
        {
            int current = arr[i];
            int j = i-1;
            while (j>=0 && arr[j]>current)
            {
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=current;
        }
        
    }
    int binarySearch(int key){
        int s=0;
        int e=size;
        while(s<=e){
            int mid= (s+e)/2;
            if (arr[mid]==key){
                return mid;
            }
            else if(arr[mid]>key){
                e= mid-1;
            }
            else if(arr[mid]<key){
                s= mid+1;
            }
        }
        return -1;
    }
    //distroc
    ~Array_op(){};
};
int main(){
    int n;
    cout<<"enter the size of the array: "<<endl;
    cin>>n;
    Array_op arr1(n);
    Array_op arr2(n);
    // arr1.getarr();
    // arr2.getarr();
    // arr1.display();
    // arr1.minMax();
    // arr1.concat(arr2);
    
    // cout<<arr1.sumOfArray()<<endl;
    // cout<<arr1.avgArr()<<endl;
    // arr1.display();
    // arr1.inst_sort();
    // arr1.display();
    // int elem;
    // cout<<"enter the element you want to search in arr1: "<<endl;
    // cin>>elem;
    // cout<<"element found at: "<<arr1.binarySearch(elem)<<endl;

    int ch;
    do {
        cout << "Menu:"<<endl;
        cout << "1. Enter Array 1"<<endl;
        cout << "2. Enter Array 2"<<endl;
        cout << "3. Display Array 1"<<endl;
        cout << "4. Calculate Sum of Array 1"<<endl;
        cout << "5. Calculate Average of Array 1"<<endl;
        cout << "6. Find Minimum and Maximum of Array 1"<<endl;
        cout << "7. Concatenate Array 1 and Array 2"<<endl;
        cout << "8. Sort Array 1 (Insertion Sort)"<<endl;
        cout << "9. Binary Search in Array 1"<<endl;
        cout << "0. Exit"<<endl;
        cout << "Enter your choice man: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter elements for Array 1:"<<endl;
                arr1.getarr();
                break;

            case 2:
                cout << "Enter elements for Array 2:"<<endl;
                arr2.getarr();
                break;

            case 3:
                cout << "Array 1:"<<endl;
                arr1.display();
                break;

            case 4:
                cout << "Sum of Array 1: " << arr1.sumOfArray() << endl;
                break;

            case 5:
                cout << "Average of Array 1: " << arr1.avgArr() << endl;
                break;

            case 6:
                arr1.minMax();
                break;

            case 7:
                arr1.concat(arr2);
                break;

            case 8:
                arr1.inst_sort();
                cout << "Sorted Array 1 --> Insertion Sort:"<<endl;
                arr1.display();
                break;

            case 9:
                int elem;
                cout << "Element you want to search in Array 1: ";
                cin >> elem;
                int index = arr1.binarySearch(elem);
                if (index != -1) {
                    cout << "Element found at index: " << index << endl;
                } else {
                    cout << "Element not found in Array 1." << endl;
                }
                break;

            case 0:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again...." << endl;
        }
    } while (ch != 0);
    return 0;
}