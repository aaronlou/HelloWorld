#include <iostream>
#include <vector>
using namespace std;

int randN(int lower, int upper);
void printVector(vector<int> a);
int getInsertPlace(vector<int> a /*an already sorted vector*/, int value);

int main(int argc, char * argv[])
{
    //generate a vector with int elements, length N
    int N;
    cout << "Give the number of integer that need to be sorted: " ;
    cin >> N;

    vector<int> unsort;
    for(int i = 0; i < N; i++){
        unsort.push_back(randN(1,N));
    }
    printVector(unsort);

    //sort the vector using binary search
    //we create a new vector to store the sorted vector
    vector<int> sorted;
    //we need to find the place where to insert the input value, we fulfill this using function getInsertPlace
    vector<int>::const_iterator it;
    for(it = unsort.begin();it != unsort.end();it++){
        int insertPlace = getInsertPlace(sorted,*it);
        sorted.insert(sorted.begin() + insertPlace, *it);
    }
    printVector(sorted);
    return 0;
}

int randN(int lower, int upper){
    return lower + rand() % (upper-lower + 1);
//    return (int)(upper-lower)*((float)rand()/RAND_MAX) + lower;
}

void printVector(vector<int> a){
    vector<int>::const_iterator it ;
    for(it = a.begin(); it != a.end(); it++){
        cout << *it << "\t";
    }
    cout << endl;
}

int getInsertPlace(vector<int> a, int value){
    if(a.size() == 0 || value <= a.at(0)){
        return 0;
    }else if(value > a.at(a.size()-1)){
        return a.size();
    }

    int l = 0;
    int u = a.size() - 1;
//    cout << "l: " << l << " u: " << u << endl;
    while(u - l > 1) {
        int tmp = l + (u - l + 1) / 2;
        if (value <= a.at(tmp)) {
            u = tmp;
        } else {
            l = tmp;
        }
//        cout << "l: " << l << " u: " << u << endl;
    }
    return u;

}
