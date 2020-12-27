#include <iostream>
using namespace std;

const int DIM = 9;

class soduku{

        public:
                soduku(){};


                void simple_print(){
                cout<<"-------------------"<<endl;
                for(int i=0;i<DIM;i++){
                        for(int j=0;j<DIM;j++){
                                cout<<"|"<<board[i][j].solution;
                        }
                        cout<<"|"<<endl;
                }
                cout<<"-------------------"<<endl;
                };

        private:
                struct square{
                        int solution = 0;
                        int possible[9] = {1,2,3,4,5,6,7,8,9};
                };
                square board[9][9];
};

int main(){
  soduku s;
  s.simple_print();
}

