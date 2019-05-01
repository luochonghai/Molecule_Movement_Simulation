#include"stdafx.h"
#include"Fly.h"
#include"calculation_tool.h"
using namespace std;

Fly::Fly() = default;

//to initialize the velocity& coordinate of each node
Fly::Fly(double initial_cor[3],double initial_vel[3]):
		cor(), vel()
	{
	    for (int i = 0; i < 3; ++i)
	    {
		    vel[i] = initial_vel[i];
		    cor[i] = initial_cor[i];
	    }
	}
	
double* Fly::original_state()//print the coordinate of node
	{
		return cor;
	}

double * Fly::original_vel()//print the velocity of node
{
	return vel;
}

void Fly::ModifyAnoVel(double *new_vel)
{
	for (int i = 0; i < 3; ++i)
		next_vel[i] = new_vel[i];
}

void Fly::ModAnoVel(double *new_vel)
{
	ModifyAnoVel(new_vel);
}
	
bool Fly::transfer(double another_vel[3],double another_node[3])//to change the velocity direction of Fly: return true if collision happens
	{
		return	collide_node(another_vel,another_node);
	}
	
double* Fly::transfer()//when the velocity has been calculated, calculate the new coordinate
	{
		return transfer_coordinate();
	}

bool Fly::collide_node(double another_vel[3],double another_node[3])//to change the velocity direction of 2 nodes when collision happens
	{
		//to calculate the coordinate of 2 nodes if they do not collide
		double B1Next[3], B2Next[3];
		for (int i = 0; i < 3; ++i)
		{
			B1Next[i] = cor[i] + vel[i] * DELTA_T;
			B2Next[i] = another_node[i] + another_vel[i] * DELTA_T;
		}
		//to check collision first
		//1st type: the two nodes have been collided.
		if (cal_dist(another_node,cor) < COLLIDE_DIST)
		{
			//calcul the dir of collision first( known as normal vector)
			double B1B2[3],NormalVec[3];
			for (int ni = 0; ni < 3; ++ni)
				B1B2[ni] = cor[ni] - another_node[ni];
			norm_vec(B1B2,NormalVec,3);

			//modify the very node's next_cor first
			RefSolu(cor,B1Next,NormalVec,next_cor);
			//to check whether the very dimension's coordinate exceeds the limit
			for (int ci = 0; ci < 3; ++ci)
			{
				if (abs(next_cor[ci]) > ColHalfScale)//the very dimension
				{
					int sig = next_cor[ci] < 0?-1:1;
					next_cor[ci] = 2*ColHalfScale*sig - next_cor[ci];
				}
			}

			//modify another node's next_cor second
			double ano_cor[3],ano_new[3];//to record the original coordinate of another_node
			for (int i2 = 0; i2 < 3; ++i2)
				ano_cor[i2] = another_node[i2];
			RefSolu(another_node,B2Next,NormalVec,ano_new);//to store the result into another_node element
			//to check whether the very dimension's coordinate exceeds the limit
			for (int ci = 0; ci < 3; ++ci)
			{
				if (abs(ano_new[ci]) > ColHalfScale)//the very dimension
				{
					int sig = ano_new[ci] < 0 ? -1 : 1;
					ano_new[ci] = 2 * ColHalfScale*sig - ano_new[ci];
				}
			}
			for (int i2 = 0; i2 < 3; ++i2)
				another_node[i2] = ano_new[i2];

			//change velocity of the very node 1st: 
			//|v| remains the same.The new v's direction is pointed from B1 to D(next_cor).
			double VelNewDir[3], B1D[3];
			for (int bd = 0; bd < 3; ++bd)
				B1D[bd] = next_cor[bd] - cor[bd];
			norm_vec(B1D, VelNewDir, 3);
			double v_len = sqrt(v2_multi(vel, vel, 3));
			for (int vi = 0; vi < 3; ++vi)
				next_vel[vi] = v_len * VelNewDir[vi];
			//change velocity of another node 2nd
			double VelAnoDir[3], B2D[3];
			for (int bd = 0; bd < 3; ++bd)
				B2D[bd] = ano_new[bd] - ano_cor[bd];
			norm_vec(B2D, VelAnoDir, 3);
			double v_len2 = sqrt(v2_multi(another_vel, another_vel, 3));
			for (int vi = 0; vi < 3; ++vi)
				another_vel[vi] = v_len2 * VelAnoDir[vi];//store the result into another_vel element
			return true;
		}
		else//2nd type: the 2 nodes may collide
		{
			double t_col = 10,delta_sta[3],delta_end[3],sta_end[3];
			for (int di = 0; di < 3; ++di)
			{
				delta_sta[di] = cor[di] - another_node[di];
				delta_end[di] = B1Next[di] - B2Next[di];
				sta_end[di] = delta_sta[di] - delta_end[di];
			}
			double LenStaEnd = v2_multi(sta_end,sta_end,3),
				LenEndDelta = v2_multi(delta_end,sta_end,3);
			for (int si = 0; si < 2; ++si)
			{
				double temp_t = (-LenEndDelta + sqrt(LenStaEnd)*COLLIDE_DIST*(si == 0 ? 1 : -1)) / (LenStaEnd);
				if (temp_t < 0 || temp_t > 1)//wrong t
					continue;
				else//compare with current t
				{
					if (temp_t < t_col)
						t_col = temp_t;
				}
			}

			if (t_col < 0 || t_col > 1)
				return false;
			else
			{
				//will collide
				double B1_col[3], B2_col[3];//define colliding nodes
				for (int bci = 0; bci < 3; ++bci)
				{
					B1_col[bci] = t_col*cor[bci] + (1-t_col)*B1Next[bci];
					B2_col[bci] = t_col*another_node[bci] + (1-t_col)*B2Next[bci];
				}

				/*calcul the dir of collision first( known as normal vector)*/
				double B1B2[3], NormalVec[3];
				for (int ni = 0; ni < 3; ++ni)
					B1B2[ni] = B2_col[ni] - B1_col[ni];
				norm_vec(B1B2, NormalVec, 3);

				//modify the very node's next_cor first
				RefSolu(B1_col, B1Next, NormalVec, next_cor);
				//to check whether the very dimension's coordinate exceeds the limit
				for (int ci = 0; ci < 3; ++ci)
				{
					if (abs(next_cor[ci]) > ColHalfScale)//the very dimension
					{
						int sig = next_cor[ci] < 0 ? -1 : 1;
						next_cor[ci] = 2 * ColHalfScale*sig - next_cor[ci];
					}
				}

				//modify another node's next_cor second
				double ano_new[3];
				RefSolu(B2_col, B2Next, NormalVec, ano_new);//to store the result into another_node element
				//to check whether the very dimension's coordinate exceeds the limit
				for (int ci = 0; ci < 3; ++ci)
				{
					if (abs(ano_new[ci]) > ColHalfScale)//the very dimension
					{
						int sig = ano_new[ci] < 0 ? -1 : 1;
						ano_new[ci] = 2 * ColHalfScale*sig - ano_new[ci];
					}
				}
				for (int ci = 0; ci < 3; ++ci)
					another_node[ci] = ano_new[ci];

				//change velocity of the very node 1st: 
				//|v| remains the same.The new v's direction is pointed from B1 to D(next_cor).
				double VelNewDir[3], B1D[3];
				for (int bd = 0; bd < 3; ++bd)
					B1D[bd] = next_cor[bd] - B1_col[bd];
				norm_vec(B1D, VelNewDir, 3);
				double v_len = sqrt(v2_multi(vel, vel, 3));
				for (int vi = 0; vi < 3; ++vi)
					next_vel[vi] = v_len * VelNewDir[vi];
				//change velocity of another node 2nd
				double VelAnoDir[3], B2D[3];
				for (int bd = 0; bd < 3; ++bd)
					B2D[bd] = ano_new[bd] - B2_col[bd];
				norm_vec(B2D, VelAnoDir, 3);
				double v_len2 = sqrt(v2_multi(another_vel, another_vel, 3));
				for (int vi = 0; vi < 3; ++vi)
					another_vel[vi] = v_len2 * VelAnoDir[vi];//store the result into another_vel element

				return true;
			}
		}
		return false;
	}



