// NAME : Azmayen Fayek Sabil
// ID   : 190042122

/*Write a function that generates a string considering the last 4 digits of your STUDENT ID. For
example, if your ID is 134436, considering the last 4 digits the program will generate the string
"MYIDISFOURFOURTHREESIX".*/

/*question 2 is about generating prefix codes of the characters of the string that we have found in question 1*/

/*--------------------------*/
//--------------------------//

#include <bits/stdc++.h>

using namespace std;


struct node{
   int freq;
   char alphabet;

   node *left = NULL, *right = NULL;

   node(char a, int f = 0){ // creates nodes
        alphabet = a;
        freq = f;
   }

   node(node *l, node *r){ // creates a new node by merging previous two nodes
        alphabet = 'x';
        freq = l->freq + r->freq;
        left = l;
        right = r;
   }

   void traverse(string code = ""){ //DFS to assign and return the code for every character
      if(left!=NULL){
         left->traverse(code+'0');
         right->traverse(code+'1');
      }
      else{
         cout <<"  "<<alphabet<<" = "<<code<<endl;
      }
   }


};


int frequency[130]; // declaring an global array to initialize every element with zero. A=65 and Z=90

void PrefixCode(string s){

    for(int i = 0; i<s.size(); i++){

        if(s[i]=='\0'){
            break;
        }
        frequency[int(s[i])]++;
    }


    //custom comparator
    auto compare = [](const auto &a, const auto &b){
        return a->freq > b->freq;
    };
    //----------------//


    priority_queue<node*, vector<node*>, decltype(compare)> pq(compare);


    for(int i = 0; i<130; i++){
        if(frequency[i]!=0){
            pq.push(new node(i,frequency[i]));
        }
    }



    while(pq.size() >1){
         node *a = pq.top();
         pq.pop();
         node *b = pq.top();
         pq.pop();
         pq.push(new node(a,b));
    }


    pq.top()->traverse();

}

int main()
{
    //---code for question 1--------------------- //
    string firstPart = "MYIDIS";
    string numbers[10]={"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};

    cout<<"PLEASE ENTER YOUR ID: "<<endl;

    string id;
    cin>>id;

    int a,b,c,d;

    a = int(id[id.size()-4]-'0');
    b = int(id[id.size()-3]-'0');
    c = int(id[id.size()-2]-'0');
    d = int(id[id.size()-1]-'0');

    string finalString = firstPart+numbers[a]+numbers[b]+numbers[c]+numbers[d]+'\0';

    cout<<"Generated String : ";

    int i=0;
    while(finalString[i]!='\0'){
        cout<<finalString[i];
        i++;
    }

    cout<<endl<<endl;

    //----------------------//

    //-----code for question 2-----------//

    cout<<"PREFIX CODE : "<<endl;

    PrefixCode(finalString);

    //----------------------------------//

    return 0;

}
