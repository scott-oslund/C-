#include <iostream>
#include <ctime>
#include <assert.h>
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
			int value = -1 // updating with the number the square must be
                };
                square board[DIM][DIM];

		struct coord{
			int x = -1; // -1 for invalid coord
			int y = -1;
		}

		inline int lookup(coord){
			/* intakes a coordinate and returns the value of that square on the board. returns -1 if the square is not yet determined */
			return board[coord.row][coord.col].value;
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
						singleton = board[row][col].possible[i]
					}
				}
			if(solved){
				board[row][col].value = singleton;
			}
			return solved;
		}

		void prop(coord){
			/* intakes a square with a single value and updates the possibilities of other squares accordingly */
			// make a data type to store to propogate values
			int prop_value = lookup(coord);
			if(prop_value = -1){
				return
			}
				// updating rows
				for(int i=0; i<DIM; i++){
					if(coord.row != i){		
		
					}
				}
		}
};

int main(){
  soduku s;
  s.simple_print();
  s.solve();
  s.solve(true);
}

