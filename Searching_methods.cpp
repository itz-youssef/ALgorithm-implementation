#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"


int Sequential_Search(vector<int> arr,int value) {
    for (int i = 0; i < arr.size() ; i++) {
        if (arr[i] == value) return i;
    }
    return -1; 
}

int Recursive_Sequential_Search(vector<int> arr,int target, int index = 0) {
    if (index == arr.size()) return -1;    
    if (arr[index] == target) return index; 
    return Recursive_Sequential_Search(arr, target, index + 1); 
}

int Binary_Search(vector<int> arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int Binary_Search_Recursive(vector<int> arr, int low, int high, int target) {
    if (low > high) return -1;
    int mid = (low + high) / 2;
    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return Binary_Search_Recursive(arr, mid + 1, high, target);
    else
        return Binary_Search_Recursive(arr, low, mid - 1, target);
}

void displayMenu() {
    cout << "\n--- Search Algorithm Menu ---\n";
    cout << "1. Sequential Search\n";
    cout << "2. Recursive Sequential Search\n";
    cout << "3. Binary Search (List Must be sorted)\n";
    cout << "4. Recursive Binary Search (List Must be sorted)\n";
    cout << "5. Exit\n";
    cout << "-----------------------------\n";
    cout << "Enter your choice: ";
}

vector<int> GetVectorFromLine(string line) {
    vector<int> output;
    stringstream ss(line);
    int num;
    while (ss >> num) {
        output.push_back(num);
    }
    return output;
}

void output(int value){
    if(value == -1) cout << RED <<"Sorry, Not Found\n" << RESET;
    else cout << "The Value Found at index " <<GREEN << value << RESET << endl;
}



int main(){

    while (true)
    {
        displayMenu();
        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 5) {
            cout << RED << "Exiting.........." << RESET << endl;
            break; 
        }

        cout << "Please Enter Your Array\n";
        string arr_input_line;
        getline(cin,arr_input_line);
        vector <int> arr = GetVectorFromLine(arr_input_line);
        int target;
        cout << "Please Enter Your Target: ";
        cin >> target;
        cin.ignore();
        int value = 0;

        switch (choice)
        {
        case 1:
            value = Sequential_Search(arr,target);
            output(value);
            break;

        case 2:
            value = Recursive_Sequential_Search(arr,target);
            output(value);
            break;
        
        case 3:
            sort(arr.begin(), arr.end());
            value = Binary_Search(arr,target);
            output(value);
            break;

        case 4:
            sort(arr.begin(), arr.end());
            value = Binary_Search_Recursive(arr,0,arr.size()-1,target);
            output(value);
            break;    

        default:
            break;
        }
    }
    

}