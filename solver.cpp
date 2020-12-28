#include <iostream>
#include <ctime>
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

		bool solve(bool timer = false){
			time_t start, end;
			if(timer){
				time(&start);
			}
			if(timer){
				time(&end);
				cout<<"Time to complete: "<<difftime(end,start)<<" seconds"<<endl;
			}
			return true; // will return false if unsolvable
		}

        private:
                struct square{
                        int solution = 0;
                        int possible[DIM] = {1,2,3,4,5,6,7,8,9};
                };
                square board[DIM][DIM];

		bool update(int row, int col, int rule_out){
				for(int i=0; i<DIM; i++){ // iterating through possible
					bool solvable = true;
					
				}
		}

		void col_prop(){
				for(int i=0; i<DIM; i++){
					
				}
		}

		void row_prop(){

		}

		void block_prop(){

		}
};

int main(){
  soduku s;
  s.simple_print();
  s.solve();
  s.solve(true);
}

