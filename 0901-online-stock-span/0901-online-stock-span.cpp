class StockSpanner {
private:
    vector<int> prices;
    stack<int> s;
    int day;
public:
    StockSpanner() {
        day = 0;
    }
    int next(int price) {
        prices.push_back(price);
        while(!s.empty() && prices[s.top()] <= price){
            s.pop();
        }
        int span;
        if(s.empty()){
            span = day+1;
        }else{
            span = day-s.top();
        }
        s.push(day);
        day++;
        return span;
    }
};