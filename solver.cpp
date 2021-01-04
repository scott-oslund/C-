#include <iostream>
#include <ctime>
#include <assert.h>
#include "set.h"
using namespace std;

const int DIM = 9;

class soduku{

        public:
                soduku(){
			for(int x = 1; x<10; x++){
				for(int y = 1; y<10; y++){
					cout<< "Enter value at row "<<x<<" col "<<y<<" (enter 0 if unkown)";
					int val;
					cin >> val;
					if(val != 0){
						propogate.to_prop[x-1][y-1] = 1;
						propogate.num_singleton++;
						board[x-1][y-1].solution = val;
						board[x-1][y-1].value = val; // should this always be 1?
						for(int i=0; i<DIM; i++){
							if(board[x-1][y-1].possible[i] != val){
								board[x-1][y-1].possible[i] = 0;
							}
						}
					}				
				}
			}
		
		};


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

		void complex_print(){
			for(int i=0;i<DIM;i++){
				for(int j=0;j<DIM;j++){
					cout<<"[ ";
					for(int k=0;k<DIM;k++){
						cout<<board[i][j].possible[k]<<" ";
					}
					cout<<"]";
				}
				cout<<endl;
			}
		}

		bool solve(bool timer = false){
			time_t start, end;
			if(timer){
				time(&start);
			}
			
			recusivley_solve();
			for(int i=0; i<10000; i++);
			
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
			int value = -1; // updating with the number the square must be
                };
                square board[DIM][DIM];

		prop_data propogate;

		inline int lookup(coord c){
			/* intakes a coordinate and returns the value of that square on the board. returns -1 if the square is not yet determined */
			return board[c.row][c.col].value;
		}

		bool update(int row, int col, int rule_out){
			/* takes in coordinates and updates possible values that square can have. returns true if there is one possible value */
			bool solved = false;
			int singleton;
			board[row][col].possible[rule_out-1] = 0;
				for(int i=0; i<DIM; i++){ // iterating through possible
					if(board[row][col].possible[i] != 0){
						if(solved){
							return false;
						}
						solved = true;
						singleton = board[row][col].possible[i];
					}
				}
			if(solved){
				propogate.update_singletons(row,col);
				board[row][col].value = singleton;
				board[row][col].solution = singleton;
			}
			return solved;
		}

		void prop(coord c){
			/* intakes a square with a single value and updates the possibilities of other squares accordingly */
			// make a data type to store to propogate values
			int prop_value = lookup(c);
			if(prop_value == -1){
				return;
			}
				// updating rows
				for(int i=0; i<DIM; i++){
					if(c.col != i){		
						update(c.row,i,prop_value);
					}
				}

				// updating columns
				for(int i=0; i<DIM; i++){
					if(c.row != i){
						update(i,c.col,prop_value);
					}
				}

				// updating the coordinate's block
				int x = (c.row / 3) * 3; // integer division
				int y = (c.col / 3) * 3;
				for(int i = 0; i < 3; i++){
					for(int j = 0; j < 3; j++){
						if(x+i != c.row || y+j != c.col){
							update(x+i,y+j,prop_value);
						}
					}
				}
		}

		void recusivley_solve(){
			coord singleton;
			do{
				singleton = propogate.yeild_singletons();
				if(singleton.row == -1){
					continue;
				}
				prop(singleton);
			}while(propogate.num_singleton != 0);

			if(num_singleton != 81){
				
			}
		}
};

int main(){
  soduku s;
  s.simple_print();
  s.solve(true);
  s.simple_print();
  s.complex_print();
}

