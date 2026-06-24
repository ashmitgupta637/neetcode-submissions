class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size() ; 

        vector<pair<int, double>> cars ; 
        // 2d arrya cars ke andar (position : time) store kr diya 
        for(int i= 0; i< n ; i++) {
            double time = (double)(target - position[i])/ speed[i] ; 
            cars.push_back({position[i] , time } ) ; 

        }
        // sort kr diya posiiton ke basis pr 
        sort(cars.begin(), cars.end(), [](auto &a, auto &b){
            return a.first > b.first;
        });

        int count = 0 ; 
        double prevtime  = 0 ; 
        for(auto car: cars)  {
            double currtime = car.second ; 

            if(currtime> prevtime) {
                count++ ; 
                prevtime = currtime ; 
            }
        }
        return count ; 

    }

};
