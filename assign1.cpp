#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <queue>
#include <algorithm>
using namespace std;

struct Game{
   int chicken;
   int wolves;
   int boat;
};

struct Bank{
   Game left;
   Game right;
   /*   bool operator == (const Bank & bk) const{
	return (left.chicken == bk.left.chicken)&&(left.wolves == bk.left.wolves)&&(left.boat == bk.left.boat) && (right.chicken == bk.right.chicken) &&(right.wolves==bk.right.wolves)&&(right.boat==bk.right.boat);
	}*/
};

struct Node{
   Bank nd;
};
void Print(Node bf){

   cout<<bf.nd.left.chicken<<","<<bf.nd.left.wolves<<","<<bf.nd.left.boat<<endl;
   cout<<bf.nd.right.chicken<<","<<bf.nd.right.wolves<<","<<bf.nd.right.boat<<endl;
  
}
Node Move_one_ck(Node start)
{
   Node newN;
   if(start.nd.right.boat == 1){
      newN.nd.right.chicken = start.nd.right.chicken - 1;
      newN.nd.left.chicken = start.nd.left.chicken + 1;
      newN.nd.right.wolves = start.nd.right.wolves;
      newN.nd.left.wolves = start.nd.left.wolves;
      newN.nd.right.boat = 0;
      newN.nd.left.boat = 1;
   }
   else{
      newN.nd.right.chicken = start.nd.right.chicken + 1;
      newN.nd.left.chicken = start.nd.left.chicken - 1;
      newN.nd.right.wolves = start.nd.right.wolves;
      newN.nd.left.wolves = start.nd.left.wolves;
      newN.nd.right.boat = 1;
      newN.nd.left.boat = 0;
   }
   return newN;
}
Node Move_one_wl(Node start){
   Node newN;
   if(start.nd.right.boat == 1){
      newN.nd.right.chicken = start.nd.right.chicken;
      newN.nd.left.chicken = start.nd.left.chicken;
      newN.nd.right.wolves = start.nd.right.wolves - 1;
      newN.nd.left.wolves = start.nd.left.wolves + 1;
      newN.nd.right.boat = 0;
      newN.nd.left.boat = 1;
   }
   else{
      newN.nd.right.chicken = start.nd.right.chicken;
      newN.nd.left.chicken = start.nd.left.chicken;
      newN.nd.right.wolves = start.nd.right.wolves + 1;
      newN.nd.left.wolves = start.nd.left.wolves - 1;
      newN.nd.right.boat = 1;
      newN.nd.left.boat = 0;

   }
   return newN;
}

Node Move_two_ck(Node start){
   Node newN;
   if(start.nd.right.boat == 1){
      newN.nd.right.chicken = start.nd.right.chicken - 2;
      newN.nd.left.chicken = start.nd.left.chicken + 2;
      newN.nd.right.wolves = start.nd.right.wolves;
      newN.nd.left.wolves = start.nd.left.wolves;
      newN.nd.right.boat = 0;
      newN.nd.left.boat = 1;
   }
   else{
      newN.nd.right.chicken = start.nd.right.chicken + 2;
      newN.nd.left.chicken = start.nd.left.chicken - 2;
      newN.nd.right.wolves = start.nd.right.wolves;
      newN.nd.left.wolves = start.nd.left.wolves;
      newN.nd.right.boat = 1;
      newN.nd.left.boat = 0;
   }
   return newN;

}
Node Move_two_wl(Node start){
   Node newN;
   if (start.nd.right.boat == 1){
      newN.nd.right.chicken = start.nd.right.chicken;
      newN.nd.left.chicken = start.nd.left.chicken;
      newN.nd.right.wolves = start.nd.right.wolves - 2;
      newN.nd.left.wolves = start.nd.left.wolves + 2;
      newN.nd.right.boat = 0;
      newN.nd.left.boat = 1;
   }
   else{
      newN.nd.right.chicken = start.nd.right.chicken;
      newN.nd.left.chicken = start.nd.left.chicken;
      newN.nd.right.wolves = start.nd.right.wolves + 2;
      newN.nd.left.wolves = start.nd.left.wolves - 2;
      newN.nd.right.boat = 1;
      newN.nd.left.boat = 0;

   }
   return newN;
}
Node Move_cl_wl(Node start){
   Node newN;
   if(start.nd.right.boat ==1){
      newN.nd.right.chicken = start.nd.right.chicken - 1;
      newN.nd.left.chicken = start.nd.left.chicken + 1;
      newN.nd.right.wolves = start.nd.right.wolves - 1;
      newN.nd.left.wolves = start.nd.left.wolves + 1;
      newN.nd.right.boat = 0;
      newN.nd.left.boat = 1;
   }
   else{
      newN.nd.right.chicken = start.nd.right.chicken + 1;
      newN.nd.left.chicken = start.nd.left.chicken - 1;
      newN.nd.right.wolves = start.nd.right.wolves + 1;
      newN.nd.left.wolves = start.nd.left.wolves - 1;
      newN.nd.right.boat = 1;
      newN.nd.left.boat = 0;
   }
   return newN;
}

