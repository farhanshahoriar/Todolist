#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using std::string;
using std::cin;
using std::cout;

struct task{
    std::string taskname,info;
    int date,month,year;

    void inputtask(){
        //we will input task details here.

        cout<<"Enter task name: ";
        cin>>taskname;
        cout<<"Enter task information: ";
        cin>>info;
        //getline(cin,inputinfo);//it's not working properly

        cout<<"Enter task date (Format:DD/MM/YYYY): ";
        scanf("%d%*c%d%*c%d",&date,&month,&year);

        //Need to check if input format,added by user is correct. will be done in next update
        if(year<100){
            year+=2000;
            //for year 2018 user can input 2018 or only 18. it will be converted here.
        }
    }

    //overloading operator to sort the task according to time.
    bool operator <(const task &tsk2)const{
        if(year==tsk2.year){
            if(month==tsk2.month){
                return date<tsk2.date;
            }
            else {
                return month<tsk2.month;
            }
        }
        else {
            return year<tsk2.year;
        }
    }
};

class alltask{
    std::vector<task> tasklist;

    void addtask(){
        task temp;
        temp.inputtask();
        tasklist.push_back(temp);
        system("clear");//Clear display
    }
};

int main(){

    return 0;
}

