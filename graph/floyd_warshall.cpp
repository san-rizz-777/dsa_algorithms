#include<vector>
#include<algorithm>

using namespace std;


void floyd_warshall(vector<vector<int>>&matrix)
{
	///brute force 
	///going for every k intermediate node and for every i and j pair
               for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				//for every i and j pair 
				if(matrix[i][k]==(-1) || matrix[k][j]==(-1))   continue; //means no connecting edge between with either of them
											
				if(matrix[i][j]==(-1))
				{
					//if not made first update
					matrix[i][j] = matrix[i][k] + matrix[k][j];
				}
				else{
					matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
		        		}

			}

		}

	}
///found the min distance
}	       
