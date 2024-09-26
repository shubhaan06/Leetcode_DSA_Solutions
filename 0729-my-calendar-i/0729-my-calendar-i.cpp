class MyCalendar {
    vector<pair<int,int>> store;
    void print(){
        for(auto p:store){
            cout << "(" << p.first << ","<<p.second << ") ";
        }
        cout << endl;
    }
public:
    MyCalendar() {
    }
    bool book(int start, int end) {
        // cout << "before : " << endl;
        // print();
        if(store.size() == 0){
            store.push_back({start,end});
            return true;
        }
        for(pair<int,int> p:store){
            if(start >= p.first && start < p.second){
                return false;
            }
        }
        for(pair<int,int> p:store){
            if(start < p.first && end > p.first){
                return false;
            }
        }
        store.push_back({start,end});
        // cout << "before : " << endl;
        // print();
        return true;
    }
};