bool validMove(Node n, vector<Node> visited){
   int i = visited.size();
   // tmp = find(visited.begin(),visited.end(),n);
   for(int i=0; i<visited.size();i++){
      if (((n.nd.left.chicken==visited[i].nd.left.chicken && n.nd.left.wolves ==visited[i].nd.left.wolves && n.nd.left.boat==visited[i].nd.left.boat && n.nd.right.chicken == visited[i].nd.right.chicken && n.nd.right.wolves==visited[i].nd.right.wolves&&n.nd.right.boat==visited[i].nd.right.boat) || n.nd.left.chicken!=0 && n.nd.left.chicken< n.nd.left.wolves) || (n.nd.right.chicken!=0 && n.nd.right.chicken< n.nd.right.wolves) || n.nd.left.chicken < 0 || n.nd.left.wolves < 0 ||n.nd.right.chicken<0 ||n.nd.right.wolves<0){
	 return false;
      }
   }
   return true;
}

Node Bfs(Node start, Node goal){
   int expand = 0;
   queue<Node> q;
   vector<Node> visited;
   visited.push_back(start);
   q.push(start);
   Node temp;
  
   while(!q.empty()){
      //   for(int i = 0; i<q.size();i++){

      temp = q.front();
      //cout<<temp.nd.left.chicken<<endl;
      q.pop();
      Print(temp);
  //    outfile<<temp.nd.left.chicken<<","<<temp.nd.left.wolves<<","<<temp.nd.left.boat<<"\n"<<temp.nd.right.chicken<<","<<temp.nd.right.wolves<<","<<temp.nd.right.boat<<"\n";
      
      if(temp.nd.left.chicken == goal.nd.left.chicken && temp.nd.left.wolves==goal.nd.left.wolves && temp.nd.left.boat == goal.nd.left.boat && temp.nd.right.chicken == goal.nd.right.chicken && temp.nd.right.wolves == goal.nd.right.wolves && temp.nd.right.boat == goal.nd.right.boat){
	cout<<"Expanded node: "<<expand<<endl;
	 return temp;
      }
      expand++;
      //Print(temp);
      Node c1,c2,w1,w2,cw;
      c1 = Move_one_ck(temp);
      c2 = Move_two_ck(temp);
      w1 = Move_one_wl(temp);
      w2 = Move_two_wl(temp);
      cw = Move_cl_wl(temp);
      //      cout<<w1.nd.left.chicken<<w1.nd.left.wolves<<w1.nd.left.boat<<endl;
      if(validMove(c1,visited)){
	 q.push(c1);
	 visited.push_back(c1);

      }
      if(validMove(c2,visited)){
	 q.push(c2);
	 // temp = c2;
	 visited.push_back(c2);
      }
      if(validMove(w1,visited)){
	 q.push(w1);
	 //temp = w1;
	 visited.push_back(w1);
      }
      if(validMove(w2,visited)){
	 q.push(w2);
	 //temp = w2;
	 visited.push_back(w2);
      }
      if(validMove(cw,visited)){
	 q.push(cw);
	 //temp = cw;
	 visited.push_back(cw);
      }
   }
   //return NULL;
   }

