#include <iostream>
#include <ctime>
#include <assert.h>
#include "set.h"
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
			
			recursivley_solve();
				
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
				board[row][col].value = singleton;
			}
			return solved;
		}

		void prop(coord c){
			/* intakes a square with a single value and updates the possibilities of other squares accordingly */
			// make a data type to store to propogate values
			int prop_value = lookup(c);
			if(prop_value = -1){
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
				x = c.row / 3; // integer division
				y = c.col / 3;
				for(int i = 0; i < 3; i++){
					for(int j = 0; j < 3; j++){
						if(x+i != c.row || y+j != c.col){
							update(x+i,y+j,prop_value);
						}
					}
				}
		}

		void recusivley_solve(){
			
		}
};

int main(){
  soduku s;
  s.simple_print();
  s.solve();
  s.solve(true);
}