double* Fly::transfer_coordinate()
	{
	for (int i = 0; i < 3; ++i)
		cor[i] += vel[i] * DELTA_T;
		return cor;
	}

//to update data after collision happened
void Fly::after_col()
{
	for (int i = 0; i < 3; ++i)
	{
		vel[i] = next_vel[i];
		cor[i] = next_cor[i];
	}
}

//public method of modifying node's coordinate after collision happened
void Fly::updateCol()
{
	after_col();
}

bool Fly::pinball()
{
	//node's coordinate at t+delta_t moment
	double NextMomCoor[3];
	for (int i = 0; i < 3; ++i)
		NextMomCoor[i] = cor[i] + vel[i] * DELTA_T;

	//the bias of box when colliding x time(s)
	int Time1Dir[6][3] = {1,0,0,-1,0,0,0,1,0,0,-1,0,0,0,1,0,0,-1};
	int Time2Dir[12][3] = {1,1,0,1,0,1,0,1,1,-1,-1,0,-1,0,-1,-1,-1,0,
	-1,0,1,-1,1,0,0,-1,1,0,1,-1,1,-1,0,1,0,-1};
	int Time3Dir[8][3] = {1,1,1,-1,1,1,1,-1,1,1,1,-1,
	1,-1,-1,-1,1,-1,-1,-1,1,-1,-1,-1};
	double CenBoxScale[6] = {-ColHalfScale,ColHalfScale,-ColHalfScale,ColHalfScale,-ColHalfScale,ColHalfScale};
	bool SigCol[3] = { false,false,false };
	double CTBox[6];

	//check whether it collides or not
	if (CheckNodeInBox(NextMomCoor, CenBoxScale))
		return false;//no collision in this time step

	//check whether it collides 1 time
	for (int i1 = 0; i1 < 6; ++i1)//i1 means direction(right,left,front,back,top,down)
	{
		for (int ci = 0; ci < 6; ++ci)
		{
			CTBox[ci] = CenBoxScale[ci] + 2*ColHalfScale * Time1Dir[i1][ci/2];
		}
		SigCol[0] = CheckNodeInBox(NextMomCoor, CTBox);
		if (SigCol[0])
		{
			//it can just go into one box
			Colli1Time(i1,NextMomCoor);
			return true;
		}
	}

	for (int i2 = 0; i2 < 12; ++i2)
	{
		for (int ci = 0; ci < 6; ++ci)
		{
			CTBox[ci] = CenBoxScale[ci] + 2 * ColHalfScale * Time2Dir[i2][ci / 2];
		}
		SigCol[1] = CheckNodeInBox(NextMomCoor,CTBox);
		if (SigCol[1])
		{
			Colli2Time(i2,NextMomCoor);
			return true;
		}
	}

	for (int i3 = 0; i3 < 8; ++i3)
	{
		for (int ci = 0; ci < 6; ++ci)
		{
			CTBox[ci] = CenBoxScale[ci] + 2 * ColHalfScale * Time2Dir[i3][ci / 2];
		}
		SigCol[2] = CheckNodeInBox(NextMomCoor, CTBox);
		if (SigCol[2])
		{
			Colli3Time(i3,NextMomCoor);
			return true;
		}
	}
}
/*DirNum:[0  -  5] --> Time1Dir[6][3]
		 [6  - 12] --> Time2Dir[12][3]
		 [13 - 26] --> Time3Dir[8][3]
*/
void Fly::Colli1Time(int DirNum,double* DestCoor)//node goes into boxes adjacent to central box(6 in 27)
{
	double NormalVec[3],solu[3],B0[3];//normal vector of plane P
	for (int ni = 0; ni < 3; ++ni)
	{
		NormalVec[ni] = (DirNum / 2 == ni);
	}
	//calculate B0(colliding place)
	CalLinePlane(cor, DestCoor, NormalVec, B0,ColHalfScale);//calculate B0
	RefSolu(B0,DestCoor,NormalVec,solu);

	//change coordinate of node
	for (int i = 0; i < 3; ++i)
	{
		next_cor[i] = solu[i];
	}

	//change velocity of node: |v| remains the same.The new v's direction is pointed from B0 to D.
	double VelNewDir[3],BD[3];
	for (int bd = 0; bd < 3; ++bd)
		BD[bd] = solu[bd] - B0[bd];
	norm_vec(BD,VelNewDir,3);
	double v_len = sqrt(v2_multi(vel,vel,3));
	for (int vi = 0; vi < 3; ++vi)
	{
		next_vel[vi] = v_len * VelNewDir[vi];
	}
}