Node Dfs(Node start, Node goal){
      int expand = 0;
      stack <Node> sk;
      vector<Node> visited;
      visited.push_back(start);
      sk.push(start);
      Node temp;
      
      while(!sk.empty()){
	 temp = sk.top();
	 sk.pop();
	 Print(temp);
	 
	 if(temp.nd.left.chicken == goal.nd.left.chicken && temp.nd.left.wolves==goal.nd.left.wolves && temp.nd.left.boat == goal.nd.left.boat && temp.nd.right.chicken == goal.nd.right.chicken && temp.nd.right.wolves == goal.nd.right.wolves && temp.nd.right.boat == goal.nd.right.boat){
	   cout<<"Expanded node: "<<expand<<endl;
	    return temp;
	   
	 }
	 
	 //Print(temp);
	 Node c1,c2,w1,w2,cw;
	 c1 = Move_one_ck(temp);
	 c2 = Move_two_ck(temp);
	 w1 = Move_one_wl(temp);
	 w2 = Move_two_wl(temp);
	 cw = Move_cl_wl(temp);

	 if(validMove(c1,visited)){
	    sk.push(c1);
	    visited.push_back(c1);
	 }
	 if(validMove(c2,visited)){
	    sk.push(c2);
	    visited.push_back(c2);
	 }
	 if(validMove(w1,visited)){
	    sk.push(w1);
	    visited.push_back(w1);
	 }
	 if(validMove(w2,visited)){
	    sk.push(w2);
	    visited.push_back(w2);
	 }
	 if(validMove(cw,visited)){
	    sk.push(cw);
	    visited.push_back(cw);
	 }
	 expand++;
      }
      
      }
