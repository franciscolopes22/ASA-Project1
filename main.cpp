#include <iostream>
#include <set>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

void solve1(vector<int>& arr, int size){

    int maxlen=1;
    vector<int> vec(size, 1), count(size, 1);

    for (int i=1; i<size; i++) {
        for (int j=0; j<i; j++) {
            if (arr[j]<arr[i]) {
                if (vec[i]<vec[j]+1) {
                    vec[i]=vec[j]+1;
                    count[i]=count[j];
                }
                else if (vec[i]==vec[j]+1)
                    count[i]+=count[j];
            }
        }
        maxlen=max(vec[i],maxlen);
    }
    int res=0;
    for (int i=0; i<size; i++)
        if (maxlen==vec[i]){
            res+=count[i];
        }
        
    cout<<maxlen<<' '<<res<<endl;
}

void solve2(vector<int>& arr1, vector<int>& arr2, int size1, int size2){

    int cur=0;
    int grid[size2];
    for (int j=0; j<size2; j++){ grid[j]=0; }
    for (int i=0; i<size1; i++){
        cur=0;
        for (int j=0; j<size2; j++){
            if (arr1[i]==arr2[j] && grid[j]<cur+1){
                grid[j]=cur+1;
            }
            if (arr2[j]<arr1[i] && grid[j]>cur){
                cur = grid[j];
            }
        }
    }
    int res = 0;
    for (int i=0; i<size2; i++)
        if (grid[i]>res){
            res=grid[i];
        }

    cout<<res<<endl;
}


int main(){

    string x;
    getline(cin, x);
    if (x=="1") {
        while (true) {
            string line;
            int number;
            vector<int> numbers;
            int count1=0;
            getline(cin, line);
            if (line.empty()) {break;}
            istringstream stream(line);
            while (stream >> number){
                numbers.push_back(number);
                count1++;
            }
            if (numbers.empty())
                break;
            solve1(numbers,count1);
        }

    } else {
        while (true) {
            string line;
            int number;
            vector<int> numbers1;
            set<int> seen;
            int count1=0;
            int count2=0;
            string line2;
            vector<int> numbers2;

            getline(cin, line);
            istringstream stream(line);
            while (stream >> number){
                numbers1.push_back(number);
                count1++;
                seen.insert(number);
            }
            getline(cin, line);
            istringstream stream2(line);
            while (stream2 >> number) {
                if(seen.find(number) != seen.end()) {
                    numbers2.push_back(number);
                    count2++;
                }
            }
            if (numbers1.empty() || numbers2.empty())
                break;
            solve2(numbers1,numbers2,count1,count2);
        }
    }
    return 0;
}
