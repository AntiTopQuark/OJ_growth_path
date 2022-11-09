#ifndef D35BA86E_9CEE_497C_B844_A0F2D3962E8B
#define D35BA86E_9CEE_497C_B844_A0F2D3962E8B
#include <stack>
#include <iostream>
class StockSpanner {
public:
    // Pair will hold two value: first->price and second->index 
    stack<pair<int,int>> st;
    StockSpanner() {
        st.push(make_pair(1e5+10,0));
    }
    
    int next(int price) {
        int curridx=st.top().second+1;
        while(st.top().first<=price)
        {
            st.pop();
        }
        int ans=curridx-st.top().second;
        st.push(make_pair(price,curridx));
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

#endif /* D35BA86E_9CEE_497C_B844_A0F2D3962E8B */
