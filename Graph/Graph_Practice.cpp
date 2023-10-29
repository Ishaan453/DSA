#include<iostream>
#include<stack>
#include<queue>
using namespace std;
class graphnode{
    int vertex;
    graphnode *next;

    public:
        graphnode(int v){
            vertex = v;
            next = NULL;
        }

        friend class listgraph;
};

class listgraph{
    int n;
    graphnode *list[100] = {NULL};

    public:
        void setN(int x){
            n = x;
        }

        void create();
        void display();
        void DFS();
        void BFS();
};

void listgraph::create(){
    int i,j;
    graphnode *newnode, *temp;
    char ans;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<"Is there an edge between "<<i+1<<" and "<<j+1<<": ";
            cin>>ans;

            if(ans == 'y' || ans == 'Y'){
                newnode = new graphnode(j+1);

                if(list[i] == NULL){
                    list[i] = temp = newnode;
                }

                else{
                    temp->next = newnode;
                    temp = temp->next;
                }
            }
        }
    }
}

void listgraph::display(){
    for(int i=0; i<n; i++){
        graphnode *temp = list[i];
        cout<<"v "<<i+1<<" -> ";
        while(temp != NULL){
            cout<<"v "<<temp->vertex<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
}

void listgraph::DFS(){
    stack<int> s;
    bool visited[100] = {false};
    s.push(1);

    while(!s.empty()){
        int v = s.top();
        if(!visited[v-1]){
            cout<<v<<" ";
            visited[v-1] = true;
        }
        graphnode *temp = list[v-1];
        while(temp != NULL){
            if(!visited[temp->vertex-1]){
                s.push(temp->vertex);
                break;
            }
            temp = temp->next;
        }

        if(temp == NULL){
            s.pop();
        }
    }

    cout<<endl;
}

void listgraph::BFS(){
    graphnode *temp;
    bool visited[100] = {false};
    queue<int> q;
    q.push(1);
    visited[0] = true;
    while(!q.empty()){
        int v = q.front();
        cout<<v<<" ";
        q.pop();
        temp = list[v-1];
        while(temp != NULL){
            if(!visited[temp->vertex-1]){
                q.push(temp->vertex);
                visited[temp->vertex-1] = true;
            }
            temp = temp->next;
        }
    }
}

int main(){
    int n;
    cout<<"Enter number of nodes"<<endl;
    cin>>n;

    listgraph G;
    G.setN(n);
    G.create();
    cout<<"List Display"<<endl;
    G.display();
    cout<<"DFS"<<endl;
    G.DFS();
    cout<<"BFS"<<endl;
    G.BFS();
}