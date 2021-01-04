#include <iostream>
using namespace std;

struct coord{
	int row = -1; // -1 for invalid coord
	int col = -1;
};


class prop_data{

	public:
		prop_data(){}

		void update_singletons(int row, int col){
			/* used to update which cells to propogate info from */
			if(row == -1 or col == -1){ // checks for invalid coord
				return;
			}
			if(to_prop[row][col] == 0){
				to_prop[row][col] = 1;
				num_singleton++;
			}
		}

		coord yeild_singletons(){ 
			/* iterator for propogating singletons */
			static int i = 0; // using static to create sudo-generator
			static int j = 0;
			for(; i<9; i++){
				cout<<"i="<<i;
				for(; j<9; j++){
					cout<<"testing "<<i<<j<<endl;
					if(to_prop[i][j] == 1){
						coord x = {i,j};
						to_prop[i][j] = -1;
						num_singleton--;
						i++;
						return x;
					}
				}
				cout<<"UPDATING ROW"<<endl;
				j=0;
			}
			i = 0; // reset static variables
			coord invalid;
			return invalid;
		}

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

		int num_singleton = 0;
};