void Fly::Colli2Time(int DirNum, double* DestCoor)//node goes into boxes in the middle of edge(12 in 27)
{
	int Time2Dir[12][3] = { 1,1,0,1,0,1,0,1,1,-1,-1,0,-1,0,-1,-1,-1,0,
		-1,0,1,-1,1,0,0,-1,1,0,1,-1,1,-1,0,1,0,-1 };
	/*judge which plane is the 1st colliding plane*/
	double A1[3],B1[3],C1[3],B2[3],O_cor[3] = {0,0,0};
	double NormalVec[2][3] = {0,0,0,0,0,0};
	int pl_i = 0;
	//to get normal vector first
	auto Box2Dir = Time2Dir[DirNum];
	for (int ni = 0,vi = 0; ni < 3; ++ni)
	{
		if (abs(Box2Dir[ni]) > 0.5)
			NormalVec[vi++][ni] = Box2Dir[ni];
	}

	//to check which plane is the first colliding plane:pl_i is the index of plane
	for (; pl_i < 2; ++pl_i)
	{
		//calculate B1
		CalLinePlane(cor, DestCoor, NormalVec[pl_i], B1,ColHalfScale);//here 1 means right,front or top
		//calculate the distance between B1 and O
		if (cal_dist(B1, O_cor) < double(ColHalfScale)*sqrt3)//the true point
			break;
	}

	RefSolu(B1,cor,NormalVec[pl_i],A1);//calculate A1
	RefSolu(B1,DestCoor,NormalVec[pl_i],C1);//calculate C1
	CalLinePlane(A1,C1,NormalVec[1-pl_i],B2,ColHalfScale);//calculate B2
	RefSolu(B2,C1,NormalVec[1-pl_i],next_cor);//calculate D(here is cor)

	//change velocity of node: |v| remains the same.The new v's direction is pointed from B2 to D.
	double VelNewDir[3], BD[3];
	for (int bd = 0; bd < 3; ++bd)
		BD[bd] = cor[bd] - B2[bd];
	norm_vec(BD, VelNewDir, 3);
	double v_len = sqrt(v2_multi(vel, vel, 3));
	for (int vi = 0; vi < 3; ++vi)
		next_vel[vi] = v_len * VelNewDir[vi];
}

