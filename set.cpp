#include <iostream>
using namespace std;

template <typename T>
class set(){

	public:
		void update_singletons(row, col){
			if(row == -1 or col == -1){ // checks for invalid coord
				return;
			}
			if(to_prop[row][col] == 0){
				to_prop[row][col] = 1;
			}
		}

		coord yeild_singletons(){ // need to make coord aviable
			/* iterator for propogating singletons */
			for(int i=0; i<9; i++){
				for(int j=0; j<9; j++){
					if(to_prop[i][j] == 1){
						// yeild coord (i,j)
						to_prop[i][j] = -1;
					}
				}
			}
		}

	private:
		char to_prop[9][9] = { // representation square to propogate
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0}
		}; // 0 = not propogated, 1 = to propogate, -1 = propogated

		
}
