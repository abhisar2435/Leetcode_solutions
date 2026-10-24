class Solution {
public:
    int convertdates(string date){
        vector<int>month={31,28,31,30,31,30,31,31,30,31,30,31};
        int mon=stoi(date.substr(0,2));
        int day=stoi(date.substr(3,2));
        int total =day;
        for(int i=0;i<mon-1;i++) {
            total+=month[i];
        }
        return total;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int a1=convertdates(arriveAlice);
        int a2=convertdates(leaveAlice);
        int b1=convertdates(arriveBob);
        int b2=convertdates(leaveBob);
        int start=max(a1,b1);
        int end=min(a2,b2);

        return max(0,end-start+1);        
    }
};