void Fly::Colli3Time(int DirNum, double* DestCoor)//node goes into boxes on the corners(8 in 27)
{
	int Time3Dir[8][3] = { 1,1,1,-1,1,1,1,-1,1,1,1,-1,
		1,-1,-1,-1,1,-1,-1,-1,1,-1,-1,-1 };
	/*Judge which plane is the 1st colliding plane.*/
	auto Box2Dir = Time3Dir[DirNum];
	double NormalVec[3][3] = { 0,0,0,0,0,0,0,0,0 }, O_cor[3] = {0,0,0};
	double B1[3];
	int pl_i = 0,pl_j = 0,pl_k;
	for (int ni = 0, vi = 0; ni < 3; ++ni)
	{
		if (Box2Dir[ni])
			NormalVec[vi++][ni] = Box2Dir[ni];
	}
	//to check which plane is the first colliding plane:pl_i is the index of plane
	for (; pl_i < 3; ++pl_i)
	{
		//calculate B1
		CalLinePlane(cor, DestCoor, NormalVec[pl_i], B1,ColHalfScale);//here 1 means right,front or top
		//calculate the distance between B1 and O
		if (cal_dist(B1, O_cor) < double(ColHalfScale)*sqrt3)//the true point
			break;
	}

	double A1[3],C1[3],A2[3],B2[3],C2[3],B3[3];
	RefSolu(B1,cor,NormalVec[pl_i],A1);//calculate A1
	RefSolu(B1,DestCoor,NormalVec[pl_i],C1);//calculate C1
	
	//check which plane is the second colliding plane: to find which cube A1 lies in, then use the same method as AC
	double O1_cor[3];//use plane 1 to get A1-cube's center coordinate
	for (int oi = 0; oi < 3; ++oi)
		O1_cor[oi] = NormalVec[pl_i][oi]*2*double(ColHalfScale);

	for (; pl_j < 3; ++pl_j)
	{
		if (pl_i == pl_j)
			continue;
		//calculate B2
		CalLinePlane(A1,C1,NormalVec[pl_j],B2,ColHalfScale);
		if (cal_dist(B2, O1_cor) < double(ColHalfScale)*sqrt3)
			break;
	}
	RefSolu(B2,A1,NormalVec[pl_j],A2);//calculate A2
	RefSolu(B2,C1,NormalVec[pl_j],C2);//calculate C2

	//the third colliding plane
	pl_k = 3 - pl_i - pl_j;
	CalLinePlane(A2,C2,NormalVec[pl_k],B3,ColHalfScale);//calculate B3
	RefSolu(B3,C2,NormalVec[pl_k],next_cor);//calculate D(here is cor)

	//change velocity of node: |v| remains the same.The new v's direction is pointed from B2 to D.
	double VelNewDir[3], BD[3];
	for (int bd = 0; bd < 3; ++bd)
		BD[bd] = cor[bd] - B3[bd];
	norm_vec(BD, VelNewDir, 3);
	double v_len = sqrt(v2_multi(vel, vel, 3));
	for (int vi = 0; vi < 3; ++vi)
		next_vel[vi] = v_len * VelNewDir[vi];
}