#include<iostream>
#include<fstream>
#include<string>
#include<list>
using namespace std;

void printlist(list <int> numbre)
{
	list <int>::iterator ik;
	for(ik=numbre.begin();ik!=numbre.end();ik++)
	{
		cout<<"Student Number is :"<<*ik<<endl;
	}
}

int main()
{
    list <int> groupA;
    list <int> groupB;
    list <int> groupC;
    list <int> classlist;
    list <int> classparticipants;
    list <int> absent;


    string line;

     ifstream A ("A.txt");
        if (A.is_open())
        {
           while(getline(A,line))
           {
               groupA.push_back(stoi(line));
           }
            A.close();
        }



        ifstream B ("B.txt");
        if (B.is_open())
        {
           while(getline(B,line))
           {
               groupB.push_back(stoi(line));
           }
            B.close();
        }



        ifstream C ("C.txt");
        if (C.is_open())
        {
           while(getline(C,line))
           {
               groupC.push_back(stoi(line));
           }
            C.close();
        }


        ifstream P ("participants.txt");
        if (P.is_open())
        {
           while(getline(P,line))
           {
               classparticipants.push_back(stoi(line));
           }
            P.close();
        }

        classlist.merge(groupA);
        classlist.merge(groupB);
        classlist.merge(groupC);

        list<int>::iterator cnum;
        list<int>::iterator pnum;

        for(cnum = classlist.begin();cnum != classlist.end();cnum++){
            bool ispresent = false;

            for(pnum = classparticipants.begin();pnum != classparticipants.end();pnum++){
                if(*cnum == *pnum){
                    ispresent = true;
                    break;
                }
            }

            if(!ispresent){
                absent.push_back(*cnum);
            }
        }

        absent.sort();

        cout<<"The following are student numbers for absent students"<<endl;

        printlist(absent);



    return 0;
}