Node Iddfs(Node start, Node goal){
      int max_deep=0;
      int expand = 0;
      stack <Node> sk;
      vector<Node> visited;
   
   while(true){
   
      visited.push_back(start);
      sk.push(start);
      Node temp;
     // ofstream outfile(out);
      while(!sk.empty()){
	 temp = sk.top();
	 sk.pop();
	 Print(temp);
         
	 if(temp.nd.left.chicken == goal.nd.left.chicken && temp.nd.left.wolves==goal.nd.left.wolves && temp.nd.left.boat == goal.nd.left.boat && temp.nd.right.chicken == goal.nd.right.chicken && temp.nd.right.wolves == goal.nd.right.wolves && temp.nd.right.boat == goal.nd.right.boat){
	    cout<<"Expanded nodes: "<< expand<<endl;
	    return temp;
	 }
	
	 //Print(temp);
	 Node c1,c2,w1,w2,cw;
	 c1 = Move_one_ck(temp);
	 c2 = Move_two_ck(temp);
	 w1 = Move_one_wl(temp);
	 w2 = Move_two_wl(temp);
	 cw = Move_cl_wl(temp);

	 if(validMove(c1,visited)){
	    sk.push(c1);
	    visited.push_back(c1);
	 }
	 if(validMove(c2,visited)){
	    sk.push(c2);
	    visited.push_back(c2);
	 }
	 if(validMove(w1,visited)){
	    sk.push(w1);
	    visited.push_back(w1);
	 }
	 if(validMove(w2,visited)){
	    sk.push(w2);
	    visited.push_back(w2);
	 }
	 if(validMove(cw,visited)){
	    sk.push(cw);
	    visited.push_back(cw);
	 }
      expand++;
      max_deep++;
      }
     }
}
Node Astar(Node start, Node goal){
      int expand = 0;
      int h = (goal.nd.left.chicken+goal.nd.left.wolves+goal.nd.left.boat)-(start.nd.left.chicken+start.nd.left.wolves+start.nd.left.boat);

      stack <Node> sk;
      vector<Node> visited;
      visited.push_back(start);
      sk.push(start);
      Node temp;
      
      while(!sk.empty()){
	 temp = sk.top();
	 sk.pop();
	 Print(temp);
	 
	 if(temp.nd.left.chicken == goal.nd.left.chicken && temp.nd.left.wolves==goal.nd.left.wolves && temp.nd.left.boat == goal.nd.left.boat && temp.nd.right.chicken == goal.nd.right.chicken && temp.nd.right.wolves == goal.nd.right.wolves && temp.nd.right.boat == goal.nd.right.boat){
	   cout<<"Expanded node: "<<expand<<endl;
	    return temp;
	   
	 }
	 
	 //Print(temp);
	 Node c1,c2,w1,w2,cw;
	 c1 = Move_one_ck(temp);
	 c2 = Move_two_ck(temp);
	 w1 = Move_one_wl(temp);
	 w2 = Move_two_wl(temp);
	 cw = Move_cl_wl(temp);

	 if(validMove(c1,visited)){
	    sk.push(c1);
	    visited.push_back(c1);
	 }
	 if(validMove(c2,visited)){
	    sk.push(c2);
	    visited.push_back(c2);
	 }
	 if(validMove(w1,visited)){
	    sk.push(w1);
	    visited.push_back(w1);
	 }
	 if(validMove(w2,visited)){
	    sk.push(w2);
	    visited.push_back(w2);
	 }
	 if(validMove(cw,visited)){
	    sk.push(cw);
	    visited.push_back(cw);
	 }
	 expand++;
      }
      
      }

      int main(int argc, char *argv[]){
	 int chiks, wols, boat;
	 string mode, oupt;
	 string current,glct;
	 Game sg[2], gg[2];
	 Bank sb, gb;
	 if (argc == 5){
	    mode = argv[3];
	    oupt = argv[4];
	    ifstream start, goal;
	    start.open(argv[1]);
	    goal.open(argv[2]);
	    int n=0, m=0;
	    string ck, wls, bt, ck1, wls1, bt1;
	    while(getline(start,current)){
	       for(int i=0;i<current.size();i++){
		  if(current[i]==','){
		     current[i]=' ';
		  }
	       }
               if(current.size()<=5){
	       ck=current.substr(0,1);
	       wls = current.substr(1,2);
	       bt = current.substr(3,4);
	       }
	       else {
	          ck=current.substr(0,3);
		  wls = current.substr(3,6);
		  bt = current.substr(6,7);
	       }
	    //   	 cout<<"ck "<<ck<<"  wls  "<<wls<<"  bt  "<<bt<<endl;


	       sg[n].chicken = atoi(ck.c_str());
	       sg[n].wolves = atoi(wls.c_str());
	       sg[n].boat = atoi(bt.c_str());  

	       n++;     
	    }
	    while(getline(goal, glct)){
	       for(int i=0;i<glct.size();i++){
		  if(glct[i]==','){
		     glct[i]=' ';
		  }
	       }
	       if(glct.size()<=5){
	       ck1 = glct.substr(0,1);
	       wls1 = glct.substr(1,2);
	       bt1 = glct.substr(3,4);}
	       else{
	       ck1 = glct.substr(0,3);
	       wls1 = glct.substr(3,6);
	       bt1 = glct.substr(6,7);
	       }
	       // cout<<"  "<<ck1<<" "<<wls1<<" "<<bt1<<endl;
	       gg[m].chicken = atoi(ck1.c_str());
	       gg[m].wolves = atoi(wls1.c_str());
	       gg[m].boat = atoi(bt1.c_str());
	       m++;
	    }

	    sb.left=sg[0];
	    sb.right=sg[1];
	    gb.left=gg[0];
	    gb.right=gg[1]; 
	    Node sa,go;
	    sa.nd = sb;
	    go.nd = gb;
	    ofstream oupt;
	    
	    if(mode == "bfs"){
	       Node bf = Bfs(sa,go);
	    }
	    else if(mode == "dfs"){
               Node df = Dfs(sa,go);
	    }
	    else if(mode == "iddfs"){
               Node idf = Iddfs(sa,go);
	    }
	    else if(mode == "astar"){
               Node as = Astar(sa,go);
	    }
	    else{
	       cout<<"invalid mode, mode: bfs/dfs/iddfs/astar"<<endl;
	    }

	 }
	 else{
	    cout<<"invaild input, the format is : a.out start_file goal_file mode output_file"<<endl;
	 } 


	 //test output:
	   /* for(int i=0;i<2;i++){
	      cout<<"st: "<<i+1<<": ck:"<<sg[i].chicken<<"   wl:"<<sg[i].wolves<<"  bt:"<<sg[i].boat<<endl;
	      cout<<"goal: "<<i+1<<": ck1:"<<gg[i].chicken<<"   wl1:"<<gg[i].wolves<<"  bt1:"<<gg[i].boat<<endl;

	      }*/
	      
	 return 0;
      }
